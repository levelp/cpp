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

void MainWindow::on_lineEdit_3_cursorPositionChanged(int arg1, int arg2) {

}



void MainWindow::on_right_clicked() {
  if(X >= 270)
    X = 270;
  else {
    X = X + 5;
    ui->textEdit->move(X, Y);
  }
}

void MainWindow::on_left_clicked() {

  if(X <= 128)
    X = 128;

  X = X - 5;
  ui->textEdit->move(X, Y);
}

void MainWindow::on_up_clicked() {
  if(Y <= 33)
    Y = 33;

  Y = Y - 5;
  ui->textEdit->move(X, Y);
}

void MainWindow::on_down_clicked() {
  if(Y >= 115)
    Y = 115;

  Y = Y + 5;
  ui->textEdit->move(X, Y);
}
