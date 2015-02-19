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

void MainWindow::on_rightButton_clicked() {
  QRect rect = ui->object->geometry();
  rect.translate(ui->step->value(), 0);
  ui->object->setGeometry(rect);
}

void MainWindow::on_downButton_clicked() {
  QRect rect = ui->object->geometry();
  rect.translate(0, ui->step->value());
  ui->object->setGeometry(rect);
}

void MainWindow::on_leftButton_clicked() {
  QRect rect = ui->object->geometry();
  rect.translate(-ui->step->value(), 0);
  ui->object->setGeometry(rect);
}

void MainWindow::on_upButton_clicked() {
  QRect rect = ui->object->geometry();
  rect.translate(0, -ui->step->value());
  ui->object->setGeometry(rect);
}
