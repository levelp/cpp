<!-- doc.py -->
Вектор - аналог массива
Массив строк
Вектор строк
Удаляем элемент из середины вектора
Второй пример
[1_vector.cpp](1_vector.cpp)

Итератор по буквам строки
-------------------------
map - ассоциативный массив
ключ - как индекс в массиве
size_t -
Итератор в строке пробегает по буквам
с первой буквы до последней по одной
Очередная буква строки
Не нашли букву => она первый раз
[6_map_count_chars.cpp](6_map_count_chars.cpp)

``` cpp
void dict() {
  // Контейнеры:
  //   vector
  //   set
  //   map
  setlocale(LC_ALL, "Russian");

  // Ассоциативный массив
  // A["Hi"] = "Привет";
  // map<key, value>
  map<string, string> dict;

  // dict[3] = 4;
  // dict[3] = 5;

  dict["Привет"] = "Hi";
  dict["Я"] = "I";

  dict["Ты"] = "You";
  cout << dict["Ты"] << endl;

  dict["Ты2"] = "You2";
  cout << dict["Ты"] << endl;

  map<MyClass, string> mm;
  MyClass m;
  mm[m] = "Test";
}
```

[7_map_dict.cpp](7_map_dict.cpp)

Задача "сортировка строк"
-------------------------
Ввести из файла **in.txt** количество строк N
Ввести из файла N строк
Отсортировать и вывести в файл **out.txt**
``` cpp
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
```

[8_sort_strings.cpp](8_sort_strings.cpp)

sort algorithm example
using default comparison (operator <):
myvector.size()
using function as comp
Сортировка в обратном порядке
using object as comp
print out content:
[9_sort_my_comparator.cpp](9_sort_my_comparator.cpp)

``` cpp
#define SHOW(x) cout << #x << " = " << x << endl;
#define X(a,b) ((a == b) ? (void)0 : _assert(#a" != "#b, __FILE__, __LINE__))
```

``` cpp
template <class T>
void showCollection(T v) {
  for(size_t i = 0; i < v.size(); ++i)
    cout << v[i] << " ";

  cout << endl;
}
```

[common.h](common.h)

