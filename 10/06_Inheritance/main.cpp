#include <QCoreApplication>


class A {
  // Что-то объявлено здесь
 public:
  int age = 18;
};


// Модификаторы при наследовании:
// private / protected / public
class B : public A {
  // Всё то, что объявлено в A
  // уже есть в B благодаря наследованию
  int x = age + 100;
};

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  return a.exec();
}

// Type a;
// Type* aPtr;
// int a;
// int* a;
// Ticket ticket;
// Родитель             Наследник
// Ticket* ticket = new AirplaneTicket();
// sizeof(T*) --> 32  4 байтам

// vector<Ticket*> v;
// |-----|
// |     |-> v.push_back(new AirplaneTicket())
// |     |   v[0] = new AirplaneTicket();
// |-----|
// |     |-> v.push_back(new SubmarineTicket())
// |     |   v[1] = new SubmarineTicket();
// |-----|
// |     |
// |-----|

