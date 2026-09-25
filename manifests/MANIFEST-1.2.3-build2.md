# BlinkGTK 1.2.3-build2 — パッケージ内容物一覧 / Package Manifest

**作成者 / Author**: BlinkGTK Project
**生成日 / Generated**: 2026-09-25(実パッケージから自動生成 / auto-generated from the actual packages)

## 配布物とチェックサム / Assets and checksums

| ファイル / File | サイズ / Size | sha256 |
|---|---|---|
| `blinkgtk-1.2.3-build2-linux-x86_64.tar.gz` | 222M | `d433b29f62ad4aaf318179b2830f057f365660246742b88e702d22ecf34c9b82` |
| `blinkgtk-1.2.3-build2-linux-x86_64.tar.bz2` | 197M | `acadb7471e049248d27b94d8fae9410658afa18dab6471fcd3a718c408a648b0` |
| `blinkgtk-devel-1.2.3-build2-linux-x86_64.tar.gz` | 56K | `5850ca449e36fe92c3fdd80f509472bf4a245d208a0653033226197b9fe1f500` |
| `blinkgtk-bin-1.2.3-build2.fc44.x86_64.rpm` | 156M | `b8f0e2b4087ccbc48b146987e1be0a219b149cbdcca1e4cae257726666335621` |
| `blinkgtk-bin-devel-1.2.3-build2.fc44.x86_64.rpm` | 40K | `be3040d182327fcae780a762213f22326718d18f005eb5d58c1516f2ef452721` |
| `blinkgtk-bin-doc-1.2.3-build2.fc44.noarch.rpm` | 412K | `724e5193ab610b4ad96c0b9d3063d73d3add2c84e3b7db3de84f5baaf7344951` |
| `blinkgtk-bin-gir-1.2.3-build2.fc44.x86_64.rpm` | 32K | `1886d9725da33010f65cc310492a29603d51676b1dac3c95c5053263b7eb96cf` |
| `gir1.2-blinkgtk-0.1_1.2.3-build2-1_amd64.deb` | 24K | `79382728c93e317f8a5d8a33c09caf68a90b73747372c493e5a47c4fca5a3739` |
| `libblinkgtk-0.1-0-dbgsym_1.2.3-build2-1_amd64.deb` | 23M | `7e0744889945a4b377614a2147898daeb3011872bb609b367c17e8e1147085ae` |
| `libblinkgtk-0.1-0_1.2.3-build2-1_amd64.deb` | 125M | `8aabfa895a324288f819a9cadd2dd437f844171d2ea4353bf09bf43f54dc759b` |
| `libblinkgtk-0.1-dev_1.2.3-build2-1_amd64.deb` | 32K | `57119d74bd47c5241dbe9178d767acaf6045c516c763e08c8426921adf22aca1` |
| `libblinkgtk-0.1-doc_1.2.3-build2-1_all.deb` | 4.0K | `f31a8b8eae9afc01996c6d41c21d89f8f3c7533943281fe3bb43ed467cf0af74` |

## バイナリ tarball (tar.gz / tar.bz2 は同一内容 / identical contents)

展開先 / Extracts to: `usr/` (FHS。`/` または任意 prefix に展開 / extract to `/` or any prefix)

| 区分 / Category | 内容 / Contents |
|---|---|
| 共有ライブラリ / Libraries | 521 files (`usr/lib64/blinkgtk-0.1/` private dir、SONAME `libblinkgtk-0.1.so.0`) |
| Chromium ランタイム / runtime | `usr/lib64/blinkgtk-0.1/chromium/` (580 files: .so / .pak / .bin / .dat / locales) |
| GObject Introspection | `usr/lib64/girepository-1.0/BlinkGTK-0.1.typelib` |
| ドキュメント / Documentation | `usr/share/doc/blinkgtk-0.1/` (100 files: README / INSTALL / RELEASE_NOTES ja+en / API リファレンス / チュートリアル / THIRD_PARTY_NOTICES) |
| ld.so 設定 / config | `etc/ld.so.conf.d/blinkgtk-0.1.conf` |
| 合計 / Total | 679 files |

## RPM (Fedora 44 / x86_64)

### `blinkgtk-bin-1.2.3-build2.fc44.x86_64.rpm`

- **パッケージ / Package**: blinkgtk-bin — GTK4 bindings for Chromium Blink rendering engine (binary distribution)
- **ファイル数 / Files**: 596 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/etc/ld.so.conf.d/blinkgtk-0.1.conf`
  - `/usr/bin/blinkgtk-browser`
  - `/usr/lib64/blinkgtk-0.1`
  - `/usr/lib64/blinkgtk-0.1/chromium`
  - `/usr/lib64/blinkgtk-0.1/libblinkgtk-0.1.so.0.0.0`
  - `/usr/lib64/libblinkgtk-0.1.so.0`
  - `/usr/libexec/blinkgtk-0.1`
  - `/usr/libexec/blinkgtk-0.1/blinkgtk_browser`

### `blinkgtk-bin-devel-1.2.3-build2.fc44.x86_64.rpm`

- **パッケージ / Package**: blinkgtk-bin-devel — Development files for blinkgtk-bin
- **ファイル数 / Files**: 10 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/include/blinkgtk-0.1`
  - `/usr/include/blinkgtk-0.1/blink_gtk`
  - `/usr/lib64/libblinkgtk-0.1.so`
  - `/usr/lib64/libblinkgtk.so`
  - `/usr/lib64/pkgconfig/blinkgtk-0.1.pc`
  - `/usr/share/vala/vapi`

### `blinkgtk-bin-doc-1.2.3-build2.fc44.noarch.rpm`

- **パッケージ / Package**: blinkgtk-bin-doc — Documentation for blinkgtk-bin
- **ファイル数 / Files**: 99 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/share/doc/blinkgtk-0.1`

### `blinkgtk-bin-gir-1.2.3-build2.fc44.x86_64.rpm`

- **パッケージ / Package**: blinkgtk-bin-gir — GObject Introspection data for blinkgtk-bin
- **ファイル数 / Files**: 2 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/lib64/girepository-1.0/BlinkGTK-0.1.typelib`
  - `/usr/share/gir-1.0/BlinkGTK-0.1.gir`

## DEB (Debian / Ubuntu、amd64)

### `gir1.2-blinkgtk-0.1_1.2.3-build2-1_amd64.deb`

- **パッケージ / Package**: gir1.2-blinkgtk-0.1 — GObject Introspection data for BlinkGTK
- **ファイル数 / Files**: 4

### `libblinkgtk-0.1-0-dbgsym_1.2.3-build2-1_amd64.deb`

- **パッケージ / Package**: libblinkgtk-0.1-0-dbgsym — debug symbols for libblinkgtk-0.1-0
- **ファイル数 / Files**: 518

### `libblinkgtk-0.1-0_1.2.3-build2-1_amd64.deb`

- **パッケージ / Package**: libblinkgtk-0.1-0 — GTK4 bindings for Chromium Blink rendering engine
- **ファイル数 / Files**: 679

### `libblinkgtk-0.1-dev_1.2.3-build2-1_amd64.deb`

- **パッケージ / Package**: libblinkgtk-0.1-dev — GTK4 bindings for Chromium Blink (development files)
- **ファイル数 / Files**: 8

### `libblinkgtk-0.1-doc_1.2.3-build2-1_all.deb`

- **パッケージ / Package**: libblinkgtk-0.1-doc — Documentation for BlinkGTK
- **ファイル数 / Files**: 2

---

検証 / Verification: 各アセットの sha256 を `SHA256SUMS` と照合してください。RPM は同梱の GPG 公開鍵で署名検証できます。
Verify each asset's sha256 against `SHA256SUMS`. RPM signatures can be verified with the bundled GPG public key.
