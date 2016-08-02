@SET PATH=C:\CodeBlocks\MinGW\bin;%PATH%

@echo === ANSI C === 
mingw32-gcc.exe -O2 -Wall hw_cp866.c -o hw_cp866_c.exe
hw_cp866_c.exe

@echo === C++ ===
g++ -O2 -Wall hw_cp866.cpp -o hw_cp866_cpp.exe
hw_cp866_cpp.exe
