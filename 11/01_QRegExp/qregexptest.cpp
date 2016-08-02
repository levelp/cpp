#include <QtTest/QTest>
#include "qregexptest.h"

QRegExpTest::QRegExpTest(QObject* parent) :
  QObject(parent) {
}

// Символы
void QRegExpTest::symbols() {
  QRegExp rx("\\s"); // Любой пробельный символ
  // Поиск подстроки
  QCOMPARE(rx.indexIn("a "), 1);
  QCOMPARE(rx.indexIn("ab\n"), 2); // Перевод строки
  QCOMPARE(rx.indexIn("abcd\tsdf"), 4); // Табуляция
  QCOMPARE(rx.indexIn("This_is_test "), 12);

  QCOMPARE(QString(" "), rx.cap(0));

  // Выделяем цифры из строки
  QRegExp digits("\\d+");
  QCOMPARE(digits.indexIn("  344   23 67 "), 2);
  QCOMPARE(digits.cap(0), QString("344"));
  QCOMPARE(digits.cap(1), QString(""));

  // c  - с помощью регулярных выражений можно искать обычные подстроки
  // \c A character that follows a backslash matches the character itself, except as specified below. e.g., To match a literal caret at the beginning of a string, write \^.
  // \a Matches the ASCII bell (BEL, 0x07).
  QCOMPARE(QRegExp("\\a").exactMatch("\a"), true);
  // \f Matches the ASCII form feed (FF, 0x0C).
  QCOMPARE(QRegExp("\\f").exactMatch("\f"), true);
  // \n Matches the ASCII line feed (LF, 0x0A, Unix newline).
  QCOMPARE(QRegExp("\\n").exactMatch("\n"), true);
  // ASCII 10 - Начало строки
  QCOMPARE(QRegExp("\\0012").exactMatch("\n"), true);
  // \r Matches the ASCII carriage return (CR, 0x0D).
  QCOMPARE(QRegExp("\\r").exactMatch("\r"), true);
  // \t Matches the ASCII horizontal tab (HT, 0x09).
  QCOMPARE(QRegExp("\\t").exactMatch("\t"), true);
  // \v Matches the ASCII vertical tab (VT, 0x0B).
  QCOMPARE(QRegExp("\\v").exactMatch("\v"), true);
  // \xhhhh Matches the Unicode character corresponding to the hexadecimal number hhhh (between 0x0000 and 0xFFFF).
  //QCOMPARE(QRegExp("\\xD0BF").exactMatch("П"), true);
  // \0ooo (i.e., \zero ooo)    matches the ASCII/Latin1 character for the octal number ooo (between 0 and 0377).
  // . (dot)    Matches any character (including newline).
  QCOMPARE(QRegExp(".").exactMatch("a"), true);
  QCOMPARE(QRegExp("c.t").exactMatch("cut"), true);
  QCOMPARE(QRegExp("c.t").exactMatch("cat"), true);

}

// Группы символов
void QRegExpTest::groups() {

}

// Кванторы
void QRegExpTest::quantors() {
  // + - один и больше
  QRegExp rx("\\d+"); // Любое число
  QCOMPARE(rx.indexIn("ab123"), 2);
  QCOMPARE(rx.cap(0), QString("123"));
  // * - ноль и больше

}
