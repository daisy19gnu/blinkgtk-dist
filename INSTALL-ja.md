# BlinkGTK インストールガイド

**作成者**: BlinkGTK Project

各パッケージは [Releases](https://github.com/daisy19gnu/blinkgtk-dist/releases) からダウンロードしてください。内容物は [`manifests/`](./manifests/) を参照。

> **注**: パス中の `0.1`(`blinkgtk-0.1` 等)は **API バージョン**です(GTK4 の `gtk-4.0` と同じ規約)。製品バージョン(v1.1.0 等)とは独立で、互換性のない API 変更時にのみ変わります。

## 0. システム要件

| 項目 | 要件 |
|---|---|
| アーキテクチャ | x86_64 (amd64) |
| glibc | **2.43 以上**(Fedora 44 / Ubuntu 25.10 相当以降) |
| ディスプレイ | **Wayland セッション必須**(X11 のみの環境では動作しません) |
| GTK | GTK4(4.6 以上、4.22 で検証) |
| GPU | 不要(既定は software レンダリング。EGL モードは実験的) |

## 1. RPM(Fedora 44 / x86_64)

依存パッケージは **dnf が自動解決**します。

```sh
# runtime(実行に必須)
sudo dnf install ./blinkgtk-bin-<ver>.fc44.x86_64.rpm

# アプリを開発する場合(ヘッダ + pkg-config)
sudo dnf install ./blinkgtk-bin-devel-<ver>.fc44.x86_64.rpm

# Python (PyGObject) / GJS から使う場合
sudo dnf install ./blinkgtk-bin-gir-<ver>.fc44.x86_64.rpm

# マニュアル(日英)
sudo dnf install ./blinkgtk-bin-doc-<ver>.fc44.noarch.rpm
```

RPM は GPG 署名済みです。公開鍵 `BlinkGTK-GPG-KEY.asc`(本リポジトリ同梱)で検証できます:

```sh
sudo rpm --import BlinkGTK-GPG-KEY.asc
rpm --checksig blinkgtk-bin-<ver>.fc44.x86_64.rpm
```

## 2. DEB(Debian / Ubuntu / amd64)

依存パッケージは **apt が自動解決**します(glibc 2.43 以上のリリースが必要です)。

```sh
sudo apt install ./libblinkgtk-0.1-0_<ver>_amd64.deb      # runtime
sudo apt install ./libblinkgtk-0.1-dev_<ver>_amd64.deb    # 開発用
```

## 3. tarball(その他の Linux / glibc / x86_64)

`.tar.gz` と `.tar.bz2` は同一内容です。**tarball はパッケージマネージャを通らないため、依存ライブラリを自分で揃える必要があります**。

### 3-1. 依存パッケージの導入(先に実行)

BlinkGTK は Chromium ランタイムを同梱しますが、システム側のライブラリ(GTK4・NSS・音声・印刷・メディア等)に依存します。主要ディストリビューションでは次の 1 コマンドでトップレベル依存が揃います(残りは連鎖導入されます):

**Fedora(44 以降)**:

```sh
sudo dnf install gtk4 nss alsa-lib cups-libs dbus-libs at-spi2-core at-spi2-atk \
  libdrm mesa-libgbm mesa-libEGL libxkbcommon wayland-utils libseccomp \
  gstreamer1 gstreamer1-plugins-base openssl-libs sqlite-libs libcurl
```

**Debian / Ubuntu(glibc 2.43 以上のリリース)**:

```sh
sudo apt install libgtk-4-1 libnss3 libasound2t64 libcups2t64 libdbus-1-3 \
  libatk-bridge2.0-0t64 libatspi2.0-0t64 libdrm2 libgbm1 libegl1 \
  libxkbcommon0 libseccomp2 libgstreamer1.0-0 gstreamer1.0-plugins-base \
  libssl3t64 libsqlite3-0
```

(パッケージ名はリリースにより多少異なります。`t64` 接尾辞は Ubuntu 24.04 以降の表記です)

### 3-2. 展開

FHS 構成(`usr/`, `etc/`)なのでルートに展開します:

```sh
sudo tar -C / -xzf blinkgtk-<ver>-linux-x86_64.tar.gz
sudo ldconfig
```

システムを汚したくない場合は任意の prefix に展開し、実行時に `LD_LIBRARY_PATH` を通してください:

```sh
mkdir -p ~/blinkgtk && tar -C ~/blinkgtk -xzf blinkgtk-<ver>-linux-x86_64.tar.gz
export LD_LIBRARY_PATH=~/blinkgtk/usr/lib64/blinkgtk-0.1:~/blinkgtk/usr/lib64/blinkgtk-0.1/chromium
```

### 3-3. 依存の不足を機械的に確認(推奨)

ディストリビューションごとのパッケージ名差異に依らず、**実際に何が足りないか**を次のコマンドで確認できます。出力が空なら依存は揃っています:

```sh
PREFIX=/            # ~/blinkgtk に展開した場合はそのパス
ldd $PREFIX/usr/lib64/blinkgtk-0.1/chromium/libcontent.so \
    $PREFIX/usr/lib64/blinkgtk-0.1/libblinkgtk-0.1.so.0.0.0 2>/dev/null \
  | grep "not found" | sort -u
```

`not found` が出た場合は、そのライブラリ名でディストリビューションのパッケージを検索して導入してください(例: Fedora `dnf provides '*/libasound.so.2'` / Debian `apt-file search libasound.so.2`)。

## 4. 検証

```sh
sha256sum -c SHA256SUMS --ignore-missing
```

## 5. 動作確認

```sh
ldconfig -p | grep blinkgtk                  # ライブラリ登録確認 (ルート展開時)
pkg-config --modversion blinkgtk-0.1         # devel 導入時
```

## 6. トラブルシューティング

| 症状 | 原因と対処 |
|---|---|
| `error while loading shared libraries: ...: cannot open shared object file` | 依存不足。§3-3 の確認コマンドで特定し、該当パッケージを導入 |
| `GLIBC_2.43 not found` | glibc が古いディストリビューションです。§0 の要件を満たすリリースをご利用ください |
| 起動直後に sandbox 関連のエラーで落ちる(コンテナ等) | 環境が Chromium sandbox に対応していません。`BLINKGTK_NO_SANDBOX=1` を設定して起動 |
| ウィンドウが出ない / `Failed to connect to Wayland display` | Wayland セッションで実行してください(X11 セッションは非対応)。`echo $WAYLAND_DISPLAY` で確認 |
| 音が出ない / 動画が再生されない | GStreamer プラグイン不足。`gstreamer1-plugins-good`(Fedora)/ `gstreamer1.0-plugins-good`(Debian)を追加 |

アプリのビルド方法・API は runtime 同梱のドキュメント(`/usr/share/doc/blinkgtk-0.1/` — 名称は API バージョン)を参照してください。
