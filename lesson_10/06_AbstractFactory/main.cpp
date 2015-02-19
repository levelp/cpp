// Абстрактная фабрика
// -------------------
#include <QCoreApplication>
#include <iostream>

using namespace std;

// Билет
// Prototype
class Ticket {
 public:
  double price;
  int placeNo;
  char planeName[10];
  // Номер рейса
  char flight[10];
  // Является ли копией?
  bool isCopy;

  Ticket() {
    isCopy = false;
  }

  void show() {
    cout << "==== Ticket ====" << endl;
    cout << planeName << " - " << flight << endl;
    cout << placeNo << " " << price << endl;

    if(isCopy)
      cout << " COPY " << endl;
  }

  Ticket clone() {
    Ticket copy = *this;
    copy.isCopy = true;
    return copy;
  }
};

// Фабрика "билетов"
// Смысл фабрики в том, что мы один раз её настраиваем
// и потом "производим" / "выпускаем" однотипные объекты
class TicketFactory {
  int placeCount;

 public:
  TicketFactory() {
    placeCount = 0;
  }

  char planeName[10];
  // Номер рейса
  char flight[10];

  // Получение билета
  Ticket& buy(double price) {
    Ticket* ticket = new Ticket;
    ticket->price = price;
    ticket->placeNo = ++placeCount;
    strcpy(ticket->flight, flight);
    strcpy(ticket->planeName, planeName);
    return *ticket;
  }
};


int main() {
  // Создаём и настраиваем фабрику
  TicketFactory tf;
  strcpy(tf.planeName, "SSJ 100");
  strcpy(tf.flight, "735");

  TicketFactory tf2;
  strcpy(tf2.planeName, "SSJ 100");
  strcpy(tf2.flight, "1243");

  Ticket t1 = tf.buy(100);
  t1.show();
  Ticket t2 = tf.buy(200);
  t2.show();
  Ticket t3 = tf2.buy(200);
  t3.show();

  Ticket t3_copy = t3.clone();
  t3_copy.show();

  return 0;
}
