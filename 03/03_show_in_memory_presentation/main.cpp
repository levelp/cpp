// Исследование как выглядит в памяти значение выбранного типа
#include <iostream>

using namespace std;

// Чтобы синхронно по всей программе менять тип который мы сейчас исследуем
typedef short My;
union InMemory {
  My value; // Исследуемое значение
  // Разложение по байтам. sizeof(My) - размер типа My в байтах
  unsigned char bytes[sizeof(My)];
};
int main() {
  InMemory m;
  m.value = 256 + 11;

  for(int i = 0; i < sizeof(My); ++i) {
    unsigned int byte = m.bytes[i];

    for(int bit = 7; bit >= 0; --bit)
      // >> - побитовый сдвиг вправо
      cout << ((byte >> bit) & 1);

    cout << " " << byte << endl;
  }

  return 0;
}
