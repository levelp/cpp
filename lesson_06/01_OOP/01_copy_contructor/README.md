Конструктор копирования
-----------------------
Создаем собственный класс "Строчка"
``` cpp
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
```

Если написать так, то получим ошибку выполнения,
т.к. пытаемся переписать константу
```cpp
const char *str = "Hello";
str[0] = 'X';
```
[main.cpp](main.cpp)

