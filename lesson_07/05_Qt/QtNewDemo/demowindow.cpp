#include "demowindow.h"
#include "ui_demowindow.h"

DemoWindow::DemoWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::DemoWindow) {
  ui->setupUi(this);
}

DemoWindow::~DemoWindow() {
  delete ui;
}
