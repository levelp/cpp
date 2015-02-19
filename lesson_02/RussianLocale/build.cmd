@echo off
for %%i in (rus rus_1251 rus_utf8) do (
  echo compile and run "%%i"
  c++ %%i.cpp -o %%i.exe
  %%i.exe
)
