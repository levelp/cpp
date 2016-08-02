#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Подключение к Базе Данных
  dbase = QSqlDatabase::addDatabase("QSQLITE");
  // Имя файла с SQLite базой данных
  dbase.setDatabaseName("..\\QtSQL_Students\\students.sqlite");

  // Открываем соединение с Базой Данных
  if (!dbase.open()) {
    // Возвращается false если не получилось
    // поключиться к Базе Данных

    // Чтобы понять что пошло не так
    // получаем код и текст ошибки
    QSqlError err = dbase.lastError();
    QMessageBox::critical(NULL,
                          "Не открыть/создать файл с базой данных!",
                          err.text());
    return;
  }

  // Показываем таблицу студентов
  model = new QSqlTableModel(this, dbase);
  model->setTable("student");
  model->setEditStrategy(QSqlTableModel::OnFieldChange);
  model->select();

  // Задаём таблице tableView
  // модель данных model
  // Таблица показывает данные из model
  // а когда мы редактируем данные
  // отправляет их обратно через model в
  // Базу данных
  ui->tableView->setModel(model);
  ui->tableView->resizeColumnsToContents();
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_addButton_clicked() {
  // Создаём новую строчку
  QSqlRecord newRec = model->record();
  // Заполняем её поля
  newRec.setValue("name", ui->nameEdit->text());
  newRec.setValue("surname", ui->surnameEdit->text());
  newRec.setValue("middlename", ui->middlenameEdit->text());
  // Добавляем её в таблицу (в модель)
  model->insertRecord(model->rowCount(), newRec);
  // Отправляем изменения в БД из модели
  model->submitAll();
  // Обновляем модель из БД чтобы получить новые
  // id для новых строк
  model->select();
}

void MainWindow::on_deleteSelectedButton_clicked() {
  // Получаем, какие строчки выбраны
  QModelIndexList list = ui->tableView->selectionModel()->selection().indexes();
  // Пробежим в цикле индексы с конца и вызовем для каждого removeRow
  for(int i = list.size() - 1; i >= 0; i--)
    model->removeRow(list.at(i).row());
  // Обновляем модель из БД чтобы
  // убрать строки из таблицы
  model->select();
}

void MainWindow::on_filterEdit_textChanged(const QString& arg1) {
  // Когда меняем текст в фильтре,
  // обновляем таблицу,
  // выполняем новый select
  QString f = QString("UPPER(surname) LIKE '%%1%'").arg(ui->filterEdit->text().toUpper());
  ui->filterReadyEdit->setText(f);
  model->setFilter(f);
}
