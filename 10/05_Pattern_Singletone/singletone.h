#ifndef SINGLETONE_H
#define SINGLETONE_H

#include <stdlib.h>

// T - из какого класса хотим сделать Singletone
template <class T>
class Singletone {
  // -static uniqueInstance
  // Один-единственный экземпляр класса T
  static T* uniqueInstance;

 public:
  // +static instance()
  static T& instance() {
    // Если объект ещё не создан
    if(uniqueInstance == NULL) {
      // Создаём его
      uniqueInstance = new T();
      // Можно вызывать private конструктор, т.к.
      // мы внутри класса T
    }

    return *uniqueInstance;
  }
};

// Первоначально экземпляр класса не создан
template <class T>
T* Singletone<T>::uniqueInstance = NULL;

#endif // SINGLETONE_H
