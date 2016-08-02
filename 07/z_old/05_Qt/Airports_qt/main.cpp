#include <QCoreApplication>
#include <iostream>
#include <cstdio>
#include <QDebug>
#include <windows.h>

#include <QtSql/qsql.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

using namespace std;

void AddFlight(QString id, QString name, QString direction, QString flightNumber, QString timeOfDepature) {
  QString sqlTemplate =
    "INSERT INTO AirportOfDepature(id,name,direction,flightNumber,timeOfDepature)"
    "VALUES('%1','%2','%3','%4','%5')";
  QString sql =
    sqlTemplate.arg(id).arg(name).arg(direction).arg(flightNumber).arg(timeOfDepature);
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
  QCoreApplication app(argc, argv);

  // freopen("log.txt", "w", stdout);

  cout << "Database driver loading" << endl;

  QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");

  QString fileName = "airports.sqlite";
  cout << "Create Database file: " << fileName.toStdString() << endl;

  dbase.setDatabaseName(fileName);

  cout << "Database opening" << endl;

  if(!dbase.open()) {
    cout << "Database opening error" << endl;
    QSqlError error = dbase.lastError();
    qDebug() << error.text();
    return -1;
  }

  cout << "Table adding" << endl;
  QSqlQuery sql;

  if(!sql.exec("CREATE TABLE AirportOfDepature"
               "(id TEXT,"
               "name TEXT,"
               "direction TEXT,"
               "flightNumber TEXT,"
               "timeOfDepature TEXT)")) {
    cout << "The table AirportOfDepature creating was failed" << endl;
    QSqlError error = sql.lastError();
    cout << error.text().toStdString() << endl;
    // return -1;
  }

  cout << "Data inserting to Database" << endl;
  AddFlight("HAM", "Fuhlsbuettel", "Zurich", "LH_819", "14:50");
  AddFlight("LHR", "Heathrow", "Rome Leonardo da Vinci", "AZ_2234", "15:00");
  AddFlight("PRG", "Prague Vaclav Havel", "Brussels", "OK_888", "15:15");
  AddFlight("LED", "Saint-Petersburg Pulkovo", "Rimini Federico Fellini", "BA_7645", "15:45");
  AddFlight("FLR", "Florence Peretola", "Glasgow", "AZ_895", "15:56");

  cout << "Data selecting from tables" << endl;
  QSqlQuery query;
  query.exec("SELECT direction FROM AirportOfDepature WHERE timeOfDepature = '15:56'");

  cout << "Data deleting from Database" << endl;
  query.exec("DELETE FROM AirportOfDepature WHERE name = 'Heathrow'");

  cout << "Data updating in Database" << endl;

  if(!sql.exec("UPDATE AirportOfDepature SET timeOfDepature = '16:00' WHERE timeOfDepature = '15:15'")) {
    QSqlError error = sql.lastError();
    cout << error.text().toStdString() << endl;
    return -1;
  }

  return 0;
}
