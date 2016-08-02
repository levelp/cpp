#include <iostream>

using namespace std;

// Макрос S(x) - определение макроса с параметром x
//  #x - вставить x как строчку
//  x - вставить x как значение
#define S(x) cout << __LINE__ << ": " << #x << " = " << x << endl;

// size_t
// ======
// В каком диапазоне могут быть индексы в массиве?
//  int? long? unsigned int? long long?
// Индексы - точно целые неотрицательные числа,
//   отрицательные индексы бессмысленны
// Но какого они размера?
// Какой максимальный индекс возможен?
// Если убрать ограничения по памяти
// Почему нельзя char c[8000000000]?
// Правильный ответ на этот вопрос:
//    есть специальный тип size_t
//   если число в него укладывается, то
//   такой индекс может быть в этом компиляторе
//   если нет, то нет

// Объявляем собственный класс Массив
template <class T = int>
class Array {
  // Закрытые (private) поля класса
  size_t capacity; // Размер массива data
  T* data; // Динамический массив
  size_t size; // Текущий размер массива (элементов)
 public:
  Array() : capacity(1), size(0) {
    data = new T[capacity];
  }
  void add(T value) {
    if(size >= capacity) {
      // Удваиваем capacity
      capacity *= 2;
      // Заводим новый массив
      // в динамической памяти
      T* newData = new T[capacity];
      // Переносим (копируем) в него данные
      // из старого массива
      //     Куда <= Откуда  Размер в байтах
      memcpy(newData, data, size * sizeof(T));
      // for(int i = 0; i < size; i++)
      //    newData[i] = data[i];
      // Теперь заменяем data на newData
      delete[] data; // Удаляем старый data
      data = newData; // Сохраняем
    }

    data[size] = value;
    size++;
  }
  void show() {
    cout << "size = " << size << "  capacity " << capacity << endl;

    for(int i = 0; i < size; i++)
      cout << data[i] << " ";

    cout << endl;
  }
  T& operator[](size_t index) {
    return data[index];
  }
};

int main(int argc, char* argv[]) {
  //const unsigned int SIZE = 1000;
  //double a[(size_t)SIZE];
  Array<int> A;
  A.add(2);
  A.show();
  A.add(4);
  A.show();
  A.add(5);
  A.show();
  S(A[0]);
  S(A[1]);
  A[2] = 356;
  S(A[2]);
  A.show();

  Array<double> B;
  B.add(3.14159);
  B.show();

  return 0;
}

