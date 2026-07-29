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
# RPM (Fedora 44)
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

| バージョン / Version | 日付 / Date | Chromium | 概要 / Summary |
|---|---|---|---|
| **v1.1.0-build4**(最新 / current) | 2026-07-29 | 150.0.7871.46 | 同梱ドキュメントと同梱バイナリの整合性を回復。ユーザーエージェント設定・Cookie 設定・権限要求 API を追加。アプリのビルド手引きとアップデート/アンインストール手順を収録。 / Bundled documentation now matches the bundled binary. Adds user-agent, cookie, and permission-request APIs, plus a build guide and update/uninstall instructions. |
| v1.1.0-build3(取り下げ / withdrawn) | 2026-07-23 | 150.0.7871.46 | 同梱ドキュメントが同梱バイナリに存在しない API を記載していたため取り下げました。v1.1.0-build4 をご利用ください。 / Withdrawn: the bundled documentation referenced APIs that do not exist in the bundled binary. Please use v1.1.0-build4. |
| v1.1.0-build2(取り下げ / withdrawn) | 2026-07-21 | 150.0.7871.46 | 同上の理由により取り下げました。v1.1.0-build4 をご利用ください。 / Withdrawn for the same reason. Please use v1.1.0-build4. |

> **取り下げについて / About the withdrawals**
> v1.1.0-build2 と v1.1.0-build3 は、同梱ドキュメントが同梱バイナリに存在しない API を
> 20 種記載しており、記載どおりに書くとビルドできない状態でした。ダウンロードを停止して
> います。すでに導入済みの場合は v1.1.0-build4 への更新をお願いします
> (`INSTALL.md` のアップデート手順を参照)。バイナリ自体の動作に問題があったわけでは
> ありません。
> 
> v1.1.0-build2 and v1.1.0-build3 have been withdrawn: their bundled documentation named
> 20 APIs that do not exist in the bundled binary, so following it would not build.
> Downloads are disabled. If you already installed one of them, please update to
> v1.1.0-build4 (see the update section of `INSTALL.md`). The binaries themselves were
> not defective.
