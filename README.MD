# libcross2d template

## Table of contents

1. [Build for Linux](#linux)
2. [Build for Nintendo Switch](#switch)
3. [Build for Nintendo 3DS](#3ds)
4. [Build for Sony Ps Vita](#vita)
5. [Build for Sony PS4](#ps4)
6. [Add custom data to your project](#data)
7. [What do to next ?](#next)

<a name="linux"></a>
### Build your first project (on linux for linux)

- Install dependencies
  ```
  sudo apt -yq update
  sudo apt -yq install build-essential cmake git libsdl2-dev libfreetype6-dev libglm-dev libconfig-dev libzip-dev libfuse-dev
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
  make -j4
  ```

<a name="switch"></a>
### Build your first project (on linux for nintendo switch)

- Install dependencies
  ```
  sudo apt -yq update
  sudo apt -yq install build-essential cmake git zip curl
  ```
- Install switch toolchain (devkitpro)
  ```
  wget https://github.com/devkitPro/pacman/releases/download/v1.0.2/devkitpro-pacman.amd64.deb
  sudo dpkg -i devkitpro-pacman.amd64.deb
  sudo dkp-pacman -Syu
  sudo dkp-pacman --noconfirm -S switch-dev switch-portlibs
  ```
- Clone this template repository
  ```
  git clone --recursive https://github.com/Cpasjuste/libcross2d-template.git
  ```
- Build !
  ```
  cd libcross2d-template
  mkdir cmake-build-release && cd cmake-build-release
  export DEVKITPRO=/opt/devkitpro
  cmake -G "Unix Makefiles" -DPLATFORM_SWITCH=ON -DCMAKE_BUILD_TYPE=Release ../
  make -j4 app.nro
  ```

<a name="3ds"></a>
### Build your first project (on linux for nintendo 3ds)

- Install dependencies
  ```
  sudo apt -yq update
  sudo apt -yq install build-essential cmake git zip curl
  ```
- Install 3ds toolchain (devkitpro)
  ```
  wget https://github.com/devkitPro/pacman/releases/download/v1.0.2/devkitpro-pacman.amd64.deb
  sudo dpkg -i devkitpro-pacman.amd64.deb
  sudo dkp-pacman -Syu
  sudo dkp-pacman --noconfirm -S 3ds-dev 3ds-portlibs
  ```
- Clone this template repository
  ```
  git clone --recursive https://github.com/Cpasjuste/libcross2d-template.git
  ```
- Build !
  ```
  cd libcross2d-template
  mkdir cmake-build-release && cd cmake-build-release
  export DEVKITPRO=/opt/devkitpro
  cmake -G "Unix Makefiles" -DPLATFORM_3DS=ON -DCMAKE_BUILD_TYPE=Release ../
  make -j4 app.3dsx
  ```

<a name="vita"></a>
### Build your first project (on linux for sony ps vita)

- Install dependencies
  ```
  sudo apt -yq update
  sudo apt -yq install build-essential cmake git zip curl python
  ```
- Install ps vita toolchain (vitasdk)
  ```
  git clone https://github.com/vitasdk/vdpm
  cd vdpm
  ./bootstrap-vitasdk.sh
  export VITASDK=/usr/local/vitasdk
  export PATH=$VITASDK/bin:$PATH
  ./install-all.sh
  ```
- Clone this template repository
  ```
  git clone --recursive https://github.com/Cpasjuste/libcross2d-template.git
  ```
- Build !
  ```
  cd libcross2d-template
  mkdir cmake-build-release && cd cmake-build-release
  export VITASDK=/usr/local/vitasdk
  cmake -G "Unix Makefiles" -DPLATFORM_VITA=ON -DCMAKE_BUILD_TYPE=Release ../
  make -j4 app.vpk
  ```

<a name="ps4"></a>
### Build your first project (on linux for sony ps4)

- Install dependencies
  ```
  sudo apt -yq update
  sudo apt -yq install build-essential cmake git zip curl libgpgme11
  ```
- Install ps4 toolchain (openorbis via pacbrew)
  ```
  wget https://github.com/PacBrew/pacbrew-pacman/releases/download/pacbrew-release-1.0/pacbrew-pacman-1.0.deb
  sudo dpkg -i pacbrew-pacman-1.0.deb
  sudo pacbrew-pacman -Syu
  sudo pacbrew-pacman --noconfirm -S ps4-openorbis ps4-openorbis-portlibs
  ```
- Clone this template repository
  ```
  git clone --recursive https://github.com/Cpasjuste/libcross2d-template.git
  ```
- Build !
  ```
  cd libcross2d-template
  mkdir cmake-build-release && cd cmake-build-release
  export OPENORBIS=/opt/pacbrew/ps4/openorbis
  cmake -G "Unix Makefiles" -DPLATFORM_PS4=ON -DCMAKE_BUILD_TYPE=Release ../
  make -j4 app_pkg
  ```

<a name="data"></a>
### Add custom data to your project

libcross2d should automatically handle your data. In
the [data](https://github.com/Cpasjuste/libcross2d-template/tree/master/data) folder of your project, you'll find
multiple directories:

- 3ds: data in this directory will only be included in nintendo 3ds builds (platform)
- common: data in this directory will be included in all builds (platforms)
- dreamcast: data in this directory will only be included in sega dreamcast builds (platform)
- linux: data in this directory will only be included in linux builds (platform)
- ps4: data in this directory will only be included in sony ps4 builds (platform)
- switch: data in this directory will only be included in nintendo switch builds (platform)
- vita: data in this directory will only be included in sony ps vita builds (platform)

In each platform directory, you'll find two subdirectories:

- datadir: files in this directory will be available on the target platform storage (hard drive, micro-sd, etc...) (Io::
  getDataPath)
- romfs: files in this directory will be embedded in the application binary (Io::getRomFsPath)

<a name="examples"></a>
### What do to next ?
You can take a look at the [libcross2d-examples](https://github.com/Cpasjuste/libcross2d-examples) repository for a few examples !