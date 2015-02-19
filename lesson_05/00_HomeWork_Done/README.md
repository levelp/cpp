<!-- doc.py -->
Домашнее задание: реализовать классы геометрических фигур
---------------------------------------------------------
Базовый класс: Фигура
``` cpp
class Shape {
  // Поля класса:
  // Имя фигуры (строка)
  char* name; // Обязательно private
 protected:
  // Конструктор для вызова из наследников
  Shape(char* name = NULL) : name(name) {
  }
  // Каждая фигура показывает своё имя
 public:
  // Чистая виртуальная функция
  //  => Класс Shape является абстрактным
  //   т.е. нельзя создать экземпляры класса Shape
  //  => Все наследники содержат таблицу
  //   виртуальных функций и должны либо
  //   реализовать этот метод, либо тоже
  //   будут абстрактными.
  virtual void show() = 0;

 protected:
  void showName() {
    if(name != NULL)
      cout << name << " ";
  }
};
```

``` cpp

class Shape2 : public Shape {
 public:
  Shape2(char* name) : Shape(name) {
  }
  void show() {
    cout << "Shape2 ";
    Shape::showName();
  }
};

// Наследники Shape:
class Point : public Shape2 {
  double x, y;
 public:
  // Конструктор
  Point(char* name, double x, double y) :
    x(x), Shape2(name), y(y) {
  }
  // final - нельзя переопределять
  void show() final {
    cout << "Point ";
    Shape::showName();
    cout << "  x = " << x << " y = " << y << endl;
  }
};

class PointX : public Point {
#if 0
  // Не компимлируется
  void show() {
  }
#endif
};

class Line : public Shape {
  // Внутри 2 точки
  Point a, b;
 public:
  // Конструктор
  Line(char* name, Point a, Point b) :
    Shape(name), a(a), b(b) {
  }
  void show() {
    cout << "Line ";
    Shape::showName();
    a.show();
    cout << " - ";
    b.show();
  }
};

class Circle : public Shape {
  // Одна точка и радиус
  Point center;
  double radius;
  // Конструктор
 public:
  Circle(char* name, Point center, double radius) :
    Shape(name), center(center), radius(radius) {
  }
  void show() {
    cout << "Circle ";
    Shape::showName();
    center.show();
    cout << "  radius = " << radius << endl;
  }
};

// Везде метод show() -> показывает свойства фигуры

int main() {
  // error: cannot allocate an object
  // of abstract type 'Shape'
  // Shape* s = new Shape;

  // error: cannot declare variable 's2'
  // to be of abstract type 'Shape'|
  // Shape s2;

  Shape* shapes[5] = {
    new Point("A", 1.2, 2.1),
    new Point("B", 5, 6),
    new Line("AB", Point("A", 1.2, 2.1),
    Point("B", 5, 6)),
    new Circle("CircleA", Point("A", 1.2, 2.1), 5.0),
    new Circle("CircleB", Point("B", 5, 6), 7.2)
  };

  for(int i = 0; i < 5; ++i)
    shapes[i]->show();

  return 0;
}
[main.cpp](main.cpp)

