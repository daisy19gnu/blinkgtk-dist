# blinkgtk-dist — BlinkGTK Binary Distribution

BlinkGTK の公開バイナリ配布リポジトリです。配布物は本リポジトリの **[Releases](https://github.com/daisy19gnu/blinkgtk-dist/releases)** に置かれます。ソースコードは配布しません。

This is the public binary distribution repository for BlinkGTK. All artifacts are published under **[Releases](https://github.com/daisy19gnu/blinkgtk-dist/releases)**. Source code is not distributed.

- 本体リポジトリ / Main repository: <https://github.com/daisy19gnu/BlinkGTK>
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

RPM は GPG 署名済みです。RPMs are GPG-signed.

## バージョン一覧 / Versions

| バージョン / Version | 日付 / Date | Chromium | 概要 / Summary |
|---|---|---|---|
| v1.1.0-build2(準備中 / upcoming) | 2026-07-21 | 150.0.7871.46 | アイドル時 CPU 解消 (#115)・大規模リフロー後の永続白紙の根本修正 (#120) / Idle-CPU fix; root fix for persistent blank pages after heavy reflow |

## ダウンロード数のカウント / Download counts

GitHub は各 Release アセットの **`download_count`** を自動集計します(アップロード時点から)。サーバー不要・無料・正確。集計は `tools/download-counts.sh` で取得できます(表示は任意、当面は非公開)。

GitHub automatically tracks `download_count` per release asset. Aggregate with `tools/download-counts.sh` (display optional; private for now).

```sh
tools/download-counts.sh                 # このリポジトリの全 Release DL 数を集計
tools/download-counts.sh owner/other     # 他リポジトリを対象にする場合
```

将来サイトに表示する場合は、public API `https://api.github.com/repos/daisy19gnu/blinkgtk-dist/releases` の `assets[].download_count` を合計するだけで表示できます(サーバー不要)。
