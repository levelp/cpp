// Переполнение строки символов
// Смертный Грех программиста №1 - источник уязвимостей
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char password[8];
  int passwordCorrect = 0;

  cout << "Enter your password: ";
  cin >> password;

  // Ввод с клавиатуры
  // Ввод из файла
  // Получение пакета из сети
  if(!strcmp(password, "pass"))
    passwordCorrect = 1;

  if(passwordCorrect)
    cout << "Password correct!" << endl;
  else
    cout << "Wrong password!" << endl;

  return 0;
}
