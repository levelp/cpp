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

void MainWindow::on_incFontSizeButton_clicked() {
  QFont font = ui->pushButton->font();
  font.setPointSize(font.pointSize() + 1);
  ui->pushButton->setFont(font);

  //ui->pushButton->setText("Привет");
}

void MainWindow::on_decFontSizeButton_clicked() {
  QFont font = ui->pushButton->font();
  font.setPointSize(font.pointSize() - 1);
  ui->pushButton->setFont(font);
}
