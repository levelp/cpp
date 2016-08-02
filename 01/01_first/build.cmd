SET PATH=C:\CodeBlocks\MinGW\bin;%PATH%

echo ANSI C 
mingw32-gcc.exe -O2 -Wall helloworld.c -o helloworld_c.exe
helloworld_c.exe

echo C++
g++ -O2 -Wall helloworld.cpp -o helloworld_cpp.exe
helloworld_cpp.exe
