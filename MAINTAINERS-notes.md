# blinkgtk-dist 運用メモ(非公開・メンテナ向け)

このファイルは公開 README には載せない運用情報です。

## ダウンロード数の集計

GitHub は各 Release アセットの `download_count` を自動集計します(サーバー不要)。

```sh
tools/download-counts.sh                 # 本リポジトリの全 Release DL 数を集計
tools/download-counts.sh owner/other     # 他リポジトリを対象にする場合
```

public API 直接:

```sh
curl -s https://api.github.com/repos/daisy19gnu/blinkgtk-dist/releases \
  | jq '[.[].assets[].download_count] | add'
```

集計結果を公開サイトに表示するかは任意(当面は非表示・内部把握のみ)。
