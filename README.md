# blinkgtk-dist — BlinkGTK Binary Distribution

BlinkGTK の公開バイナリ配布リポジトリです。配布物は本リポジトリの **[Releases](https://github.com/daisy19gnu/blinkgtk-dist/releases)** に置かれます。ソースコードは配布しません。

This is the public binary distribution repository for BlinkGTK. All artifacts are published under **[Releases](https://github.com/daisy19gnu/blinkgtk-dist/releases)**. Source code is not distributed.

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
| **v1.1.0-build2**(初回公開 / first public release) | 2026-07-21 | 150.0.7871.46 | v1.1 系の初回一般公開。アイドル時 CPU 解消 (#115)・大規模リフロー後の永続白紙の根本修正 (#120) / First public v1.1 release. Idle-CPU fix; root fix for persistent blank pages after heavy reflow |
