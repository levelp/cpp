// Порядок вызова функций
#include <vector>
#include <iostream>

using namespace std;

// Функция для ввода целого числа n
int f() {
  int n;
  cin >> n;
  return n;
}

int main() {
  // В каком порядке будут выведены числа?
  cout << f() << " " << f() << endl;
  return 0;
}