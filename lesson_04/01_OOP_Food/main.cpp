// Приготовление ужина
// -------------------
// Дано: набор продуктов
// их можно смешивать, подогревать
// Нужно: хранить набор продуктов,
//  + добавлять новый продукт
#include <iostream>
#include <cassert>
#include <climits>
#include <cstring>

using namespace std;

const double EPS = 1e-10;

// Компонент еды - конкретный продукт
class FoodItem {
 public:
  char* name = "";
  char* measureUnit = "";
  double amount;
};

// Список продуктов
class FoodList {
  struct Element {
    FoodItem item;
    Element* next = NULL;
  };
  // Корневой элемент списка
  Element* root = NULL;
 public:
  // Список пуст?
  bool isEmpty() {
    return root == NULL;
  }
  // Добавляем элемент в начало списка
  void add(FoodItem item) {
    Element* e = new Element;
    e->item = item;
    // Добавляем элемент в начало
    // как в стек
    e->next = root;
    root = e;
  }
  void add(char* name, double amount,
           char* measureUnit) {
    FoodItem item;
    item.name = name;
    item.amount = amount;
    item.measureUnit = measureUnit;

    add(item);
  }

  // Количество данного компонента
  double getAmount(char* name) {
    Element* cur = root;

    while(cur != NULL) {
      if(!strcmp(cur->item.name, name)) {
        // Нашли нужный компонент
        return cur->item.amount;
      }

      cur = cur->next;
    }

    // Если не нашли такого продукта?
    return 0;
  }

  int calc(FoodList& food) {
    // Минимум из всех компонент
    int minComp = INT_MAX;

    Element* cur = food.root;

    while(cur != NULL) {
      // Сколько у нас данного продукта есть?
      double weHave = getAmount(cur->item.name);

      if(weHave > EPS) {
        // Сколько мы можем приготовить
        // учитывая только этот компонент
        int c = weHave / cur->item.amount;
        cout << weHave << " / " << cur->item.amount
             << " -> " << c << endl;

        if(c < minComp)
          minComp = c;
      }

      cur = cur->next;
    }

    return minComp;
  }
};

int main() {
  // Пустой список продуктов
  FoodList foodList;
  assert(foodList.isEmpty());

  FoodItem milk;
  milk.name = "Молоко";
  milk.amount = 1;
  milk.measureUnit = "л";

  foodList.add(milk);
  assert(!foodList.isEmpty());

  FoodItem m2;
  m2.name = "Мука пшеничная";
  m2.amount = 400;
  // Единица измерения
  m2.measureUnit = "г.";
  foodList.add(m2);

  FoodItem s;
  s.name = "Сахар";
  s.amount = 3;
  s.measureUnit = "столовые ложки";
  foodList.add(s);

  // Новый список - список, что нужно для
  // приготовления блинов
  FoodList pancake;
  pancake.add("Молоко", 0.1, "л");
  pancake.add("Мука пшеничная", 100, "г.");

  cout << foodList.calc(pancake) << endl;

  return 0;
}
