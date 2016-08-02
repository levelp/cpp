#include <iostream>
#include <list>

// Каждый компонент умеет себя "показывать" -
// т.е. выполнять метод show
class Component {
 public:
  virtual void show() = 0;
};

// Лист (нижний уровень дерева)
// просто выводит строчку на экран
class Leaf : public Component {
  std::string s;
 public:
  Leaf(std::string s) : s(s) {}
  void show() {
    std::cout << s.c_str() << std::endl;
  }
};

// Составной объект состоит из нескольких компонент
class Composite : public Component {
  // Содержит несколько компонент (является контейнером)
  std::list<Component*> list;
 public:
  void show() {
    std::list<Component*>::iterator i;

    for(i = list.begin(); i != list.end(); i++)
      (*i)->show();
  }
  void add(Component* child) {
    list.push_back(child);
  }
  void remove(Component* child) {
    list.remove(child);
  }
};

int main() {
  Composite comp;
  Leaf test("test");
  test.show();

  comp.add(&test);
  Composite a;
  a.add(new Leaf("aa"));
  a.add(new Leaf("bb"));
  a.show();

  comp.add(&a);
  comp.show();

  return 0;
}
