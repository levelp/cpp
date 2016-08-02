/// Виды памяти: статическая и стек
/// -------------------------------
#include <stdio.h>
#include <stdlib.h>

//-->
// Глобальная переменная
int data[100000000]; // Статическая память

void f(int N) { // Стек
  int localArray[100]; // Весь массив в стеке
  static int staticArray[100]; // Доступен только в f
  // в статической области памяти
  printf("f(%d)\n", N);
  f(N + 1);
}

// переполнение адресами возврата
void empty() {
  empty();
}

int main() {
  //empty();

  int data2[100000]; // Стек
  int i;
  f(1);

  for(i = 0; i < 4000; i++) {
    // Динамическая память
    if(malloc(1000000) == NULL) {
      printf("NULL\n");
      break;
    }

    printf("i = %d\n", i);
  }

  {
    {
      int ii = 10;
    } // переменная ii существует в стеке только до этого момента
    {
      double ii = 1.1;
      double ii2;
    } // double ii удаляется здесь
    // Сначала будет удалена ii2, а потом ii
  }

  return 0;
}
//<--
