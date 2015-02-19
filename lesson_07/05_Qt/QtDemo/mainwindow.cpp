#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  // Получаем 2 строки из интерфейса
  QString a = ui->textEdit_1->toPlainText();
  QString b = ui->textEdit_2->toPlainText();
  // Конкатенация строк
  QString c = a + b;
  // Передаём результат в интерфейс
  ui->textEditSum->setText(c);
}

// Генерация случайной строки
QString MainWindow::generateRandomString() {
  QString str;
  int length = rand() % 20 + 3;

  for(int i = 0; i < length; ++i) {
    // Любая буква английского алфавита
    char nextChar = rand() % ('Z' - 'A' + 1) + 'A';
    str += nextChar;
  }

  return str;
}

void MainWindow::on_generateStr1_triggered() {
  ofstream of("log.txt");
  qDebug() << "Generate first string";
  of << "Генерируем первую строку";
  of.close();

  // Генерируем первую строку
  ui->textEdit_1->setText(generateRandomString());
}

void MainWindow::on_generateStr2_triggered() {
  // Генерируем вторую строку
  ui->textEdit_2->setText(generateRandomString());
}
