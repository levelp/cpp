//  Пример консольной программы для демонстрации принципов работы с БД в Qt
// -------------------------------------------------------------------------
// SQLite - компактная встраиваемая реляционная база данных
// Слово «встраиваемый» означает, что SQLite не использует парадигму клиент-сервер,
// то есть движок SQLite не является отдельно работающим процессом,
// с которым взаимодействует программа, а предоставляет библиотеку,
// с которой программа компонуется и движок становится составной частью программы.
// Таким образом, в качестве протокола обмена используются вызовы функций (API) библиотеки SQLite.
// Такой подход уменьшает накладные расходы, время отклика и упрощает программу.
// SQLite хранит всю базу данных (включая определения, таблицы, индексы и данные)
// в единственном стандартном файле на том компьютере, на котором исполняется программа.
#include <QtSql> // Библиотека со всеми нужным классами
#include <iostream>
#include <clocale>

using namespace std;

// query - SQL-запрос в виде строки
void SQL_Execute(QString query) {
  // QSqlQuery a_query(query);
  // SELECT * FROM phone WHERE people_id = 1
  //QString sqlTemplate("SELECT * FROM phone WHERE people_id = %1");
  //QSqlQuery query;
  //bool res = query.exec(sqlTemplate.arg(1));

  QSqlQuery q;
  bool res = q.exec(query);

  if (!res) {
    qDebug() << "Cannot execute: " << query
             << q.lastError().text();
  }
}

// Можно сделать отдельную функцию для добавления контакта,
// которая принимает параметрами данные о контакте
void AddContact(QString name, QString birthday = NULL) {
  if(birthday == NULL) {
    // Шаблон SQL-запроса INSERT   %1 %2 %3 - параметры шаблона
    QString q = "INSERT INTO "
                "contacts(name,birthday) "
                "VALUES('%1',NULL);";
    SQL_Execute(q.arg(name));
  } else {
    QString q = "INSERT INTO "
                "contacts(name,birthday) "
                "VALUES('%1','%2');";
    SQL_Execute(q.arg(name).arg(birthday));
  }
}

// Проверка что таблица существует
//   tableName - имя таблицы
bool TableExists(QString tableName) {
  // Шаблон запроса
  QString queryTemplate =
    "SELECT count(*) AS count "   // count(*) - просто возвращает количество записей удовлетворяющих критериям
    "FROM sqlite_master WHERE "   // sqlite_master - служебная таблица с информацией обо всех таблицах, столбцах и др. объектах БД
    " type = 'table' AND name = '%1'";
  // %1 - первый аргумент
  QSqlQuery q;
  QString sql = queryTemplate.arg(tableName);
  qDebug() << "SQL: " << sql;

  if (!q.exec(sql)) {
    // Если exec() вернул false => при выполнении запроса
    // произошла ошибка => надо об этом сообщить пользователю
    // и завершить программу.
    // "Мёртвые программы не лгут" (с) "Программист-прагматик"
    qDebug() << q.lastError().text();
    return false;
  }

  // Читаем таблицу результатов
  QSqlRecord rec = q.record();
  q.next();
  int result = q.value(rec.indexOf("count")).toInt();
  cout << "result " << result << endl;

  if(result == 0)
    cout << "Table " << tableName.toStdString() << " - not exists!" << endl;
  else
    cout << "Table " << tableName.toStdString() << " - OK" << endl;

  return result;
}


void ShowContacts() {
  QSqlQuery q; // Запрос

  if (!q.exec("SELECT * FROM contacts")) {
    qDebug() << "Cannot Select data";
    return;
  }

  QSqlRecord rec = q.record();
  cout << "Count: " << q.size() << endl;

  int count = 0;

  // Выбираем следующую строку
  while (q.next()) {
    // Для Qt до версии 5
    // Индекс (начиная с нуля) столбца с заданным именем
    // в строке результатов
    int fieldNo = q.record().indexOf("name");
    //QVariant nameQVariant = q.value("name");
    //QString name = nameQVariant.toString();
    QString name = q.value(fieldNo).toString();
    QString birthday = q.value("birthday").toString();

    //        cout << ++count << ". " << name.toLocal8Bit().constData() << " " <<
    //                birthday.toStdString() << " " << endl;
    qDebug() << ++count << ". " << name << " " <<
             birthday << " " << endl;
  }

}

// Работаем с БД SQLite
int SQLiteTest() {
  // -- Подключение к Базе Данных --
  // Подключаем драйвер для работы с SQLite
  cout << "SQLite driver" << endl;
  // Названия драйверов для Qt:
  //   http://qt-project.org/doc/qt-5/sql-driver.html
  QSqlDatabase dbase =
    QSqlDatabase::addDatabase("QSQLITE");
  // Sqlite3
  // Имя файла с SQLite базой данных
  dbase.setDatabaseName("my_db.sqlite");

  if (!dbase.open()) {
    qDebug() << "Не получилось открыть/создать файл с базой данных!";
    return -1;
  }

  // База данных открыта и можно выполнять запросы

  // -- Создание схемы БД --
  // DDL query - создаём новую таблицу
  // Data Definition Language (DDL) - язык описания данных

  // Создаём таблицу контактов
  SQL_Execute("CREATE TABLE contacts ("
              "id INTEGER PRIMARY KEY AUTOINCREMENT,"
              "name TEXT,"
              "surname TEXT,"
              "birthday TEXT);");
  // Создаём таблицу телефонов
  SQL_Execute("CREATE TABLE phones ("
              "contact_id NUMERIC,"
              "phone TEXT);");


  TableExists("not_existing_table");
  TableExists("phones");

  // -- Добавление данных --
  // DML
  // Data Manipulation Language (DML) - язык управления (манипулирования) данными

  AddContact("Вася", "25.01.2014");
  AddContact("Петя", NULL);
  AddContact("Маша", "26.01.2014");
  AddContact("Оля", "25.01.2014");
  AddContact("Оля", "26.01.2014");
  AddContact("Лена", "31.01.2014");
  AddContact("Лена", "31.01.2014");
  AddContact("Лена", "31.01.2014");
  AddContact("Лена", "31.01.2014");
  AddContact("Иван Васильевич", NULL);

  SQL_Execute("INSERT INTO phones VALUES(9,'+79113523325')");
  SQL_Execute("INSERT INTO phones VALUES(7,'+79213295835')");

  // -- Выполнение запроса и навигация по результирующей выборке --
  ShowContacts();

  cout << "DELETE example" << endl;
  SQL_Execute("DELETE FROM contacts WHERE name='Лена'");

  cout << ">>>>" << endl;
  ShowContacts();
  cout << "<<<<" << endl;

  QSqlQuery a_query;

  // Сложный запрос с JOIN'ами
  if (!a_query.exec("SELECT name, phone FROM"
                    " contacts LEFT JOIN phones "
                    "ON contacts.id = phones.contact_id "
                    "WHERE name = 'Лена'")) {
    qDebug() << "Даже селект не получается, я пас.";
    return -2;
  }

  QSqlRecord rec = a_query.record();
  QString name = "", phone = "";

  int count = 0;

  while (a_query.next()) {
    name = a_query.value(rec.indexOf("name")).toString();
    phone = a_query.value(rec.indexOf("phone")).toString();

    cout << ++count << ". " << name.toLocal8Bit().constData() << " " <<
         phone.toStdString() << " " << endl;
  }


  return 0;
}


int main() {
  //setlocale(LC_ALL, "Russian");

  SQLiteTest();

  return 0;
}
