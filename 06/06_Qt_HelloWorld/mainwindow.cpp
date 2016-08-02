#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_anyDo_clicked() {
  cout << "AnyDo()" << endl;
  ui->log->addItem("AnyDo()");
}

void MainWindow::on_setAnyDoAction_clicked() {
  cout << "connect(ui->anyDo, SIGNAL(clicked(),"
       "this, SLOT(close());" << endl;
  connect(ui->anyDo, SIGNAL(clicked()),
          this, SLOT(close()));
}
