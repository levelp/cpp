Зачем нужны get/set методы?
---------------------------
Don’t Repeat Yourself
http://ru.wikipedia.org/wiki/Don%E2%80%99t_repeat_yourself
Дублирование данных
``` cpp
class Square2 {
  double side; // Сторона
  double area; // Площадь
 public:
  // Просто возвращаем значение
  double getSide() {
    return side;
  }
  double getArea() {
    return area;
  }
  // При изменении меняем одновременно
  void setSide(double value) {
    side = value;
    area = value * value;
  }
  void setArea(double value) {
    side = sqrt(value);
    area = value;
  }
};
```

[main.cpp](main.cpp)

Реализация метода в отдельном C++ файле
``` cpp
void Square::setArea(double value) {
#ifdef SIDE
  side = sqrt(value);
#else
  area = value;
#endif
}
```

[square.cpp](square.cpp)

Инкапсуляция
------------
Объект должен быть "скромным"
Класс "Квадрат"
``` cpp
class Square {
  //private: // Инкапсуляция
#ifdef SIDE
  double side; // Сторона
#else
  double area; // Площадь - сторона в квадрате
#endif // SIDE
 public:
  // Получить сторону квадрата
  double getSide() {
#ifdef SIDE
    return side;
#else
    return sqrt(area);
#endif // SIDE
  }
  // Задать сторону квадрата
  void setSide(double value) {
#ifdef SIDE
    side = value;
#else
    area = value * value;
#endif // SIDE
  }
  // Получить площадь
  double getArea() {
#ifdef SIDE
    return side * side;
#else
    return area;
#endif // SIDE
  }
  // Задать площадь
  void setArea(double value);
};
```

[square.h](square.h)

