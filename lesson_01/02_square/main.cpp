#include <iostream>

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");

  double d;
  cout << "Введите число: ";
  cin >> d;

  cout << d << " в квадрате равно " << d* d << endl;
  return 0;
}
