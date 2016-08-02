/// Изменение свойств объектов по событиям
/// ======================================
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

//-->
void MainWindow::on_incFontSizeButton_clicked() {
  // Получаем у кнопки её шрифт
  QFont font = ui->pushButton->font();
  font.setPointSize(font.pointSize() + 1);
  ui->pushButton->setFont(font);
  ui->pushButton->setText("Привет");
}
//<--

void MainWindow::on_decFontSizeButton_clicked() {
  QFont font = ui->pushButton->font();
  font.setPointSize(font.pointSize() - 1);
  ui->pushButton->setFont(font);
}

void MainWindow::on_incAllFontButton_clicked() {
  QFont font = ui->centralWidget->font();
  font.setPointSize(font.pointSize() + 1);
  ui->centralWidget->setFont(font);
}

void MainWindow::on_incConcreteButton_clicked() {
  QFont font = ui->incAllFontButton->font();
  font.setPointSize(font.pointSize() + 1);
  ui->incAllFontButton->setFont(font);
}
