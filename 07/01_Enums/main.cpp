/// Перечисления (enum)
/// -------------------
/// Зачем?
/// Удобная замена константам
/// которые соответствуют разным элементам
/// одного и того же типа.
#include <iostream>

using namespace std;

/// Направления движения:
/// вверх - 0, вниз - 1,
/// влево - 2, вправо - 3
///-->
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

// Используем значения для констант
// в перечислении по-умолчанию
// т.е. 0, 1, 2...
enum DirectionX {
  T_UP /* 0 */, T_DOWN /* 1 */,
  T_NEW_SUPER_DIRECTION, /* 2 */
  T_LEFT /* 2->3 */, T_RIGHT /* 3->4 */
};
// Способы избежать "сдвига" констант в перечислении:
// 1. Задавать значения констант явно
// 2. Добавлять новые значения ТОЛЬКО в конец

// Когда используются перечисления:
// 1. Мы их можем перечислить сразу (при создании
//  приложения) и добавление каждой новой
//  константы требует изменения логики
// 2 (доп). Когда констант относительно немного
// Чтобы добавить новый элемент в перечисление
// надо перекомпилировать программу.
// Т.е. если при добавлении нового элемента
// скорее надо будет добавить/изменить код
// => всё равно перекомпилировать программу
// => используйте перечисление
//<--

#pragma pack(1)

// Упаковка - несколько enum в один байт
struct S {
  DirectionX dir1: 2;
  DirectionX dir2: 2;
  DirectionX dir3: 2;
  DirectionX dir4: 2;
  /*DirectionX dir5:2;
  DirectionX dir6:2;
  DirectionX dir7:2;
  DirectionX dir8:2;
  DirectionX dir9:2;
  DirectionX dir10:2;
  DirectionX dir11:2;
  DirectionX dir12:2;
  DirectionX dir13:2;
  DirectionX dir14:2;
  DirectionX dir15:2;
  DirectionX dir16:2;

  DirectionX dir17:2; */
} __attribute__((gcc_struct, __packed__));

//#pragma pack(4)

Direction directionEnum = UP;

#define SHOW(x) { cout << #x << " = " << x << endl; }

/// Последовательная нумерация
enum DirectionXX {
  XX_UP = 4, XX_DOWN /* 5 */,
  XX_LEFT /* 6 */, XX_RIGHT /* 7 */
};

enum FileFormat {
  BMP /* 0 */, GIF, GIF2,
  PNG, JPG,
  FILE_FORMAT_END /* = количество_форматов */
};

int main(int argc, char* argv[]) {
  SHOW(sizeof(S));

  direction = X_DOWN;
  directionEnum = DOWN;

  if(direction == DOWN)
    cout << "Go down!" << endl;

  switch(direction) {
    case X_UP: // Для 2-х направлений
    case X_DOWN:
      /* что-то */
      break;
    case X_LEFT:
      break;
  }

  switch(directionEnum) {
    case UP:
      ;

    case DOWN:
      ;
  }

  directionEnum = LEFT;
  cout << "LEFT =  " <<  directionEnum << endl;
  directionEnum = UP;
  cout << "UP =  " <<  directionEnum << endl;

  SHOW(XX_UP);
  SHOW(XX_LEFT);

  return 0;
}
