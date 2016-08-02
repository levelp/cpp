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

void MainWindow::on_pushButton_clicked() {
  // Получаем текст из интерфейса
  QString s1 = ui->lineEdit1->text();
  QString s2 = ui->lineEdit2->text();
  // Объединяем строки и получаем результат
  QString res = s1 + s2;
  // Передаю текст обратно в интерфейс
  ui->resultEdit->setText(res);
}
