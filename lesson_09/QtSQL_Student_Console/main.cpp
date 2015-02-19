#include <QCoreApplication>
#include <locale.h>

#include <QtSql/qsql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <iostream>
#include <QTextCodec>
#include <QDebug>
#include <windows.h>

using namespace std;

void AddStudent(QString name, QString surname, int subject) {
  QString sqlTemplate =
    "INSERT INTO Student(name,surname,likeSubject) "
    "VALUES('%1','%2',%3)";
  QString sql =
    sqlTemplate.arg(name).arg(surname).arg(subject);
  cout << sql.toStdString() << endl;

  QSqlQuery query;

  if(!query.exec(sql)) {
    QSqlError error = query.lastError();
    cout << error.text().toStdString() << endl;
  }

  cout << query.lastInsertId().Int << endl;
  cout << query.executedQuery().toStdString() << endl;
}

int main(int argc, char* argv[]) {
  // system("chcp 65001");
  //setlocale(LC_ALL, "Russian.UTF-8");
  // SetConsoleCP(65001);
  // SetConsoleOutputCP(65001);
  freopen("log.txt", "w", stdout);


  //QTextCodec* tc = QTextCodec::codecForName("IBM 866");

  //cout << QString(tc->fromUnicode("Юникод СТрока :)")).data() << endl;

  cout << "Загружаем драйвер Базы Данных" << endl;

  QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");

  QString fileName = "students.sqlite";
  cout << "Создадим файл с Базой Данных: " << fileName.toStdString() << endl;

  dbase.setDatabaseName(fileName);

  cout << "Открываем Базу Данных" << endl;

  if(!dbase.open()) {
    cout << "Ошибка при открытии БД" << endl;
    QSqlError error = dbase.lastError();
    qDebug() << error.text();
    return 1; // Завершаем программу
  }

  cout << "Добавим таблицы" << endl;
  QSqlQuery sql;

  if(!sql.exec("CREATE TABLE Student"
               "(likeSubject NUMERIC, "
               "id INTEGER PRIMARY KEY, "
               "name TEXT, surname TEXT)")) {
    cout << "Не удалось создать таблицу Student" << endl;
    QSqlError error = sql.lastError();
    cout << error.text().toStdString() << endl;
  }

  // MySQL   number_of_lessons
  // MSSQL   NumberOfLessons
  // ORACLE  NUMBER_OF_LESSONS

  if(!sql.exec("CREATE TABLE Subject"
               "(number_of_lessons NUMERIC, "
               "name TEXT, id INTEGER PRIMARY KEY)")) {
    cout << "Не удалось создать таблицу Subject" << endl;
    QSqlError error = sql.lastError();
    cout << error.text().toStdString() << endl;
  }

  cout << "DELETE - удалим данные из БД" << endl;
  sql.exec("DELETE FROM Student");

  cout << "Выполним INSERT - добавим данные в БД" << endl;
  AddStudent("Иван", "Иванов", 1);
  AddStudent("Пётр", "Петров", 4);
  AddStudent("Сидор", "Сидоров", 2);
  sql.exec("INSERT INTO Student(name,surname,likeSubject) VALUES('Иван','Иванов',1)");

  cout << "Выполним SELECT - получим данные из таблиц" << endl;

  cout << "UPDATE - изменим данные в БД" << endl;

  if(!sql.exec("UPDATE Student SET name = 'Ваня' WHERE name = 'Иван'")) {
    QSqlError error = sql.lastError();
    cout << error.text().toStdString() << endl;
  }

  return 0;
}
