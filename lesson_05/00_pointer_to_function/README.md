<!-- doc.py -->
Указатель на функцию
--------------------
Определение нового типа **MyFunction**
Спецификация функции:
* тип возвращаемого значения - int
* тип первого параметра int
* тип второго параметра void*
``` cpp
typedef int (*MyFunction)(int, void*);
```

Две реализации функции
``` cpp
int f1(int a, void* b) {
  cout << __FUNCTION__ << "(" << a << ", " << b << ")" << endl;
  return 1;
}

int f2(int a, void* b) {
  cout << __FUNCTION__ << "(" << a << ", " << b << ")" << endl;
  return 2;
}
```

Функция, которая на вход получает double
и возвращает тоже double (например: sin/cos)
``` cpp
typedef double (*DoubleFuncPtr)(double);
```

error: invalid conversion from
'int (*)(int, void*)' to
'DoubleFuncPtr {aka double (*)(double)}'
showFuncTable(&f1);
```

[main.cpp](main.cpp)

