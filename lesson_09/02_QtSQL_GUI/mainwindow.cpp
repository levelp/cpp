#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  if(!createConnection()) {
    QMessageBox::critical(this,
                          "Ошибка", "Не могу подключиться к Базе Данных",
                          QMessageBox::Ok );
  }


  model = new QSqlTableModel(this);
  model->setTable("person");
  model->setEditStrategy(QSqlTableModel::OnFieldChange);

  model->select();

  model->setHeaderData(0, Qt::Horizontal, tr("ID"));
  model->setHeaderData(1, Qt::Horizontal, tr("Имя"));
  model->setHeaderData(2, Qt::Horizontal, tr("Фамилия"));

  // Задаём на нашего компонента view
  ui->tableView->setModel(model);
  ui->tableView->resizeColumnsToContents();

  ui->tableView_2->setModel(model);
  ui->tableView_2->resizeColumnsToContents();

  ui->listView->setModel(model);
}

MainWindow::~MainWindow() {
  delete ui;
}

bool MainWindow::createConnection() {
  // Устанавливаем соединение
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  //db.setDatabaseName(":memory:");
  db.setDatabaseName("SQL_GUI.sqlite");

  if (!db.open()) {
    QMessageBox::critical(0, qApp->tr("Cannot open database"),
                          qApp->tr("Unable to establish a database connection.\n"
                                   "This example needs SQLite support. Please read "
                                   "the Qt SQL driver documentation for information how "
                                   "to build it.\n\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
    return false;
  }

  QSqlQuery query;
  query.exec("create table person (id int primary key, "
             "firstname varchar(20), lastname varchar(20))");
  query.exec("insert into person values(101, 'Danny', 'Young')");
  query.exec("insert into person values(102, 'Christine', 'Holand')");
  query.exec("insert into person values(103, 'Lars', 'Gordon')");
  query.exec("insert into person values(104, 'Roberto', 'Robitaille')");
  query.exec("insert into person values(105, 'Maria', 'Papadopoulos')");

  query.exec("create table items (id int primary key,"
             "imagefile int,"
             "itemtype varchar(20),"
             "description varchar(100))");
  query.exec("insert into items "
             "values(0, 0, 'Qt',"
             "'Qt is a full development framework with tools designed to "
             "streamline the creation of stunning applications and  "
             "amazing user interfaces for desktop, embedded and mobile "
             "platforms.')");
  query.exec("insert into items "
             "values(1, 1, 'Qt Quick',"
             "'Qt Quick is a collection of techniques designed to help "
             "developers create intuitive, modern-looking, and fluid "
             "user interfaces using a CSS & JavaScript like language.')");
  query.exec("insert into items "
             "values(2, 2, 'Qt Creator',"
             "'Qt Creator is a powerful cross-platform integrated "
             "development environment (IDE), including UI design tools "
             "and on-device debugging.')");
  query.exec("insert into items "
             "values(3, 3, 'Qt Project',"
             "'The Qt Project governs the open source development of Qt, "
             "allowing anyone wanting to contribute to join the effort "
             "through a meritocratic structure of approvers and "
             "maintainers.')");

  query.exec("create table images (itemid int, file varchar(20))");
  query.exec("insert into images values(0, 'images/qt-logo.png')");
  query.exec("insert into images values(1, 'images/qt-quick.png')");
  query.exec("insert into images values(2, 'images/qt-creator.png')");
  query.exec("insert into images values(3, 'images/qt-project.png')");

  return true;
}

void MainWindow::on_submitChangesButton_clicked() {
  model->database().transaction();

  if (model->submitAll())
    model->database().commit();
  else {
    model->database().rollback();
    QMessageBox::warning(this, tr("Cached Table"),
                         tr("The database reported an error: %1")
                         .arg(model->lastError().text()));
  }
}
