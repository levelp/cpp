/// Задача: посчитать сколько каких букв в строке
/// =============================================
/// "using namespace std"
/// "u" -> 1
/// "s" -> 3
/// и так далее...

#include <iostream>
#include <map>

using namespace std;

int main() {
  string s = "using namespace std";
  // Ключ имеет тип char
  // Значение имеет тип int
  map<char, int> stat; // Статистика
  for(auto cur = s.begin(); cur != s.end(); cur++) {
    char curChar = *cur; // значение = *итератор;
    // Ищем, есть ли такой символ в нашем map
    auto f = stat.find(curChar);
    // Если нет, то find возвращает конец множества
    // stat.end()
    if(f == stat.end()) {
      // Если нет, то мы записываем новый символ
      // количество равно 1
      stat[curChar] = 1;
    } else {
      // Если есть, то увеличиваем количество для
      // этого символа на 1
      stat[curChar]++;
    }
    // cout << curChar << endl;
  }
  // Выводим весь map
  for(auto p = stat.begin(); p != stat.end(); p++) {
    // Итератор пробегает по всему map
    // при "разыменовании" итератора получаем
    // пару <ключ, значение>
    //      first  second
    pair<char, int> line = *p;
    cout << "\"" << line.first << "\" -> " << line.second << endl;
  }

  return 0;
}
