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

void MainWindow::on_hiButton_clicked() {
  ui->lineEdit->setText("Привет!");
}

void MainWindow::on_byeButton_clicked() {
  ui->lineEdit->setText("Пока!");
}
