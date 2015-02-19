#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  QString fileName("..\\phonebook.sqlite");
  db.setDatabaseName(fileName);

  if (!db.open()) {
    QMessageBox::critical(this, "Ошибка",
                          QString("Невозможно открыть файл с БД: %1").
                          arg(fileName)
                          , QMessageBox::Cancel);
    return;
  }

  QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE");
  QString fileName2("..\\phonebook2.sqlite");
  db2.setDatabaseName(fileName);

  if (!db2.open()) {
    QMessageBox::critical(this, "Ошибка",
                          QString("Невозможно открыть файл с БД: %1").
                          arg(fileName)
                          , QMessageBox::Cancel);
    return;
  }

  model = new QSqlTableModel(this, db);
  model->setTable("people");
  model->setEditStrategy(QSqlTableModel::OnFieldChange);
  model->select();

  ui->tableView->setModel(model);

}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_deleteButton_clicked() {
  QItemSelectionModel* selectionModel = ui->tableView->selectionModel();
  QModelIndexList indexes = selectionModel->selectedRows();

  for(int i = 0; i < indexes.size(); ++i) {
    int index = indexes[i].row();
    model->removeRow(index);
  }

  // Сохраняем все изменения
  model->submitAll();

  // Обновляем модель
  model->select();
}

void MainWindow::on_addButton_clicked() {
  // TODO: разобраться с id autoincrement
  model->insertRow(model->rowCount());
}
