﻿Модульное тестирование в Qt
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

