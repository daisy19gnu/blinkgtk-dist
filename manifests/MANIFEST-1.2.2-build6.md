# BlinkGTK 1.2.2-build6 — パッケージ内容物一覧 / Package Manifest

**作成者 / Author**: BlinkGTK Project
**生成日 / Generated**: 2026-09-19(実パッケージから自動生成 / auto-generated from the actual packages)

## 配布物とチェックサム / Assets and checksums

| ファイル / File | サイズ / Size | sha256 |
|---|---|---|
| `blinkgtk-1.2.2-build6-linux-x86_64.tar.gz` | 220M | `12540ed37eac0a2f7204d7758ff224795494e054e04dc656f619b144cfd4e561` |
| `blinkgtk-1.2.2-build6-linux-x86_64.tar.bz2` | 195M | `cba442bda6f902d3f8cf5ab878b5b108c76b059130faa4a16d9fb7f7586a1275` |
| `blinkgtk-devel-1.2.2-build6-linux-x86_64.tar.gz` | 48K | `98b7dba91eb2ef4e8f63b680c669861e169ad6461d2ed516ef2de875052f554e` |
| `blinkgtk-bin-1.2.2-build6.fc44.x86_64.rpm` | 155M | `8a8b448feacd926437471364953958293682ff80eff444c3fbc202bf5e489cee` |
| `blinkgtk-bin-devel-1.2.2-build6.fc44.x86_64.rpm` | 36K | `b8090ed212134feb07eb4834dec2e2b8ca3b9745b466d449076c46e04623cc10` |
| `blinkgtk-bin-doc-1.2.2-build6.fc44.noarch.rpm` | 404K | `ba2948341b52d6a153b64f8d9c472293271ba92c4564126b76a2e889ef90ce43` |
| `blinkgtk-bin-gir-1.2.2-build6.fc44.x86_64.rpm` | 32K | `c0dfaabeb2399ad2e04652098a790ff694075f818b1cad8991087d0a63fd69b9` |
| `libblinkgtk-0.1-0_1.2.2-build6_amd64.deb` | 149M | `0639dff351c17c85e15b7d10d7590ad2f376c8714b6438b1a755c6690a4cebfe` |
| `libblinkgtk-0.1-dev_1.2.2-build6_amd64.deb` | 32K | `b9552fd408e462044f4315462e0abb6406ecf7f581f5c0aad6ab663b1977f323` |

## バイナリ tarball (tar.gz / tar.bz2 は同一内容 / identical contents)

展開先 / Extracts to: `usr/` (FHS。`/` または任意 prefix に展開 / extract to `/` or any prefix)

| 区分 / Category | 内容 / Contents |
|---|---|
| 共有ライブラリ / Libraries | 526 files (`usr/lib64/blinkgtk-0.1/` private dir、SONAME `libblinkgtk-0.1.so.0`) |
| Chromium ランタイム / runtime | `usr/lib64/blinkgtk-0.1/chromium/` (585 files: .so / .pak / .bin / .dat / locales) |
| GObject Introspection | `usr/lib64/girepository-1.0/BlinkGTK-0.1.typelib` |
| ドキュメント / Documentation | `usr/share/doc/blinkgtk-0.1/` (100 files: README / INSTALL / RELEASE_NOTES ja+en / API リファレンス / チュートリアル / THIRD_PARTY_NOTICES) |
| ld.so 設定 / config | `etc/ld.so.conf.d/blinkgtk-0.1.conf` |
| 合計 / Total | 684 files |

## RPM (Fedora 44 / x86_64)

### `blinkgtk-bin-1.2.2-build6.fc44.x86_64.rpm`

- **パッケージ / Package**: blinkgtk-bin — GTK4 bindings for Chromium Blink rendering engine (binary distribution)
- **ファイル数 / Files**: 601 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/etc/ld.so.conf.d/blinkgtk-0.1.conf`
  - `/usr/bin/blinkgtk-simple-browser`
  - `/usr/lib64/blinkgtk-0.1`
  - `/usr/lib64/blinkgtk-0.1/chromium`
  - `/usr/lib64/blinkgtk-0.1/libblinkgtk-0.1.so.0.0.0`
  - `/usr/lib64/libblinkgtk-0.1.so.0`
  - `/usr/libexec/blinkgtk-0.1`
  - `/usr/libexec/blinkgtk-0.1/blinkgtk_browser`

### `blinkgtk-bin-devel-1.2.2-build6.fc44.x86_64.rpm`

- **パッケージ / Package**: blinkgtk-bin-devel — Development files for blinkgtk-bin
- **ファイル数 / Files**: 10 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/include/blinkgtk-0.1`
  - `/usr/include/blinkgtk-0.1/blink_gtk`
  - `/usr/lib64/libblinkgtk-0.1.so`
  - `/usr/lib64/libblinkgtk.so`
  - `/usr/lib64/pkgconfig/blinkgtk-0.1.pc`
  - `/usr/share/vala/vapi`

### `blinkgtk-bin-doc-1.2.2-build6.fc44.noarch.rpm`

- **パッケージ / Package**: blinkgtk-bin-doc — Documentation for blinkgtk-bin
- **ファイル数 / Files**: 99 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/share/doc/blinkgtk-0.1`

### `blinkgtk-bin-gir-1.2.2-build6.fc44.x86_64.rpm`

- **パッケージ / Package**: blinkgtk-bin-gir — GObject Introspection data for blinkgtk-bin
- **ファイル数 / Files**: 2 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/lib64/girepository-1.0/BlinkGTK-0.1.typelib`
  - `/usr/share/gir-1.0/BlinkGTK-0.1.gir`

## DEB (Debian / Ubuntu、amd64)

### `libblinkgtk-0.1-0_1.2.2-build6_amd64.deb`

- **パッケージ / Package**: libblinkgtk-0.1-0 — GTK4 bindings for Chromium Blink rendering engine (runtime)
- **ファイル数 / Files**: 684

### `libblinkgtk-0.1-dev_1.2.2-build6_amd64.deb`

- **パッケージ / Package**: libblinkgtk-0.1-dev — GTK4 bindings for Chromium Blink rendering engine (development files)
- **ファイル数 / Files**: 7

---

検証 / Verification: 各アセットの sha256 を `SHA256SUMS` と照合してください。RPM は同梱の GPG 公開鍵で署名検証できます。
Verify each asset's sha256 against `SHA256SUMS`. RPM signatures can be verified with the bundled GPG public key.
