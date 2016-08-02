Шаблоны
=======

Шаблонная функция:
``` cpp
// Шаблонная функция вычисления минимума
template <class T>
T myMin(T a, T b) {
  return (a < b) ? a : b;
}
```

Шаблон класса:
``` cpp
template <class T> 
class ClassName {
  T x, y; // Использование параметра
}
```

Тестирование:
``` cpp
int main() {
  cout << myMin(2, 3) << endl;
  cout << myMin(2.3, 3.22) << endl;
  cout << myMin<char>('s', 'd') << endl;
  return 0;
}
```
