#ifndef TEST_SMART_H
#define TEST_SMART_H

#include <QObject>
#include <QString>

// Класс, который содержит тесты
class AllTests : public QObject {
  Q_OBJECT
 public:
  explicit AllTests(QObject* parent = 0);

 private slots: // должны быть приватными
  // Тестирование вычисления максимума
  void max();

  // Новый тест для вычисления факториала
  void factorial();

  // Тест для квадратного уравнения
  void rootsTest();

  // Число в строку до 100
  void intToStrBefore100();

  // Число в строку от 100 до 199
  void intToStr_100_to_199();

  // Число в строку от 200 до 999
  void intToStr_200_to_999();

  // Число в строку от 1000 до 999999
  void intToStr_1000_to_999999();

  // Тестирование функции суммирования
  void testSum();
};

#endif // TEST_SMART_H
