# Mojo 受信メッセージの集計

Chromium は **Mojo メッセージの受信**をトレースに出しており、
そこに `payload_size` (ユーザペイロード) と `data_num_bytes` (ヘッダ込み) が載ります。
これは上流 Chromium の共通コードなので、**BlinkGTK と CEF の両方で同じ方法が使えます**
(出どころ: `mojo/public/cpp/bindings/lib/interface_endpoint_client.cc:977-978`)。

エンジン側に計装を足す必要はありません。

## 取り方

```sh
<ブラウザ> --url <URL> \
  --trace-startup=toplevel,mojom \
  --trace-startup-duration=6 \
  --trace-startup-format=json \
  --trace-startup-file=/絶対パス/t.json
```

`--trace-startup-file` は**絶対パス**にしてください (相対だと起動時の
作業ディレクトリに出ます)。

## 集計

```sh
python3 mojo-trace-summary.py t.json [--since-us N] [--until-us N] [--top N]
```

依存ライブラリはありません (標準の `json` のみ)。
`--since-us` / `--until-us` はトレース内の `ts` (マイクロ秒) で区間を切ります。

exit 0 = 集計した / 2 = 前提条件エラー (トレースに Mojo の受信が 1 件も無い、など)。

## 出力の例 (BlinkGTK v1.2.2-build6 / software / 6.43 秒)

```
  受信件数  : 1,396
  ペイロード: 604,760 bytes  (0.58 MiB)
  総バイト  : 683,296 bytes  (ヘッダ込み)

  -- プロセス別 --
      908288  Browser              925 件       500,344 bytes
      908403  Renderer             206 件        78,448 bytes
      908393  Service: network.mojom.NetworkService      52 件         5,896 bytes

  -- インターフェース別 --
        209 件       249,736 bytes  viz.mojom.CompositorFrameSink
        146 件       139,016 bytes  viz.mojom.GpuService
```

## 🔴 数え方について

- **受信だけを数えます。** 送信側にサイズを持つトレースイベントは上流にありません。
  1 プロセスツリーの中では送信 1 回に受信 1 回が対応するので、ツリー内の全プロセスの
  受信を合計すれば、**二重計上なしに総転送量**になります
- **共有メモリ / dmabuf のピクセルは入りません。** Mojo メッセージにはハンドルだけが
  載り、中身は Mojo を通らないためです
- **トレース自体の負荷は測っていません。** `toplevel,mojom` は軽くありません。
  比較の数字を取るときは、トレース有りと無しを分けて走らせることをお勧めします
- `--trace-startup-format=json` は読みやすい代わりに、**プロセスが異常終了すると
  データを失いやすい**形式です (既定の `proto` のほうが途中まで残ります)。
  正常終了する計測に向いています
