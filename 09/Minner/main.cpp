#include <QApplication>
#include "common.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  QTranslator myTranslator;
  myTranslator.load("minner_" + QLocale::system().name());
  a.installTranslator(&myTranslator);

  Minner w;
  w.show();
  return a.exec();
}
