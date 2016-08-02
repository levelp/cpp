#include <iostream>
#include <fstream> // Файловый ввод и вывод с помощью потоков
#include <map>

using namespace std;

// Словарь
map <string, string> dict;

// Чтение словаря из файла
void readDictionary() {
  string dictFileName("dict.txt");
  ifstream dictFile(dictFileName);

  if (!dictFile.good()) {
    cout << "File \"" << dictFileName << "\" - not exists!" << endl;
    return;
  }

  while(!dictFile.eof()) {
    // from - слово на исходном языке
    // to - перевод
    string from, to;
    dictFile >> from >> to;
    // from - ключ, to - значение
    //dict[from] = to;
    dict.insert(make_pair(from, to));
  }

  dictFile.close();
}

int main() {
  readDictionary();

  ifstream in("in.txt");
  ofstream out("out.txt");

  int wordCount = 0;

  while(!in.eof()) {
    string s;
    in >> s;
    cout << (++wordCount) << ". " << s << endl;

    //out << dict.find(s) << " " << dict.end() << endl;
    if(dict.find(s) == dict.end())
      out << s << "* ";
    else
      out << dict[s] << " ";
  }

  in.close();
  out.close();

  return 0;
}
