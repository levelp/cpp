// Компиляция C:     source.c -> source.obj -> source.exe
//            C++:   source.cpp -> source.obj -> source.exe
// Несколько модулей:
//            a.c -> a.obj    b.c -> b.obj    a.obj + b.obj -> x.exe
// Для C: .H  пример: stdio.h    .c - C
#include <stdio.h>
// Для C++: нет расширения/.hpp  примеры: iostream   test.hpp  - .cpp C++
#include <iostream>
// Используем: <>  из include компилятора
// Используем: ""  подключаем из текущего каталога
#include "a_my.h"
//#include "test/a.h"

//using namespace std;

int main() { // begin
  //cout << " i = " << i << endl;
  int a = 1, A = 2;  // Var a : Integer = 1;
  // << - побитный оператор сдвига влево
  int x =  3 << 1; //  00000011    сдвигаем влево на 1
  //  00000110 -> 6
  // << - для cout перегружен как вывод в поток (вывод в текстовую консоль)
  // cout - "c"onsole "out"put
  std::cout << " i = " << i << std::endl;  // "%n" "\r\n"
  std::cout << " i = " << i << "\r\n\\\t\"  \\\\\\";
  char c = '\t';
  // Windows: CR LF - #13 #10 CR=\r LF=\n
  // Linux: LF - #10
  // MacOS (старые версии): CR - #13
  //string str = "world!";
  //string s = "Hello, " + str;
  int j = 241;
  std::cout << " i = " << i << "    j = " << j << std::endl;
  printf("i = %d\n", i);  //  Format('i = %d\n', [i]);
  // Writeln('i = ', i);
  if(1 < 2) {
    // ...
  }

  return 0;
}  // end.

