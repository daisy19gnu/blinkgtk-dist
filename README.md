# blinkgtk-dist

BlinkGTK の**公開バイナリ配布**リポジトリ。blinkgtk.org からの配布物（Portable バンドル等）を GitHub Releases として置く場所です。

## ダウンロード数のカウント

GitHub は各 Release アセットの **`download_count`** を自動集計します（アップロード時点から）。
サーバー不要・無料・正確。集計は `tools/download-counts.sh` で取得できます（表示は任意、当面は非公開）。

```sh
tools/download-counts.sh                 # このリポジトリの全 Release DL 数を集計
tools/download-counts.sh owner/other     # 他リポジトリを対象にする場合
```

## 配布物の置き方（バイナリができたら）

```sh
# 例: v0.1.0 のポータブルバンドルを Release として公開
gh release create v0.1.0 blinkgtk-portable-linux-x64.tar.zst \
  --repo daisy19gnu/blinkgtk-dist \
  --title "BlinkGTK Portable v0.1.0" --notes "..."
```

以降、その `...releases/download/v0.1.0/blinkgtk-portable-linux-x64.tar.zst` への
ダウンロードが自動的にカウントされます。blinkgtk.org からはこの URL にリンクします。

## 将来、サイトにカウントを表示したくなったら

このリポジトリは public なので、ページ側から認証なしで
`https://api.github.com/repos/daisy19gnu/blinkgtk-dist/releases` を fetch し、
`assets[].download_count` を合計するだけで表示できます（サーバー不要）。今は表示しません。
