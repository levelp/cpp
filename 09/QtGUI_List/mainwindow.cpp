#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // В f записываем куда переключаться
  f = new Dialog(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_addToListButton_clicked() {
  // Получаем текст из textEdit
  QString s = ui->plainTextEdit->toPlainText();
  // Добавляем в listWidget
  ui->listWidget->addItem(s);
}

void MainWindow::on_actionSwitchToForm2_triggered() {
  // Это форма 1
  // Прячем свою форму
  hide();
  // Запоминаем ссылку для переключения обратно
  f->setFrom(this);
  // Показываем другую форму
  f->show();
}
