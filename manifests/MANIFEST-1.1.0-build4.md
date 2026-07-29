# BlinkGTK 1.1.0-build4 — パッケージ内容物一覧 / Package Manifest

**作成者 / Author**: BlinkGTK Project
**生成日 / Generated**: 2026-07-29(実パッケージから自動生成 / auto-generated from the actual packages)

## 配布物とチェックサム / Assets and checksums

| ファイル / File | サイズ / Size | sha256 |
|---|---|---|
| `blinkgtk-1.1.0-build4-linux-x86_64.tar.gz` | 198M | `ee14bcb45558b5c04ba2566e31d36d359b9e5213597114f9aed3fcd0b2bdee39` |
| `blinkgtk-1.1.0-build4-linux-x86_64.tar.bz2` | 177M | `1e7e53e5f34f4269a63e18d96c2d5d589c96773db7988aee4c14128e8d19a2c4` |
| `blinkgtk-devel-1.1.0-build4-linux-x86_64.tar.gz` | 36K | `c83d6966761656b6ff08c7e4fb794dd11117e4f661e7de2b841368282267e91b` |
| `blinkgtk-bin-1.1.0-build4.fc44.x86_64.rpm` | 143M | `2a09aecaa55e6918285c19b3bd9a50c714905cec6822704cf2c85bfd846b2697` |
| `blinkgtk-bin-devel-1.1.0-build4.fc44.x86_64.rpm` | 28K | `f1e01c2a08faf58aeac5359b9d03998d92c1b5d8f158aa044f77a839f13e80c5` |
| `blinkgtk-bin-doc-1.1.0-build4.fc44.noarch.rpm` | 636K | `f1e51dace65ea14995c2569c1b4c0038879ad51150fe4262fba685051c9a6aff` |
| `blinkgtk-bin-gir-1.1.0-build4.fc44.x86_64.rpm` | 28K | `24464aa66442c33012af0debdcfc9932e037a3a3d901dd47726e1181007977c1` |
| `libblinkgtk-0.1-0_1.1.0-build4_amd64.deb` | 136M | `0e4a52bfec7fa82378244019ca72452ecc8229e201d774ee444606a2620832da` |
| `libblinkgtk-0.1-dev_1.1.0-build4_amd64.deb` | 24K | `becc3bcb7faa525e0bf95090fa37d8e95a3b9348e5f8d2edc4313eacc5334922` |

## バイナリ tarball (tar.gz / tar.bz2 は同一内容 / identical contents)

展開先 / Extracts to: `usr/` (FHS。`/` または任意 prefix に展開 / extract to `/` or any prefix)

| 区分 / Category | 内容 / Contents |
|---|---|
| 共有ライブラリ / Libraries | 529 files (`usr/lib64/blinkgtk-0.1/` private dir、SONAME `libblinkgtk-0.1.so.0`) |
| Chromium ランタイム / runtime | `usr/lib64/blinkgtk-0.1/chromium/` (535 files: .so / .pak / .bin / .dat / locales) |
| GObject Introspection | `usr/lib64/girepository-1.0/BlinkGTK-0.1.typelib` |
| ドキュメント / Documentation | `usr/share/doc/blinkgtk-0.1/` (64 files: README / INSTALL / RELEASE_NOTES ja+en / API リファレンス / チュートリアル / THIRD_PARTY_NOTICES) |
| ld.so 設定 / config | `etc/ld.so.conf.d/blinkgtk-0.1.conf` |
| 合計 / Total | 597 files |

## RPM (Fedora 44 / x86_64)

### `blinkgtk-bin-1.1.0-build4.fc44.x86_64.rpm`

- **パッケージ / Package**: blinkgtk-bin — GTK4 bindings for Chromium Blink rendering engine (binary distribution)
- **ファイル数 / Files**: 551 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/etc/ld.so.conf.d/blinkgtk-0.1.conf`
  - `/usr/bin/blinkgtk-simple-browser`
  - `/usr/lib64/blinkgtk-0.1`
  - `/usr/lib64/blinkgtk-0.1/chromium`
  - `/usr/lib64/blinkgtk-0.1/libblinkgtk-0.1.so.0.0.0`
  - `/usr/lib64/libblinkgtk-0.1.so.0`
  - `/usr/libexec/blinkgtk-0.1`
  - `/usr/libexec/blinkgtk-0.1/content_shell.pak`

### `blinkgtk-bin-devel-1.1.0-build4.fc44.x86_64.rpm`

- **パッケージ / Package**: blinkgtk-bin-devel — Development files for blinkgtk-bin
- **ファイル数 / Files**: 11 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/include/blinkgtk-0.1`
  - `/usr/include/blinkgtk-0.1/blink_gtk`
  - `/usr/lib64/libblinkgtk-0.1.so`
  - `/usr/lib64/libblinkgtk.so`
  - `/usr/lib64/pkgconfig/blinkgtk-0.1.pc`
  - `/usr/share/vala/vapi`

### `blinkgtk-bin-doc-1.1.0-build4.fc44.noarch.rpm`

- **パッケージ / Package**: blinkgtk-bin-doc — Documentation for blinkgtk-bin
- **ファイル数 / Files**: 63 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/share/doc/blinkgtk-0.1`

### `blinkgtk-bin-gir-1.1.0-build4.fc44.x86_64.rpm`

- **パッケージ / Package**: blinkgtk-bin-gir — GObject Introspection data for blinkgtk-bin
- **ファイル数 / Files**: 2 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/lib64/girepository-1.0/BlinkGTK-0.1.typelib`
  - `/usr/share/gir-1.0/BlinkGTK-0.1.gir`

## DEB (Debian / Ubuntu、amd64)

### `libblinkgtk-0.1-0_1.1.0-build4_amd64.deb`

- **パッケージ / Package**: libblinkgtk-0.1-0 — GTK4 bindings for Chromium Blink rendering engine (runtime)
- **ファイル数 / Files**: 597

### `libblinkgtk-0.1-dev_1.1.0-build4_amd64.deb`

- **パッケージ / Package**: libblinkgtk-0.1-dev — GTK4 bindings for Chromium Blink rendering engine (development files)
- **ファイル数 / Files**: 8

---

検証 / Verification: 各アセットの sha256 を `SHA256SUMS` と照合してください。RPM は同梱の GPG 公開鍵で署名検証できます。
Verify each asset's sha256 against `SHA256SUMS`. RPM signatures can be verified with the bundled GPG public key.
