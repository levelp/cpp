#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dragwidget.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->horizontalLayout->
  addWidget(new DragWidget);
  ui->horizontalLayout->
  addWidget(new DragWidget);
}

MainWindow::~MainWindow() {
  delete ui;
}
