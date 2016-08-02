#include <stdio.h> /* Подключаем библиотеку */
#include <locale.h>
#include <windows.h>

int main() {
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "Russian_Russia.UTF-8");
  printf("C: Привет мир!\n");
  return 0;
}