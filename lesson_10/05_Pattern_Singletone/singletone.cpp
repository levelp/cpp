#include "singletone.h"


static T& Singletone::instance() {
  // Если объект ещё не создан
  if(uniqueInstance == NULL) {
    // Создаём его
    uniqueInstance = new T();
    // Можно вызывать private конструктор, т.к.
    // мы внутри класса T
  }

  return *uniqueInstance;
}
