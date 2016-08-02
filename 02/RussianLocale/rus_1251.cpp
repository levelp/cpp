#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  cout << "Привет, мир!" << endl;
  return 0;
}
