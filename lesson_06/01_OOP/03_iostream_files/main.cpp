#include <iostream>
#include <fstream>

using namespace std;

// cin - istream;
// cout - ostream;
int main() {
  // ifstream - input file stream
  //
  // Открываем текстовый файл для ввода
  //-->
  ifstream in("data.txt");
  string s;
  double x, y;
  in >> s >> x >> y;
  cout << s << " " << x << " " << y <<
       "   x + y = " << (x + y) << endl;
  in.close();
  //<--

  // Перенаправляем вывод в файл **log.txt**:
  //-->
  freopen("log.txt", "a", stdout);

  cout << "Квадраты чисел:" << endl;

  for(int i = 0; i < 10; ++i)
    cout << i << "^2 = " << i* i << endl;

  //<--
  // Выходной файл автоматически
  // закрывается при закрытии программы

  return 0;
}
