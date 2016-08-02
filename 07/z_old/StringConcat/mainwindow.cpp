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
  // 1. Получаем данные из интерфейса
  QString s1 = ui->lineEdit_1->text();
  QString s2 = ui->lineEdit_2->text();

  // 2. Соединяем 2 строки в одну (конкатенация)
  QString res = "Привет, " + s1 + " и " + s2 + "!";

  // 3. Отправляем результат в интерфейс
  ui->resLabel->setText(res);
}
