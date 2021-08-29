# kOS
kOS is a small (mostly) C-written Operating System.  
It is still in a very early stage, thus it has no real goal yet.

## Building
Building kOS requires LLVM (clang and LLD) and CMake to be installed.
```sh
cmake -B build -G Ninja # In case your C compiler is not clang, pass the following as well: -DCMAKE_C_COMPILER=$(which clang)
cmake --build build
```
