#ifndef SIMPLETESTS_H
#define SIMPLETESTS_H

#include <QObject>

class SimpleTests : public QObject {
  Q_OBJECT
 public:
  explicit SimpleTests(QObject* parent = 0);

 private slots:
  void initTestCase();

  void integerOperations();

};

#endif // SIMPLETESTS_H
