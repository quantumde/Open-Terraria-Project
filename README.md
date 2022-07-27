Open Terraria Project
=========
Open Terraria Project is...
Try to make something like Terraria, but in terminal, c++, and using only cross-platform libraries.


### Dependencies

#### Required
 * Meson (>= 0.62)
 * libncurses (>= 6.0)

### Build instructions
Use Meson to configure OpenSourceTerraria and build it with ninja:
```bash
mkdir build
cd build
meson ..
ninja
```

### Installation
To install the compiled binaries and required data, execute
`ninja install` with superuser permission.
