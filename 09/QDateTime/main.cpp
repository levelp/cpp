#include <QApplication>
#include "wnd.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  TWindow wnd;
  wnd.show();
  return a.exec();
}
