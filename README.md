## About:
**cRay** is a raycasting game engine written in C language that uses [the Digital Differential Analysis](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)) aka the "DDA" algorithm.

## Overview:
![Screenshot from 2023-09-12 00-17-14](https://github.com/kaboussi/cRay/assets/95357302/c037377f-db38-49d5-9048-3c1c53a7b504)


## Dependencies:
The [MLX42](https://github.com/codam-coding-college/MLX42) is a minimal graphical library that depends on [OpenGL](https://www.opengl.org/) and [glfw](https://www.glfw.org/) library.
- For distribution based on **Debian**
```bash
➜ sudo apt update
➜ sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev

➜ # for Wayldan display server you will need extra packeges
➜ sudo apt install libwayland-dev libxkbcommon-dev wayland-protocols extra-cmake-modules libglfw3-wayland
```
- For MacOS you can find the [documentation](https://github.com/codam-coding-college/MLX42#for-macos).
- For Windows WSL2 here's the [documentation](https://github.com/codam-coding-college/MLX42#for-windows-with-windows-subsystem-for-linux-2-wsl2).

## Setup:
```bash
➜  ~ git clone https://github.com/https://github.com/kaboussi/cRay
➜  ~ cd cRay/MLX42
➜  ~ cmake -B build
➜  ~ cmake --build build -j4
```

## Compile and run:
* Using Cmake
```bash
➜  ~ cmake -B cmake-build-debug
➜  ~ cd cmake-build-debug
➜  ~ make -C cmake-build-debug
➜  ~ ./cmake-build-debug/cRay assets/maps/map.cub
```

* Using Makfile
```bash
➜  ~ make
➜  ~ ./cRay assets/maps/map.cub
```
