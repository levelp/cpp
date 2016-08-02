#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <map>
#include <stdlib.h>


using namespace std;

map <string, string> dict;

void readFile() {
  ifstream source("source.txt");

  if (!source) {
    cout << "Can't open file \"source.txt\"!\n";
    getch();
    exit(0);
  }

  while (!source.eof()) {
    string from, to;
    source >> from >> to;
    dict[from] = to;
  }

  source.close();
}

int main() {
  setlocale(LC_ALL, "Russian");
  readFile();
  ifstream in("in.txt");
  ofstream out("out.txt");

  if (!in) {
    cout << "Can't open file \"in.txt\"!\n";
    getch();
    exit(1);
  }

  if (!out) {
    cout << "Can't open file \"out.txt\"!\n";
    getch();
    exit(1);
  }

  int word_count = 0;

  while (!in.eof()) {
    string s;
    in >> s;
    cout << (++word_count) << ". " << s << endl;
    out << dict[s] << " ";
  }

  in.close();
  out.close();
  return 0;
}
