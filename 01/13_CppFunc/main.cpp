#include <iostream>

using namespace std;

int min(int a, int b) {
  cout << "int" << endl;
  return (a < b) ? a : b;

  if (a < b)
    return a;
  else
    return b;
}

double min(double a, double b) {
  cout << "double" << endl;
  return (a < b) ? a : b;
}

int main() {
  cout << min(2, 3) << endl;
  cout << min(2.2, 4.) << endl;
  return 0;
}
