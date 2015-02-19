// "Странный" приоритет операций в стандарте
#include <iostream>

using namespace std;

int main() {
  int x = 4;
  cout << (x ^ 5 == 3) << endl;
}