#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>
#include <QStandardItem>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Создаём модель в динамической памяти
  listModel = new QStandardItemModel();

  // Первый список строк
  ui->listView->setModel(listModel);
  // Задаём как модель для дерева
  ui->treeView->setModel(listModel);
  // Задаём как модель для таблицы
  ui->tableView->setModel(listModel);

  ui->columnView->setModel(listModel);
}

MainWindow::~MainWindow() {
  delete ui;
}

// Когда нажимаем на кнопку "Добавить"
void MainWindow::on_addButton_clicked() {
  // Добавляем запись в listView (текст берём из интерфейса)
  qDebug() << "Add item to listView (text from interface)";
  QStandardItem* Items =
    new QStandardItem(ui->lineEdit->text());
  listModel->appendRow(Items);
}

void MainWindow::on_removeButton_clicked() {
  // Удалить выделенную запись
  foreach( // Каждый элемент коллекции (массива)
    const QModelIndex& index,
    // Массив (коллекция) по которой надо пробежать
    ui->listView->selectionModel()->selectedIndexes())
    listModel->removeRow(index.row());
}
