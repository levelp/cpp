#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Модель данных (массив 9 на 9 элементов)
  model = new QStandardItemModel(9, 9);

  // В таблице в интерфейсе будет показываться именно
  // эта модель
  ui->tableView->setModel(model);

  // Добавляем таблицу чисел
  for(int i = 1; i <= 9; ++i)
    for(int j = 1; j <= 9; ++j) {
      QString s = QString::number(i * j);
      model->setItem(i - 1, j - 1,
                     new QStandardItem(s));
    }
}

MainWindow::~MainWindow() {
  delete ui;
}
