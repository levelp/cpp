<!-- doc.py -->
Умные указатели
Умный указатель (Smart Pointer) — класс (обычно шаблонный),
имитирующий интерфейс обычного указателя и добавляющий некую новую функциональность,
например, проверку границ при доступе или очистку памяти.
В STL есть: std::auto_ptr
Обычный класс
Использует динамическую память
Умный указатель
``` cpp
template <class T>
class SmartPtr {
  T* ptr;
 public:
  SmartPtr(T* p) {
    ptr = p;
  }
  // Автоматическая отчистка динамической памяти
  ~SmartPtr() {
    delete ptr;
  }
  T* operator ->() { // Переход по ссылке
    return ptr;
  }
  T& operator*() { // Оператор разыменования
    return *ptr;
  }
};
```

setlocale(LC_ALL, "Russian");
SmartPtr<int[]> m2 = new int[10];
[main.cpp](main.cpp)

