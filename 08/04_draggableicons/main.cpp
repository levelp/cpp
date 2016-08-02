#include <QApplication>
#include <QHBoxLayout>
#include "mainwindow.h"

#include "dragwidget.h"

int main(int argc, char* argv[]) {
  Q_INIT_RESOURCE(draggableicons);

  QApplication app(argc, argv);

  MainWindow w;
  w.show();

  return app.exec();
}
