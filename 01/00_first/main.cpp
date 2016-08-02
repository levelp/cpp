#include <iostream>
#include <cstdlib>

using namespace std; // Пространство имён, чтобы не писать везде std::cin

int main() { // Основная функция
  <<< <<< < HEAD: 01 / 00_first / main.cpp
  // Выводим на экран
  == == == =
    cout << "Hello World!" << endl; // Выводим на экран
  >>> >>> > fccd5862bd1da50c8eb904f7c35edd2dda453d3c: 01 / 00_first / main.cpp
  cout << "Enter two numbers" << endl;
  int a, b; // Объявляем 2 переменные целого типа
  cin >> a >> b; // Вводим их с клавиатуры
  cout << a << " + " << b << " = " << a + b << endl; // Вывод суммы
  system("pause"); // Нажмите любую клавишу...
  return 0; // Программа завершилась удачно, 0 - код возврата
}
