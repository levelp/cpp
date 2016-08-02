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

void MainWindow::on_upButton_clicked() {
  // Получаем текущее расположение кнопки
  QRect rect = ui->pushButton->geometry();
  // Изменяем координаты кнопки
  rect.moveTop(rect.top() - 10);
  // Передаём изменённые координаты обратно в интерфейс
  ui->pushButton->setGeometry(rect);
}

void MainWindow::on_downButton_clicked() {
  // Получаем текущее расположение кнопки
  QRect rect = ui->pushButton->geometry();
  // Изменяем координаты кнопки
  rect.moveTop(rect.top() + 10);
  // Передаём изменённые координаты обратно в интерфейс
  ui->pushButton->setGeometry(rect);
}

void MainWindow::on_leftButton_clicked() {
  // Получаем текущее расположение кнопки
  QRect rect = ui->pushButton->geometry();
  // Изменяем координаты кнопки
  rect.moveLeft(rect.left() - 10);
  // Передаём изменённые координаты обратно в интерфейс
  ui->pushButton->setGeometry(rect);
}

void MainWindow::on_rightButton_clicked() {
  // Получаем текущее расположение кнопки
  QRect rect = ui->pushButton->geometry();
  // Изменяем координаты кнопки
  rect.moveLeft(rect.left() + 10);
  // Передаём изменённые координаты обратно в интерфейс
  ui->pushButton->setGeometry(rect);
}
