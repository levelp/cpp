#include <iostream>

using namespace std;

union Bits {
  unsigned char byte; // Байт
  struct byBits { // Байт по битам
    unsigned char b0 : 1, b1 : 1,
             b2 : 1, b3 : 1,
             last4bits : 4; // 4 бита в одном поле
  };
};

typedef double My;

union InMemory {
  My value;
  unsigned char bytes[sizeof(My)];
};

// & - AND - И         логические &&
// | - OR - ИЛИ                   ||
// ~ - NOT - НЕ                   !
// ^ - XOR
// >> - сдвиг вправо   1011011 -> 0010110
// << - сдвиг влево
int main() {
  InMemory m; // union
  m.value = 5; // value нашего типа My
  m.value = 256 + 11;
  // Программа показывает как выглядит число на данной платформе

  for(int i = 0; i < sizeof(My); ++i) {
    //
    unsigned int byte = m.bytes[i];

    // Печатаем байт по битам
    for(int bit = 7; bit >= 0; --bit)
      cout << ((byte >> bit) & 1);

    cout << " " << byte << endl;
  }

  // TODO: написать про работу с signed и unsigned
  //cout << () << endl;

  return 0;
}
