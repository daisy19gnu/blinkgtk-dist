# BlinkGTK Installation Guide

**Author**: BlinkGTK Project

Download packages from [Releases](https://github.com/daisy19gnu/blinkgtk-dist/releases). See [`manifests/`](./manifests/) for package contents.

> **Note**: the `0.1` in paths (`blinkgtk-0.1` etc.) is the **API version** (same convention as GTK4's `gtk-4.0`). It is independent of the product version (v1.1.0 etc.) and only changes on incompatible API revisions.

## 1. RPM (Fedora 44 / x86_64)

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

RPMs are GPG-signed; import the public key to verify signatures.

## 2. DEB (Debian / Ubuntu / amd64)

```sh
sudo apt install ./libblinkgtk-0.1-0_<ver>_amd64.deb      # runtime
sudo apt install ./libblinkgtk-0.1-dev_<ver>_amd64.deb    # development
```

## 3. tarball (other Linux / glibc / x86_64)

`.tar.gz` and `.tar.bz2` have identical contents. The layout is FHS (`usr/`, `etc/`), so extract to root:

```sh
sudo tar -C / -xzf blinkgtk-<ver>-linux-x86_64.tar.gz
sudo ldconfig
```

To keep your system clean, extract to any prefix and set `LD_LIBRARY_PATH`:

```sh
mkdir -p ~/blinkgtk && tar -C ~/blinkgtk -xzf blinkgtk-<ver>-linux-x86_64.tar.gz
export LD_LIBRARY_PATH=~/blinkgtk/usr/lib64/blinkgtk-0.1:~/blinkgtk/usr/lib64/blinkgtk-0.1/chromium
```

## 4. Verification

```sh
sha256sum -c SHA256SUMS --ignore-missing
```

## 5. Sanity check

```sh
pkg-config --modversion blinkgtk-0.1        # with devel installed
ldconfig -p | grep blinkgtk                  # library registration
```

For building applications and API usage, see the bundled documentation under `/usr/share/doc/blinkgtk-0.1/`.
