/// STL - Standart Template Library
/// ===============================
/// Контейнеры:
/// * vector - вектор (аналог массива)
/// * set - множество
/// * map - ассоциативный массив
/// * stack - стек
/// * queue - очередь

/// Методы:
///  * Конструктор (без параметров / размер / размер и заполнение)
///  * push_back(..) - добавление в конец
///  * insert(..) - вставка в произвольное место
///  * erase(..) - удаление
///  * clear() - очистить всё
///  * begin() - указатель (итератор) на первый элемент
///  * front() - первый элемент
///  * end() - указатель (итератор) на последний элемент
///  * back() - последний элемент
///  * size() - количество элементов
///  * var[index] - работа с элементом с индексом index

#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // sort - сортировка массива или коллекции (контейнера)

#include <locale.h>

#define SHOW(x) { cout << #x << " = " << x << endl; };

using namespace std;

template <class T>
void show(T cont) { // cont - контейнер
  int i = 0;
  for(typename T::iterator k = a.begin();
      k != a.end();
      k++)
    cout << (++i) << ". " << *k << endl;;
}

int main() {
  //setlocale(LC_ALL, "Russian");
  /// Вектор (vector) - аналог массива
  //-->
  vector<int> ints; // Пустой вектор целых чисел
  vector<int> ints2(10); // Вектор из 10 целых чисел
  vector<int> ints3(10, 0); // 10 целых, заполнить нулями

  // Добавление в конец vector'а
  for(int i = 0; i < 5; i++)
    ints.push_back(i);

  // Изменяем элемент с заданным индексом
  ints[0] = 10;
  //<--

  for(int i = 0; i < ints.size(); i++)
    cout << "ints[" << i << "] = " << ints[i] << endl;

  ints.insert(ints.begin() + 2, 222);

  for(int i = 0; i < ints.size(); i++)
    cout << "ints[" << i << "] = " << ints[i] << endl;

  sort(ints.begin(), ints.end());

  cout << "SORTED" << endl;

  for(int i = 0; i < ints.size(); i++)
    cout << "ints[" << i << "] = " << ints[i] << endl;

  // Удалить элемент вектора
  ints.erase(ints.begin()); // Удаление первого элемента
  //ints.erase(ints.begin() + 1); // Удаление 2-ого элемента
  //ints.erase(ints.begin() + index); // Удаление заданного элемента

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
  // Изначало в векторе 2 элемента
  vector<int> a(2, 1); // { 1, 1 }
  // теперь будем добавлять по элементу в вектор
  // наблюдая сколько памяти он реально занимает


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
