#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "primecalcthread.h"
#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_primeSearchButton_clicked() {
  // Передаём все необходимые данные
  // при старте
  PrimeCalcThread* thread =
    new PrimeCalcThread(this,
                        ui->primesList,
                        ui->fromValue->value(),
                        ui->toValue->value()
                       );
  thread->start(QThread::LowestPriority);
  qDebug() << "After thread started";
}
