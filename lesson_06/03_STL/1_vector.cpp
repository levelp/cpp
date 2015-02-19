#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "common.h"

template <class T>
void show(vector<T> a) {
  for(int i = 0; i < a.size() - 1; ++i)
    cout << a[i] << ", ";

  cout << a[a.size() - 1] << endl;
}

// Вектор - аналог массива
void test_vector() {
  // Массив строк
  string vv[4];
  // Вектор строк
  {
    vector<string> v;
    v.push_back("s1");
    X(v.size(), 1);
    v.push_back("s2");
    X(v.size(), 2);
    v.push_back("s3");
    X(v.size(), 3);
    v.push_back("s4");
    X(v.size(), 4);

    showCollection(v);

    // Удаляем элемент из середины вектора
    v.erase(v.begin() + 2);

    showCollection(v);
  }

  // Второй пример
  {
    vector<int> v = {2, 3, 4};
    show(v);
    v.push_back(6);
    show(v);
    v.erase(v.begin() + 2);
    show(v);

    vector<double> d = {3.4, 22.3, 3.3};
    show(d);
  }
}
