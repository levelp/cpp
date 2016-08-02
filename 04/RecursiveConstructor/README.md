<!-- doc.py -->
Рекурсивный конструктор
=======================
``` cpp
class A {
 public:
  // Рекурсивный конструктор
  A(int N) {
    cout << "Constructor " << N << endl;
    // Пока N > 0 вызываем самого себя
    if(N > 0)
      A(N - 1); // Вызов конструктора
  }
};
```

Тестирование:
``` cpp
int main() {
  A a(6);
  // После запуска получим:
  // Constructor 6
  // Constructor 5
  // Constructor 4
  // Constructor 3
  // Constructor 2
  // Constructor 1
  // Constructor 0
  return 0;
}
```

[main.cpp](main.cpp)

