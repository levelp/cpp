#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_concButton_clicked() {
  // Получаем 2 строки из интерфейса
  QString s1 = ui->lineEdit_1->text();
  QString s2 = ui->lineEdit_2->text();
  // Соединяем строки
  QString res = s1 + s2;

  // Результат в интерфейс
  ui->resultEdit->setText(res);
}

void MainWindow::on_openSecondWindowButton_clicked() {
  SecondWindow* w = new SecondWindow(this);

  w->show();

  qDebug() << "Конец метода";
}
