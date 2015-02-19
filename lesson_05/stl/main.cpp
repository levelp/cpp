#include <iostream>
#include <vector>
#include <set>

#include <locale.h>

#define SHOW(x) { cout << #x << " = " << x << endl; };

using namespace std;

template <class T>
void show(T a) {
  int i = 0;

  for(typename T::iterator k = a.begin();
      k != a.end();
      k++)
    cout << (++i) << ". " << *k << endl;;
}

int main() {
  setlocale(LC_ALL, "Russian");

  // set - множество (неповторяющиеся элементы)
  cout << "set " << endl;
  set<int> s;
  cout << "s.count(2) = " << s.count(2) << endl;
  s.insert(2);
  cout << "s.count(2) = " << s.count(2) << endl;
  s.insert(2);
  cout << "s.count(2) = " << s.count(2) << endl;
  s.insert(2);
  cout << "s.count(2) = " << s.count(2) << endl;
  s.insert(2); // { 2 }
  cout << "s.count(2) = " << s.count(2) << endl;
  show(s);
  s.insert(20); // { 2, 20 }
  s.insert(3); // { 2, 3, 20 }
  s.erase(3); // { 2, 20 }
  s.erase(2); // { 20 }

  show(s);

  // Вектор - аналог массива
  cout << "Vector (int) " << endl;
  vector<int> a(2, 1); // { 1, 1 }
  cout << "Capacity: " << a.capacity() << "  size: " << a.size() << endl;
  a.push_back(10);
  cout << "Capacity: " << a.capacity() << "  size: " << a.size() << endl;
  a.push_back(23);
  cout << "Capacity: " << a.capacity() << "  size: " << a.size() << endl;
  a.push_back(50);
  cout << "Capacity: " << a.capacity() << "  size: " << a.size() << endl;
  a.push_back(123);
  cout << "Capacity: " << a.capacity() << "  size: " << a.size() << endl;
  cout << "a[0] = " << a[0] << endl;
  a[0] += 10;
  a.insert(a.begin() + 2, 99);

  for(int i = 0; i < a.size(); ++i)
    cout << "a[" << i << "] = " << a[i] << endl;

  show(a);

  SHOW(a[0]);
  SHOW(a[1]);
  SHOW(a[2]);
  SHOW(a[3]);

  a.clear(); // Удалить все значения

  return 0;

  cout << "Первый элемент: " << a.front() << endl;
  cout << "Последний элемент: " << a.back() << endl;

  for(vector<int>::iterator k = a.begin();
      k != a.end();
      k++) {
    cout << *k << endl;

    if(*k == 23) {
      cout << "Нашли число 23: " << *k << endl;
      a.erase(k);
    }
  }

  for(size_t i = 0; i < a.size(); i++)
    cout << "a[" << (i + 1) << "] =  " << a[i] << endl;

  //a.insert(2, 10);
  //a.remove(3);
  a.clear();
  cout << "Добавляем 10 в конец вектора" << endl;
  a.push_back(10);

  show(a);

  return 0;
}
