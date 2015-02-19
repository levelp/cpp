#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
// Подключаю вторую форму чтобы использовать
// её из первой
#include "form2.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Создаём поле
  const int MapSize = 6;
  const int ButtonSize = 40;

  for(int i = 0; i < MapSize; ++i)
    for(int j = 0; j < MapSize; ++j) {
      QPushButton* button = new QPushButton(this);
      int x1 = j * ButtonSize + 30;
      int y1 = i * ButtonSize + 30;
      button->setGeometry(x1, y1, ButtonSize, ButtonSize);

      connect(button, SIGNAL(clicked()),
              this, SLOT(s()));

      button->setText(QString("%1x%2").arg(i).arg(j));

      //button->setVisible(true);
    }
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  Form2* f = new Form2(NULL);
  f->show();
}

void MainWindow::s() {
  // QObject::sender() - указатель на отправителя сигнала
  // проблема в том что этот указатель не того типа
  // Он типа QObject*, а не QPushButton*
  // Поэтому мы его приводим к нужному типу
  QPushButton* button = (QPushButton*) QObject::sender();
  // a = (double)(23423 + 32424)
  qDebug() << "Button pressed " << button->text();

  // Выключаем поле
  button->setEnabled(false);
}
