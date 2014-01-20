#include <iostream>
#include <stdio.h>
#include <windows.h> // WinAPI
#include <math.h>

using namespace std;

union Bytes {
    int i; // Тип int занимает 4 байта
    char bytes[4]; // Он же в виде 4-х отдельных
};

struct Shape {
    char type; // type = 'C' - круг, 'S' - квадрат
    double x,y;
    union {
        double R;
        double Side;
    };
};

struct Point {
  double x,y;

  // Расстояние между точками
  double dist(Point b){
    return sqrt(pow(x - b.x, 2) +
                pow(y - b.y, 2));
  }

};


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.

    Point p1 = {2, 3};
    Point p2 = {3, 5};
    Point p3 = {3, 7};
    cout << "Расстояние: " << p1.dist(p2) << endl;

//
//    char str[10]; // Строка до 9 символов, последний символ 0
//
//    cout << "Введите строку больше 10 символов: ";
//    cin >> str;
//
//    //freopen("result.txt", "w", stdout);
//    cout << str << endl;
     int i=0;
     i++;

    return 0;
}
