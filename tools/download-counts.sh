#!/usr/bin/env bash
# BlinkGTK download counter.
# Reads GitHub Releases asset download_count (auto-tracked by GitHub) and
# prints a per-asset breakdown plus a grand total. Read-only; nothing public.
#
# Usage:
#   tools/download-counts.sh                    # default: daisy19gnu/blinkgtk-dist
#   tools/download-counts.sh owner/repo         # any repo
#   tools/download-counts.sh --json owner/repo  # machine-readable JSON
#
# Requires: gh (authenticated), python3.
set -euo pipefail

JSON=0
if [ "${1:-}" = "--json" ]; then JSON=1; shift; fi
REPO="${1:-daisy19gnu/blinkgtk-dist}"

data="$(gh api "repos/${REPO}/releases?per_page=100" 2>/dev/null || echo '[]')"

echo "$data" | JSON="$JSON" REPO="$REPO" python3 -c '
import os, sys, json
repo = os.environ["REPO"]
as_json = os.environ["JSON"] == "1"
try:
    data = json.load(sys.stdin)
except Exception:
    data = []
if isinstance(data, dict):  # error object from the API
    print("Error / no access:", data.get("message", "unknown"), file=sys.stderr); sys.exit(1)

rows = []
total = 0
for rel in data:
    tag = rel.get("tag_name", "?")
    for a in rel.get("assets", []):
        c = int(a.get("download_count", 0))
        total += c
        rows.append({"tag": tag, "asset": a.get("name", "?"), "count": c})

if as_json:
    print(json.dumps({"repo": repo, "total": total, "assets": rows}, ensure_ascii=False, indent=2))
    sys.exit(0)

print(f"Download counts for {repo}")
print("=" * 60)
if not rows:
    print("(no release assets yet — counts appear once binaries are uploaded)")
else:
    w = max(len(r["asset"]) for r in rows)
    for r in rows:
        print(f'  {r["tag"]:14}  {r["asset"]:<{w}}  {r["count"]:>9,}')
    print("-" * 60)
    print(f"  {\"TOTAL\":<{14+2+w}}  {total:>9,}")
'
