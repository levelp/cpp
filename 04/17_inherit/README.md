Наследование
------------
struct A <--> class A { public:
class A <--> struct A { private:
``` cpp
struct A {
  static int staticInClass;
  int a; // Поле доступно отовсюду

  void doA() {
    cout << "doA()" << endl;
    onlyInA = 2;
    cout << "onlyInA = " << onlyInA << endl;
    forChilds = 10;
  };
 private:
  int onlyInA; // Только внутри класса A
 protected:
  int forChilds; // Внутри класса A и в наследниках
};
```

B - наследник A
``` cpp
struct B : public A {
  int b;
  int forChilds; // Поле с тем же именем
  void doB() {
    cout << "doB()" << endl;
    //onlyInA = 2; // Недоступно в наследниках
    doA();
    //cout << "onlyInA = " << onlyInA << endl;
    A::forChilds = 12;
    forChilds = 20; // Работает
    this->forChilds = 20; // Работает

    cout << "A::forChilds = " << A::forChilds << endl;
    cout << "B::forChilds = " << B::forChilds << endl;
  };
};
```


Множественное наследование
show(); // Ошибка компиляции
Мы должны явно указать из какого предка вызываем метод
потому что это глобальная переменная
a.onlyInA = 3; // 'int A::onlyInA' is private
'int A::forChilds' is protected
cout << a.forChilds << endl;
Нет доступа, т.к. onlyInA private
b.onlyInA = 10;
c.a = 1; // Ошибка из-за protected наследования
c.b = 2; // Ошибка из-за protected наследования
c.doA();
c.doB();
x.doL();
[main.cpp](main.cpp)

