// Переполнение строки - источник уязвимостей
// ------------------------------------------
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
  //-->
  bool passwordCorrect = false;
  char password[10]; // Строка до 9 символов, последний символ 0

  while(true) {
    cout << "Enter password: ";
    cin >> password;

    if(!strcmp(password, "pass"))
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
