// C++
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <clocale>

using namespace std;

int main() {
  // Вывод в консоль по-русски:
  //-->
  //system("chcp 65001");
  SetConsoleOutputCP(CP_UTF8);
  //std::locale::global(std::locale ("en_US.UTF-8"));
  printf("Это моя первая программа!\n");
  //cout << "Текст в UTF-8" << endl;
  //cout << "И он нормально читается в Windows-консоли!" << endl;
  //<--

  int a = 2;
  int b = 3;
  int c = a + b;

  cout << a << "+" << b << "=" << c << endl;

  return 0;
}
