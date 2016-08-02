Указатели и ссылки
------------------
* Указатели есть и в C и в C++
* Ссылки есть только в C++
``` cpp
void f(int*);

void f(int* a) {
  *a = 10;
}

int main() {
  int a = 10;
  // aPtr - указатель
  int* aPtr = &a, aa = 2; // aPtr - указатель, b - не указатель
  aPtr = &a; // записываем в него адрес a
  SHOW(a); // a = 10
  // *aPtr = что-то..
  // Записываем значение туда, куда указывает
  // aPtr
  *aPtr = 12; // a = 12
  SHOW(a);
  // Перемещаем указатель
  // теперь он будет указывать на aa
  aPtr = (int*) aa;
  // *aPtr = 1000; -- пишем в неведомую ячейку
  aPtr = &aa;
  *aPtr = 1000;
  SHOW(aa);

  int* bPtr, c;

  int& b = a; // Ссылка
  //int &bb;  // error: 'bb' declared as
  // reference but not initialized
  int d = 22;
  // &b = d; // Нельзя переопределять ссылки

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  b = 11;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  int* ptr; // Указатель можно не инициализировать

  // Указывает на переменную a
  ptr = &a;
  cout << "*ptr = " << *ptr << endl;

  ptr = &d;
  cout << "*ptr = " << *ptr << endl;

  ptr = NULL;

  return 0;
}
```

[main.cpp](main.cpp)

