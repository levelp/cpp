#include <iostream>
#include <cstdlib>

using namespace std; // Пространство имён, чтобы не писать везде std::cin

int main() { // Основная функция
  cout << "Hello World!" << endl; // Выводим на экран
  cout << "Enter two numbers: ";

  // тип имя_переменной_1, имя_переменной_2;
  int a, b; // Объявляем 2 переменные целого типа
  cin >> a >> b; // Вводим их с клавиатуры
  cout << a << " + " << b << " = " << a + b << endl; // Вывод суммы
  system("pause"); // Нажмите любую клавишу...
  return 0; // Программа завершилась удачно, 0 - код возврата
}
