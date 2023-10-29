as --64 -o test.o test.s
rmdir /s /q .\build
md build
cd build
cmake -G "MinGW Makefiles"  ..
mingw32-make
cd ..
