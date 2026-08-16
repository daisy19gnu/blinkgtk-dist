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

## パッケージの選び方 / Choosing a package

| 環境 / Your system | 選ぶもの / Pick |
|---|---|
| Fedora 44 (x86_64) | `blinkgtk-bin-<ver>.fc44.x86_64.rpm`(開発するなら `-devel`、Python/GJS なら `-gir` も) |
| Debian / Ubuntu (amd64) | `libblinkgtk-0.1-0_<ver>_amd64.deb`(開発するなら `-dev` も) |
| その他の Linux / Other Linux (glibc, x86_64) | `blinkgtk-<ver>-linux-x86_64.tar.gz` または / or `.tar.bz2`(同一内容 / identical contents) |

各バージョンの**内容物一覧**は [`manifests/`](./manifests/) を参照してください(実パッケージから自動生成)。
See [`manifests/`](./manifests/) for **per-version package manifests** (auto-generated from the actual packages).

## インストール / Installation

詳細は [INSTALL-ja.md](./INSTALL-ja.md) / [INSTALL-en.md](./INSTALL-en.md) を参照。概要 / Quick start:

```sh
# Fedora: dnf リポジトリを登録すると dnf upgrade で追随できる
# Fedora: register the dnf repository, then dnf upgrade keeps you current
sudo curl -o /etc/yum.repos.d/blinkgtk.repo \
  https://blinkgtk.org/repo/fedora/blinkgtk.repo
sudo dnf install blinkgtk-bin

# RPM を個別に / individual RPM (Fedora 44)
sudo dnf install ./blinkgtk-bin-<ver>.fc44.x86_64.rpm

# DEB (Debian / Ubuntu)
sudo apt install ./libblinkgtk-0.1-0_<ver>_amd64.deb

# tarball (ルートに展開 / extract to root)
sudo tar -C / -xzf blinkgtk-<ver>-linux-x86_64.tar.gz && sudo ldconfig
```

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

## 不具合報告・質問 / Reporting problems

配布パッケージの不具合や質問は、本リポジトリの **[Issues](https://github.com/daisy19gnu/blinkgtk-dist/issues)** にご報告ください(テンプレートがあります)。報告前に [`INSTALL.md`](./INSTALL.md) のトラブルシューティングもご確認ください。詳しくは [`SUPPORT.md`](./SUPPORT.md)。

Report problems or ask questions via **[Issues](https://github.com/daisy19gnu/blinkgtk-dist/issues)** (templates provided). Please also check the troubleshooting section of [`INSTALL.md`](./INSTALL.md) first. See [`SUPPORT.md`](./SUPPORT.md).

> 本配布物は無保証です。Issue への対応はベストエフォートで、商用サポートではありません(反映を保証しません)。 / Packages are provided as-is; issue handling is best-effort and not commercial support.
>
> 商用サポート・受託開発のご相談は <https://blinkgtk.com/> へ。 / For commercial support or custom development, see <https://blinkgtk.com/>.
>
> BlinkGTK は上流 Chromium に追従します。Web の描画・互換性に関する挙動は上流 Chromium と共通のことが多く、原因が上流にある場合は BlinkGTK 側で修正できないことがあります。 / BlinkGTK tracks upstream Chromium; web rendering/compatibility behavior is often shared with upstream, and some issues originate upstream and cannot be fixed in BlinkGTK.

## バージョン一覧 / Versions

| バージョン / Version | 日付 / Date | Chromium | 累計DL / Downloads | 概要 / Summary |
|---|---|---|---:|---|
| **v1.2.0-build9**（最新 / current） | 2026-08-16 | 151.0.7922.108 | 0 | 描画経路を再起動なしで切り替えられるようになりました（BlinkShift 公開 API。切替は数百ミリ秒、失敗時は自動で元へ）。GtkApplication と正しく併用できる `blink_gtk_application_run()` と提示ポリシー API を追加、大きなユーザースクリプトが届かない問題も解消。 / Render paths can now be switched live without restarting (BlinkShift public API — a few hundred ms, automatic rollback on failure). Adds `blink_gtk_application_run()` for correct GtkApplication integration and a presentation-policy API; fixes large user scripts never reaching the renderer. |
| v1.2.0-build8 | 2026-08-12 | 151.0.7922.108 | 0 | セキュリティ点検の結果を反映しました。**サイトごとのプロセス分離が既定で有効**になり（メモリ使用量が増えることがあります）、sandbox の可否判定を実測に変更、状態を問い合わせる API を追加しました。 / Applied the results of a security review: per-site process isolation is now on by default (which can increase memory use), sandbox availability is measured rather than inferred, and a new API reports the sandbox state. |
| v1.2.0-build7 | 2026-08-12 | 151.0.7922.108 | 0 | 開発用パッケージが同梱するヘッダの版数を是正しました（build1〜6 は 1 版前を名乗っていました）。実行時 API は当初から正しく、影響はコンパイル時のマクロのみです。実行部分は build6 と同一です。 / Corrected the version macros in the header shipped with the development package; build1-6 claimed the previous release. The runtime API was always correct, so only compile-time macros were affected. The runtime is identical to build6. |
| v1.2.0-build6 | 2026-08-11 | 151.0.7922.108 | 0 | Chromium 151 系の最新安定版に更新しました。ウィンドウ操作と入力の経路の不具合が直り、登録したユーザースクリプトがページ本文より先に走ります。 / Updated to the latest stable in the Chromium 151 series. Fixes defects in the window and input paths; user scripts now run before the page's own scripts. |
| **v1.2.0-build5** | 2026-08-10 | 151.0.7922.71 | 0 | 欧文の分綴 (`hyphens: auto`) が効くようになりました。52 言語の辞書を同梱。終了処理と診断出力も整理しています。 / Western hyphenation (`hyphens: auto`) now works, with dictionaries for 52 languages. Shutdown and diagnostic output also tidied up. |
| **v1.2.0-build4** | 2026-08-08 | 151.0.7922.71 | 0 | `dnf` でインストールと更新ができるようになりました。動き続けるページ (Canvas・CSS アニメーション・動画) が静止しません。 / Install and update with `dnf`. Continuously animating pages no longer freeze. |
| v1.2.0-build2 | 2026-08-03 | 151.0.7922.71 | 41 | 版が正しく名乗られるように (`navigator.userAgent`)。縦書き版面の実測値を JavaScript から読めます。 / Correct version in `navigator.userAgent`; vertical-writing metrics readable from JavaScript. |
| v1.2.0-build1 | 2026-08-01 | 151.0.7922.71 | 46 | Chromium 151 へ更新。圏点を付けても行送りが太らず、ルビのはみ出しが指定どおりに効きます。 / Chromium 151. Emphasis marks no longer inflate line height; ruby overhang behaves as specified. |
| v1.1.0-build6 | 2026-07-29 | 150.0.7871.46 | 196 | 同梱ドキュメントを全面是正し、記載と実装の一致を機械検査する仕組みを導入しました。 / Bundled documentation overhauled, with mechanical checks that it matches the implementation. |

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
