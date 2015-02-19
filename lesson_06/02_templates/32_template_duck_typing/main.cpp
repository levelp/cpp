// Утиная типизация - Duck Typing
// ------------------------------
#include <iostream>

using namespace std;

template <class T>
void utka(T t) {
  cout << "Before Krya" << endl;
  t.Krya(); // Метод "Кря"
  cout << "After Krya" << endl;
}

template <class T>
void sobaka(T t) {
  cout << "Before Gav" << endl;
  t.Gav(); // Метод "Гав"
  //t.VilyaletHvostom(); // Виляет хвостом
  cout << "After Gav" << endl;
}

struct A {
  void Krya() {
    cout << "A: Krya!" << endl;
  }
};

struct B {
  void Gav() {
    cout << "B: Gav!" << endl;
  }
};

struct C {
  void Krya() {
    cout << "C: Krya!" << endl;
  }
  void Gav() {
    cout << "C: Gav!" << endl;
  }
};

int main() {
  A a;
  utka(a);
  B b;
  sobaka(b);

  C c;
  utka(c);
  sobaka(c);

  return 0;
}
