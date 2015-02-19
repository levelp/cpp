// Очень странно что переполнение знакового целого с последующим сравнением UB
#include <cstdio>

using namespace std;

int main() {
  int t = 1;

  while (t > 0) {
    t *= 9;
    printf("%d\n", t);
  }

  puts("finished");
}