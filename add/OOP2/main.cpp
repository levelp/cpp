// Создание анкеты
#include <iostream>
#include <string>
using namespace std;

// Base
class Human {
 private:
  int age;
  string name;
  string sex;
 public:
  Baze() {
    cout << "Введите ваши данные " << endl;
  }
  void Age() {
    cout << "Сколько вам лет?" << endl;
    cout << "- ";
    int fage;
    cin >> fage;
    age = fage;

  }
  void Name() {
    cout << "Ваше имя?" << endl;
    cout << "- ";
    string fname;
    cin >> fname;
    name = fname;
  }
  void Sex() {
    cout << "Ваш пол?" << endl;
    cout << "- ";
    string fsex;
    cin >> fsex;
    sex = fsex;
  }
  void end() {
    cout << name  << "  возраст  " << age << "   пол  " << sex << endl;
  }
};

class wife : public Human {
 private:
  //string name;
  //int age;
  bool W;
 public:
  void Woman() {
    cout << "Вы женаты?  = ";
    string yes;
    cin >> yes;

    if (yes == "да")
      W = true;

    if (yes == "нет")
      W = false;

    if (yes == "да") {
      cout << "Как ее зовут?" << endl;
      string fname;
      cin >> fname;
      name = fname;
      cout << "Сколько ей лет?" << endl;
      int fage;
      cin >> fage;
      age = fage;
    }
  }
  void end() {
    if(W == true)
      cout << "Ваша жена  " << name << " ей  " << age << " лет." << endl;
    else
      cout << "Не женат " << endl;
  }
};
class child {
 private:
  int age;
  string name;
  bool W;
 public:
  void Child() {
    cout << "У вас есть ребенок " << endl;
    string yes;
    cin >> yes;

    if(yes == "да")
      W = true;

    if (yes == "нет")
      W = false;
  }
  void Name() {
    if(W) {
      cout << "Имя ребенка " << endl;
      string fname;
      cin >> fname;
      fname = name;
    }
  }
  void Age() {
    if(W) {
      cout << "Возраст ребенка " << endl;
      int fage;
      cin >> fage;
      fage = age;
    }
  }
  void end() {
    if(W) {
      cout << "Имя ребенка " << name << " его возраст " << age << endl; // не выводит имя
    } else {                                                              // и возраст на экран
      cout << "Нет ребенка" << endl;                                    // выдает хрень
    }
  }
};

class x : public Baze, public wife, public child {
 public:
  x() {
    cout << "Клас наследник " << endl;
  }
};

void f() {
  x person;
  person.Baze::Name();
  person.Baze::Age();
  person.Baze::Sex();
  person.Woman();
  person.Child();
  person.child::Name();
  person.child::Age();
  person.Baze::end();
  person.wife::end();
  person.child::end();
}

int main() {
  f();

  return 0;
}
