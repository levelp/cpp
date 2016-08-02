// Файловый ввод и вывод с помощью потоков
// ---------------------------------------
#include <iostream>
//-->
#include <fstream> // Файловый ввод и вывод с помощью потоков
//<--

using namespace std;

int main() {
  //-->
  ifstream in("in.txt");
  ofstream out("out.txt");

  int a, b;
  in >> a >> b;
  out << "a + b = " << (a + b) << endl;

  in.close();
  out.close();
  //<--

  return 0;
}
