#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_fontComboBox_currentIndexChanged(const QString& arg1) {
  // Новый выбранный шрифт
  QFont font = ui->fontComboBox->currentFont();
  qDebug() << font.family();
  ui->textEdit->setFont(font);
  ui->textEdit->setPlainText("Test");
  ui->lineEdit->setFont(font);
  qDebug() << ui->textEdit->font().family();
}

void MainWindow::on_fontComboBox_activated(const QString& arg1) {

}
