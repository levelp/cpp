Отладка Qt приложений
=====================
* Точки останова
* Логгирование
``` cpp
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
```

Создает копии динамических переменных и ресурсов:
``` cpp
string::string(string& right) {
  Str = new char[right.size() + 1];
  strcpy(Str, right.Str); // strcpy - копирование строки
  id = ++count;
  std::cout << "string copy contructor" << std::endl;
}
```

[main.cpp](main.cpp)

