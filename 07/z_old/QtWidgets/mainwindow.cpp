#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  //  ui->gridLayout->
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_2_clicked() {
  // TODO: Вывести сообщение: а мы и не сомневались!
}
