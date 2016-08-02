#include <iostream>
#include <string.h> // strlen
#include <windows.h>
#include <assert.h> // Проверка утверждений

class string {
  static int count; // Общая переменная
  int id; // Идентификатор объекта
 public:
  char* Str; // Строка
  int Size() { // Длина строки
    return strlen(Str);
  }
 public:
  string(string&); // Конструктор копирования
  string(char* str) {
    assert(str != NULL);
    Str = new char[strlen(str) + 1]; // Добавляем 1,
    // потому что в строке символ 0 - окончание строки
    strcpy(Str, str);
    id = ++count;
  }
  void show() {
    std::cout << "#" << id << " (" << count << ") " << " " << Str
              << "  Адрес: " << ((int)Str)
              << std::endl;
  }
  int operator ==(string& right) {
    return Str == right.Str;
  }
  int operator !=(string& right) {
    return Str != right.Str;
  }
};

int string::count = 0;

// Создает копии динамических переменных и ресурсов
string::string(string& right) {
  Str = new char[right.Size() + 1];
  strcpy(Str, right.Str); // strcpy - копирование строки
  id = ++count;
  std::cout << "string copy contructor" << std::endl;
}

void f(int i) {
  assert( i != 3);
  int j = 10 / (i - 3);
  f(i - 1);
}

int main() {
  //SetConsoleCP(65001);
  //SetConsoleOutputCP(65001);

  f(10);

  string aa(NULL);
  string a("Test");
  string b = a; // Используется конструктор копирования
  string c(a); // Использование конструктора копирования
  a.show();
  b.show();

  // Добавить в конец кусок строки
  // Строка должна стать "TestEnd" после этой операции
  a.append("End");
  assert( strcmp(a.Str, "TestEnd") == 0 );

  assert( a != b );

  return 0;
}
