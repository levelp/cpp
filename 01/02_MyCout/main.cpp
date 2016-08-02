/// Использование namespace - пространств имён
/// ------------------------------------------
/// Можно объявить свой cout
#include <iostream>

using namespace std;

//-->
namespace my {
int cout = 10;
}

using namespace my;

int main() {
  cout << "cout = " << my::cout << endl;
  return 0;
}
//<--
