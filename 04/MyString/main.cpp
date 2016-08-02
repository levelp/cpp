#include <iostream>
#include <string.h>
// Работа с утверждениями
#include <cassert> // assert.h

using namespace std;

// Класс СТРОКА
class String {
  // Обязательные поля класса:
  // указатель на char — хранит адрес динамически выделенной
  // памяти для размещения символов строки;
  char* data;
  // значение типа int — хранит длину строки в байтах
  int len;
  // Обязательные методы:
 public:
  // конструктор без параметров;
  String() : data(NULL) {
    setString("");
  };
  // конструктор, принимающий в качестве параметра строку;
  String(const char* value) : data(NULL) {
    setString(value);
  }
  // конструктор копирования;
  String(const String& s) {
    setString(s.data);
  }
  // получение длины строки;
  int getLen() const {
    return len;
  }
  // замена строки (ввод новой строки setString);
  void setString(const char* value) {
    delete data;
    len = strlen(value);
    data = new char[strlen(value) + 1];
    strcpy_s(data, len + 1, value);
  }
  // вывод текущей строки (getString);
  char* getString() {
    // TODO: надо ли создавать копию?
    char* copy = new char[len + 1];
    strcpy_s(copy, len + 1, data); // Скопировали строчку
    return copy;
  }
  // очистка строки (сделать строку пустой);
  void clear() {
    setString("");
  }
  // деструктор.
  ~String() {
    delete data;
  }
  // вывод строки на экран
  void show() {
    cout << "String: \"" << data << "\"" << endl;
  }
};

void testDefaultConstructor() {
  // Тестируем конструктор по-умолчанию
  // 1. Подготавливаем все нужные данные/объекты
  String s;
  // 2. Проверяем утверждения
  assert(s.getLen() == 0);
  assert(strcmp("", s.getString()) == 0);
  // 3. Очищаем память/ресурсы
}

void testCopyConstructor() {
  // Тестируем конструктор копирования
  // 1. Подготавливаем все нужные данные/объекты
  String src("Test");
  String dst = src;
  // 2. Проверяем утверждения
  assert(src.getLen() == dst.getLen());
  assert(strcmp(src.getString(), dst.getString()) == 0);
  // 3. Очищаем память/ресурсы
}

void testClear() {
  // Тестируем очищение строки
  // 1. Подготавливаем все нужные данные/объекты
  String s("Какая-то строка");
  // 2. Проверяем утверждения
  assert(s.getLen() != 0);
  assert(strcmp("", s.getString()) != 0);
  s.clear();
  assert(s.getLen() == 0);
  assert(strcmp("", s.getString()) == 0);
  // 3. Очищаем память/ресурсы
}

int main() {
  String s("Hello world!");
  s.show();
  assert(2 * 2 == 4);
  testDefaultConstructor();
  testCopyConstructor();
  testClear();
  system("pause");
  return 0;
}
