#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
// Подключаем .h файл второй формы
#include "spacersform.h"
#include "buttonsform.h"

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
  /*QFont font = ui->fontComboBox->currentFont();
  qDebug() << font.family();
  ui->textEdit->setFont(font);
  ui->textEdit->setPlainText("Test");
  ui->lineEdit->setFont(font);
  qDebug() << ui->textEdit->font().family(); */
}

void MainWindow::on_fontComboBox_activated(const QString& arg1) {

}

void MainWindow::on_spacersButton_clicked() {
  SpacersForm* form = new SpacersForm(this);
  form->show();
}

void MainWindow::on_actionGroupBox_triggered() {
  ButtonsForm* form = new ButtonsForm(this);
  form->show();
}

void MainWindow::on_action_triggered() {
  SpacersForm* form = new SpacersForm(this);
  form->show();
}
