#include <QCoreApplication>
#include <iostream>
#include <fstream> // Работа с файлами

using namespace std;

int main(int argc, char* argv[]) {
  ifstream in("input.txt");
  int a, b;
  in >> a >> b;
  cout << a << " + " << b << " = " << (a + b) << endl;
  in.close();

  // Открыть файл для записи
  ofstream f("output.txt");
  // Вывод как в cout
  f << "2 * 3 = " << (2 * 3) << endl;

  for(int i = 1; i <= 9; ++i)
    f << i << "^2 = " << (i * i) << endl;

  // Закрыть файл
  f.close();

  return 0;
}
