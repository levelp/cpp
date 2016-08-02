@SET PATH=C:\CodeBlocks\MinGW\bin;%PATH%

del hw_utf8_cpp.exe

@echo === C++ ===
g++ -O2 -Wall hw_utf8.cpp -o hw_utf8_cpp.exe
hw_utf8_cpp.exe
