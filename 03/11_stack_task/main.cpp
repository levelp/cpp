#include <iostream>

using namespace std;

class Stack {
  // Поля объекта - переменные "внутри" объекта
  // Их нужно заполнить перед использованием
  // начальными корретными значениями
  // "проинициализировать"
  // Сам процесс - "инициализация"
  int size; // Размер стека
  string* data; // Указатель на массив строк
  int count = 0; // Количество элементов в стеке
 public:
  // Конструктор
  // Используется список инициализации
  Stack(int s) : size(s) { // size = s
    cout << "Constructor size = " << size << endl; //c~tor
    data = new string[size];
  }
  void push(string s) {
    if(count >= size) {
      cout << "Stack is full!" << endl;
      return;
    }

    data[count] = s;
    count++;
  }
  string pop() {
    if(count <= 0) {
      cout << "Stack is empty!" << endl;
      return "Error!!";
    }

    --count;
    return data[count];
  }
};

int main() {
  string str = "Test";
  string str2("Test");
  cout << str << endl;

  Stack s(10); // 10 - размер стека в элементах
  // Поместить на вершину стека
  s.push("Hello!");
  s.push("World!");

  // Получить элемент с вершины стека и удалить его
  cout << s.pop() << endl;
  cout << s.pop() << endl;

  return 0;
}
