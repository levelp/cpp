// Ввод и вывод данных (консоль) в C и в C++. Ввод и вывод из текстового файла
// ---------------------------------------------------------------------------
#include <iostream>
#include <clocale>
#include <stdio.h>
#include <cstdlib>

using namespace std;

static int staticVar = 3;

int f() {
  static int local = 3;
  local++;
  return local;
}

// Программа, которая складывает два числа
int main() {
  // Ввод и вывод из текстового файла
  // Раскомментировать для ввода из файла
  //    freopen("input.txt", "r", stdin);
  // Раскомментировать для вывода в файл
  //    freopen("result.txt", "w", stdout);
  //    static int a = 3;
  setlocale(LC_ALL, "Russian");
  // Ввод двух чисел
  int a, b; // Обьявление переменных
  //cout << "Введите A и B: ";
  cin >> a >> b; // Console INput
  // Сложение
  int c = a + b;
  // Вывод результата
  cout << a << " + " << b << " = " << (a + b) << endl;
  system("pause");
  return 0;
}
