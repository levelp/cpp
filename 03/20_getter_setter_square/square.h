#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include <cmath>

#define SIDE

/// Инкапсуляция
/// ------------
/// Объект должен быть "скромным"
/// Класс "Квадрат"
//-->
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
//<--

#endif // SQUARE_H_INCLUDED
