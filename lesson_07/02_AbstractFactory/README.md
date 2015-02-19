Создание класса в C++ по его идентификатору
-------------------------------------------
Иерархия классов
``` cpp
struct MyClass {
  virtual void show() = 0;
};

struct MyClass1 : public MyClass {
  MyClass1() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
  void show() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
};

struct MyClass2 : public MyClass {
  MyClass2() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
  void show() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
};

```

Первый способ
-------------
Функция - фабрика
``` cpp
MyClass* CreateInstance(int id) {
  switch(id) {
    case 1:
      return new MyClass1();

    case 2:
      return new MyClass2();

    default:
      cout << "TODO: " << __FUNCTION__ << " for " << id << endl;
  }

  throw id;
}
```

Использование
``` cpp
  MyClass* a = CreateInstance(1);
  a->show();
  MyClass* b = CreateInstance(2);
  b->show();
```

Второй способ
-------------
Спецификация шаблона для определённых значений
``` cpp
template<int id>
MyClass* Create() {
  throw "Need specialization";
}

template<>
MyClass* Create<1>() {
  return new MyClass1();
}

template<>
MyClass* Create<2>() {
  return new MyClass2();
}
```

Использование
``` cpp
  MyClass* a1 = Create<1>(), *a2 = Create<2>();
  a1->show();
  a2->show();
```

[main.cpp](main.cpp)

﻿``` delphi
type
  TMyClass = class
  end;

  TMyClass2 = class(TMyClass)
  end;

  TMyClassType = class of TMyClass;

  procedure CreateClass;
  var
    MyClassType: TMyClassType;
    MyClassObj: TMyClass;
  begin
    MyClassType := TMyClass;
    MyClassObj := MyClassType.Create; // эквивалентно MyClassObj := TMyClass.Create

    MyClassType := TMyClass2;
    MyClassObj := MyClassType.Create; // эквивалентно MyClassObj := TMyClass2.Create

    // ps: вся прелесть в том что MyClassType - переменная, которая может
    //     принимать как значение тип класса любого обьекта совместимого с
    //     TMyClass
  end;
```

