<!-- doc.py -->
Домашнее задание: точка (класс Point)
-------------------------------------
Объявить основной класс с именем point, с следующими данными:
``` cpp
class point {
 protected:
  // Координаты точки: х, у;
  double x, y;
 public:
  // Конструктор:
  point(double x, double y) : x(x), y(y) {
    cout << "Point (" << x << ";" << y << ")" << endl;
  }
  // Деструктор:
  ~point() {
    cout << "Point destructor" << endl;
  }
  // Функция ввода данных;
  void input() {
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
  }
};
```

И второстепенный класс graphicPoint. В этом классе добавляются новые данные:
``` cpp
class graphicPoint : public point {
  // с – цвет точки;
  int c;
 public:
  // x,y - координаты, c - цвет
  graphicPoint(double x, double y, int c) : point(x, y), c(c) {
  }
  // Функция которая рисует точку
  void draw() {
    cout << "Draw point (" << x << ";" << y << ") color: " << c << endl;
  }
};
```

Тестируем классы point и graphicPoint
[main.cpp](main.cpp)

