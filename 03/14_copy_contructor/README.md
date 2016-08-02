Конструктор копирования
-----------------------
``` cpp
// Класс "строка"
class string {
  static int count; // Количество строк
  char*    Str;
  int     size;
 public:
  int id; // Идентификатор данной строки
  string(string&); // Конструктор копирования
  // Конструктор
  string(const char* str) {
    id = ++count;
    std::cout << "Constructor #" << id << " \"" << str << "\"" << std::endl;
    size = strlen(str); // "ABC\0"
    Str = new char[size + 1];
    strcpy(Str, str);
  };
  // Вывод строки на экран
  void show() {
    std::cout << Str << std::endl;
  }
  // Деструктор
  ~string() {
    std::cout << "Destructor #" << id << std::endl;
    delete[] Str; // Очищаем динамическую память
  }
  // Перегрузка операции присваивания
  string& operator=(string& right) {
    if(Str != NULL)
      delete[] Str;

    std::cout << "= #" << id << std::endl;
    // if(Str != NULL)
    //   delete[] Str;
    Str = new char[right.size + 1];
    size = right.size;
    strcpy(Str, right.Str);
  }
};

// Конструктор копирования
// Создает копии динамических переменных и ресурсов
string::string(string& x) {
  id = ++count;
  std::cout << "Copy constructor #" << id << std::endl;
  // if(Str != NULL)
  //   delete[] Str;
  Str = new char[x.size + 1];
  size = x.size;
  strcpy(Str, x.Str);
}

int string::count = 0;
```

[main.cpp](main.cpp)

