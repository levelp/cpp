/// Полиморфизм
/// ===========
#include <iostream>

using namespace std;

#define SHOW(x) cout << ": " << #x << " = " << x << endl;
#define MY_CONST 5
//const int MY_CONST = 10;

//-->
// Фигура
struct Shape {
  //void show(){
  //  cout << "Shape" << endl;
  //};
  virtual void show() = 0; // Абстрактный метод
 protected:
  // virtual void doA() = 0;
  // virtual void doB() = 0;
  // virtual void doC() = 0;
  // virtual void doD() = 0;
  // virtual void doE() = 0;
  //int x;
 private:
  /*char c1;
  char c2;
  char c3;
  char c4;
  char c5; */
} __attribute__((packed));
//<--

// Квадрат
//-->
struct Square : public Shape {
  double side;
  Square(double s) : side(s) { }
  void show() {
    cout << "Square side = " << side << endl;
  }
} __attribute__((packed));
//<--

// Прямоугольник
//-->
struct Rectangle : public Shape {
  double height, width;
  Rectangle(double h, double w) :
    height(h), width(w) { }
  void show() {
    cout << "Rectangle " << height <<
         " x " << width << endl;
  }
};
//<--

//-->
int main() {
  Shape shape; // Ошибка компиляции
  SHOW(sizeof(Shape));
  SHOW(sizeof(Square));
  SHOW(sizeof(Rectangle));
  // DRY - Don't Repeat Yourself

  const int N = 3;
  Shape* s[N] = {
    new Square(10),
    new Rectangle(2, 3),
    new Square(15),
  };

  for(int i = 0; i < N; ++i)
    s[i]->show();

  return 0;
}
//<--
