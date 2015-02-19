SET PATH=C:\CodeBlocks\MinGW\bin;%PATH%

for /D %%i in (01,02,03,04,05,06,07,08,09,10,11,12,13,15,16,17,18) do ( 
  c++ -O2 -Wall sol%%i.cpp -o "sol%%i.exe" 
)

g++ -Wall vector.cpp -o vector.exe
g++ -O2 -Wall vector.cpp -o vector_O2.exe
vector.exe