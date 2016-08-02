#include <iostream>
#include <cstring>

using namespace std;

#define SHOW(x) { cout << #x << " = " << x << endl; }

int cnt = 0;

class A {
  void init(char* name) {
    if(objName != NULL) {
      delete[] objName;
      cnt--;
    }

    if(name != NULL) {
      objName = new char[strlen(name) + 1];
      cnt++;
      strcpy(objName, name);
      cout << "Init: " << objName << endl;
    } else
      cout << "Init without name" << endl;
  }
 public:
  char* objName = NULL; // Hello  'H' 'e' 'l' 'l' 'o' \0
  A(char* name = NULL) {
    init(name);
  }
  ~A() {
    cout << "Destructor: " << objName << endl;
    delete[] objName;
    cnt--;
  }
  // Конструктор копирования
  A(A& a) {
    init(a.objName);
    cout << "Copy constructor: " << objName << endl;
  }
  A& operator =(A& a) {
    init(a.objName);
    cout << "Copy: " << objName << endl;
    return *this;
  }
};

int main() {
  {
    char name[] = "Hello!";
    A a(name);
    A b = a; // Конструктор копирования
    A x(a); // Вызов конструктора копирования
    b = a; // Операция присваивания
    A c;
    c = a;
    name[0] = 'X';
  }
  SHOW(cnt);
  return 0;
}
