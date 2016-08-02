// Компилятор:
// ----------
// 1. Лексический анализ
//   Текст => Массив лексем
// 2. Синтаксический анализатор
//   Массив лексем => "дерево" программы
// 3. Оптимизатор
//   Упрощение дерева для ускорения вычислений и т.д.
// 4. Кодогенератор
//   Генерация нового кода

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// Лексема
// Лексемы бывают разных видов
enum LexType {
  NO, // Ничего не было (начало строки или разделитель)
  VAR, // Переменная
  OP, // Операция
  NUMBER // Число
};

// Лексема
struct Lex {
  string s; // Текст лексемы: "x", "myVar", "+", "^"
  LexType type; // Тип лексемы
  friend ostream& operator << (ostream& os, Lex& lex) {
    switch(lex.type) {
      case VAR:
        cout << "VAR ";
        break;

      case OP:
        cout << "OP ";
        break;

      case NUMBER:
        cout << "NUMBER ";
        break;
    }

    os << lex.s << endl;
    return os;
  }
};

bool isOperation(char c) {
  return (c == '+' || c == '-' ||
          c == '*' || c == '/' ||
          c == '^' || c == '=');
}

// Лексический разбор строки
vector<Lex> parse(string text) {
  vector<Lex> r;
  Lex lex;
  lex.s = "";
  lex.type = NO;

  for(auto cur = text.begin(); cur != text.end(); cur++) {
    // Текущая буква
    char c = *cur;
    // Тип текущей лексемы
    LexType type;

    // Если цифра => то это число
    if(isdigit(c)) type = NUMBER;

    // Если буква => то это переменная
    if(isalpha(c)) type = VAR;

    // Если знак операции
    if(isOperation(c)) type = OP;

    // Если началась новая лексема
    if(lex.type != type) {
      // Добавляю предыдущую лексему в список
      if(lex.type != NO) r.push_back(lex);

      // Запоминаю новую лексему
      lex.s = c;
      lex.type = type;
    } else
      lex.s += c;
  }

  // Сохраняю последнюю лексему
  if(lex.type != NO) r.push_back(lex);

  return r;
}

// Квадратное уравнение
struct SqEq {
  double a, b, c;
};

// Синтаксический анализ
struct Syntax {
  SqEq res; // Результат разбора
  vector<Lex> r;

  // Проверяем что в позиции i
  // есть лексема типа type
  // с текстом s
  bool check(int i, LexType type, string s) {
    // Чтобы не выходить за границы вектора
    if(i < 0 && i >= r.size()) return false;

    return r[i].type == type && r[i].s == s;
  }

  bool check(int i, LexType type) {
    // Чтобы не выходить за границы вектора
    if(i < 0 && i >= r.size()) return false;

    return r[i].type == type;
  }

  double parseDouble(int i) {
    return check(i, NUMBER) ? atof(r[i].s.c_str()) : 1.0;
  }

  Syntax(vector<Lex> ri) {
    r = ri;
    // Если коэффициент не указан
    res.a = 0.0;
    res.b = 0.0;
    res.c = 0.0;

    for(int i = 0; i < r.size(); i++) {
      // Сейчас переменная
      if(check(i, VAR)) {
        // Если за ней идёт ^2
        if(check(i + 1, OP, "^") && check(i + 2, NUMBER, "2")) {
          // То это x^2, запоминаем степень перед ним
          res.a = parseDouble(i - 1);
        } else if (check(i + 1, OP)) {
          // То это x
          res.b = parseDouble(i - 1);
        }
      }

      if(check(i, NUMBER) && check(i + 1, OP, "=")) {
        // То это константа
        res.c = parseDouble(i);
      }
    }
  }
};

int main() {
  // Лексический анализ
  cout << "=== LEXIC ===" << endl;
  vector<Lex> r = parse("2x^2+42.5x+3=0");

  for(auto e = r.begin(); e != r.end(); e++)
    cout << *e;

  // Синтаксический анализ
  // На входе поток лексем
  // На выходе - структурированные объекты
  cout << "=== SYNTAX ===" << endl;
  Syntax s(r);
  cout << "a = " << s.res.a << endl;
  cout << "b = " << s.res.b << endl;
  cout << "c = " << s.res.c << endl;

  return 0;
}
