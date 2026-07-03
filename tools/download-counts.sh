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

printf '%s' "$data" | python3 - "$REPO" "$JSON" <<'PY'
import sys, json

repo = sys.argv[1]
as_json = sys.argv[2] == "1"

try:
    data = json.load(sys.stdin)
except Exception:
    data = []

if isinstance(data, dict):  # API error object
    sys.stderr.write("Error / no access: %s\n" % data.get("message", "unknown"))
    sys.exit(1)

rows = []
total = 0
for rel in data:
    tag = rel.get("tag_name", "?")
    for a in rel.get("assets", []):
        c = int(a.get("download_count", 0))
        total += c
        rows.append((tag, a.get("name", "?"), c))

if as_json:
    out = {"repo": repo, "total": total,
           "assets": [{"tag": t, "asset": n, "count": c} for (t, n, c) in rows]}
    print(json.dumps(out, ensure_ascii=False, indent=2))
    sys.exit(0)

print("Download counts for %s" % repo)
print("=" * 60)
if not rows:
    print("(no release assets yet - counts appear once binaries are uploaded)")
else:
    w = max(len(n) for (_, n, _) in rows)
    for (t, n, c) in rows:
        print("  %-14s  %-*s  %9d" % (t, w, n, c))
    print("-" * 60)
    print("  %-*s  %9d" % (14 + 2 + w, "TOTAL", total))
PY
