// Объявление переменных. Основные типы данных: целочисленные (модификаторы знаковый/беззнаковый), вещественные (с плавающей точкой), логический тип, символы, строки
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Примитивные типы данных в C/C++
#include <stdio.h> // printf
#include <iostream>
#include <climits>  // В C - limits.h
// limits.h - заголовочный файл стандартной библиотеки общего назначения,
// который включает определения характеристик общих типов переменных.
#include <cfloat> // Аналог climits для действительных чисел

using namespace std;

#define show(x) cout << #x << " = " << x << "   ";

void ints() {
  // ЦЕЛЫЕ ЧИСЛА
  // -----------

  // Дополнительный код:
  // * 000 - 0
  // * 001 - 1
  // * 010 - 2
  // * 011 - 3
  // * 100 - 4  @ -4
  // * 101 - 5  @ -3
  // * 110 - 6  @ -2
  // * 111 - 7  @ -1 => -1
  // *   1 + -1 = 0
  // * 01 + 11 = 100
  // https://ru.wikipedia.org/wiki/%D0%94%D0%BE%D0%BF%D0%BE%D0%BB%D0%BD%D0%B8%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D1%8B%D0%B9_%D0%BA%D0%BE%D0%B4_(%D0%BF%D1%80%D0%B5%D0%B4%D1%81%D1%82%D0%B0%D0%B2%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5_%D1%87%D0%B8%D1%81%D0%BB%D0%B0)

  // *char* 1 байт = 8 бит
  cout << "sizeof(char) = " << sizeof(char) <<
       "  0.." << UCHAR_MAX <<
       "  " << SCHAR_MIN << ".." << SCHAR_MAX << endl;
  // U - unsigned - беззнаковые типы
  // S - signed - знаковые типы
  char c = 'a';
  char c1 = 97;
  cout << "c = " << c << "  c1 = " << (int)c1 << " ";
  signed char sc = 'a' + 1;
  cout << "   sc = 'a' + 1 = " << sc;
  unsigned char uc = 'b' - 1;
  cout << "   uc = 'b' - 1 = " << uc << endl;

  (CHAR_MAX == UCHAR_MAX) ? printf("This compiler uses unsigned char by default\n") :
  printf("This compiler uses signed char by default\n");
  //cout << end;

  // 2 байта = 16 бит
  cout << "sizeof(short) = " << sizeof(short) <<
       "  0.." << USHRT_MAX <<
       "  " << SHRT_MIN << ".." << SHRT_MAX << endl;
  short s = 12321;
  signed short ss = s + 121;
  unsigned short us = -1;
  cout << "s = " << s << "   ss = " << ss << "   us = " << us << endl;
  cout << endl;

  // 4 байта = 32 бита
  cout << "sizeof(int) = " << sizeof(int) <<
       "  0.." << UINT_MAX <<
       "  " << INT_MIN << ".." << INT_MAX << endl;
  int i = 0xFFFF; // В шестнадцатеричной системе счисления
  // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F
  cout << "i = 0xFFFF = " << i << "  ";
  signed int si = 010; // Восьмеричная система счисления
  // Двоичных констант в C/C++ нет
  cout << "si = 010 = " << si << "  ";
  unsigned int ui = -1;
  cout << "ui = -1 = " << ui << endl; //4294967295
  cout << endl;

  // 4 байта для 32-битной и 8 байт для 64-битной
  cout << "sizeof(long) = " << sizeof(long) <<
       "  0.." << ULONG_MAX <<
       "  " << LONG_MIN << ".." << LONG_MAX << endl;
  long l = 12321;
  signed long sl = 1234567890L; // L
  unsigned long ul = 1234567890UL; // UL
  cout << "l = " << l << "  sl = " << sl << "  ul = " << ul << endl;
  cout << endl;

  // Microsoft C++
  // В GNU C++ для совместимости:
  //   #define __int64 long long
  cout << "sizeof(__int64) = " << sizeof(__int64) << "   ";
  __int64 ll1 = 2147483647LL + 1;// 123456789012345678LL; // LL
  signed __int64 sll1 = 121;
  unsigned __int64 ull1 = 121;
  cout << "ll1 = " << ll1 << " " << sll1 << " " << ull1;
  cout << endl << endl;

  cout << "sizeof(long long) = " << sizeof(long long) << endl <<
       "  0.." << ULLONG_MAX <<
       "  " << LLONG_MIN << ".." << LLONG_MAX << endl;
  long long ll = 12321;
  signed long long sll = 1231 + 2 * 4121;
  unsigned long long ull = 12345678901234567890ULL; // ULL
  cout << "ll = " << ll << "  sll = " << sll << "  ull = " << ull << endl;
  cout << endl;
}

// Вещественные/действительные (с плавающей точкой)
// ------------------------------------------------
void floats() {
  // === Действительные числа ===
  show(2 + 2);
  show(sizeof(float));
  // 0.10101111111 * 2^(101110101)
  cout << "sizeof(float)" << " = " << sizeof(float) << "   ";
  show(FLT_MIN);
  show(FLT_MAX);
  cout << endl;
  float f = 0.1f;
  show(f);
  cout << endl;

  double d = 1.1;
  show(sizeof(double));
  show(d);
  cout << endl;
  show(DBL_MIN);
  show(DBL_MAX);
  show(DBL_EPSILON);
  cout << endl << endl;

  long double ld = 1.2;
  show(sizeof(long double));
  show(ld);
  cout << endl;
  show(LDBL_MIN);
  show(LDBL_MAX);
  show(LDBL_EPSILON);
}

// Логический тип, символы, строки
// -------------------------------
void chars() {
  char c = 'A';
  unsigned char b = 'B';
}

int main() {
  //  setlocale(LC_ALL, "Russian");
  ints();

  floats();

  return 0;
}
