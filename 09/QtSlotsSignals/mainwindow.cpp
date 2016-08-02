#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  cout << "Test" << endl;

  // Связываем слот и сигнал из кода
  connect(ui->pushButton,    // Откуда сигнал (объект)
          SIGNAL(clicked()), // Какой сигнал
          this,  // Куда отправить (объект)
          SLOT(mySlot())); // в какой слот

  QString s1 = "1";
  QString s2 = "2";
  QString res = s1 + "x" + s2; // "1x2"
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::mySlot() {
  qDebug() << "mySlot";
}

void MainWindow::on_pushButton_2_clicked() {
  cout << "color: #FFFF00" << endl;
  ui->pushButton->setStyleSheet("color: #FFFF00");
}

void MainWindow::on_pushButton_3_clicked() {
  cout << "color: #00FFFF" << endl;
  ui->pushButton->setStyleSheet("color: #00FFFF");
}
