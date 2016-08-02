#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  cout << "MainWindow constructor" << endl;
}

MainWindow::~MainWindow() {
  cout << "MainWindow destructor" << endl;

  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  cout << "Нажали кнопку \"Сумма\"" << endl;
}
