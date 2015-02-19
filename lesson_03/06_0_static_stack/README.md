Виды памяти
-----------
``` cpp
int data[100000000]; // Статическая память

void f(int N) { // Стек
  //int localArray[100];
  printf("f(%d)\n", N);
  f(N + 1);
}

int main() {
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

  return 0;
}
```

[main.c](main.c)

