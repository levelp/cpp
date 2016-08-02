#include <QCoreApplication>

#include <iostream> // cin/cout

#include <vector> // Контейнер vector
#include <set> // Контейнер множество
#include <map> // Контейнер map

using namespace std;

template<class T>
void countElements(T v) {
  // Подсчитать количество одинаковых элементов
  // Вывести в виде Значение элемента -> Количество
  map<typename T::value_type, int> m; // Количество элементов с заданным значением

  // Пробежим по всем значениям в векторе
  for(typename T::iterator i = v.begin();
      i != v.end(); i++) {
    // Если такого значения ещё нет, добавим в m значение 1
    if(!m.count(*i))
      m.insert(make_pair(*i, 1));
    else {
      // Если есть, то увеличим на 1
      m[*i]++;
    }
  }

  // Выведем набор Ключ => Значение
  for(typename map<typename T::value_type, int>::iterator
      i = m.begin(); i != m.end(); i++)
    cout << i->first << " -> " << i->second << endl;
}

typedef map<char, int> myMap;

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  setlocale(LC_ALL, "Russian");

  // map - словарь
  //map<тип_ключа, тип_значения>
  myMap m;
  pair<char, int> pair = make_pair('A', 10);
  m.insert(pair);
  // Вывод отдельной пары
  // cout << pair.first << " " << pair.second << endl;

  //m.insert('D', 30);
  m['E'] = 35;
  cout << "m['A'] = " << m['A'] << endl;
  m['A'] = 1;
  cout << "m['A'] = " << m['A'] << endl;

  myMap::iterator i;

  for(i = m.begin(); i != m.end(); i++)
    //        Ключ             Значение
    cout << i->first << " " << i->second << endl;

  // Количество вхождений элемента A
  //cout << m.count('A') << endl;
  // Удаляем элемент
  //m.erase('A');
  //cout << m.count('A') << endl;
  vector<string> v;
  v.push_back(string("Test"));
  v.push_back(string("Test"));
  v.push_back(string("A"));
  v.push_back(string("B"));
  v.push_back(string("A"));
  v.push_back(string("A"));

  countElements(v);

  vector<int> vv(10, 5);
  vv.push_back(143);
  vv.push_back(1);
  vv.push_back(1);
  countElements(vv);

  return a.exec();
}
