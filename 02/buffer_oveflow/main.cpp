// Переполнение строки - источник уязвимостей
// ------------------------------------------
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
  //-->
  char password[10]; // Строка до 9 символов, последний символ 0
  bool passwordCorrect = false;

  while(true) {
    cout << "Enter password: ";
    cin >> password;

    if(!strcmp(password, "123"))
      passwordCorrect = true;

    if(passwordCorrect) {
      cout << "OK! Access GRANTED!" << endl;
      system("pause");
      return 0;
    } else
      cout << "Access DENIED :)" << endl;
  }

  //<--
  return 0;
}
