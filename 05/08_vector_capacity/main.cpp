#include <iostream>
#include <vector>

#define SHOW(x) cout << #x << " = " << x << "  ";

using namespace std;

// Изначало в векторе 2 элемента
vector<int> a; //(2, 1); // { 1, 1 }

// Добавляем элемент в вектор a
// смотрим количество элементов size()
// и размер в памяти capacity()
void addNumber(int value) {
  a.push_back(value);
  SHOW(a.size())
  SHOW(a.capacity());
  cout << endl;
}

int main() {
  // Вектор - аналог массива
  cout << "Vector (int) " << endl;
  // теперь будем добавлять по элементу в вектор
  // наблюдая сколько памяти он реально занимает
  for(int i = 1; i <= 10; i++)
    addNumber(i);

  return 0;
}
