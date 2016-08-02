#include <iostream>

using namespace std;

class Girl; // Объявили, что будет класс Girl

class Boy {
 public:
  Girl* link;
  void meet(Girl& girl);
  void hi() {
    cout << "Boy: Hi! " << endl;
  }
  void bye() {
    cout << "Boy: Bye!" << endl;
  }
};

class Girl {
 public:
  Boy* link;
  void hi() {
    cout << "Girl: Hi! How are you? " << endl;
  }
  void meet(Boy& boy) {
    link = &boy;
    hi();
    link->bye();
  }
};

void Boy::meet(Girl& girl) {
  link = &girl;
  hi();
  girl.meet(*this);
}

int main() {
  Boy b;
  Girl g;
  b.meet(g);

  return 0;
}
