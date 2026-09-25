# blinkgtk-dist — BlinkGTK Binary Distribution

BlinkGTK の公開バイナリ配布リポジトリです。配布物は本リポジトリの **[Releases](https://github.com/daisy19gnu/blinkgtk-dist/releases)** に置かれます。ソースコードは配布しません。

This is the public binary distribution repository for BlinkGTK. All artifacts are published under **[Releases](https://github.com/daisy19gnu/blinkgtk-dist/releases)**. Source code is not distributed.

> **各リリースの「Source code (zip / tar.gz)」について**: これは GitHub がすべてのリリースに自動生成するアーカイブで、**本配布リポジトリ (README・INSTALL 等) のスナップショットであり、BlinkGTK エンジンのソースコードではありません**。実際の配布物は各リリースに添付されたパッケージ(`.rpm` / `.tar.gz` / `.tar.bz2` / `.deb`)です。
>
> **About "Source code (zip / tar.gz)" on each release**: this is an archive GitHub auto-generates for every release. It is a **snapshot of this distribution repository (README, INSTALL, etc.) — not the BlinkGTK engine source code**. The actual distributables are the packages (`.rpm` / `.tar.gz` / `.tar.bz2` / `.deb`) attached to each release.

- プロジェクトサイト / Project site: <https://blinkgtk.org/>
- 連絡先 / Contact: `daisy19@gmail.com`

## バージョン表記について / About version numbers

パッケージ名やパス中の **`0.1`(例: `libblinkgtk-0.1.so.0`、`/usr/share/doc/blinkgtk-0.1/`)は API バージョン**です。GTK4 の `gtk-4.0` や WebKitGTK の `webkitgtk-6.0` と同じ規約で、**製品バージョン(v1.1.0 等)とは独立**しており、API/ABI に互換性のない変更が入るときにのみ変わります。

The **`0.1` in package names and paths (e.g. `libblinkgtk-0.1.so.0`, `/usr/share/doc/blinkgtk-0.1/`) is the API version** — the same convention as GTK4's `gtk-4.0` and WebKitGTK's `webkitgtk-6.0`. It is **independent of the product version** (v1.1.0 etc.) and only changes on incompatible API/ABI revisions.

### v1.2.2-build4 / build5 の同梱ヘッダにあった `Since: 1.2.3` について（v1.2.2-build6 で解消）

v1.2.2-build4 / build5 の devel パッケージに同梱した `blink_gtk.h` に、
**存在しない版 `1.2.3` を指す `Since:` が入っています。** 対象は次の 4 つです。

```
blink_gtk_init()               v1.2.2-build5 で利用できます (正しくは Since: 1.2.2)
blink_web_view_get_gpu_mode()  v1.2.2-build5 で利用できます (正しくは Since: 1.2.2)
blink_gtk_init_with_sandbox()  まだ出していません
blink_gtk_sandbox_init()       まだ出していません
```

`1.2.3` という版はありません。**v1.2.2-build6 で書き直しました。**build4 / build5 をお使いの場合のみ該当し、動作には影響しません。

In the devel package of v1.2.2-build4 / build5, `blink_gtk.h` carries
`Since: 1.2.3` — **a version that does not exist.** The first two functions
above are available in v1.2.2-build5 (they should read `Since: 1.2.2`); the
sandbox functions are not released yet. This will be corrected in the next
release. It does not affect behaviour.

## パッケージの選び方 / Choosing a package

| 環境 / Your system | 選ぶもの / Pick |
|---|---|
| Fedora 45 (x86_64) | `blinkgtk-bin-<ver>.fc45.x86_64.rpm`(開発するなら `-devel`、Python/GJS なら `-gir` も。v1.2.3-build1 から) |
| Fedora 44 (x86_64) | `blinkgtk-bin-<ver>.fc44.x86_64.rpm`(同上。Fedora 44 向けの提供は v1.2.3 まで / Fedora 44 is served up to v1.2.3) |
| Debian / Ubuntu (amd64) | `libblinkgtk-0.1-0_<ver>_amd64.deb`(開発するなら `-dev` も) |
| その他の Linux / Other Linux (glibc, x86_64) | `blinkgtk-<ver>-linux-x86_64.tar.gz` または / or `.tar.bz2`(同一内容 / identical contents) |

各バージョンの**内容物一覧**は [`manifests/`](./manifests/) を参照してください(実パッケージから自動生成)。
See [`manifests/`](./manifests/) for **per-version package manifests** (auto-generated from the actual packages).

## インストール / Installation

詳細は [INSTALL-ja.md](./INSTALL-ja.md) / [INSTALL-en.md](./INSTALL-en.md) を参照。概要 / Quick start:

```sh
# Fedora: dnf リポジトリを登録すると dnf upgrade で追随できる
# Fedora: register the dnf repository, then dnf upgrade keeps you current
# リポジトリは Fedora の版ごとに分かれています (v1.2.3-build1 から)。以前に登録した
# 設定のままでも Fedora 44 向けを受け取れます。Fedora 45 向けを受け取るには取り直してください
# The repository is split by Fedora release (from v1.2.3-build1). An older .repo keeps
# receiving the Fedora 44 packages; fetch it again to receive the Fedora 45 packages
sudo curl -o /etc/yum.repos.d/blinkgtk.repo \
  https://blinkgtk.org/repo/fedora/blinkgtk.repo
sudo dnf install blinkgtk-bin

# RPM を個別に / individual RPM (Fedora 45 なら .fc45、Fedora 44 なら .fc44)
sudo dnf install ./blinkgtk-bin-<ver>.fc45.x86_64.rpm

# DEB (Debian / Ubuntu)
sudo apt install ./libblinkgtk-0.1-0_<ver>_amd64.deb

# tarball (ルートに展開 / extract to root)
sudo tar -C / -xzf blinkgtk-<ver>-linux-x86_64.tar.gz && sudo ldconfig
```

## Windows (BlinkGTK for Windows)

BlinkGTK-Windows が作成している Windows 版です。**Linux 版とは版数が違います** (Chromium 152)。
Windows 10 (64bit) 以降の x64 が対象で、確認したのは Windows 11 Pro (build 26200) です。描画経路は software のみ、コード署名はまだありません。
The Windows build, produced by BlinkGTK-Windows. **Its version differs from the Linux build** (Chromium 152). It targets x64 Windows 10 (64-bit) or later and was verified on Windows 11 Pro (build 26200). Rendering uses the software path only, and the package is not code-signed yet.

| 版 / Version | 日付 / Date | Chromium | ファイル / Files |
|---|---|---|---|
| **v1.2.1-build3-windows** | 2026-09-24 | 152.0.7977.64 | 52 |

はじめかた / Getting started: [日本語](https://blinkgtk.org/docs/windows-getting-started-ja.html) · [English](https://blinkgtk.org/docs/windows-getting-started-en.html)

## 検証 / Verification

各 Release の `SHA256SUMS` と照合してください / Verify against `SHA256SUMS` in each Release:

```sh
sha256sum -c SHA256SUMS --ignore-missing
```

RPM は GPG 署名済みです。公開鍵は本リポジトリの [`BlinkGTK-GPG-KEY.asc`](./BlinkGTK-GPG-KEY.asc) です:

RPMs are GPG-signed. The public key is [`BlinkGTK-GPG-KEY.asc`](./BlinkGTK-GPG-KEY.asc) in this repository:

```sh
sudo rpm --import BlinkGTK-GPG-KEY.asc
rpm --checksig blinkgtk-bin-<ver>.fc44.x86_64.rpm    # 'digests signatures OK' を確認
```

## 計測につかう道具 / Measurement tools

[`tools/multiview-host/`](./tools/multiview-host) に、**WebView を N 個作って同じ URL を読ませるホスト**を置いています。配布 SDK だけで組めます (C 言語、依存は BlinkGTK と GTK4 のみ)。view 数を増やしたときのコストを他のエンジンと比べる用途を想定しています。

- `--views N` / `--url URL` / `--seconds T`
- `--profile-per-view` — view ごとに別の profile と cache を使う (v1.2.2-build6 以降)
- `--fresh-profiles` — 起動前に profile を消す。**毎回まっさらから測る**
- `--cache-bust` — 各 view の URL に `?blinkgtk_view=<i>` を足す

名前付き profile は HTTP キャッシュをディスクに置くため、`--fresh-profiles` を付けないと 2 回目以降は温まった状態から始まります。

A host that creates N WebViews and loads the same URL in each is provided under [`tools/multiview-host/`](./tools/multiview-host). It builds against the distributed SDK alone (C, depending only on BlinkGTK and GTK4), and is intended for comparing the cost of adding views against other engines. A named profile keeps its HTTP cache on disk, so without `--fresh-profiles` the second and later runs start warm.

## 不具合報告・質問 / Reporting problems

配布パッケージの不具合や質問は、本リポジトリの **[Issues](https://github.com/daisy19gnu/blinkgtk-dist/issues)** にご報告ください(テンプレートがあります)。報告前に [`INSTALL.md`](./INSTALL.md) のトラブルシューティングもご確認ください。詳しくは [`SUPPORT.md`](./SUPPORT.md)。

Report problems or ask questions via **[Issues](https://github.com/daisy19gnu/blinkgtk-dist/issues)** (templates provided). Please also check the troubleshooting section of [`INSTALL.md`](./INSTALL.md) first. See [`SUPPORT.md`](./SUPPORT.md).

> 本配布物は無保証です。Issue への対応はベストエフォートで、商用サポートではありません(反映を保証しません)。 / Packages are provided as-is; issue handling is best-effort and not commercial support.
>
> 商用サポート・受託開発のご相談は <https://blinkgtk.com/> へ。 / For commercial support or custom development, see <https://blinkgtk.com/>.
>
> BlinkGTK は上流 Chromium に追従します。Web の描画・互換性に関する挙動は上流 Chromium と共通のことが多く、原因が上流にある場合は BlinkGTK 側で修正できないことがあります。 / BlinkGTK tracks upstream Chromium; web rendering/compatibility behavior is often shared with upstream, and some issues originate upstream and cannot be fixed in BlinkGTK.

## バージョン一覧 / Versions

| バージョン / Version | 日付 / Date | Chromium | 累計DL※ / Downloads※ | 概要 / Summary |
|---|---|---|---:|---|
| **v1.2.3-build3**（最新 / current） | 2026-09-26 | 154.0.8037.57 | 20 | 独自スキーム (`ebook://` など) で配った 5 MB 以上の音声を `<audio>` で開くと、アプリのウィンドウごと応答しなくなる問題を直しました。長い朗読音声もそのまま再生・シークできます。公開 API は変わりません / Opening audio of 5 MB or more served over a custom scheme (such as `ebook://`) with `<audio>` no longer makes the whole application window stop responding. Long narration audio can be played and seeked as is. The public API is unchanged |
| **v1.2.3-build2** | 2026-09-25 | 154.0.8037.57 | 81 | ページを PDF ファイルに書き出せるようになりました (`blink_web_view_print_to_pdf_with_options()`)。ダウンロードの保存、リンク先と新しいウィンドウの開き方の判断、カメラとマイク、HTTP 認証への応答、許可の決定を覚える口、既定のフォントと最小文字サイズの指定も加わりました。swiftshader モードで画面に何も出なかった問題も直しています (外部利用者のご報告)。実行時に CUPS のライブラリ (`libcups.so.2`) が要ります。`/usr/bin/blinkgtk-simple-browser` は `/usr/bin/blinkgtk-browser` になりました。 / Pages can now be written to PDF files. Saving downloads, deciding where links and new windows open, the camera and microphone, answering HTTP authentication, remembering permission decisions, and choosing default fonts and a minimum font size are added. swiftshader mode showing nothing on screen is fixed (reported by an external user). The CUPS library (`libcups.so.2`) is now required at run time. `/usr/bin/blinkgtk-simple-browser` is now `/usr/bin/blinkgtk-browser`. |
| **v1.2.3-build1** | 2026-09-24 | 154.0.8037.57 | 66 | レンダリングエンジンを Chromium 154 に更新しました。`blink_web_view_set_javascript_enabled(FALSE)` などの設定がページに反映されるようになりました（1.2.2 までは値を覚えるだけで、`FALSE` にしてもスクリプトは実行されていました）。画像と localStorage の無効化、既定の文字サイズも効きます。既定の文字コードはまだ効きません。入力メソッドは GTK の選択に従います（1.2.2 の動作は `BLINKGTK_IM_MODULE=ibus`）。独自スキームの MIME の引数と `fetch()`、パッケージ版でのリソースの自動検出も直しました（外部利用者のご報告）。Fedora 45 向けの RPM（.fc45）も用意しています。 / Updated to Chromium 154. Settings such as `blink_web_view_set_javascript_enabled(FALSE)` now take effect (up to 1.2.2 the value was only stored and scripts still ran). Turning off images and localStorage, and the default font size, also work; the default encoding does not yet. The input method follows GTK's choice (`BLINKGTK_IM_MODULE=ibus` restores 1.2.2). Custom-scheme MIME parameters and `fetch()`, and resource detection in packaged builds, are fixed (reported by an external user). Fedora 45 RPMs (.fc45) are also provided. |
| v1.2.2-build6 | 2026-09-19 | 153.0.8010.36 | 89 | WebView ごとに別の profile と cache を使えるようになりました（`blink_web_view_new_with_profile()`）。これまで 1 プロセスの全 WebView が profile と cache を共有しており、同じ URL を複数の view で開くと 2 つ目以降はキャッシュに当たるため、**実際の読み込みは 1 回しか起きません**でした。view を増やしたときのコストを測る用途では、そのままでは測れません（外部利用者のご報告）。名前付き profile は HTTP キャッシュを `profiles/<name>/Cache` に置きます（既定の view はメモリ上のまま）。**キャッシュは終了後も残る**ので、毎回まっさらから始めたい場合は profile ディレクトリを消してから起動してください。あわせて `permission-request` シグナルの種別名が 13 種から 40 種になり、これまで `"unknown"` で届いていた 27 種（`screen-wake-lock` / `local-fonts` / `persistent-storage` など）を見分けられます。 / Each WebView can now have its own profile and cache (`blink_web_view_new_with_profile()`). Until now every WebView in a process shared one profile and cache, so opening the same URL in several views served all but the first from that cache and **only one load actually happened** — which made it impossible to measure what an additional view costs (reported by an external user). A named profile keeps its HTTP cache on disk at `profiles/<name>/Cache`; views from `blink_web_view_new()` keep an in-memory cache. **The cache survives shutdown**, so remove the profile directory first when a run must start cold. The `permission-request` signal now names 40 kinds instead of 13, so the 27 that used to arrive as `"unknown"` (`screen-wake-lock`, `local-fonts`, `persistent-storage` and others) can be told apart. |
| v1.2.2-build5 | 2026-09-14 | 153.0.8010.36 | 66 | 描画経路を API から選べるようになりました（`blink_gtk_set_gpu_mode()` を `blink_gtk_init()` の前に呼びます）。これまで `blink_web_view_new_with_gpu_mode()` で EGL を指定しても経路は切り替わらず、環境変数 `BLINKGTK_GPU_MODE` を併用していない場合は CPU ピクセル経路で動いていました（外部利用者のご報告）。描画経路はエンジンの初期化中に 確定し、GPU プロセスへ渡す起動フラグもそこで決まるため、WebView を作る時点ではもう 変えられません。起動ログはどちらの場合も EGL と表示するので、指定が効いているかを外から 確かめる手段もありませんでした。`blink_web_view_get_gpu_mode()` は初期化の後、実際に 動いている経路を返します。 / The rendering path can now be chosen from the API (call `blink_gtk_set_gpu_mode()` before `blink_gtk_init()`). Asking for EGL through `blink_web_view_new_with_gpu_mode()` did not change the path, so applications that did not also set `BLINKGTK_GPU_MODE` were running on the CPU pixel path (reported by an external user). The rendering path is settled during engine initialisation, together with the startup flags handed to the GPU process, so it can no longer be changed by the time a WebView is created. The startup log named EGL in both cases, so there was no way to tell from outside whether the request had taken effect. `blink_web_view_get_gpu_mode()` now reports the path actually in use after initialisation. |
| v1.2.2-build4 | 2026-09-13 | 153.0.8010.36 | 46 | Virtio GPU を使う環境（仮想機械など）で、GPU 描画（`BLINKGTK_GPU_MODE=egl`）の画面が最初から最後まで白いままになる問題を解消しました（外部利用者のご報告）。エンジンは「この画面は空だ」と判定するために描かれた画像を CPU 側から読んでいますが、この種の GPU では描画が機械の外側で行われるため読み取り側には何も見えず、中身はあるのに空と判定していました。動きのないページほど当たりやすく、開いたまま白が続きます。あわせて、スクリーンリーダなどの支援技術を**後から起動しても読み上げが効く**ようになりました。これまではアプリの起動時点で支援技術が動いている必要がありました。 / Fixed a problem where the EGL path (`BLINKGTK_GPU_MODE=egl`) stayed blank from start to finish on systems using a Virtio GPU, such as virtual machines (reported by an external user). The engine reads the drawn image from the CPU side to decide whether a frame is empty, but on this kind of GPU the drawing happens outside the machine, so that read sees nothing and frames that did have content were judged empty. Pages without animation were the most affected, staying blank for as long as they were open. Assistive technology started after the application now reaches the content as well; previously a screen reader had to be running before launch.  |
| v1.2.2-build3 | 2026-09-11 | 153.0.8010.36 | 42 | ページの読み込みが終わる前に窓を閉じると落ちる問題を解消しました。本を開いた直後に閉じる、といった普通の操作で当たっていました（外部利用者のご報告）。利用者側の回避（閉じる前に完了を待つ）はもう要りません。あわせて、画面に出たかどうかを compositor に問い合わせる診断を追加しました。「中身が空だった」と「中身はあったが画面に出なかった」を区別できます。`BLINKGTK_GX_LOG=1` のときだけ記録し、既定では描画も表示判定も変わりません。 / Closing the window before a page finished loading no longer crashes. Opening a book and closing it right away — an ordinary action — triggered it (reported by an external user). The workaround (waiting for the load to finish before closing) is no longer needed. This build also adds a diagnostic that asks the compositor whether a frame reached the screen, distinguishing "the content was empty" from "the content was there but never displayed". It is printed only with `BLINKGTK_GX_LOG=1`; nothing changes by default. |
| v1.2.2-build2 | 2026-09-10 | 153.0.8010.36 | 79 | 同梱していたリリースノートの誤りを訂正しました。build1 の記述で「前版の回避を取り除いた」としていましたが取り除いておらず、この版でも入ったままです。**プログラムの中身は build1 と同じ**で、組版の結果は変わりません（版数を名乗る文字列だけが 1.2.2-build2 になります）。誤りは BlinkGTK-Readium からの照会で判明しました。 / Corrects an error in the release notes shipped with build1, which said our previous workaround had been removed; it had not, and it is still present. **The program is otherwise identical to build1** and typeset output does not change; only the reported version string becomes 1.2.2-build2. The error was found through an enquiry from BlinkGTK-Readium. |
| v1.2.2-build1 | 2026-09-10 | 153.0.8010.36 | 25 | レンダリングエンジンを Chromium 153 に更新しました。縦組みで閉じ括弧が行末に来ると行が途中で切れる現象が直ります（35 文字入る行に 17 文字しか入らず、`text-align: justify` が残りを引き伸ばすため字間が倍に開いていました）。13 通りの設定のうち 8 通りで起きていたものがすべて解消します。横組みでは起きません。当方から上流へ報告し（crbug 542686223）Chromium 側で修正されたものです。同梱のデモが `--version` に応じるようになり、不具合を報告するときに版を一意に示せます。測ったのは 1 行に入る文字数で、段組みの列末に残る余地は測っていません。 / Updated to Chromium 153. In vertical writing, lines no longer break half-way when a closing bracket falls at the line end (a line with room for 35 characters held only 17, and `text-align: justify` then doubled the inter-character advance). Of 13 configurations, 8 exhibited it and all are now fixed; it does not occur in horizontal writing. We reported it upstream (crbug 542686223) and Chromium fixed it. The bundled demo now answers `--version`, so a problem report can identify the build exactly. |
| v1.2.1-build3 | 2026-09-08 | 152.0.7977.64 | 52 | 不具合を報告するときに、どの版で起きたかが実行時に分かるようになりました（`blink_gtk_get_version_full()` が `1.2.1-build3` を返します）。同じ版でも build が違えば挙動が違うことがあり、これまではパッケージ名でしか判別できませんでした。画面が出ないときの配送ログが、実際に呼んだ操作と Wayland の buffer 識別子を記すようになり、測定を打ち切る枚数も伸ばせます（`BLINKGTK_DELIVER_LOG_MAX` / `BLINKGTK_CONTENT_PROBE_MAX`）。描画経路のライブ切替に EGL が加わりました（`BLINKGTK_GPU_MODE=egl` で起動した場合のみ）。 / The build number is now available at run time when reporting a problem (`blink_gtk_get_version_full()` returns `1.2.1-build3`). Behaviour can differ between builds of one version, and until now only the package file name identified a build. The frame-delivery log records the operation actually performed and the Wayland buffer id, and the measurement caps can be raised (`BLINKGTK_DELIVER_LOG_MAX` / `BLINKGTK_CONTENT_PROBE_MAX`). Live render-path switching now covers the EGL path (only when started with `BLINKGTK_GPU_MODE=egl`). |
| v1.2.1-build2 | 2026-08-30 | 152.0.7977.64 | 165 | GPU が使用できない環境でも、フォールバックによりソフトウェア描画で表示されるようになりました（ドライバが無い、仮想環境で GPU が見えない場合など）。描画データが 5 秒間届かなければ切り替わり、理由を標準エラー出力に記します。GPU が使える環境では切り替わりません。あわせて、画面を撮影した画像で赤と青が入れ替わることがある問題を修正しました（8 枚中 4 枚 → 0 枚）。 / Where the GPU path is unavailable (no driver, no GPU inside a virtual machine, and so on), BlinkGTK now falls back to software rendering and keeps drawing; it switches when no frame arrives within five seconds and writes the reason to standard error. It does not switch on machines where the GPU path works. Captured screenshots no longer come out with red and blue exchanged (four of eight images before, none now). |
| v1.2.1-build1 | 2026-08-27 | 152.0.7977.64 | 52 | レンダリングエンジンを Chromium 152 に更新しました。縦組みで、閉じ括弧が行末に来ると行が途中までしか埋まらない現象（34 文字入る行に 17 文字）が直り、段組みでも列が最後の 1 行を次の列へ送らなくなります。`direction: rtl` との併用時の行格子も保たれます。**組版の結果が変わります。** パッケージの宙吊り symlink も修正（RPM は 12 版、DEB はリソース 6 本が Debian に無い場所を指していました）。 / Updated to Chromium 152. In vertical writing, lines no longer break half-way when a closing bracket falls at the line end (a line with room for 34 characters held only 17), and columns now fill to capacity. The line grid is preserved with `direction: rtl`. **Typeset output changes.** Dangling symlinks in the packages are also fixed (12 releases in the RPM; in the DEB, six resources pointed at a path that does not exist on Debian). |
| v1.2.0-build9 | 2026-08-16 | 151.0.7922.108 | 63 | 描画経路を再起動なしで切り替えられるようになりました（BlinkShift 公開 API。切替は数百ミリ秒、失敗時は自動で元へ）。GtkApplication と正しく併用できる `blink_gtk_application_run()` と提示ポリシー API を追加、大きなユーザースクリプトが届かない問題も解消。 / Render paths can now be switched live without restarting (BlinkShift public API — a few hundred ms, automatic rollback on failure). Adds `blink_gtk_application_run()` for correct GtkApplication integration and a presentation-policy API; fixes large user scripts never reaching the renderer. |
| v1.2.0-build8 | 2026-08-12 | 151.0.7922.108 | 10 | セキュリティ点検の結果を反映しました。**サイトごとのプロセス分離が既定で有効**になり（メモリ使用量が増えることがあります）、sandbox の可否判定を実測に変更、状態を問い合わせる API を追加しました。 / Applied the results of a security review: per-site process isolation is now on by default (which can increase memory use), sandbox availability is measured rather than inferred, and a new API reports the sandbox state. |
| v1.2.0-build7 | 2026-08-12 | 151.0.7922.108 | 2 | 開発用パッケージが同梱するヘッダの版数を是正しました（build1〜6 は 1 版前を名乗っていました）。実行時 API は当初から正しく、影響はコンパイル時のマクロのみです。実行部分は build6 と同一です。 / Corrected the version macros in the header shipped with the development package; build1-6 claimed the previous release. The runtime API was always correct, so only compile-time macros were affected. The runtime is identical to build6. |
| v1.2.0-build6 | 2026-08-11 | 151.0.7922.108 | 2 | Chromium 151 系の最新安定版に更新しました。ウィンドウ操作と入力の経路の不具合が直り、登録したユーザースクリプトがページ本文より先に走ります。 / Updated to the latest stable in the Chromium 151 series. Fixes defects in the window and input paths; user scripts now run before the page's own scripts. |
| **v1.2.0-build5** | 2026-08-10 | 151.0.7922.71 | 4 | 欧文の分綴 (`hyphens: auto`) が効くようになりました。52 言語の辞書を同梱。終了処理と診断出力も整理しています。 / Western hyphenation (`hyphens: auto`) now works, with dictionaries for 52 languages. Shutdown and diagnostic output also tidied up. |
| **v1.2.0-build4** | 2026-08-08 | 151.0.7922.71 | 13 | `dnf` でインストールと更新ができるようになりました。動き続けるページ (Canvas・CSS アニメーション・動画) が静止しません。 / Install and update with `dnf`. Continuously animating pages no longer freeze. |
| v1.2.0-build2 | 2026-08-03 | 151.0.7922.71 | 31 | 版が正しく名乗られるように (`navigator.userAgent`)。縦書き版面の実測値を JavaScript から読めます。 / Correct version in `navigator.userAgent`; vertical-writing metrics readable from JavaScript. |
| v1.2.0-build1 | 2026-08-01 | 151.0.7922.71 | 37 | Chromium 151 へ更新。圏点を付けても行送りが太らず、ルビのはみ出しが指定どおりに効きます。 / Chromium 151. Emphasis marks no longer inflate line height; ruby overhang behaves as specified. |
| v1.1.0-build6 | 2026-07-29 | 150.0.7871.46 | 171 | 同梱ドキュメントを全面是正し、記載と実装の一致を機械検査する仕組みを導入しました。 / Bundled documentation overhauled, with mechanical checks that it matches the implementation. |

※ パッケージ (rpm / deb / tar.gz / tar.bz2) の取得数。SHA256SUMS・署名・公開鍵は含みません。
  Counts package downloads only (rpm / deb / tar.gz / tar.bz2); checksum, signature and key files are excluded.

> **累計ダウンロード数について / About the download counts**
> 2026-08-08 時点の GitHub Releases の集計値です。取り下げた版は一覧から
> 外しています。取り下げ版のうち 2026-08-16 に GitHub からリリースごと
> 削除した 5 件 (v1.2.0-build3 / v1.1.0-build2〜5) の実績 129 件は、削除時点の
> 記録に基づき blinkgtk.org / blinkgtk.com の累計表示へ恒久的に加算しています
> (パッケージ実体は当プロジェクトの保管庫に全数保存)。
>
> These are GitHub Releases counts. Withdrawn versions are omitted from this
> table. Five withdrawn releases (v1.2.0-build3, v1.1.0-build2..5) were removed
> from GitHub on 2026-08-16; their 129 recorded downloads are permanently
> included in the totals shown on blinkgtk.org / blinkgtk.com, and the package
> files themselves remain archived by the project.
