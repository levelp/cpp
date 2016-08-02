// Задание: сумма элементов массива
// --------------------------------
// Нумерация элементов массива с 0
// Все элементы на чётных местах взять с "+"
// Все элементы на нечётных местах с "-"
// Чётные: 0, 2, 4, 6 и т.д.
// Нечётные: 1, 3, 5...
#include <iostream>
#include <iomanip>

#define SHOW(x) cout << #x << " = " << x << endl;

using namespace std;

int sum2(int* A, int N/*, int M*/) {
  int s = 0; // Сумма

  for(int i = 0; i < N; ++i) {
    //if((i % 1) == 0)
    if((i & 1) == 0)  // Чётное
      s += A[i];
    else   // Нечётное
      s -= A[i];

    //cout << s << endl;
  }

  return s;
}

//      int A[]
int sum(int* A, int N) {
  int s = 0; // Сумма

  for(int i = 0; i < N; ++i) {
    //if((i % 1) == 0)
    // 101110110
    if((i & 1) == 0)  // Чётное
      s += A[0];
    else   // Нечётное
      s -= *A;

    A++; // Сдвигаю указатель
    //cout << s << endl;
  }

  return s;
}

void showBin(int N) {
  cout << setw(5) << N << " ";

  for(int bit = 7; bit >= 0; --bit)
    cout << ((N >> bit) & 1);

  cout << endl;
}

int main() {
  /*int x = 10;
  showBin(x);
  for(int s = 1; s < 4; s++){
    cout << x << " >> " << s << endl;
    showBin(x >> s);
  }
  for(int s = 1; s < 4; s++){
    // 00000001
    cout << "(" << x << " >> " << s  << ") & 1" << endl;
    showBin((x >> s) & 1);
  } */
  const int N = 6;
  int A[N] = {1, 3, -2, 4, 2, 10};
  // 1 - 3 -2 -4 + 2 -10 = -16
  cout << "sum(A, N) = " << sum(A, N) << endl;
  // Обращение к элементам массива
  // Обращение к 1-ому элементу
  SHOW(A[1]);
  // A - просто указатель, так что можно прибавить 1
  // и обращаться к 0-ому элементу
  SHOW((A + 1)[0]);
  // Можно и, наоборот, переставить слагаемые и добавить
  SHOW((1 + A)[0]);
  SHOW(1[A]);
  SHOW(*(A + 1))
  SHOW(*(1 + A))
  return 0;
}
