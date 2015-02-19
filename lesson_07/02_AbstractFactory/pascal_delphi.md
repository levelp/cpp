``` delphi
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