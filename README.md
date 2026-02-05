# Physics Simulator

A custom-built physics engine implemented from scratch in C++ using SDL2.
This project focuses on understanding the mathematics that goes into the making of powerful physics engines, while maintaining maximum efficiency.

## Requirements

- **C++ 17** compiler (GCC/Clang)
- **SDL2** development libraries
- **CMake** (3.10 or higher)

## Installation

### Windows
Install MSYS2
From the terminal install the needed dependencies
```bash
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-sdl2 mingw-w64-ucrt-x86_64-make
```

### Fedora
To run the simulation, ensure that SDL2 is installed on your system.
If you are using Fedora, you can install the development headers using:
```bash
sudo dnf install SDL2-devel
```


## Build & Run
Create a build directory:
```bash
mkdir build
cd build
```

Generate build files and compile the source code:
```bash
cmake ..
make
```

Run the simulation:
```bash
./main
```
