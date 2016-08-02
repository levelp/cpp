#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  this->setStyleSheet("#centralWidget { background-image: url(:/main/back.jpg) }");
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_beginButton_clicked() {

}
