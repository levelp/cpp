#include <iostream>

using namespace std;

int N; // Количество пар скобок

char s[100] = {0}; // Строчка со скобками

// Рекурсивная функция
// Уже поставлено:
//   o - открывающих  с - закрывающих
// Всего надо поставить N откр и N закр
void f(int o, int c) {
  //while(o <= N && c <= N) {
  if(o > c) {
    s[o + c] = ')';
    f(o, c + 1);
  }

  if(o < N) {
    s[o + c] = '(';
    f(o + 1, c);
  }

  if(o == N && c == N) cout << s << endl;

  return;

  //};
}

int main() {
  cout << "Unsigned integer N = ";
  cin >> N;
  f(0, 0);
  return 0;
}
