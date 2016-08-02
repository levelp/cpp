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

void MainWindow::on_addButton_clicked() {
  // Добавить запись в дерево
  //ui->treeWidget->selectionModel()->selection()
  QTreeWidgetItem* item = new QTreeWidgetItem();
  item->setText(0, ui->lineEdit->text());
  ui->treeWidget->insertTopLevelItem(
    ui->treeWidget->topLevelItemCount(),
    item);

  // Сортировка
  /*QTreeWidgetItem *item1 = ui->treeWidget->itemAt(0, 0);
  QTreeWidgetItem *item2 = ui->treeWidget->itemAt(1, 0);
  ui->treeWidget->insertTopLevelItem(0, item2);
  ui->treeWidget->insertTopLevelItem(1, item1);
  */
  ui->treeWidget->sortByColumn(0, Qt::AscendingOrder);
}
