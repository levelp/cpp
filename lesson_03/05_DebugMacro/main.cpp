// Макросы для отладки
// -------------------
#include <iostream>
#include <cassert> // C++. Подключаем библиотеку для assert
#include <assert.h> // C

using namespace std;

//-->
#define MY_DEBUG
#ifdef MY_DEBUG
#define SHOW(x) cout << __FILE__ << ":" << __LINE__ << " " << #x << " = " << x << endl;
#else
#define SHOW(x) ;
#endif

#define ASSERT_EQ(a,b) ((a == b) ? (void)0 : _assert(#a" != "#b, __FILE__, __LINE__))
//<--

int main() {
  int i = 324;
  SHOW(i);
  char* myString = "Hello World!";
  SHOW(myString);

  assert(2 * 2 == 4);

  char* c = NULL; //new
  assert(c == NULL);

  ASSERT_EQ(2 * 2 + 4, 8);

  char a = 'a' + 1;

  return 0;

}
