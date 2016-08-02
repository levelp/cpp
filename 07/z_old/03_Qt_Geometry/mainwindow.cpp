/// Положение и размеры виджетов
/// ----------------------------
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

void MainWindow::on_upButton_clicked() {
  ///-->
  QRect r = ui->object->geometry();
  r.setBottom(r.bottom() - ui->step->value());
  r.moveTop(r.top() - ui->step->value());
  ui->object->setGeometry(r);
  ///<--
}

void MainWindow::on_downButton_clicked() {
  ///-->
  // Получаем прямоугольник с координатами перемещаемого объекта
  QRect r = ui->object->geometry();
  // Двигаем прямоугольник
  r.translate(0, ui->step->value());
  // Задаём новое положение объекта
  ui->object->setGeometry(r);
  ///<--
}

void MainWindow::on_rightButton_clicked() {

}
