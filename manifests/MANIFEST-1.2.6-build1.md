# BlinkGTK 1.2.6-build1 — パッケージ内容物一覧 / Package Manifest

**作成者 / Author**: BlinkGTK Project
**生成日 / Generated**: 2026-11-04(実パッケージから自動生成 / auto-generated from the actual packages)

## 配布物とチェックサム / Assets and checksums

| ファイル / File | サイズ / Size | sha256 |
|---|---|---|
| `blinkgtk-1.2.6-build1-linux-x86_64.tar.gz` | 217M | `e7b2e8577c9238be55d33686a39263c822bbdb29d969191db7874cc3e7d76471` |
| `blinkgtk-1.2.6-build1-linux-x86_64.tar.bz2` | 194M | `44f0310ec540c014f91db078e7708d1cf8bd4700ea78d2decd688919a2e83b19` |
| `blinkgtk-devel-1.2.6-build1-linux-x86_64.tar.gz` | 68K | `995e2f60ac0c5c747758f1430bc48bc9c19c21acdfcb76e140e570cfaf0e9a2c` |
| `blinkgtk-bin-1.2.6-build1.fc45.x86_64.rpm` | 154M | `c50a7aeeccfdb30d7de6f26ddd2e8559e513a20eac590c4234f735964eb8cf53` |
| `blinkgtk-bin-devel-1.2.6-build1.fc45.x86_64.rpm` | 44K | `54cc49c17ee354d5f7090212131fac0a6c1967e078ae8428a20cc7bc3732cf7a` |
| `blinkgtk-bin-doc-1.2.6-build1.fc45.noarch.rpm` | 444K | `aa2a94fa9d4bbfccbf21bf5733678f55bc97f40580cc771d70739412b989d27c` |
| `blinkgtk-bin-gir-1.2.6-build1.fc45.x86_64.rpm` | 44K | `2a894e0e8179feb3eafbdc989f3e52208d2663b5f3cc6b2ba5fb234bb091666c` |
| `blinkgtk-release-1-1.noarch.rpm` | 12K | `b75a5eaa572060007dfe4902feed416696370c4a329e9788a7fb765067406676` |
| `gir1.2-blinkgtk-0.1_1.2.6-build1-1_amd64.deb` | 36K | `b9e3137b4f684e554c0b5fafb1d37b2efd42c0c8f5ecbde81f389dd6e6b711c9` |
| `libblinkgtk-0.1-0-dbgsym_1.2.6-build1-1_amd64.deb` | 21M | `4d391332b88ab3c35beaabc568eecfb36671be85f30e2ec4272d6d6802e92d3b` |
| `libblinkgtk-0.1-0_1.2.6-build1-1_amd64.deb` | 124M | `2114450238a175f8d5d1a26710a0f32b8c8e214de9aa3a93f5b3086432829c22` |
| `libblinkgtk-0.1-dev_1.2.6-build1-1_amd64.deb` | 36K | `841c031202924435f204830a6d5fbd051545d6098895ca5ab90a25383afc7871` |
| `libblinkgtk-0.1-doc_1.2.6-build1-1_all.deb` | 4.0K | `70a43cfc625b048d4704a1bf55fe588d80291cd32d466254524931f2eece84fa` |

## バイナリ tarball (tar.gz / tar.bz2 は同一内容 / identical contents)

展開先 / Extracts to: `usr/` (FHS。`/` または任意 prefix に展開 / extract to `/` or any prefix)

| 区分 / Category | 内容 / Contents |
|---|---|
| 共有ライブラリ / Libraries | 522 files (`usr/lib64/blinkgtk-0.1/` private dir、SONAME `libblinkgtk-0.1.so.0`) |
| Chromium ランタイム / runtime | `usr/lib64/blinkgtk-0.1/chromium/` (581 files: .so / .pak / .bin / .dat / locales) |
| GObject Introspection | `usr/lib64/girepository-1.0/BlinkGTK-0.1.typelib` |
| ドキュメント / Documentation | `usr/share/doc/blinkgtk-0.1/` (104 files: README / INSTALL / RELEASE_NOTES ja+en / API リファレンス / チュートリアル / THIRD_PARTY_NOTICES) |
| ld.so 設定 / config | `etc/ld.so.conf.d/blinkgtk-0.1.conf` |
| 合計 / Total | 687 files |

## RPM (Fedora 45 / x86_64)

### `blinkgtk-bin-1.2.6-build1.fc45.x86_64.rpm`

- **パッケージ / Package**: blinkgtk-bin — GTK4 bindings for Chromium Blink rendering engine (binary distribution)
- **ファイル数 / Files**: 600 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/etc/ld.so.conf.d/blinkgtk-0.1.conf`
  - `/usr/bin/blinkgtk-browser`
  - `/usr/bin/blinkgtk-run`
  - `/usr/lib64/blinkgtk-0.1`
  - `/usr/lib64/blinkgtk-0.1/chromium`
  - `/usr/lib64/blinkgtk-0.1/libblinkgtk-0.1.so.0.0.0`
  - `/usr/lib64/libblinkgtk-0.1.so.0`
  - `/usr/libexec/blinkgtk-0.1`

### `blinkgtk-bin-devel-1.2.6-build1.fc45.x86_64.rpm`

- **パッケージ / Package**: blinkgtk-bin-devel — Development files for blinkgtk-bin
- **ファイル数 / Files**: 10 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/include/blinkgtk-0.1`
  - `/usr/include/blinkgtk-0.1/blink_gtk`
  - `/usr/lib64/libblinkgtk-0.1.so`
  - `/usr/lib64/libblinkgtk.so`
  - `/usr/lib64/pkgconfig/blinkgtk-0.1.pc`
  - `/usr/share/vala/vapi`

### `blinkgtk-bin-doc-1.2.6-build1.fc45.noarch.rpm`

- **パッケージ / Package**: blinkgtk-bin-doc — Documentation for blinkgtk-bin
- **ファイル数 / Files**: 103 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/share/doc/blinkgtk-0.1`

### `blinkgtk-bin-gir-1.2.6-build1.fc45.x86_64.rpm`

- **パッケージ / Package**: blinkgtk-bin-gir — GObject Introspection data for blinkgtk-bin
- **ファイル数 / Files**: 2 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/usr/lib64/girepository-1.0/BlinkGTK-0.1.typelib`
  - `/usr/share/gir-1.0/BlinkGTK-0.1.gir`

### `blinkgtk-release-1-1.noarch.rpm`

- **パッケージ / Package**: blinkgtk-release — BlinkGTK repository configuration
- **ファイル数 / Files**: 2 / **署名 / Signature**: RSA/SHA512
- 主要パス / Key paths:
  - `/etc/pki/rpm-gpg/RPM-GPG-KEY-blinkgtk`
  - `/etc/yum.repos.d/blinkgtk.repo`

## DEB (Debian / Ubuntu、amd64)

### `gir1.2-blinkgtk-0.1_1.2.6-build1-1_amd64.deb`

- **パッケージ / Package**: gir1.2-blinkgtk-0.1 — GObject Introspection data for BlinkGTK
- **ファイル数 / Files**: 4

### `libblinkgtk-0.1-0-dbgsym_1.2.6-build1-1_amd64.deb`

- **パッケージ / Package**: libblinkgtk-0.1-0-dbgsym — debug symbols for libblinkgtk-0.1-0
- **ファイル数 / Files**: 520

### `libblinkgtk-0.1-0_1.2.6-build1-1_amd64.deb`

- **パッケージ / Package**: libblinkgtk-0.1-0 — GTK4 bindings for Chromium Blink rendering engine
- **ファイル数 / Files**: 687

### `libblinkgtk-0.1-dev_1.2.6-build1-1_amd64.deb`

- **パッケージ / Package**: libblinkgtk-0.1-dev — GTK4 bindings for Chromium Blink (development files)
- **ファイル数 / Files**: 8

### `libblinkgtk-0.1-doc_1.2.6-build1-1_all.deb`

- **パッケージ / Package**: libblinkgtk-0.1-doc — Documentation for BlinkGTK
- **ファイル数 / Files**: 2

---

検証 / Verification: 各アセットの sha256 を `SHA256SUMS` と照合してください。RPM は同梱の GPG 公開鍵で署名検証できます。
Verify each asset's sha256 against `SHA256SUMS`. RPM signatures can be verified with the bundled GPG public key.
