#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QDebug>

SecondWindow::SecondWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::SecondWindow) {
  ui->setupUi(this);
}

SecondWindow::~SecondWindow() {
  qDebug() << "Деструктор SecondWindow";
  delete ui;
}
