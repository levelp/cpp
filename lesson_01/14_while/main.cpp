// Цикл while, структуры
// ---------------------
#include <iostream>
using namespace std;

int main() {
  // Вывод на русском языке
  setlocale(LC_ALL, "Russian");
  int i = 0; // инициализируем счетчик цикла
  int sum = 0; // сумма

  while(i < 1000) {
    i++;
    sum += i;
  }

  cout << "Сумма чисел от 1 до 1000 = " << sum << endl;
  return 0;
}

// Структура для хранения адреса
struct addr {
  char name[40];
  char street[40];
  char city[40];
  char state[3];
  char zip[10];
};

struct addr* get_struct(void) {
  struct addr* p;

  if((p = malloc(sizeof(struct addr))) == NULL) {
    printf("Ошибка при распределении памяти\n");
    exit(1);
  }

  return p;
}

#define MAX(a,b) ((a) > (b) ? (a) : (b))

// В стиле C:
Point* p = (Point*) malloc(sizeof(Point));
free(p);

// В стиле C++
Point* p = new Point;
delete p;







