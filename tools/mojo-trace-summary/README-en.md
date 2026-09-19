# Counting received Mojo messages

Chromium traces **the receipt of every Mojo message**, and the trace carries
`payload_size` (user payload) and `data_num_bytes` (including headers).
This lives in shared upstream Chromium code, so **the same method works for both
BlinkGTK and CEF** (source: `mojo/public/cpp/bindings/lib/interface_endpoint_client.cc:977-978`).

No engine-side instrumentation is required.

## Recording

```sh
<browser> --url <URL> \
  --trace-startup=toplevel,mojom \
  --trace-startup-duration=6 \
  --trace-startup-format=json \
  --trace-startup-file=/absolute/path/t.json
```

Use an **absolute path** for `--trace-startup-file`; a relative path is resolved
against the working directory at startup.

## Aggregating

```sh
python3 mojo-trace-summary.py t.json [--since-us N] [--until-us N] [--top N]
```

No dependencies (standard `json` only). `--since-us` / `--until-us` slice by the
`ts` field (microseconds) inside the trace.

exit 0 = aggregated / 2 = precondition failure (for example, the trace contains
no Mojo receive events at all).

## Example output (BlinkGTK v1.2.2-build6, software path, 6.43 s)

```
  received       : 1,396
  payload        : 604,760 bytes  (0.58 MiB)
  total          : 683,296 bytes  (including headers)

  -- per process --
      908288  Browser              925       500,344 bytes
      908403  Renderer             206        78,448 bytes
      908393  Service: network.mojom.NetworkService      52         5,896 bytes

  -- per interface --
        209       249,736 bytes  viz.mojom.CompositorFrameSink
        146       139,016 bytes  viz.mojom.GpuService
```

## 🔴 What is counted

- **Receives only.** Upstream has no trace event carrying a size on the send
  side. Within one process tree each send has exactly one matching receive, so
  summing receives across the tree gives the total transferred **without double
  counting**
- **Shared-memory / dmabuf pixels are excluded.** Only the handle travels through
  the Mojo message; the buffer contents do not
- **The cost of tracing itself has not been measured.** `toplevel,mojom` is not
  cheap; record comparison runs with and without tracing separately
- `--trace-startup-format=json` is easy to read but **loses more data if the
  process terminates abnormally** than the default `proto` format. It suits
  measurements that end with a clean exit
