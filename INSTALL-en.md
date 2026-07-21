# BlinkGTK Installation Guide

**Author**: BlinkGTK Project

Download packages from [Releases](https://github.com/daisy19gnu/blinkgtk-dist/releases). See [`manifests/`](./manifests/) for package contents.

> **Note**: the `0.1` in paths (`blinkgtk-0.1` etc.) is the **API version** (same convention as GTK4's `gtk-4.0`). It is independent of the product version (v1.1.0 etc.) and only changes on incompatible API revisions.

## 0. System requirements

| Item | Requirement |
|---|---|
| Architecture | x86_64 (amd64) |
| glibc | **2.43 or later** (Fedora 44 / Ubuntu 25.10 or equivalent) |
| Display | **Wayland session required** (X11-only environments are not supported) |
| GTK | GTK4 (4.6+, verified with 4.22) |
| GPU | Not required (software rendering by default; EGL mode is experimental) |

## 1. RPM (Fedora 44 / x86_64)

Dependencies are **resolved automatically by dnf**.

```sh
# runtime (required)
sudo dnf install ./blinkgtk-bin-<ver>.fc44.x86_64.rpm

# for application development (headers + pkg-config)
sudo dnf install ./blinkgtk-bin-devel-<ver>.fc44.x86_64.rpm

# for Python (PyGObject) / GJS
sudo dnf install ./blinkgtk-bin-gir-<ver>.fc44.x86_64.rpm

# manuals (Japanese/English)
sudo dnf install ./blinkgtk-bin-doc-<ver>.fc44.noarch.rpm
```

RPMs are GPG-signed. Verify with the bundled public key `BlinkGTK-GPG-KEY.asc`:

```sh
sudo rpm --import BlinkGTK-GPG-KEY.asc
rpm --checksig blinkgtk-bin-<ver>.fc44.x86_64.rpm
```

## 2. DEB (Debian / Ubuntu / amd64)

Dependencies are **resolved automatically by apt** (a release with glibc 2.43+ is required).

```sh
sudo apt install ./libblinkgtk-0.1-0_<ver>_amd64.deb      # runtime
sudo apt install ./libblinkgtk-0.1-dev_<ver>_amd64.deb    # development
```

## 3. tarball (other Linux / glibc / x86_64)

`.tar.gz` and `.tar.bz2` have identical contents. **The tarball bypasses the package manager, so you must install the dependencies yourself.**

### 3-1. Install dependencies first

BlinkGTK bundles the Chromium runtime but depends on system libraries (GTK4, NSS, audio, printing, media, etc.). On major distributions, one command installs the top-level dependencies (the rest are pulled in transitively):

**Fedora (44+)**:

```sh
sudo dnf install gtk4 nss alsa-lib cups-libs dbus-libs at-spi2-core at-spi2-atk \
  libdrm mesa-libgbm mesa-libEGL libxkbcommon wayland-utils libseccomp \
  gstreamer1 gstreamer1-plugins-base openssl-libs sqlite-libs libcurl
```

**Debian / Ubuntu (a release with glibc 2.43+)**:

```sh
sudo apt install libgtk-4-1 libnss3 libasound2t64 libcups2t64 libdbus-1-3 \
  libatk-bridge2.0-0t64 libatspi2.0-0t64 libdrm2 libgbm1 libegl1 \
  libxkbcommon0 libseccomp2 libgstreamer1.0-0 gstreamer1.0-plugins-base \
  libssl3t64 libsqlite3-0
```

(Package names vary slightly by release; the `t64` suffix is used on Ubuntu 24.04+.)

> **When upgrading**: if you previously extracted a tarball to a non-root prefix (e.g. `~/blinkgtk`), **remove the old version's directory before extracting** the new one (mixing old shared libraries can cause malfunctions). RPM/DEB are replaced automatically by the package manager.

### 3-2. Extract

The layout is FHS (`usr/`, `etc/`), so extract to root:

```sh
sudo tar -C / -xzf blinkgtk-<ver>-linux-x86_64.tar.gz
sudo ldconfig
```

To keep your system clean, extract to any prefix and set `LD_LIBRARY_PATH`:

```sh
mkdir -p ~/blinkgtk && tar -C ~/blinkgtk -xzf blinkgtk-<ver>-linux-x86_64.tar.gz
export LD_LIBRARY_PATH=~/blinkgtk/usr/lib64/blinkgtk-0.1:~/blinkgtk/usr/lib64/blinkgtk-0.1/chromium
```

### 3-3. Machine-check for missing dependencies (recommended)

Independent of distribution package naming, the following shows **exactly what is missing**. Empty output means all dependencies are satisfied:

```sh
PREFIX=/            # or the prefix you extracted to
ldd $PREFIX/usr/lib64/blinkgtk-0.1/chromium/libcontent.so \
    $PREFIX/usr/lib64/blinkgtk-0.1/libblinkgtk-0.1.so.0.0.0 2>/dev/null \
  | grep "not found" | sort -u
```

If something is reported `not found`, search your distribution for the providing package (e.g. Fedora `dnf provides '*/libasound.so.2'`, Debian `apt-file search libasound.so.2`).

## 4. Verification

```sh
sha256sum -c SHA256SUMS --ignore-missing
```

## 5. Sanity check

```sh
ldconfig -p | grep blinkgtk                  # library registration (root install)
pkg-config --modversion blinkgtk-0.1         # with devel installed
```

## 6. Troubleshooting

| Symptom | Cause and fix |
|---|---|
| `error while loading shared libraries: ...: cannot open shared object file` | Missing dependency. Identify it with §3-3 and install the providing package |
| `GLIBC_2.43 not found` | Your distribution's glibc is too old. Use a release meeting §0 |
| Crashes at startup with sandbox errors (containers etc.) | The environment does not support the Chromium sandbox. Start with `BLINKGTK_NO_SANDBOX=1` |
| No window / `Failed to connect to Wayland display` | Run inside a Wayland session (X11 sessions are unsupported). Check `echo $WAYLAND_DISPLAY` |
| No audio / video playback | Missing GStreamer plugins. Add `gstreamer1-plugins-good` (Fedora) / `gstreamer1.0-plugins-good` (Debian) |

For building applications and API usage, see the bundled documentation under `/usr/share/doc/blinkgtk-0.1/` (directory named after the API version).

If this does not help, please report via [Issues](https://github.com/daisy19gnu/blinkgtk-dist/issues) (a bug-report template is provided).

For commercial support or custom development, see <https://blinkgtk.com/>.
