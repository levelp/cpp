Определение глобальной переменной
в **module1.cpp**
``` cpp
int globalVar = 2;
```

[module1.cpp](module1.cpp)

В **module2.cpp** тоже можно
использовать **globalVar**
``` cpp
void v2() {
  D(globalVar = 2);
  SHOW(globalVar);
}

void show2() {
  D(SHOW(globalVar));
}
```

[module2.cpp](module2.cpp)

Глобальная переменная в **vars.h**
``` cpp
extern int globalVar;
```

[vars.h](vars.h)

