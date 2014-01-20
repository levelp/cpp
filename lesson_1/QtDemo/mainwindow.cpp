#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Получаем 2 строки из интерфейса
    QString a = ui->textEdit_1->toPlainText();
    QString b = ui->textEdit_2->toPlainText();
    // Конкатенация строк
    QString c = a + b;
    // Передаём результат в интерфейс
    ui->textEditSum->setText(c);
}
