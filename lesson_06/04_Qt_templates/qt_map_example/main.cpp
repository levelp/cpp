#include <map> // map
#include <string> // string
#include <iostream> // cout

using namespace std;

int main() {
  freopen("log.txt", "w", stdout);

  map<string, string> dict;
  dict["Hi"] = "Привет";
  dict["Sorry"] = "Извини";
  dict["Everyone"] = "Каждому";
  dict["permitted"] = "разрешено";
  dict["copy"] = "копировать";
  dict["distribute"] = "распространять";
  dict["is"] = "(быть)";
  dict["to"] = "(до)";
  dict["and"] = "и";

  string src = "Everyone is permitted to copy and distribute";

  unsigned int wordBegin = 0;

  for(unsigned int i = 0; i <= src.size(); ++i) {
    // Конец слова
    if((i == src.size() || src[i] == ' ')) {
      if(i == wordBegin) {
        wordBegin++;
        continue;
      }

      // Выделяем слово
      string word = src.substr(wordBegin, i - wordBegin);
      // Переводим слово
      string inRussian;

      if(dict[word].empty())
        inRussian = word;
      else
        inRussian = dict[word];

      cout << inRussian << " ";

      wordBegin = i + 1;
    }
  }

  return 0;
}
