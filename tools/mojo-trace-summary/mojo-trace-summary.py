#!/usr/bin/env python3
# Copyright 2026 BlinkGTK Project
# SPDX-License-Identifier: BSD-3-Clause
#
# mojo-trace-summary.py — Chromium の JSON トレースから Mojo の受信を数える。
#
# Chromium は Mojo メッセージの**受信**を TRACE_EVENT に出しており、
# chrome_mojo_event_info に payload_size (ユーザペイロード) と
# data_num_bytes (ヘッダ込み) が載る。
# 出どころ: mojo/public/cpp/bindings/lib/interface_endpoint_client.cc:977-978
#
# **送信側にサイズを持つイベントは無い。** 1 プロセスツリーの中では
# 送信 1 回に受信 1 回が対応するので、ツリー内の全プロセスの受信を合計すれば
# 二重計上なしに総転送量になる。
#
# 取り方:
#   <browser> --trace-startup=toplevel,mojom --trace-startup-duration=<秒> \
#             --trace-startup-format=json --trace-startup-file=/abs/t.json
#
# 使い方:
#   mojo-trace-summary.py <t.json> [--since-us N] [--until-us N] [--top N]
#   --since-us / --until-us はトレース内の ts (マイクロ秒) で区間を切る。
#
# exit 0=集計した / 2=前提条件エラー
import sys, json, collections

def die(msg):
    print(f"前提NG: {msg}", file=sys.stderr); sys.exit(2)

args = sys.argv[1:]
if not args: die("トレースファイルを指定してください")
path = args[0]
since = until = None; top = 15
i = 1
while i < len(args):
    if args[i] == '--since-us': since = int(args[i+1]); i += 2
    elif args[i] == '--until-us': until = int(args[i+1]); i += 2
    elif args[i] == '--top': top = int(args[i+1]); i += 2
    else: die(f"不明な引数: {args[i]}")

raw = open(path, encoding='utf-8', errors='replace').read()
try:
    doc = json.loads(raw)
except json.JSONDecodeError:
    # 途中で切れたトレースでも読めるように、traceEvents 配列だけを救う
    s = raw.find('[')
    if s < 0: die("JSON として読めない")
    end = raw.rfind('},')
    if end < 0: die("JSON として読めない (traceEvents が空)")
    doc = {"traceEvents": json.loads(raw[s:end+1] + ']')}
    print("  ⚠️  トレースが途中で切れていたので、読めた分だけ集計した")

events = doc.get('traceEvents')
if not events: die("traceEvents が無い")

per_iface = collections.Counter(); bytes_iface = collections.Counter()
per_pid = collections.Counter(); bytes_pid = collections.Counter()
n = 0; payload = 0; total = 0; tmin = tmax = None
for e in events:
    info = (e.get('args') or {}).get('chrome_mojo_event_info')
    if not isinstance(info, dict): continue
    if 'payload_size' not in info: continue        # 受信イベントだけが持つ
    ts = e.get('ts')
    if since is not None and (ts is None or ts < since): continue
    if until is not None and (ts is None or ts > until): continue
    tag = info.get('mojo_interface_tag', '(不明)')
    pid = e.get('pid', -1)
    n += 1
    payload += info.get('payload_size', 0)
    total += info.get('data_num_bytes', 0)
    per_iface[tag] += 1; bytes_iface[tag] += info.get('payload_size', 0)
    per_pid[pid] += 1;   bytes_pid[pid] += info.get('payload_size', 0)
    if ts is not None:
        tmin = ts if tmin is None else min(tmin, ts)
        tmax = ts if tmax is None else max(tmax, ts)

if n == 0:
    die("Mojo の受信イベントが 0 件。--trace-startup=toplevel,mojom を付けたか、"
        "区間の指定が外れていないか確かめてください")

names = {}
for e in events:
    if e.get('name') == 'process_name' and e.get('ph') == 'M':
        names[e.get('pid')] = (e.get('args') or {}).get('name', '')

print("=" * 60)
print(" Mojo 受信メッセージの集計")
print("=" * 60)
print(f"  対象      : {path}")
if tmin is not None:
    print(f"  区間      : ts {tmin} 〜 {tmax}  ({(tmax-tmin)/1e6:.2f} 秒)")
print(f"  受信件数  : {n:,}")
print(f"  ペイロード: {payload:,} bytes  ({payload/1024/1024:.2f} MiB)")
print(f"  総バイト  : {total:,} bytes  (ヘッダ込み)")
print()
print("  -- プロセス別 --")
for pid, c in per_pid.most_common():
    print(f"    {pid:>8}  {names.get(pid,''):<16} {c:>7,} 件  {bytes_pid[pid]:>12,} bytes")
print()
print(f"  -- インターフェース別 (上位 {top}) --")
for tag, c in per_iface.most_common(top):
    print(f"    {c:>7,} 件  {bytes_iface[tag]:>12,} bytes  {tag}")
