// Стратегия (strategy)
// Поведенческий шаблон
#include <QCoreApplication>
#include <vector>
#include <iostream>

using namespace std;

// Стратегия - абстрактный класс
class Strategy {
 public:
  virtual void put(vector<int>& v, int value) = 0;
  virtual int get(vector<int>& v) = 0;
};

// Стратегия стек
class StrategyStack : public Strategy {
  void put(vector<int>& v, int value) {
    v.insert(v.begin(), value);
  }
  int get(vector<int>& v) {
    int res = v.at(0);
    v.erase(v.begin());
    return res;
  }
};

// Стратегия очередь
class StrategyQueue : public Strategy {
  void put(vector<int>& v, int value) {
    v.push_back(value);
  }
  int get(vector<int>& v) {
    int res = v.at(0);
    v.erase(v.begin());
    return res;
  }
};

//
class Context {
 public:
  Strategy* strategy;
  vector<int> data;
  void someOperation() {
    strategy->put(data, 2);
    strategy->put(data, 3);
    cout << strategy->get(data) << endl;
  }
};

int main() {
  Context c;
  cout << "Use Queue" << endl;
  c.strategy = new StrategyQueue();
  c.someOperation();
  cout << "Use Stack" << endl;
  c.strategy = new StrategyStack();
  c.someOperation();

  return 0;
}
