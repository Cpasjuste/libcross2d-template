# libcross2d template

### Build your first project (on linux for linux)

- Install dependencies (Ubuntu)
  ```
  sudo apt-get install build-essential cmake git libsdl2-dev libfreetype6-dev libglm-dev libconfig-dev libphysfs-dev
  ```
  Fedora
  ```
  sudo dnf install @development-tools cmake git SDL2-devel freetype-devel glm-devel libconfig-devel physfs-devel Box2D-devel
  ```
- Clone this template repository
  ```
  git clone --recursive https://github.com/Cpasjuste/libcross2d-template.git
  ```
- Build !
  ```
  cd libcross2d-template
  mkdir cmake-build-release && cd cmake-build-release
  cmake -G "Unix Makefiles" -DPLATFORM_LINUX=ON -DCMAKE_BUILD_TYPE=Release ../
  make
  ```

### Add custom data to your project
libcross2d should automatically handle your data. In the [data](https://github.com/Cpasjuste/libcross2d-template/tree/master/data) folder of your project, you'll find multiple directories:
  - 3ds: data in this directory will only be included in nintendo 3ds builds (platform)
  - common: data in this directory will be included in all builds (platforms)
  - dreamcast: data in this directory will only be included in sega dreamcast builds (platform)
  - linux: data in this directory will only be included in linux builds (platform)
  - switch: data in this directory will only be included in nintendo switch builds (platform)
  - vita: data in this directory will only be included in sony ps vita builds (platform)

In each platform directory, you'll find two subdirectories:
  - datadir: files in this directory will be available on the target platform storage (hard drive, micro-sd, etc...) (Io::getDataPath)
  - romfs: files in this directory will be embedded in the application binary (Io::getRomFsPath)
