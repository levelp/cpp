#include "inttostr.h"
#include <QDebug>

//#define DEBUG1

// Число в строку
QString intToStr(int N) {
#ifdef DEBUG1
  int originN = N;
#endif
  QString res("");

  if(N == 0)
    res = "ноль";

  QString digits[20] = {
    "", "один", "два", "три",
    "четыре", "пять", "шесть", "семь",
    "восемь", "девять", "десять",
    "одиннадцать", "двенадцать",
    "тринадцать", "четырнадцать",
    "пятнадцать", "шестнадцать", "семьнадцать",
    "восемьнадцать", "девятьнадцать",
  };
  QString dec[10] = {
    "", "", "двадцать", "тридцать",
    "сорок", "пятьдесят", "шестьдесят",
    "семьдесят", "восемьдесят",
    "девяносто"
  };
  QString hundreds[10] = {
    "", "сто", "двести", "триста", "четыреста", "пятьсот",
    "шестьсот", "семьсот", "восемьсот", "девятьсот",
  };

  bool thExists = false;
  int th = 0;

  if(N >= 100000) {
    int hund_th = N / 100000;
    res += " " + hundreds[hund_th];
    N %= 100000;
    thExists = true;
  }

  if(N >= 20000) {
    int dec_th = N / 10000;
    res += " " + dec[dec_th];
    N %= 10000;

    th = N / 1000;
    thExists = true;
  }

  if(N >= 1000) {
    th = N / 1000;

    switch (th) {
      case 1:
        res += " одна";
        break;

      case 2:
        res += " две";
        break;

      default:
        res += " " + digits[th];
        break;
    }

    thExists = true;
    N %= 1000;
  }

  if(thExists) {
    switch (th) {
      case 1:
        res += " тысяча";
        break;

      case 2:
      case 3:
      case 4:
        res += " тысячи";
        break;

      default:
        res += " тысяч";
        break;
    }
  }

  if(N >= 100) {
    res += " " + hundreds[N / 100];
    N %= 100;
  }

  if(N >= 20) {
    res += " " + dec[N / 10];
    N %= 10;
  }

  res += " " + digits[N];

  // Обрезаем лишние пробелы в начале и конце
  res = res.trimmed();
  // Первая буква в верхнем регистре
  res[0] = res.at(0).toUpper();
#ifdef DEBUG1
  qDebug() << originN << " -> " << res;
#endif
  return res;
}

