# libcross2d template

### How to build your first project (on linux for linux)

- Install dependencies
  ```
  sudo apt-get install build-essential cmake git libsdl2-dev libfreetype6-dev libglm-dev libconfig-dev libphysfs-dev
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