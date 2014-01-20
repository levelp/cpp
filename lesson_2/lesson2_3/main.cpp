#include <iostream>
#include <clocale> // setlocale

using namespace std;

int main()
{
    // Win1251 и в исходном тексте и в консоли
    setlocale(LC_ALL, "Russian");

    cout << "Введите номер вашей ветки метро: ";
    int metro;
    cin >> metro;
    switch(metro){
    case 1:
        cout << "Красная: Кировско-Выборгская. Самая старая ветка метро." << endl;
        break;
    case 2:
        cout << "Синяя: Московско-Петроградская. " << endl;
        break;
    case 3:
        cout << "Зелёная: Василеостровская" << endl;
        break;
    case 4:
        cout << "Жёлтая: Правобережная" << endl;
        break;
    case 5:
        cout << "Фиолетовая: Спасско-Преображенская" << endl;
        break;
    default:
        cout << "Я не знаю :) Такой ветки ещё не построили в 2013 году." << endl;
    }
    return 0;
}
