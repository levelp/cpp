// Конструктор копирования
// -----------------------
#include <iostream>
#include <cstring>

#define SHOW(x) { cout << #x << " = " << x << endl; }
#define D(x) cout << #x << endl; x;

using namespace std;

// Создаем собственный класс "Строчка"
//-->
struct String {
  char* str; // Здесь храним строчку
  int x; // Дополнительное поле
  // Конструктор
  String(char* initStr) {
    str = new char[strlen(initStr) + 1];
    strcpy(str, initStr);
  }
  // Конструктор копирования
  String(String& s) : String(s.str)  {
    cout << "Copy constructor" << endl;
    x = s.x;
  }
  // Деструктор
  ~String() {
    delete[] str;
  }
};
//<--

int main() {
  // Если написать так, то получим ошибку выполнения,
  // т.к. пытаемся переписать константу
  //```cpp
  //const char *str = "Hello";
  //str[0] = 'X';
  //```
  char strInStack[6] = "Hello";
  String s1(strInStack);
  s1.x = 123; // Любое число
  String s2 = s1; // Автоматически копируется
  SHOW(s1.str); // Строки
  SHOW(s2.str); // одинаковы
  SHOW(s1.x); // Числа
  SHOW(s2.x); // тоже
  D(strInStack[0] = 'X');
  SHOW(s1.str);
  SHOW(s2.str);
  D(s1.str[0] = '#');
  SHOW(s1.str);
  SHOW(s2.str);
  String s3(s2);
  return 0;
}
