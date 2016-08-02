#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;

int main() {
  SetConsoleCP(65001);
  SetConsoleOutputCP(65001);

  cout << " \x08Привет, мир!" << endl;
  return 0;
}
