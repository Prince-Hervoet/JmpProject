as --64 -o swap_ctx_asm.o swap_ctx_asm.S
rmdir /s /q .\build
md build
cd build
cmake -G "MinGW Makefiles"  ..
mingw32-make
cd ..
