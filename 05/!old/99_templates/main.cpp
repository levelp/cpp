#include <iostream>
#include <string>

int min(int a, int b) {
  return (a < b) ? a : b;
}

double min(double a, double b) {
  return (a < b) ? a : b;
}

string min(string a, string b) {
  return (a < b) ? a : b;
}

//template <class X>
template <typename X> // class, typename
X min(X a, X b) {
  return (a < b) ? a : b;
}

template <class T, typename Q, int size>
T min(T a, Q b) {
  return (a < b) ? a : b;
}

using namespace std;

int main() {
  cout << "Hello world!" << endl;
  return 0;
}
