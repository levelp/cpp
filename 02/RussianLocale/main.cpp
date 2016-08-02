#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;

int main() {
  //   SetConsoleOutputCP(65001);
  //  SetConsoleCP(65001);

  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  //  setlocale(LC_ALL, "Russian.UTF-8");


  cout << "Привет, мир!" << endl;
  return 0;
}
