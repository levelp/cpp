#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  for(int i = 1; i <= 3; i++) {
    QString s = QString("Запись %1").arg(i);
    ui->listWidget->addItem(s);
  }

}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_addButton_clicked() {
  QString s = ui->nameEdit->text();
  ui->listWidget->addItem(s);
}

void MainWindow::on_deleteButton_clicked() {
  QList<QListWidgetItem*> list = ui->listWidget->selectedItems();
  // for(int i = list.size()-1; i >= 0; i--){
  //ui->listWidget->removeItemWidget(list.at(i));
  //  delete list.at(i);
  // }

  foreach (QListWidgetItem* item, list)
    delete item;
}
