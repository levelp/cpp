#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_goButton_clicked() {
  QString url = ui->urlEdit->text();

  if(!url.startsWith("http://") &&
      !url.startsWith("https://"))
    url = "https://" + url;

  ui->webView->setUrl(url);
}

void MainWindow::on_actionAbout_triggered() {
  QMessageBox::information(this,
                           "О программе",
                           "Это наш браузер :)");
}
