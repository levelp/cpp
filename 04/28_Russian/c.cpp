#include <iostream>
#include <locale>
using namespace std;
int main() {
  std::locale::global (std::locale ("Russuan_Russia.UTF-8"));
  wcout << L"привет\n";
}