/// Автоматическое удаление при указании parent
/// -------------------------------------------
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myclass.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  MyClass* obj = new MyClass(this);
  cout << "------" << endl;
  //delete obj;
}

MainWindow::~MainWindow() {
  delete ui;
}
