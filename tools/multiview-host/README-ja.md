# 複数 view 計測ホスト

1 プロセスに N 個の WebView を作り、外から CPU・メモリを測るための実行ファイル。
blinkgtk-dist #7 (WebView を 1/2/4/8 と増やしたときの増分を他エンジンと比べたい)
への対応。

## ビルド

**配布 SDK だけで組める。** ツリーは要らない。

```sh
gcc -O2 -o multiview_host multiview_host.c $(pkg-config --cflags --libs blinkgtk-0.1)
```

## 使い方

```sh
./multiview_host --views 4 --seconds 30 \
  --resources /usr/lib64/blinkgtk-0.1/chromium \
  --url http://localhost:8123/index.html
```

| 引数 | |
|---|---|
| `--views N` | 作る WebView の数 (1..64) |
| `--url URL` | 各 view が読み込む URL |
| `--seconds T` | この秒数だけ走ってから終了する |
| `--cache-bust` | 各 view の URL に `?blinkgtk_view=<i>` を足す |
| `--resources D` | `icudtl.dat` / `*.pak` の置き場 |

## `--resources` が要る理由

SDK で組んだ実行ファイルは、リソースの隣に置かれない。指定しないと
`icu_util.cc:310` で異常終了する。

**子プロセス (zygote / renderer / GPU) も同じ実行ファイルを再起動して `main()` に
入る。そのときの argv は Chromium が組み立てるので `--resources` は入っていない。**
本ホストは環境変数 `MULTIVIEW_HOST_RESOURCES` に載せ直して子へ渡している。
エンジンはこの名前を読まない — 本ホスト固有の受け渡しである。

## `--cache-bust` が要る理由 (実測)

BlinkGTK は 1 プロセスに BrowserContext を 1 つしか持たず、`blink_web_view_new()`
は常にその 1 つを使う (`blink_gtk_api.cc:2983`)。**すべての view が profile と
cache を共有する。**

同じ URL を N 個の view で開くと、サーバへの要求は 1 回に畳まれる。

| views | 同じ URL | `--cache-bust` |
|---|---|---|
| 1 | 要求 1 回 | 1 回 |
| 2 | **1 回** | 2 回 |
| 4 | **1 回** | **4 回** |

(2026-09-18 実測。weston headless / software モード / Chromium 153.0.8010.36。
全実行で `loaded=N/N`。検算票 `docs/03-current-phase/numbers/multiview-cache-sharing.md`)

**view 数のコストを測るなら `--cache-bust` を付ける。** 付けないと 2 つ目以降が
ネットワークを経ないため、N view 分のコストにならない。

両方を測って差を見るのが正しい使い方。差が出なければ、その配信元では
キャッシュが効いていない (`file://` や `no-store` など)。

## 注意

EGL 経路 (`BLINKGTK_GPU_MODE=egl`) は dmabuf の宛先が 1 つで、複数 view を同時に
描く作りになっていない。**software モードで使うこと。**

`VmRSS` の出力は**ブラウザプロセスのみ**。renderer は別プロセスなので、
プロセスツリー全体を測るには cgroup など外からの計測を使う。
