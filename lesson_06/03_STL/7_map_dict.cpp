#include <iostream>
#include <map>
#include <locale.h>

using namespace std;

class MyClass {
  int value;
 public:
  friend
  bool operator < (const MyClass& left,
                   const MyClass& right) {
    return left.value < right.value;
  }
};


//-->
void dict() {
  // Контейнеры:
  //   vector
  //   set
  //   map
  setlocale(LC_ALL, "Russian");

  // Ассоциативный массив
  // A["Hi"] = "Привет";
  // map<key, value>
  map<string, string> dict;

  // dict[3] = 4;
  // dict[3] = 5;

  dict["Привет"] = "Hi";
  dict["Я"] = "I";

  dict["Ты"] = "You";
  cout << dict["Ты"] << endl;

  dict["Ты2"] = "You2";
  cout << dict["Ты"] << endl;

  map<MyClass, string> mm;
  MyClass m;
  mm[m] = "Test";
}
//<--
