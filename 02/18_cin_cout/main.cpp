#include <iostream>
#include <stdio.h>

using namespace std;

struct Point {
  double x, y;
};

int main() {
  /*  Point p1;
    cout << "Enter point X Y: ";
    //cin >> p1.x >> p1.y;
    char str[1024];
   // cin.getline(str, 1024);
    cin >> str;
    cout << "\"" << str << "\"" << endl;
    sscanf(str, // Строка для разбора
           "%lf %lf",
           &p1.x,&p1.y);

    // Вывести на экран точку 1
    cout << "(" << p1.x << ";" <<
      p1.y << ")" << endl;
  */
  char buf[] = "213-23-35";
  int a, b, c;
  sscanf(buf, "%d-%d-%d", &a, &b, &c);
  cout << c << " " << b << " " << a << endl;

  int x = 0;

  while(x <= 0 || x > 30) {
    cout << "Enter number: ";
    cin >> x; // Вводим 3.14
    //cin.clear();
    cin.ignore(100, '\n');
    cout << endl;

    if(x <= 0 || x > 30)
      cout << "ERROR" << endl;
  }

  return 0;
}
