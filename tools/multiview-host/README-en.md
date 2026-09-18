# Multi-view measurement host

A program that creates N WebViews in a single process so that CPU and memory can be
measured from the outside. Written for blinkgtk-dist #7 (measuring the increment as
WebViews go 1/2/4/8, for comparison with other engines).

## Build

**The distributed SDK is enough.** No source tree required.

```sh
gcc -O2 -o multiview_host multiview_host.c $(pkg-config --cflags --libs blinkgtk-0.1)
```

## Usage

```sh
./multiview_host --views 4 --seconds 30 \
  --resources /usr/lib64/blinkgtk-0.1/chromium \
  --url http://localhost:8123/index.html
```

| Option | |
|---|---|
| `--views N` | Number of WebViews to create (1..64) |
| `--url URL` | URL each view loads |
| `--seconds T` | Run for this many seconds, then exit |
| `--cache-bust` | Append `?blinkgtk_view=<i>` to each view's URL |
| `--resources D` | Directory holding `icudtl.dat` and the `*.pak` files |

## Why `--resources` is needed

An executable built against the SDK does not sit next to the resources. Without this
option it aborts at `icu_util.cc:310`.

**Child processes (zygote, renderer, GPU) re-launch the same executable and enter
`main()` again. Chromium builds their argv, so `--resources` is not in it.** This host
re-exports the value as the environment variable `MULTIVIEW_HOST_RESOURCES` so children
inherit it. The engine does not read that name — it is this host's own arrangement.

## Why `--cache-bust` is needed (measured)

BlinkGTK holds a single BrowserContext per process, and `blink_web_view_new()` always
uses it (`blink_gtk_api.cc:2983`). **Every view shares the same profile and cache.**

Opening the same URL in N views collapses to a single request to the server.

| views | same URL | `--cache-bust` |
|---|---|---|
| 1 | 1 request | 1 |
| 2 | **1** | 2 |
| 4 | **1** | **4** |

(Measured 2026-09-18. weston headless, software mode, Chromium 153.0.8010.36.
Every run reported `loaded=N/N`.)

**Use `--cache-bust` when measuring the cost of additional views.** Without it, views
2..N never reach the network, so the total is not the cost of N views.

Measure both and compare. If there is no difference, caching is not in play for that
origin (`file://`, `no-store`, and so on).

## Notes

The EGL path (`BLINKGTK_GPU_MODE=egl`) has a single dmabuf destination and is not built
to draw several views at once. **Use software mode.**

The `VmRSS` figure printed by the host covers **the browser process only**. Renderers are
separate processes; measure the whole process tree from the outside (cgroup, for example).
