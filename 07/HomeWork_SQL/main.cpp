#include <QCoreApplication>
#include <QtSql> // Для работы с SQLite

int main() {
  QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
  // Назначаем имя файлу
  dbase.setDatabaseName("../HomeWork/practic.sqlite");

  // Открываем БД
  if (!dbase.open()) {
    qDebug() << dbase.lastError().text();
    return 1;
  }

  // Создаём экземпляр класса QSqlQuery чтобы выполнить запрос
  QSqlQuery q;

  // Выполняем запрос, если ошибка в запросе,
  // то метод возвращает false
  if(!q.exec("SELECT * FROM students")) {
    // Выводим подробное сообщение об ошибке
    qDebug() << "SQL error: " << q.lastError().text();
    return 1;
  }

  while(q.next()) {
    qDebug() << q.value("name").toString() <<
             "  " << q.value("surname").toString();
  }

  return 0;
}
