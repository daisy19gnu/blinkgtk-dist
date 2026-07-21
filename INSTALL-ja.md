# BlinkGTK インストールガイド

**作成者**: BlinkGTK Project

各パッケージは [Releases](https://github.com/daisy19gnu/blinkgtk-dist/releases) からダウンロードしてください。内容物は [`manifests/`](./manifests/) を参照。

> **注**: パス中の `0.1`(`blinkgtk-0.1` 等)は **API バージョン**です(GTK4 の `gtk-4.0` と同じ規約)。製品バージョン(v1.1.0 等)とは独立で、互換性のない API 変更時にのみ変わります。

## 1. RPM(Fedora 44 / x86_64)

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

RPM は GPG 署名済みです。署名検証を行う場合は公開鍵をインポートしてください。

## 2. DEB(Debian / Ubuntu / amd64)

```sh
sudo apt install ./libblinkgtk-0.1-0_<ver>_amd64.deb      # runtime
sudo apt install ./libblinkgtk-0.1-dev_<ver>_amd64.deb    # 開発用
```

## 3. tarball(その他の Linux / glibc / x86_64)

`.tar.gz` と `.tar.bz2` は同一内容です。FHS 構成(`usr/`, `etc/`)なのでルートに展開します:

```sh
sudo tar -C / -xzf blinkgtk-<ver>-linux-x86_64.tar.gz
sudo ldconfig
```

システムを汚したくない場合は任意の prefix に展開し、実行時に `LD_LIBRARY_PATH` を通してください:

```sh
mkdir -p ~/blinkgtk && tar -C ~/blinkgtk -xzf blinkgtk-<ver>-linux-x86_64.tar.gz
export LD_LIBRARY_PATH=~/blinkgtk/usr/lib64/blinkgtk-0.1:~/blinkgtk/usr/lib64/blinkgtk-0.1/chromium
```

## 4. 検証

```sh
sha256sum -c SHA256SUMS --ignore-missing
```

## 5. 動作確認

```sh
pkg-config --modversion blinkgtk-0.1        # devel 導入時
ldconfig -p | grep blinkgtk                  # ライブラリ登録確認
```

アプリのビルド方法・API は runtime 同梱のドキュメント(`/usr/share/doc/blinkgtk-0.1/`)を参照してください。
