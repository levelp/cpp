/// Вывод таблицы ASCII
/// ===================
#include <iostream>
//-->
#include <iomanip> // Функция setw
//<--

using namespace std;

int main() {
  /// Цикл для вывода таблицы ASCII
  //-->
  for(int code = 0; code < 256; code++)
    cout << setw(4) << code << " " << (char)code << "  ";
  //<--
  return 0;
}
