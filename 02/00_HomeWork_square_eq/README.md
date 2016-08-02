Решение квадратного уравнения - разбор домашнего задания
----------------------------------------------------------
Задание:
Написать программу, которое решает квадратное уравнение.
Пользователь вводит (с клавиатуры) три действительных
коэффициента a, b, c.
Программа выводит все решения уравнения (два, одно),
"решений нет", если их нет или "бесконечно много решений",
если подходит любое значение x (a = 0, b = 0, c = 0).
Обработать все варианты исходных данных.
a*x^2 + b*x + c = 0
#ifdef DEBUG
#else
#define SHOW(x)
#endif // DEBUG
``` cpp
// Точность сравнения с нулём
const double EPS = 1e-10;
```

Функция: решение квадратного уравнения
a,b,c - коэффициенты уравнения
результат функция выводит на экран
``` cpp
void solve_equation(double a, double b, double c) {
  if(fabs(a) < EPS) {
    if(fabs(b) < EPS) {
      if(fabs(c) < EPS) {
        // Если все три коэффициента нули, то x - любой
        // 0x^2 + 0x + 0 = 0
        cout << "x - any number" << endl;
        return;
      }

      // 0*x^2 + 0*x + не_ноль = 0 - решений нет
      cout << "no solutions" << endl;
      return;
    }

    // Линейное уравнение
    // 0*x^2 + b*x + c = 0
    double x = -c / b;
    cout << "x = " << x << endl;
    // Проверка решения
    cout << "0*x^2 + b*x + c = " << 0 * pow(x, 2) + b* x + c << endl;
    return;
  }

  // Вычисление дискриминанта
  double D = b * b - 4 * a * c;

  if((fabs(D) < EPS) && (D != 0)) {
    SHOW(a)
    SHOW(b)
    SHOW(c)
    cout << "FIND IT! :)" << endl;
    system("pause");
  }

  cout << "D = " << D << endl;

  if(fabs(D) == EPS) {
    double x = -b / (2 * a);
    cout << "x = " << x << endl;
    // Проверяем полученный x
    cout << "f(x) = " << a* x* x + b* x + c << endl;
    return;
  }

  if(D < 0) {
    cout << "no solutions" << endl;
    // Комплексные корни
    double x_re = -b / (2 * a);
    double x1_im = +sqrt(-D) / (2 * a);
    double x2_im = -sqrt(-D) / (2 * a);
    cout << "x1 = " << x_re << " + " << x1_im << " i" << endl;
    cout << "x2 = " << x_re << " + " << x2_im << " i" << endl;
    return;
  }

  // D > 0 - 2 действительных корня
  double x1 = (-b + sqrt(D)) / (2 * a);
  double x2 = (-b - sqrt(D)) / (2 * a);
  cout << "x1 = " << x1 << "  x2 = " << x2 << endl;
  // Проверяем полученные решения
  cout << "f(x1) = " << a* x1* x1 + b* x1 + c << endl;
  cout << "f(x2) = " << a* x2* x2 + b* x2 + c << endl;
}
```

Основная программа - тестирование
``` cpp
  while(1) {
    // Коэффициенты квадратного уравнения
    double a = 2, b, c;
    SHOW(a)
    cout << "a = ";
    cin >> a;

    if(!cin.good()) {
      SHOW(a)
      break;
    }

    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << endl;

    // Вызов функции решения квадратного уравнения
    solve_equation(a, b, c);
```

[main.cpp](main.cpp)

