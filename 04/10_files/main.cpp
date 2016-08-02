#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream in("data.txt");
  string s;
  double x, y;
  in >> s >> x >> y;
  cout << s << " " << x << " " << y << endl;
  in.close();

  ofstream out("log.txt");

  out << "Привет, мир!" << endl;

  for(int i = 0; i < 10; ++i)
    out << i << "^2 = " << i* i << endl;

  out.close();
  return 0;
}
