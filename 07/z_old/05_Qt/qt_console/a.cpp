#include <iostream> // cin/cout

#include <vector> // Контейнер vector
#include <set> // Контейнер множество
#include <map> // Контейнер map

using namespace std;

// template<ПАРАМЕТРЫ>
//   class Имя_класса{}
//   Тип_возвращаемого_значения Функция(параметры)

// ПАРАМЕТРЫ:
//    int aa, char A, class T / typename T
//  template<template<int> class X>

template<template<int> class X>
class MyClass {
  //    X
};

template<class T>
void print_vector(vector<T> v) {
  typename vector<T>::iterator i;

  for(i = v.begin(); i != v.end(); i++)
    cout << *i << endl;
}

template<class V> // class V, typename V, int size
void print(const char* title, V v) {
  cout << title << endl;
  int cnt = 0;

  if(v.empty()) {
    cout << "Container is empty" << endl;
    return;
  }

  cout << "size: " << v.size() << endl;

  for(typename V::iterator i = v.begin(); i != v.end(); i++)
    cout << ++cnt << ". " << *i << endl;
}

// Стек на основе массива
template<typename T, int size>
class Stack {
  // По-умолчанию private
  T data[size]; // данные
  int count; // количество элементов
 public:
  Stack() : count(0) {}
  //Stack() { count = 0; }
  // Поместить на вершину стека
  void push(T x) {
    data[count++] = x;
  }
  // Получить значение с вершины стека
  T pop() {
    return data[--count];
  }
};

int main(int argc, char* argv[]) {
  Stack<int, 20> stack;
  stack.push(10);
  cout << stack.pop() << endl;

  setlocale(LC_ALL, "Russian");

  // vector<тип> имя_переменной(количество, начальное_значение)
  vector<int> intVector;      // Пустой (ноль элементов) вектор из элементов типа int
  vector<float> floatVector(10); // Вектор из 10-и элементов типа float
  vector<char> charVector(5, '#'); // Вектор, состоящий из 5-и символов '#'

  // Добавляем в конец вектора
  intVector.push_back(3);
  intVector.push_back(10);
  intVector.push_back(3);

  cout << "Vector size: " << intVector.size() << endl;

  print_vector<int>(intVector);
  print<vector<int> >("intVector:", intVector);
  print<vector<char> >("charVector:", charVector);

  for(unsigned int i = 0; i < intVector.size(); i++)
    cout << intVector[i] << endl;

  // Тип_вектора::iterator
  vector<int>::iterator it;

  for(it = intVector.begin(); it != intVector.end(); it++)
    cout << *it << endl;

  it = intVector.end();

  for(it--; it != intVector.begin(); --it)
    cout << *it << endl;

  cout << *it << endl;

  intVector.clear(); // Удаляются все элементы и вектор снова длины 0
  cout << "capacity: " << intVector.capacity() << endl;

  // Множество
  set<int> intSet;
  // Добавляем элементы
  intSet.insert(1);
  //if(intSet.find(1))
  //    cout << "1 exists" << endl;
  intSet.insert(1);
  intSet.insert(2);
  // Удаляем элемент
  intSet.erase(1);
  intSet.erase(2);
  print<set<int> >("intSet: ", intSet);

  // map - словарь
  //map<тип_ключа, тип_значения>
  map<char, int> m;
  pair<char, int> pair = make_pair<char, int>('A', 10);
  m.insert(pair);
  cout << pair.first << " " << pair.second << endl;

  //m.insert('D', 30);
  m['E'] = 35;

  return 0;
}
