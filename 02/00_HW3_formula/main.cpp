#include <iostream>

using namespace std;

void displayExplanation(void) {
  cout << "This program count the factor t "
       << "for sale manager.\n"
       << "With this factor we can take into "
       << "the overhead cost for any item\n "
       << "from the price list.\n";
  return;
}

int main() {
  // Вводим переменную, описывающую стоимость оборудования EXW = x,
  // c - скидка на заводе производителе, p - полная стоимость оборудования.
  // d - стоимость оборудования со скидками на заводе.
  // t - коэффициент для расчета цены менеджером.
  displayExplanation();
  float x, c, d, p, t;
  cout << "Enter EXW price x: " << endl;
  cin >> x;
  cout << "Enter your discount on manufactory c: " << endl;
  cin >> c;
  d = ((x - (x * (c / 100))) * 1.03);
  cout << "The price with discount d:" << d << endl;
  // задаём формулу расчета полной стоимости оборудования для поставщика
  double coef1 = 0.3; // Формула
  p = d + (d * coef1) + (d * 0.03); // d * 1.33
  // первая скобка считает стоимость exw с учётом скидки, вторая
  // скобка считает оптимальный вариант перевозки - 30% от стоимости
  // оборудования,третья скобка учитывает расходы
  // на комиссию за банковские услуги
  cout << "Total price for supplier p = " << p << endl;

  if (p > d * 1.4)
    cout << "Check your costs!" << endl;
  else if (p < d * 1.4)
    cout << "The price is good" << endl;
  else
    cout << "The price is optimal" << endl;

  t =  ((d * 1.4) + (d * (c / 100))) / x ;
  cout << "The calculation factor for price t: " << t << endl;

  return 0;
}
