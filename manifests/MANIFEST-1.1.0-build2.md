# BlinkGTK 1.1.0-build2 — パッケージ内容物一覧 / Package Manifest

**作成者 / Author**: BlinkGTK Project
**生成日 / Generated**: 2026-07-22(実パッケージから自動生成 / auto-generated from the actual packages)

## 配布物とチェックサム / Assets and checksums

| ファイル / File | サイズ / Size | sha256 |
|---|---|---|
| `blinkgtk-1.1.0-build2-linux-x86_64.tar.gz` | 198M | `0df5e6a9cfc1f9881f176bfbca2b068a30e9fcce402d960fd0fef0f86af5bc1a` |
| `blinkgtk-1.1.0-build2-linux-x86_64.tar.bz2` | 177M | `483a19e48921a141a9b9c9455d5406d071d6f2c0f65858a9494b0647276ea04f` |
| `blinkgtk-bin-1.1.0-build2.fc44.x86_64.rpm` | 143M | `43a7f88afc1a53a61833c3da57b77f1f82bb07cd0ce746c00367057777fbcd27` |
| `blinkgtk-bin-devel-1.1.0-build2.fc44.x86_64.rpm` | 28K | `09922667f5e486aedd656b28f50e40744df57004663e4bee5a159769d259bea1` |
| `blinkgtk-bin-doc-1.1.0-build2.fc44.noarch.rpm` | 332K | `a2b2c095396b7962ee1ece4bd5b46e8cb7adb6dace321c2e386133ba1f0feeeb` |
| `blinkgtk-bin-gir-1.1.0-build2.fc44.x86_64.rpm` | 28K | `a29ee3eb74ef15548bcdaed610de384354167296bb79025debe52f92beb319a9` |
| `libblinkgtk-0.1-0_1.1.0-build2_amd64.deb` | 135M | `8392524f92ba0e5fedd26568174b8c1db0b440301116e0a891cb599d12315da6` |
| `libblinkgtk-0.1-dev_1.1.0-build2_amd64.deb` | 24K | `0d44c01f44dc94c7046ae00bce90c6c5b4a67b126085b300f70c57fed0996f34` |

## バイナリ tarball (tar.gz / tar.bz2 は同一内容 / identical contents)

展開先 / Extracts to: `usr/` (FHS。`/` または任意 prefix に展開 / extract to `/` or any prefix)

| 区分 / Category | 内容 / Contents |
|---|---|
| 共有ライブラリ / Libraries | 529 files (`usr/lib64/blinkgtk-0.1/` private dir、SONAME `libblinkgtk-0.1.so.0`) |
| Chromium ランタイム / runtime | `usr/lib64/blinkgtk-0.1/chromium/` (535 files: .so / .pak / .bin / .dat / locales) |
| GObject Introspection | `usr/lib64/girepository-1.0/BlinkGTK-0.1.typelib` |
| ドキュメント / Documentation | `usr/share/doc/blinkgtk-0.1/` (43 files: README / INSTALL / RELEASE_NOTES ja+en / API リファレンス / チュートリアル / THIRD_PARTY_NOTICES) |
| ld.so 設定 / config | `etc/ld.so.conf.d/blinkgtk-0.1.conf` |
| 合計 / Total | 582 files |

## RPM (Fedora 44 / x86_64)

### `blinkgtk-bin-1.1.0-build2.fc44.x86_64.rpm`

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

### `blinkgtk-bin-devel-1.1.0-build2.fc44.x86_64.rpm`

- **パッケージ / Package**: blinkgtk-bin-devel — Development files for blinkgtk-bin
- **ファイル数 / Files**: 11 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/include/blinkgtk-0.1`
  - `/usr/include/blinkgtk-0.1/blink_gtk`
  - `/usr/lib64/libblinkgtk-0.1.so`
  - `/usr/lib64/libblinkgtk.so`
  - `/usr/lib64/pkgconfig/blinkgtk-0.1.pc`
  - `/usr/share/vala/vapi`

### `blinkgtk-bin-doc-1.1.0-build2.fc44.noarch.rpm`

- **パッケージ / Package**: blinkgtk-bin-doc — Documentation for blinkgtk-bin
- **ファイル数 / Files**: 42 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/share/doc/blinkgtk-0.1`

### `blinkgtk-bin-gir-1.1.0-build2.fc44.x86_64.rpm`

- **パッケージ / Package**: blinkgtk-bin-gir — GObject Introspection data for blinkgtk-bin
- **ファイル数 / Files**: 2 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/lib64/girepository-1.0/BlinkGTK-0.1.typelib`
  - `/usr/share/gir-1.0/BlinkGTK-0.1.gir`

## DEB (Debian / Ubuntu、amd64)

### `libblinkgtk-0.1-0_1.1.0-build2_amd64.deb`

- **パッケージ / Package**: libblinkgtk-0.1-0 — GTK4 bindings for Chromium Blink rendering engine (runtime)
- **ファイル数 / Files**: 582

### `libblinkgtk-0.1-dev_1.1.0-build2_amd64.deb`

- **パッケージ / Package**: libblinkgtk-0.1-dev — GTK4 bindings for Chromium Blink rendering engine (development files)
- **ファイル数 / Files**: 8

---

検証 / Verification: 各アセットの sha256 を `SHA256SUMS` と照合してください。RPM は同梱の GPG 公開鍵で署名検証できます。
Verify each asset's sha256 against `SHA256SUMS`. RPM signatures can be verified with the bundled GPG public key.
