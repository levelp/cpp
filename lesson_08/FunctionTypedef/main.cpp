#include <QCoreApplication>

// __stdcall

//typedef int(*myfun)(int a, void *b)

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  return a.exec();
}
