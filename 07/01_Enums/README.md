Перечисления (enum)
-------------------
Зачем?
Удобная замена константам
которые соответствуют разным элементам
одного и того же типа.
Направления движения:
вверх - 0, вниз - 1,
влево - 2, вправо - 3
``` cpp
const int X_UP = 0;
const int X_DOWN = 1;
const int X_LEFT = 2;
const int X_RIGHT = 3;
int direction = X_UP;

// Вводим специальный тип
enum Direction {
  UP = 4 /* 0 */, DOWN = 13 /* 1 */,
  LEFT = (1L << 31) - 1 /* 2 */,
  RIGHT = 7 /* 3 */
};

enum DirectionX {
  T_UP /* 0 */, T_DOWN /* 1 */,
  T_LEFT /* 2 */, T_RIGHT /* 3 */
};
```

Упаковка
#pragma pack(4)
Последовательная нумерация
[main.cpp](main.cpp)

