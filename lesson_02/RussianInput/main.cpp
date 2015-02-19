#include <iostream>
#include <fstream>
#include <locale.h>
#include <windows.h>

using namespace std;

int main() {
  setlocale(LC_ALL, "");

  char src[200];
  char dst[200];

  ofstream of("text.txt");

  cout << "Введите предложение по-русски: ";
  cin >> src;
  OemToAnsi(src, dst);
  cout << "Это же предложение: " << dst << endl;
  of << "Это же предложение: " << dst << endl;

  of.close();

  return 0;
}
