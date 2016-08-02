Модульное тестирование в Qt
===========================

Модульные тесты:
  Входные данные -> Тестируемый класс -> Ожидаемый результат

Если мы не знаем какой результат ожидать => мы не можем написать тест.

Но запустив тест один раз и посмотрев результат мы можем
написать так называемый **регрессионный тест**.
Т.е. тест, который страхует нас от **регрессий** - ухудшения качества ПО
(когда что-то что уже работало в какой-то версии "ломается" в следующей).

Для использования модульных тестов надо подключить модуль **testlib**.

``` pro
# testlib - библиотека для модульного тестирования
QT       += testlib core gui
```

Пример
------

Тестируемая функция:
``` cpp
// Сумма: a + b
int sum(int a, int b){
  return a + b;
}
```

Модульный тест к ней:
``` cpp
// Класс, который содержит тесты
class AllTests : public QObject {
  Q_OBJECT
private slots: // должны быть приватными
  // Тестирование функции суммирования
  void testSum(){
    QCOMPARE(sum(2,2), 4);
    QCOMPARE(sum(2,3), 5);
  }
};
```

В основной программе все тесты можно запустить так:
```cpp
  QTest::qExec(new AllTests, argc, argv);
```


Подключаем все модули для тестирования
``` cpp
#include "inttostr.h"
#include "functions.h"
#include "myclass.h"
#include "squareeq.h"
// И свой заголовочный файл
#include "alltests.h"
```

Тестирование вычисления максимума
``` cpp
  MyClass a(this);
  // QCOMPARE( вызов_тестируемой_функции, ожидаемое_значение );
  QCOMPARE(a.max(2, 3), 3);  // 1 тест
  QCOMPARE(a.max(2, 4), 4);  // 2 тест
  QCOMPARE(a.max(5, 1), 5);
  QCOMPARE(a.max(1, 2), 2);
  QCOMPARE(a.max(-10, -20), -10);
```

Тестирование вычисления факториала
``` cpp
  QCOMPARE( ::factorial(1), 1LL );
  QCOMPARE( ::factorial(2), 2 * 1LL );
  QCOMPARE( ::factorial(3), 3 * 2 * 1LL );
  QCOMPARE( ::factorial(4), 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(5), 5 * 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(6), 6 * 5 * 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(7), 7 * 6 * 5 * 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(8), 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(9), 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1LL );

  // Проверка исключения (ожидаемое исключение)
  try {
    ::factorial(-1);
    // Если мы оказались в этом месте программы,
    // то метод факториал не сгенерировал исключение
    QFAIL("Exception expected!");
  } catch(QString q) {
    QCOMPARE( q, QString("N > 0"));
  }

```

Квадратное уравнение
TDD - Test Driven Development
``` cpp
  SquareEq a;
  Roots roots = a.quadraticEquation(1, 0, 0);

  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], 0.0);

  roots = a.quadraticEquation(4, 0, 0);
  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], 0.0);

  roots = a.quadraticEquation(1, 0, -1);
  QCOMPARE(roots.numberOfRoots, 2);
  QCOMPARE(roots.x[0], 1.0);
  QCOMPARE(roots.x[1], -1.0);

  roots = a.quadraticEquation(1, 0, 1);
  QCOMPARE(roots.numberOfRoots, 0);

  roots = a.quadraticEquation(0, 1, 1);
  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], -1.0);

  roots = a.quadraticEquation(0, 0, 1);
  QCOMPARE(roots.numberOfRoots, 0);

  roots = a.quadraticEquation(0, 2, 1);
  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], -0.5);
  QCOMPARE(a.calc(0, 2, 1, roots.x[0]), 0.0);

  // 0*x*x + 0*x + 0 = 0
  try {
    a.quadraticEquation(0, 0, 0);
    QFAIL("Exception expected!");
  } catch(QString q) {
    QCOMPARE( q, QString("Бесконечное число решений"));
  }

```

Число в строку
[alltests.cpp](alltests.cpp)

Класс, который содержит тесты
Тестирование вычисления максимума
Новый тест для вычисления факториала
Тест для квадратного уравнения
Число в строку до 100
Число в строку от 100 до 199
Число в строку от 200 до 999
Число в строку от 1000 до 999999
Тестирование функции суммирования
[alltests.h](alltests.h)

Сумма: a + b
Факториал
Численное интегрирование
Метод трапеций

[functions.cpp](functions.cpp)

Сумма: a + b = c
Факториал
function - указатель на функцию возвращающую 1
Численное интегрирование
Метод трапеций
[functions.h](functions.h)

Константная функция
Константная функция
y = x   0..1  -> 0.5
y = x^2  x^3/3   0..1  -> 1/3
[integraltest.cpp](integraltest.cpp)

Тестирование интегрирования константной функции
[integraltest.h](integraltest.h)

#define DEBUG1
Число в строку
Обрезаем лишние пробелы в начале и конце
Первая буква в верхнем регистре
[inttostr.cpp](inttostr.cpp)

Модуль с функцией для тестирования
Целое число N в строку
[inttostr.h](inttostr.h)

Подключаем модульные тесты
Вывод числа в строку
Выведем все числа в файл (чтобы посмотреть на них вручную)
freopen("testing.txt", "w", stdout);
QTest::qExec(new SimpleTests());
QTest::qExec(new AllTests, argc, argv);
writeNumbersToFile();
[main.cpp](main.cpp)

return 10;
[myclass.cpp](myclass.cpp)

Тестируемый класс
Вычисление максимума
Вычисление минимума
[myclass.h](myclass.h)

И
QCOMPARE(2 * 2 + 1, 4);
[simpletests.cpp](simpletests.cpp)

Вызывается при инициализации
всех тестов
[simpletests.h](simpletests.h)

Генерируем исключение
Нет решений
Линейное уравнение
Квадратное уравнение
[squareeq.cpp](squareeq.cpp)

Корни квадратного уравнения
Решение квадратного уравнения
[squareeq.h](squareeq.h)

