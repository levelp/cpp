/// Отладка Qt приложений
/// =====================
/// * Точки останова
/// * Логгирование
#include <iostream>
#include <string.h> // strlen
#include <windows.h>
#include <assert.h> // Проверка утверждений

//-->
class string {
  static int count; // Общая переменная
  int id; // Идентификатор объекта
 public:
  char* Str; // Строка
  int size() { // Длина строки
    return strlen(Str);
  }
 public:
  string(string&); // Конструктор копирования
  string(char* str) {
    Str = new char[size() + 1]; // Добавляем 1,
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
//<--

int string::count = 0;

/// Создает копии динамических переменных и ресурсов:
//-->
string::string(string& right) {
  Str = new char[right.size() + 1];
  strcpy(Str, right.Str); // strcpy - копирование строки
  id = ++count;
  std::cout << "string copy contructor" << std::endl;
}
//<--

int main() {
  SetConsoleCP(65001);
  SetConsoleOutputCP(65001);

  string a("Test");
  string b = a; // Используется конструктор копирования
  string c(a); // Использование конструктора копирования
  a.show();
  b.show();

  assert( a != b );

  return 0;
}
