// Применение модификатора const в ООП
#include <iostream>

using namespace std;

template <typename T, int n>
class Array {
  T a_[n];
 public:
  Array() {
    for(int i = 0; i < n; i++)
      a_[i] = i + 1;
  }
  T& operator[](int i) {
    return a_[i];
  }
  // Метод не модифицирует состояние объекта
  const T& operator[](int i) const {
    return a_[i];
  }
};


int main() {
  const Array<int, 3> a;
  const int& b = a[0];
  return 0;
}
