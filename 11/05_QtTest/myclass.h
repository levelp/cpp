#ifndef SMART_H
#define SMART_H

#include <QObject>

// Тестируемый класс
class MyClass : public QObject {
  Q_OBJECT
 public:
  explicit MyClass(QObject* parent);

 public slots:
  // Вычисление максимума
  int max(int a, int b);
  // Вычисление минимума
  int min(int a, int b);
};
#endif
