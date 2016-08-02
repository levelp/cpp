#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char str[80];
  cout << "Enter string: ";
  cin.getline(str, sizeof(str));

  int len = strlen(str);
  char result_str[80] = {0};
  // Позиция в исходная строке
  int i = 0;
  // Текущий символ в результирующей строке
  int p = 0;
  // Пропускаем все лидирующие пробелы
  while(str[i] == ' ' && i < len)
    i++;
  // Теперь у нас i в конце строки или на первом "слове"
  bool spaces = false; // Были ли пробелы?
  for(; i < len; ++i) {
    if(str[i] == ' ')
      spaces = true;
    else {
      if(spaces)
        result_str[p++] = ' ';
      result_str[p] = str[i];
      ++p;
      spaces = false;
    }
  }
  cout << "\"" << result_str << "\"" << endl;
  return 0;
}
