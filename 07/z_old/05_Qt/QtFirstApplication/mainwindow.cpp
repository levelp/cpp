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

void MainWindow::on_strAddButton_clicked() {
  // Получаем строчку из первого (верхнего) поля
  QString s1 = ui->lineEdit1->text();
  int i1 = s1.toInt();
  // Получаем строчку из второго поля
  QString s2 = ui->lineEdit2->text();
  int i2 = s2.toInt();
  // Складываем числа
  int sum = i1 + i2;
  // Результат в строчку
  // ..используем строку форматирования..
  QString res = QString("%1+%2=%3")
                .arg(i1).arg(i2).arg(sum);
  // Помещаем результат обратно в интерфейс
  ui->resEdit->setText(res);
}
