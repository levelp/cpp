#include <QCoreApplication>
#include <QtSql>
#include <QString>
#include <QFile>
#include <QDebug>
#include <cstdio>

int main(int argc, char* argv[]) {
  freopen("stderr.txt", "w", stderr);

  QString fileName = "..\\phonebook.sql";

  QFile sqlFile(fileName);
  sqlFile.open(QIODevice::ReadOnly | QIODevice::Text);

  QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
  // Имя файла с SQLite базой данных
  dbase.setDatabaseName("..\\phonebook.sqlite");

  if (!dbase.open()) {
    qDebug() << "Не получилось открыть/создать файл с базой данных!";
    return -1;
  }

  QTextStream in(&sqlFile);
  in.setCodec("UTF-8");

  while(!in.atEnd()) {
    // Читаем SQL оператор
    QString line = in.readLine();
    qDebug() << line;

    // Выполняем в базе данных
    QSqlQuery query;

    if(!query.exec(line)) {
      qDebug() << "SQL Error:" << line <<
               query.lastError().text();
    }
  }

  sqlFile.close();

  return 0;
}
