#include <iostream>

using namespace std;

typedef double MyType;

union Bits {
  unsigned char byte;
  struct byBits {
    unsigned char b1 : 1, b2 : 1;
  };
};

union InMemory {
  MyType value;
  unsigned char bytes[sizeof(MyType)];
};

int main() {
  InMemory m;
  m.value = 256 + 11;

  for(int i = 0; i < sizeof(MyType); ++i) {
    int byte = m.bytes[i];

    for(int bit = 7; bit >= 0; --bit)
      cout << ((byte >> bit) & 1);

    cout << " " << byte << endl;
  }

  return 0;
}
