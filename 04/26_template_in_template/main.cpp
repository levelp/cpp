#include <iostream>
#include <assert.h>

using namespace std;

// Шаблонная функция вычисления минимума
template <class T>
T myMin(T a, T b) {
  return (a < b) ? a : b;
}
/*
int min(int a, int b){
  return (a < b) ? a : b;
}
double min(double a, double b){
  return (a < b) ? a : b;
}
char min(char a, char b){
  return (a < b) ? a : b;
}
MyClass min(MyClass a, MyClass b){
  return (a < b) ? a : b;
}
MyClass operator <
*/

// Стек заданной длины
//  T - тип элементов
//  Size - максимальное количество
//    (размер стека)
template <typename T, int Size>
class Stack {
  // Массив для хранения данных
  T data[Size];
  // Количество элементов
  int size;
 public:
  typedef T value_type;

  int getSize() {
    return size;
  }

  Stack() {
    size = 0;
  }
  // Положить в стек значение
  void push(T value) {
    assert(size < Size);
    data[size] = value;
    ++size;
  }
  // Извлечь с вершины стека значение
  T pop() {
    assert(size > 0);
    --size;
    return data[size];
  }

  T getFirst() {
    return pop();
  }
};

// Очередь заданной длины
template <typename T, int Size>
class Queue {
  T data[Size];
  // Голова и хвост очереди
  int head, tail;
 public:
  typedef T value_type;
  // Количество элементов
  int getSize() {
    return tail - head + 1;
  }

  Queue() {
    head = 0;
    tail = -1;
  }
  // Положить в конец очереди
  void put(T value) {
    tail++;
    data[tail % Size] = value;
  }
  // Взять из начала очереди
  T get() {
    return data[head++ % Size];
  }

  T getFirst() {
    return get();
  }

};

// TODO: Разобрать пример на следующем занятии
// Шаблонная функция для печати любой коллекции
/*template <template<typename X, int I> class T>
void show(T<X, int> t){
  cout << "size = " << t.getSize() << endl;
  typename T::value_type temp = t.getFirst();
  cout << "First element: " << temp << endl;
}; */

template <class T>
void show(T t) {
  cout << "size = " << t.getSize() << endl;
  typename T::value_type temp = t.getFirst();
  cout << "First element: " << temp << endl;
}

/*template <template<typename,int> class T>
  void show2(T< <typename X, int I> > t){
    cout << "size = " << t.getSize() << endl;
    typename T::value_type temp = t.getFirst();
    cout << "First element: " << temp << endl;
  }; */



int main() {
  cout << myMin(2, 3) << endl;
  cout << myMin(2.3, 3.22) << endl;
  cout << myMin<char>('s', 'd') << endl;

  Stack<int, 3> s;
  Stack<int, 3>::value_type tt = 2;
  s.push(1);
  s.push(2);
  s.push(3);
  show(s);

  Queue<double, 4> q;
  q.put(2.2);
  show(q);

  /*  Shower<Stack<int, 3> > ss; */

  return 0;
}
