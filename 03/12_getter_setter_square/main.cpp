// Пример: зачем нужны get/set методы
// Don’t Repeat Yourself
// http://ru.wikipedia.org/wiki/Don%E2%80%99t_repeat_yourself
#include <iostream>
#include <math.h>

using namespace std;

// Инкапсуляция
class Square {
  //private:
  double side; // Сторона
  //double area; // Площадь
 public:
  // Получить сторону квадрата
  double getSide() {
    //return sqrt(area);
    return side;
  }
  // Задать сторону квадрата
  void setSide(double value) {
    //area = value * value;
    side = value;
  }
  // Получить площадь
  double getArea() {
    //return area;
    return side * side;
  }
  // Задать площадь
  void setArea(double value) {
    //area = value;
    side = sqrt(value);
  }
};

int main() {
  Square s;
  cout << "set side 12" << endl;
  s.setSide(12);
  cout << "side = " << s.getSide() << endl;
  cout << "area = " << s.getArea() << endl;

  cout << "set area 100" << endl;
  s.setArea(100);
  cout << "side = " << s.getSide() << endl;
  cout << "area = " << s.getArea() << endl;

  return 0;
}
