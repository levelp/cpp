// Работа с this
// -------------
#include <iostream>

using namespace std;

//-->
class Boy;

class Girl {
 public:
  Boy* boy;
  void reg(Boy* b) {
    boy = b;
  }
  void answer();
};

class Boy {
 public:
  Girl* girl;
  //Girl* g;
  void reg(Girl* g) {
    // this->g = g;
    girl = g;
    girl->reg(this);
  }
  void dialog() {
    cout << "Boy: hi!" << endl;
    girl->answer();
  }
  void answer() {
    cout << "Boy: I'm find! And how are you?" << endl;
  }
};

void Girl::answer() {
  cout << "Girl: Hi! How are you?" << endl;
  boy->answer();
}


int main() {
  Girl g;
  Boy b;
  b.reg(&g);

  b.dialog();

  return 0;
}
//<--
