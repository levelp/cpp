#include "mywindow.h"
#include "ui_mywindow.h"
#include <QDebug>

MyWindow::MyWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MyWindow) {
  ui->setupUi(this);
}

MyWindow::~MyWindow() {
  delete ui;
}

void MyWindow::on_onButton_clicked() {
  ui->exitButton->setVisible(true);
}

void MyWindow::on_offButton_clicked() {
  ui->exitButton->setVisible(false);
}

void MyWindow::on_exitButton_clicked() {
  close();
}

void MyWindow::close() {
  // Save
  // ...
  qDebug() << "Debug Info";

  QMainWindow::close();
}
