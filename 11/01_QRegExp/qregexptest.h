#ifndef QREGEXPTEST_H
#define QREGEXPTEST_H

#include <QObject>
#include <QString>

// Тестирование стандартных выражений QRegExp (PCRE - Perl Comp Reg Exp)
class QRegExpTest : public QObject {
  Q_OBJECT
 public:
  explicit QRegExpTest(QObject* parent = 0);

 private slots: // Тесты - слоты, которые должны быть приватными
  // Символы
  void symbols();

  // Группы символов
  void groups();

  // Кванторы
  void quantors();
};

#endif // QREGEXPTEST_H
