#include <stdio.h> /* Подключаем библиотеку */
#include <clocale>
#include <locale.h>

int main() {
  setlocale(LC_ALL, "Russian");
  printf("C: Привет мир!\n");
  return 0;
}