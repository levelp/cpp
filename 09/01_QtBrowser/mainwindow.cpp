#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "urlcomplete.h"
#include "mockurlworker.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  UrlComplete uc(new MockUrlWorker());
  uc.complete("google.com");
  uc.complete("ya.ru");
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  UrlComplete uc(this);
  uc.complete(ui->urlEdit->text());
}

void MainWindow::DoURL(QString URL) {
  ui->webView->setUrl(URL);
}
