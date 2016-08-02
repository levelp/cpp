/// Задача на использование vector
/// ==============================
/// Пользователь вводит числа с клавиатуры
/// Когда он вводит 0, выводим сумму и все элементы
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  int x; // Очередное значение
  int sum = 0; // Сумма

  do {
    // Вводим очередное значение
    cout << "x = ";
    cin >> x;

    // Если не равно 0
    if(x != 0) {
      // Добавляем в вектор
      v.push_back(x);
      // Добавляем к сумме
      sum += x;
    }
  } while(x != 0);

  cout << "sum = " << sum << endl;

  for(int i = 0; i < v.size(); i++)
    cout << "v[" << i << "] = " << v[i] << endl;

  return 0;
}
