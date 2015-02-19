#include <iostream>

using namespace std;

#define xx(a) { cout << #a << " = " << a << endl; };

// Базовый класс "Фигура"
class Shape {
 public:
  virtual void show() {
    cout << "Shape" << endl;
  };
  virtual char* type() = 0; // Чистый виртуальный метод
};

// Круг - 1-ый наследник
class Circle : public Shape {
 public:
  double x, y, R;
  Circle(double x, double y, double R) {
    this->x = x;
    this->y = y;
    this->R = R;
  }
  void show() {
    cout << "Circle: " << endl;
    xx(x);
    xx(y);
    xx(R);
  }
  char* type() {
    return "Circle";
  }
};

// Прямоугольник - 2-ой наследник
class Rectangle : public Shape {
  double a, b;
 public:
  // Конструктор
  Rectangle(double a, double b) {
    this->a = a;
    this->b = b;
  }
  // Выводим на экран
  void show() {
    cout << "Rectangle: " << endl;
    xx(a);
    xx(b);
  }
  char* type() {
    return "Rectangle";
  }
};

int main() {
  Shape* s[] = { new Circle(2.2, 3.4, 2.1), new Rectangle(11, 20) };

  for(int i = 0; i < 2; i++) {
    cout << s[i]->type() << endl;
    s[i]->show();
  }

  return 0;
}
