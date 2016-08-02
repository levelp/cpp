/// Значение / ссылка / указатель
/// -----------------------------
/// * **__FUNCTION__** - имя текущей функции
/// * **__FILE__** - имя текущего файла
/// * **__LINE__** - номер текущей строки
#include <iostream>

using namespace std;

/// Усовершенствованный макрос **SHOW**
//-->
#define SHOW(x) cout << __FUNCTION__ << ":" << \
                     __LINE__ << " " << #x << " = " << x << endl;
//<--

// Передача параметров в функции
//-->
// По значению
void f1(int i) {
  SHOW(i)
  i++; // i - это уже другая переменная
  // значение копируется из внешней i
  // i - локальная переменная
  SHOW(i) // i = 1
}

int globalVar = 10;

// По ссылке (только C++)
void f2(int& i) {
  // У i тот же адрес, что и у j
  cout << "i - alias for j" << endl;
  SHOW(i)
  i++;
  SHOW(i)
  // i = &globalVar;
}

// По указателю
void f3(int* i) {
  (*i)++;
  SHOW(*i)
  i = &globalVar;
}

int main() {
  int j = 0; // i или j не имеет значения
  SHOW(j); // j = 0

  f1(j);
  SHOW(j); // j = 0

  f2(j);
  SHOW(j); // j = 1

  f3(&j);
  SHOW(j);

  return 0;
}
//<--
