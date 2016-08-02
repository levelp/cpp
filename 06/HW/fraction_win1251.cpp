#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

class fraction {
 private:
  long chis;
  long znam;
  long temp;
  long gcd;
 public:
  fraction() {
  }
  fraction(long ch, long zn, long te, long gc): chis(ch), znam(zn), temp(te), gcd(gc) {
  }
  void getfract() {
    cout << "\nВведите числитель дроби: ";
    cin >> chis;
    cout << "\nВведите знаменатель дроби: ";
    cin >> znam;
  }
  void showfract() {
    cout << chis << "/" << znam << endl;
  }
  void add_fract(fraction, fraction);
  void sub_fract(fraction, fraction);
  void mul_fract(fraction, fraction);
  void div_fract(fraction, fraction);
  void lowterms();
};

void fraction::add_fract(fraction f1, fraction f2) {
  chis = f1.chis * f2.znam + f1.znam * f2.chis;
  znam = f1.znam * f2.znam;
}

void fraction::sub_fract(fraction f1, fraction f2) {
  chis = f1.chis * f2.znam - f1.znam * f2.chis;
  znam = f1.znam * f2.znam;
}

void fraction::mul_fract(fraction f1, fraction f2) {
  chis = f1.chis * f2.chis;
  znam = f1.znam * f2.znam;
}

void fraction::div_fract(fraction f1, fraction f2) {
  chis = f1.chis * f2.znam;
  znam = f1.znam * f2.chis;
}

void fraction::lowterms() {
  long tchis, tznam, temp, gcd;
  tchis = labs(chis);// требует #include <cmath>
  tznam = labs(znam);//используем неотрицательные значения

  if(tznam == 0) {
    cout << "Недоступный знаменатель!";
    exit(1);
  } else if(tchis == 0) {
    chis = 0;
    znam = 1;
    return;
  }

  while(tchis != 0) {
    if(tchis < tznam) {
      temp = tchis;
      tchis = tznam;
      tznam = temp;
    }

    tchis = tchis - tznam;
  }

  gcd = tznam;
  chis = chis / gcd;
  znam = znam / gcd;
}

int main() {
  setlocale(LC_ALL, "Russian");
  fraction frac1, frac2, frac3;
  char znak, ch;

  do {
    cout << "Введите первую дробь: ";
    frac1.getfract();
    cout << " Введите операцию: ";
    cin >> znak;
    cout << "Введите вторую дробь: ";
    frac2.getfract();

    switch(znak) {
      case '+':
        frac3.add_fract(frac1, frac2);
        break;

      case '-':
        frac3.sub_fract(frac1, frac2);
        break;

      case '*':
        frac3.mul_fract(frac1, frac2);
        break;

      case '/':
        frac3.div_fract(frac1, frac2);
        break;
    }

    frac3.showfract();
    frac3.lowterms();
    frac3.showfract();
    cout << "Выполнить ещё одну операцию (y/n)?";
    cin >> ch;
  } while (ch != 'n');

  system("PAUSE");
  return 0;
}