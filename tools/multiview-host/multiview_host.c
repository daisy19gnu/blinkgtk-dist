/* Copyright 2026 BlinkGTK Project
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * multiview_host.c — 1 プロセスに N 個の WebView を作り、外から計測するためのホスト
 *
 * 背景:
 *   WebView を 1/2/4/8 と増やしたときの CPU・メモリの増分を、他エンジンと
 *   比べたいという要望 (blinkgtk-dist #7)。BlinkGTK には複数 view を同時に
 *   持つ実行ファイルが無かったため、配布 SDK だけで組めるものを用意する。
 *
 * キャッシュについて (この計測の肝):
 *   BlinkGTK は 1 プロセスに BrowserContext を 1 つしか持たず、
 *   blink_web_view_new() は常にその 1 つを使う
 *   (blink_gtk_api.cc:2983 が g_browser_client->browser_context() を渡す)。
 *   よって **すべての view が profile と cache を共有する。**
 *
 *   同じ URL を N 個の view で開くと、2 つ目以降はキャッシュに当たり、
 *   N view 分の本当のコストが出ない。--cache-bust を付けると各 view の URL に
 *   ?blinkgtk_view=<i> を足し、キャッシュのキーを分ける。
 *
 *   **両方を測って差を見るのが正しい使い方。** 差が出なければ、その配信元では
 *   キャッシュが効いていない (file:// や no-store など)。
 *
 * 注意:
 *   EGL 経路 (BLINKGTK_GPU_MODE=egl) は dmabuf の宛先が 1 つなので、複数 view を
 *   同時に描くようには出来ていない。**software モードで使うこと。**
 *
 * ビルド (配布 SDK だけで組める):
 *   gcc -O2 -o multiview_host multiview_host.c $(pkg-config --cflags --libs blinkgtk-0.1)
 *
 * 使い方:
 *   ./multiview_host --views 4 --url http://localhost:8123/index.html --seconds 30
 *   ./multiview_host --views 4 --url http://localhost:8123/index.html --seconds 30 --cache-bust
 */

#include <blink_gtk/blink_gtk.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIEWS 64

static int   g_views       = 1;
static int   g_seconds     = 30;
static int   g_cache_bust  = 0;
static const char* g_url   = "http://localhost:8123/index.html";
static const char* g_resources = NULL;
static int   g_profile_per_view = 0;
static int   g_loaded      = 0;

/* /proc/self/status から 1 行引く (kB 単位の整数を返す。読めなければ -1) */
static long read_status_kb(const char* key) {
  FILE* f = fopen("/proc/self/status", "r");
  if (!f) return -1;
  char line[256];
  size_t klen = strlen(key);
  long val = -1;
  while (fgets(line, sizeof(line), f)) {
    if (strncmp(line, key, klen) == 0) {
      val = strtol(line + klen, NULL, 10);
      break;
    }
  }
  fclose(f);
  return val;
}

static void report(const char* tag) {
  printf("[multiview] %s views=%d cache_bust=%d profile_per_view=%d "
         "VmRSS=%ldkB threads=%ld\n",
         tag, g_views, g_cache_bust, g_profile_per_view,
         read_status_kb("VmRSS:"), read_status_kb("Threads:"));
  fflush(stdout);
}

static gboolean on_timeout(gpointer user_data) {
  (void)user_data;
  report("end");
  printf("[multiview] loaded=%d/%d — shutting down\n", g_loaded, g_views);
  fflush(stdout);
  blink_gtk_shutdown();
  return G_SOURCE_REMOVE;
}

static void on_load_changed(BlinkWebView* view, int event, gpointer user_data) {
  (void)view;
  /* BLINK_LOAD_FINISHED まで数える。値は blink_gtk.h の BlinkLoadEvent。 */
  if (event == BLINK_LOAD_FINISHED) {
    g_loaded++;
    printf("[multiview] view %ld finished (%d/%d)\n",
           (long)(intptr_t)user_data, g_loaded, g_views);
    fflush(stdout);
  }
}

static void usage(const char* argv0) {
  fprintf(stderr,
    "Usage: %s [--views N] [--url URL] [--seconds T] [--cache-bust]\n"
    "  --views N      作る WebView の数 (1..%d、既定 1)\n"
    "  --url URL      各 view が読み込む URL\n"
    "  --seconds T    この秒数だけ走ってから終了する (既定 30)\n"
    "  --cache-bust   各 view の URL に ?blinkgtk_view=<i> を足す\n"
    "  --profile-per-view\n"
    "                 view ごとに別の profile / cache を使う\n"
    "                 (blink_web_view_new_with_profile。1.2.3 以降)\n"
    "  --resources D  icudtl.dat / *.pak の置き場 (SDK では <prefix>/lib/chromium)\n"
    "                 省略すると MULTIVIEW_HOST_RESOURCES を見る。どちらも無ければ\n"
    "                 Chromium が実行ファイルの隣を探し、見つからなければ FATAL\n",
    argv0, MAX_VIEWS);
}

int main(int argc, char** argv) {
  /* 引数は blink_gtk_init より前に処理する (init を通すとループに入る) */
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "--views") == 0 && i + 1 < argc) {
      g_views = atoi(argv[++i]);
    } else if (strcmp(argv[i], "--url") == 0 && i + 1 < argc) {
      g_url = argv[++i];
    } else if (strcmp(argv[i], "--seconds") == 0 && i + 1 < argc) {
      g_seconds = atoi(argv[++i]);
    } else if (strcmp(argv[i], "--resources") == 0 && i + 1 < argc) {
      g_resources = argv[++i];
    } else if (strcmp(argv[i], "--profile-per-view") == 0) {
      g_profile_per_view = 1;
    } else if (strcmp(argv[i], "--cache-bust") == 0) {
      g_cache_bust = 1;
    } else if (strcmp(argv[i], "--help") == 0) {
      usage(argv[0]);
      return 0;
    }
  }
  if (g_views < 1 || g_views > MAX_VIEWS) {
    fprintf(stderr, "--views は 1..%d\n", MAX_VIEWS);
    return 2;
  }
  if (g_seconds < 1) {
    fprintf(stderr, "--seconds は 1 以上\n");
    return 2;
  }

  /* リソース (icudtl.dat / content_shell.pak / locales) の置き場。
   * **blink_gtk_init より前に呼ぶ必要がある。**
   * 指定が無いと Chromium は実行ファイルの隣を探し、見つからないと
   * icu_util.cc:310 で FATAL になる (SDK で組んだ実行ファイルは別の場所に
   * 置かれるので、まずここに当たる)。 */
  if (!g_resources) g_resources = getenv("MULTIVIEW_HOST_RESOURCES");
  if (g_resources) {
    /* 🔴 子プロセス (zygote / renderer / GPU) も同じ実行ファイルを再起動して
     *    main() に入る。そのときの argv は Chromium が組み立てるので
     *    --resources は入っていない。**環境変数に載せないと子で ICU が
     *    見つからず icu_util.cc:310 で FATAL になる。**
     *    エンジンはこの名前を読まない (資源パスの環境変数は無い)。
     *    これは本ホスト固有の受け渡しで、値を使うのはこの main() だけ。 */
    setenv("MULTIVIEW_HOST_RESOURCES", g_resources, 1);
    printf("[multiview] resources=%s\n", g_resources);
    blink_gtk_set_resources_path(g_resources);
  }

  if (!blink_gtk_init(&argc, &argv)) {
    fprintf(stderr, "[multiview] blink_gtk_init に失敗\n");
    return 1;
  }

  report("start");

  for (int i = 0; i < g_views; i++) {
    GtkWidget* window = gtk_window_new();
    char title[64];
    snprintf(title, sizeof(title), "BlinkGTK multiview %d/%d", i + 1, g_views);
    gtk_window_set_title(GTK_WINDOW(window), title);
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);

    GtkWidget* view;
    if (g_profile_per_view) {
      char prof[32];
      snprintf(prof, sizeof(prof), "mvview%d", i);
      view = blink_web_view_new_with_profile(prof);
    } else {
      view = blink_web_view_new();
    }
    if (!view) {
      fprintf(stderr, "[multiview] view %d の作成に失敗\n", i);
      return 1;
    }
    g_signal_connect(view, "load-changed",
                     G_CALLBACK(on_load_changed), (gpointer)(intptr_t)i);

    gtk_window_set_child(GTK_WINDOW(window), view);
    gtk_window_present(GTK_WINDOW(window));

    char url[2048];
    if (g_cache_bust) {
      snprintf(url, sizeof(url), "%s%cblinkgtk_view=%d",
               g_url, strchr(g_url, '?') ? '&' : '?', i);
    } else {
      snprintf(url, sizeof(url), "%s", g_url);
    }
    printf("[multiview] view %d -> %s\n", i, url);
    fflush(stdout);
    blink_web_view_load_uri(BLINK_WEB_VIEW(view), url);
  }

  g_timeout_add_seconds(g_seconds, on_timeout, NULL);

  /* blink_gtk_run_main_loop() はループ終了後に後始末まで行う。
   * g_application_run() では読み込みが始まらない。 */
  return blink_gtk_run_main_loop();
}
