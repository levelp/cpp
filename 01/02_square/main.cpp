#include <iostream>

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");

  double d;
  cout << "Введите число: ";
  cin >> d;

  cout << d << " ^ 2 = " << d* d << endl;
  return 0;
}
