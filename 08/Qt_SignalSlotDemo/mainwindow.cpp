#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::slot1() {
  ui->listWidget->addItem("slot1");
}

void MainWindow::slot2() {
  ui->listWidget->addItem("slot2");
}
