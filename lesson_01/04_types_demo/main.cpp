// Операции
// --------
#include <iostream>

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");
  /*  int a = 10;
    cout << a++ << endl;
    cout << a << endl;
    cout << ++++++++++a << endl;
    cout << a << endl;

    cout << --++--++a << endl; */

  int b = 10;
  int res = b == 10;
  cout << "b = 10" << endl;
  cout << "b == 10 -> " << (b == 10) << endl;
  cout << "b == 11 -> " << (b == 11) << endl;
  cout << "b > 10 -> " << (b > 10) << endl;
  cout << "b < 11 -> " << (b < 11) << endl;
  cout << "b >= 10 -> " << (b >= 10) << endl;
  cout << "b <= 11 -> " << (b <= 11) << endl;
  cout << "b != 11 -> " << (b != 11) << endl;

  cout << "b == 11 или b == 10 -> " << (b == 11 || b == 10) << endl;

  cout << "0 || 0 -> " << (0 || 0) << endl;
  cout << "0 || 2 -> " << (0 || 2) << endl;
  cout << "2 || 0 -> " << (2 || 0) << endl;
  cout << "2 || 2 -> " << (2 || 2) << endl;

  cout << "0 && 0 -> " << (0 && 0) << endl;
  cout << "0 && 2 -> " << (0 && 2) << endl;
  cout << "2 && 0 -> " << (2 && 0) << endl;
  cout << "2 && 2 -> " << (2 && 2) << endl;




  for(int i = -2; i <= 4; i++) {
    int j = i;

    if(j = 0)
      cout << i << " - истина!" << endl;
    else
      cout << i << " - ложь!" << endl;
  }


  return 0;
}
