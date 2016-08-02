SET PATH=C:\Qt\5.4\mingw491_32\bin;C:\Qt\Tools\mingw48_32\bin;%PATH%
qmake qt_debug.pro
mingw32-make.exe
mingw32-make.exe -f Makefile.Debug
