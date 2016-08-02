// template: реализация структуры данных "Список"
// ----------------------------------------------
#include <iostream>

using namespace std;


// Шаблонная функция
template<class A, class B>
void f(A a, B b) {

}

// Элемент списка
template<class T>
struct ListElement {
  T value; // Значение элемента списка
  ListElement<T>* next; // Указатель на следующий элемент списка
};

template<class T>
struct List {
  ListElement<T>* root; // Указатель на первый элемент

  // Конструктор
  List() {
    cout << "Constructor" << endl;
    root = NULL;
    // Так нельзя (!!!):
    // root->next = NULL;
  }

  // Деструктор - метод, который вызывается при
  // уничтожении объекта
  ~List() {
    cout << "Destructor" << endl;
    ListElement<T>* cur = root;

    while(cur != NULL) {
      root = cur->next;
      delete cur;
      cur = root;
    }
  }

  // Добавить в начало списка
  void addToBegin(T newValue) {
    // Заводим новый элемент списка в динамической памяти
    ListElement<T>* newElement = new ListElement<T>;
    // Записываем в него новое значение
    newElement->value = newValue;
    // (*newElement).value = newValue;
    // Этот элемент должен встать в начало списка,
    // т.е. все остальные элементы будут после него.
    newElement->next = root;
    root = newElement;
  }

  // Показать список
  void show() {
    // Текущий элемент - сначала 1-ый
    int No = 0;

    for(ListElement<T>* cur = root;
        cur != NULL; cur = cur->next)
      cout << ++No << ". " << cur->value << endl;
  }

  // Добавить элемент в конец списка
  void addToEnd(T newValue) {
    if(root == NULL) {
      addToBegin(newValue);
      return;
    }

    // Идём до последнего элемента
    ListElement<T>* cur = root;

    while(cur->next != NULL)
      cur = cur->next;

    //for(ListElement* cur = root;
    //    cur->next != NULL; cur = cur->next)
    //    /* Ничего не надо делать :) */;

    // Создаём новый элемент
    ListElement<T>* newElement = new ListElement<T>;
    newElement->value = newValue;
    newElement->next = NULL;

    // Новый элемент ставим в конец списка
    cur->next = newElement;
  }
};

// myFunction<double>()
// make_pair(234, 'c');
template<typename T>
T myFunction(T n) { // int i = myFunction<int>()
  T myVar = n * 1000000000L;
  cout << "sizeof(T) = " << sizeof(T) << endl;
  return myVar;
}

int main() {
  int hh = myFunction<long long>(12);
  hh = myFunction<long>(12);
  hh = myFunction<short>(12);
  hh = myFunction<unsigned char>(12);
  cout << hh << endl;

  List<int> list1;

  List<double> list; // Создали список
  // List - класс
  // list - объект этого класса
  list.addToBegin(5.0); // Добавляем 5 в начало
  list.addToBegin(3.1);
  list.addToBegin(43.2);
  list.addToBegin(56.3);
  list.addToEnd(111.1);
  list.show();

  List<char> charList;
  charList.addToBegin('A');

  return 0;
}
