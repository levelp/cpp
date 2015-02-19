#include <iostream>
#include <clocale> // setlocale
#include <windows.h>

using namespace std;

int main() {
  // Win1251 и в исходном тексте и в консоли
  setlocale(LC_ALL, "Russian");
  //system("chcp 65001");
  // freopen()

  cout << "== Метрополитен Санкт-Петербурга ==" << endl;
  cout << "Введите номер вашей ветки метро: \n";

  int metro;
  cin >> metro;

  switch(metro) {
    case 1:
      cout << "Красная: Кировско-Выборгская. Самая старая ветка метро." << endl;
      break;

    case 2:
      cout << "Синяя: Московско-Петроградская. " << endl;
      break;

    case 3:
      cout << "Зелёная: Василеостровская" << endl;
      break;

    case 4:
      cout << "Жёлтая: Правобережная" << endl;
      break;

    case 5:
      cout << "Фиолетовая: Спасско-Преображенская" << endl;
      break;

    default:
      cout << "Я не знаю :) Такой ветки ещё не построили в 2014 году." << endl;
  }

  /*  double d = 1.1;
    switch(d){ // <-- Ошибка компиляции, т.к. d неприводим к целому типу
     case 1.1:
       break;
    } */

  char c = 'A';

  switch(c) {
    case 'A':
      cout << "A!!" << endl;
      break;
  }

  return 0;
}
