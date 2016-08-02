#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  // Создаём и настраиваем виджеты
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  // Удаляем форму
  delete ui;
}

void MainWindow::on_concatButton_clicked() {
  // Поле называется: имяПоля
  // get - имяПоля()
  // set - setИмяПоля()
  // Получить текст из строки 1
  QString str1 = ui->strEdit1->text();
  // Получить текст из строки 2
  QString str2 = ui->strEdit2->text();
  // Соединяем 2 строки
  QString result = str1 + str2;
  // Результат отправляем в интерфейс
  ui->resultEdit->setText(result);
}
