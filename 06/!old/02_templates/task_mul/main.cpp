#include <iostream>
#include <typeinfo>

using namespace std;

// Произведение всех чисел
// в массиве A
//-->
template <typename T>
T mul(T A[], size_t size) {
  if(typeid(T) == typeid(int))
    cout << "int" << endl;

  if(typeid(T) == typeid(double))
    cout << "double" << endl;

  //cout << typeid(T).name() << endl;
  // TODO: реализовать
  T res = 1; // Произведение 1

  for(size_t i = 0; i < size; ++i)
    res *= A[i]; // Умножаем на все последующие

  return res;
}
//<--

int main() {
  int intA[] = {2, 5, 6};
  cout << mul(intA, 3) << endl;

  double doubleA[] = {1.2, 5.1, 6.1};
  cout << mul(doubleA, 3) << endl;

  return 0;
}
