// VisualStudioExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

typedef int(*myfun)(int a, void* b);

void f(myfun x) {
  cout << "return " << x(1, NULL) << endl;
}

int f1(int N, void* xxx) {
  cout << "f1 " << N << endl;
  return 1;
}

int f2(int N, void* xxx) {
  cout << "f2 " << N << endl;
  return 2;
}


int _tmain(int argc, _TCHAR* argv[]) {
  f(f1);
  f(f2);
  system("pause");
  return 0;
}

