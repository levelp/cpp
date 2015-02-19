/// Задача "сортировка строк"
/// -------------------------
/// Ввести из файла **in.txt** количество строк N
/// Ввести из файла N строк
/// Отсортировать и вывести в файл **out.txt**
#include <iostream>
#include <fstream>
#include <algorithm> // sort
#include <vector> // vector
#include <string> // string

using namespace std;

void sort_strings() {
  ///-->
  // Вектор для хранения строк
  vector<string> strings;
  // Открываем входной файл
  ifstream in("in.txt");

  // Считываем сами строки
  // in.eof() in.good() - до конца файла
  while(!in.eof()) {
    string s;
    getline(in, s);

    if(in.eof())
      break;

    strings.push_back(s);
    cout << s << endl;
  }

  // Сортируем
  sort(strings.begin(), strings.end());

  // Открываем файл для вывода
  ofstream out("out.txt");

  // Выводим строки
  /*for(int i = 0; i < strings.size(); ++i)
    out << strings[i] << endl; */

  for(vector<string>::iterator
      i = strings.begin();
      i != strings.end();
      ++i )
    out << *i << endl;

  // Закрываем файл
  out.close();
  //<--
}

