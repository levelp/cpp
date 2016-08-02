/// Переполнение строки символов
/// ----------------------------
// Смертный Грех программиста №1 - источник уязвимостей
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  while(true) {
    char password[8]; // Переполнение здесь!
    //string password; // Устранение уязвимости
    bool passwordCorrect = false; // 0 - false
    // Ввод с клавиатуры
    cout << "Enter your password: ";
    cin >> password;

    // Пресечение атаки
    if(strlen(password) > 8)
      continue;

    // Но строчка может быть получена из файла
    // по сети, из другого файла взят кусок и т.д.
    // Получение пакета из сети
    if(!strcmp(password, "123"))
      passwordCorrect = true;

    if(passwordCorrect)
      cout << "Password correct!" << endl;
    else
      cout << "Wrong password!" << endl;
  }

  return 0;
}
