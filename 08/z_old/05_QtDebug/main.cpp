#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <assert.h>
#include <cassert>
#include <QtGui>

using namespace std;

long long fact(int N) {
  if(N == 1)
    return 1;
  else
    return N * fact(N - 1);
}

int main(int argc, char* argv[]) {
  // Перенаправляем все сообщения
  // которые программа выводит в текстовую
  // консоль в файл
  // freopen("stdout.txt", "w", stdout);
  // freopen("stderr.txt", "w", stderr);

  assert(fact(1) == 1);
  assert(fact(2) == 2);
  assert(fact(3) == 6);
  assert(fact(4) == 1 * 2 * 3 * 4);

  cout << "Test" << endl;
  qDebug() << fact(10);

  int i = 1;
  cout << "i = " << i << endl;
  cout << "Увеличиваем i" << endl;
  i++;
  int j = i + 2;

  //system("pause");
  return 0;
}
