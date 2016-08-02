#include <iostream>

#define X(t) cout << "sizeof(" << #t << ") = " << sizeof(t) << endl;

using namespace std;

struct Point {
  int x, y;
};

struct OneChar {
  char a; // 1 байт
};

struct TwoChars { // 2 байта
  char a;
  char b;
};

struct Chars3 {
  char a;
  char b;
  char c;
};

struct OnePointer {
  OneChar* pointer; // 4 байта
};

struct OnePointerChar {
  OneChar* pointer;
  char c;
};

struct TwoPointer {
  OneChar* pointer;
  char c;
  OneChar* pointer2;
};

// Плотная упаковка - без выравнивания
#pragma pack(push, 1) // exact fit - no padding
struct TwoPointerPacked {
  OneChar* pointer;
  char c;
  OneChar* pointer2;
}; // __attribute__((packed));
#pragma pack(pop)

int main() {
  int i = 1;
  X(i);
  X(char);
  X(short);
  X(int);
  X(long long);
  X(float);
  X(double);
  X(long double);
  X(char[10]);
  X(int*)
  X(int[10][20]);
  X(Point);
  X(OneChar);
  X(TwoChars);
  X(Chars3);
  X(OnePointer);
  X(OnePointerChar);
  X(TwoPointer);
  X(TwoPointerPacked);

  return 0;
}
