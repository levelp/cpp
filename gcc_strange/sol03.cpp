// <<Странный>> приоритет операций в стандарте C++
#include <iostream>

using namespace std;

int main() {
  int x = 4;
  cout << (x ^ 5 == 3) << endl;
}
// Как получается 4?
