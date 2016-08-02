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

void MainWindow::on_downButton_clicked() {
  ui->textEdit->append("Вниз");
  // TODO: реализовать перемещение
  //ui->textEdit->geometry().translate(0, 10);
  QRect rect = ui->textEdit->geometry();
  rect.translate(0, 10);
  ui->textEdit->setGeometry(rect);
}

void MainWindow::on_rightButton_clicked() {
  ui->textEdit->append("Вправо");
  // TODO: реализовать перемещение
  QRect rect = ui->textEdit->geometry();
  rect.translate(10, 0);
  ui->textEdit->setGeometry(rect);
}

void MainWindow::on_leftButton_clicked() {
  ui->textEdit->append("Влево");
  // TODO: реализовать перемещение
  QRect rect = ui->textEdit->geometry();
  rect.translate(-10, 0);
  ui->textEdit->setGeometry(rect);
}

void MainWindow::on_upButton_clicked() {
  ui->textEdit->append("Вверх");
  // TODO: реализовать перемещение
  QRect rect = ui->textEdit->geometry();
  rect.translate(0, -10);
  ui->textEdit->setGeometry(rect);
}
