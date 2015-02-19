// Объединения - union
// -------------------
// Два и более объекта занимают одну и ту же ячейку памяти
#include <iostream>
#include <bits/

#define SHOW(x) cout << #x << " = " << x << endl;

using namespace std;

// Пример:
//-->
union HH {
  int a;
  int b;
  char c;
};
//<--

void demo_HH() {
  SHOW(sizeof(HH)); // 4 байта = sizeof(int)
}

// Как выглядит переменная какого-то типа в памяти?
//
// Чтобы абстрагироваться от конкретного типа
// используем **typedef**:
// typedef Определение_типа Имя_нового_типа;

//-->
typedef unsigned int MyType;
//<--

// Объединение:
//-->
union InMemoryPresentation {
  MyType field; // Поле нашего типа
  unsigned char b[sizeof(MyType)]; // Массив байт того же размера
};
//<--

int main() {
  demo_HH();

  MyType i = 10;
  MyType b, a = 132;
  a = i * b;

  //-->
  InMemoryPresentation u;
  u.field = 76; // 'A';

  for(int i = 0; i < sizeof(MyType); ++i) {
    cout << i << ". ";

    for(int b = 7; b >= 0; --b) {
      unsigned char byte = u.b[i];
      // Число:    01101110  00001101
      // Ном.бита: 76543210         1
      // Вырезаем b-ый бит
      cout << ((byte >> b) & 1);
    }

    cout << endl;
  }

  //<--

  return 0;
}
// Для intel-совместимых процессоров
// младший байт первый
// Intel: little-endian: "остроконечный"
// big-endian, дословно: "тупоконечный"
// TODO: посмотреть endian.h
