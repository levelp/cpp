#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;

// 1 11 21 1211 111221  312111 13111231
int main() {
  cout << "Последовательность LookAndSay " << endl;
  string a = "1";

  for(int k = 0; k < 20; k++) {
    if(!cin.good()) break;

    cout << a << " => ";
    stringstream out;
    char c = -1; // Текущий символ
    int cnt = 0; // Количество

    // пробегаем по всем символам строки
    for(int i = 0; i < a.size(); i++) {
      if(a[i] == c)
        cnt++;
      else {
        if(cnt > 0) out << cnt << c;

        c = a[i];
        cnt = 1;
      }
    }

    if(cnt > 0) out << cnt << c;

    a = out.str();
    cout << a << endl;
  }

  return 0;
}
