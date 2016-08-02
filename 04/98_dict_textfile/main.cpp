#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  /// Открываем текстовый файл для чтения
  //-->
  freopen("in.txt", "r", stdin);
  //<--
  /// Открываем текстовый файл для записи
  //-->
  freopen("out.txt", "w", stdout);
  //<--

  map<string, string> dict;

  int numberOfWords;
  cin >> numberOfWords;

  for(int i = 0; i < numberOfWords; i++) {
    string inEnglish, inRussian;
    cin >> inEnglish >> inRussian;
    dict[inEnglish] = inRussian;
  }

  // TODO: доделайте сами :)

  return 0;
}
