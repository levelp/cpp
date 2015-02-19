#include <QDebug> // Вывод отладочных сообщений в консоль
#include <QMessageBox> // Вывод окон с сообщениями пользователю
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "historybutton.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_goButton_clicked() {
  // При нажатии на кнопку Go переходим на адрес
  ui->webView->setUrl(ui->urlEdit->text());
}

// Добавление адреса сайта в закладки
void MainWindow::on_toolButton_clicked() {
  // Создаём новую кнопку
  HistoryButton* button =
    new HistoryButton(
    this,
    ui->urlEdit->text()
  );

  // Добавляем на панель
  ui->historyToolbar->addWidget(button);
}

void MainWindow::on_goToHistory_clicked() {
  // Кто отправил сигнал?
  HistoryButton* button = (HistoryButton*)QObject::sender();

  if(button == NULL) {
    qDebug() << "Должны быть только объекты QPushButton";
    return;
  }

  QString url = button->url();
  // Выводим URL для отладки
  qDebug() << "URL:" << url;
  ui->urlEdit->setText(url);
  ui->webView->setUrl(url);
}

void MainWindow::on_webView_urlChanged(const QUrl& url) {
  ui->urlEdit->setText(url.toString());
}
