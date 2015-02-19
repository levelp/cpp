/// Итератор по буквам строки
/// -------------------------
#include <iostream>
#include <map>

#define SHOW(x) { cout << #x << " = " << x << endl; }

using namespace std;

int map_count_chars() {
  string s = "Hello world!";

  // map - ассоциативный массив
  //  ключ - как индекс в массиве
  //  size_t -
  map<char, int> charCount;

  SHOW(charCount['A']);

  // Итератор в строке пробегает по буквам
  // с первой буквы до последней по одной
  for(string::iterator c = s.begin();
      c != s.end();
      c++) {
    // Очередная буква строки
    char letter = *c;
    map<char, int>::iterator i = charCount.find(letter);

    if(i == charCount.end()) {
      // Не нашли букву => она первый раз
      charCount[letter] = 1;
    } else
      charCount[letter]++;
  }

  charCount['Z'] = 100;

  for(map<char, int>::iterator i = charCount.begin();
      i != charCount.end();
      i++ ) {
    pair<char, int> p = *i;
    cout << "'" << p.first << "' -> " << p.second << endl;
  }

  return 0;
}
