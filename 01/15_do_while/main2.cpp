//-->
#include <iostream>
#include <clocale>

using namespace std;

int main() {
  // Win1251 и в исходном тексте и в консоли
  setlocale(LC_ALL, "Russian");

  cout << "Программа для вычисления суммы чисел" << endl;
  cout << "Вводите целые числа для суммирования" << endl;
  cout << "Для окончания ввода введите 0" << endl;

  int sum = 0; // Текущее значение суммы

  int num;

  // Цикл с постусловием
  // Аналог repeat until в Delphi
  do {
    // Тело цикла
    cout << "Введите число: ";
    cin >> num;

    if(num != 0)
      sum += num;

  } while(num != 0);  /* Условие продолжения цикла */

  cout << "Сумма: " << sum << endl;

  return 0;
}
//<--
