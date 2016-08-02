Упакованный массив
------------------
Использовать битовые поля не получится
``` cpp
struct OneBitStruct {
  int OneBit : 1;
};

// Размер массива вовсе не 1 байт
OneBitStruct array[8];
```

``` cpp
// Массив, в котором хранится size элементов.
// Каждый элемент должен занимать bits бит.
// Например:
//   массив из 8 элементов по 1 биту должен занимать
//   1 байт
//
//  00000000
//    1
//    0
// Сдвигаем на bits влево
//  и меняем её в массиве
//
//   5
//  00000000111111112222222233333333 - байты
//  0000011111222223333344444     - элементы

// bits - количество бит на одно число
// size - размер массива
// ValueType
template <int bits, int size, typename ValueType>
struct CalcBits {
  // Размер ValueType в битах
  // размер каждой ячейки массива в битах
  static const int BITS = sizeof(ValueType) * 8;

  // Номер ячейки массива
  // Элемент может занимать одну ячейку i
  // либо две ячейки массива i и i+1
  int i;
  // Номер первого бита значения в ячейке
  int idxIn;
  // Битов в i-ой ячейке
  int bits1;
  // Битов в i+1-ой ячейке
  int bits2;
  // Создаём две маски
  //  mask - биты используемые в i-ой ячейке 1
  //  mask2 - биты используемые в i+1-ой ячейке 1
  int mask, mask2;

  CalcBits(int index) {
    // Номер первого бита значения относительно
    // начала массива
    //  0000011111222223333344444     - элементы
    int bitIdx = index * bits;
    // Номер ячейки массива
    i = bitIdx / BITS;
    // Номер бита в i-ой ячейке массива
    idxIn = bitIdx % BITS;
    // Сколько бит в i-ой ячейке
    // BITS - idxIn - сколько осталось бит
    // bits - сколько требуется для хранения значения
    bits1 = min(bits, BITS - idxIn);
    // Сколько бит осталось на i+1 ячейку
    bits2 = bits - bits1;
    // Создаём маску для i-ой ячейки
    //  Хочу получить маску длины N
    //    1 << N  - единицу на N бит влево
    //  N = 3
    //    1000
    //  Вычитаю 1 из двоичного числа
    //    0111
    //  И дальше её сдвигаю влево на idxIn бит
    //     01110000
    mask = ((1 << bits1) - 1) << idxIn;
    // Получаю маску из bits2 для i+1 ячейки
    mask2 = (1 << bits2) - 1;
  }
};
```

``` cpp
// bits - количество бит на одно число
// size - размер массива
template <int bits, int size, typename ValueType = unsigned char>
class PackedArray {
  static const int BITS = sizeof(ValueType) * 8;
  ValueType data[(size * bits + BITS - 1) / BITS];
 public:
  void setValue(int index, ValueType value) {
    // Вычисляю биты, где будет расположено значение
    // value
    CalcBits<bits, size, ValueType> x(index);
    // Младшая часть числа
    // ~x.mask - побитовое НЕ (инвертирование)
    data[x.i] &= ~x.mask; // Очищаем биты
    data[x.i] |= (value << x.idxIn); // Новое значение

    // Старшая часть числа
    if(x.bits2 > 0) {
      data[x.i + 1] &= ~x.mask2; // Очищаем биты
      data[x.i + 1] |= (value >> x.bits1); // Новое значение
    }
  }
  // Получить значение
  ValueType getValue(int index) {
    CalcBits<bits, size, ValueType> x(index);
    // Младшая часть
    int v1 = (data[x.i] & x.mask) >> x.idxIn;

    if(x.bits2 == 0)
      return v1;

    // Старшая часть числа
    int v2 = (data[x.i + 1] & x.mask2);
    return v1 | (v2 << x.bits1);
  }
  // TODO: реализовать перегрузку operator[]
};
```

Тестирование
Массив из 10 бит
``` cpp
  PackedArray<1, 10> pa;

  for(int i = 0; i < 10; ++i)
    for(int v = 0; v <= 1; ++v) {
      pa.setValue(i, v);
      assert(pa.getValue(i) == v);
    }

```

Случайный тест
``` cpp
  for(int t = 0; t < 1000; ++t) {
    int i = rand() % 10;
    int v = rand() % 2;
    pa.setValue(i, v);
    assert(pa.getValue(i) == v);
  }

```

Из 10 элементов по 4 бита
``` cpp
  PackedArray<4, 10> pa2;

  for(int t = 0; t < 10000; ++t) {
    int i = rand() % 10;
    int v = rand() % (1 << 4);
    pa2.setValue(i, v);
    assert(pa2.getValue(i) == v);
  }

```

По 5 бит, с перехлёстом байтов
``` cpp
  CalcBits<5, 10, unsigned char> cb(1);
  assert( cb.i == 0 );
  assert( cb.idxIn == 5 );
  assert( cb.bits1 == 3 );
  assert( cb.bits2 == 2 );
  assert( cb.mask == 0b11100000 );
  assert( cb.mask2 == 0b00000011 );

  PackedArray<5, 10> pa5;

  for(int t = 0; t < 10000; ++t) {
    int i = rand() % 10;
    int v = rand() % (1 << 5);
    pa5.setValue(i, v);
    assert(pa5.getValue(i) == v);
  }

```

С другим типом данных и перехлёстом
``` cpp
  PackedArray<11, 10, unsigned int> pa11;

  for(int t = 0; t < 10000; ++t) {
    int i = rand() % 10;
    int v = rand() % (1 << 11);
    pa11.setValue(i, v);
    //SHOW(i);
    //SHOW(v);
    //SHOW(pa11.getValue(i));
    assert(pa11.getValue(i) == v);
  }

```

[main.cpp](main.cpp)

