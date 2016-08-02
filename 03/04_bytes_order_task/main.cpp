/// Задание на union - порядок байт в целых типах
/// ---------------------------------------------
#include <iostream>

using namespace std;

typedef int Type;

union Bytes {
  Type value; // Значение целое
  unsigned char bytes[sizeof(Type)]; // По байтам
};

int main() {
  Bytes b;
  b.value = (2 << 8) + 13;

  for(int i = 0; i < sizeof(Type); i++)
    cout << i << " " << (int)b.bytes[i] << endl;

  return 0;
}
