#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginform.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_actionLogin_triggered() {
  LoginForm* lf = new LoginForm(this);
  lf->show();
}
