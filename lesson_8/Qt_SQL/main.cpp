// SQLite - компактная встраиваемая реляционная база данных
// Слово «встраиваемый» означает, что SQLite не использует парадигму клиент-сервер,
// то есть движок SQLite не является отдельно работающим процессом,
// с которым взаимодействует программа, а предоставляет библиотеку,
// с которой программа компонуется и движок становится составной частью программы.
// Таким образом, в качестве протокола обмена используются вызовы функций (API) библиотеки SQLite.
// Такой подход уменьшает накладные расходы, время отклика и упрощает программу.
// SQLite хранит всю базу данных (включая определения, таблицы, индексы и данные)
// в единственном стандартном файле на том компьютере, на котором исполняется программа.
#include "mainwindow.h"
#include <QApplication>
#include <QtSql>

// Работаем с БД SQLite
int SQLiteTest(){
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    // Имя файла с SQLite базой данных
    dbase.setDatabaseName("my_db.sqlite");
    if (!dbase.open()) {
        qDebug() << "Не получилось открыть файл с базой данных!";
        return -1;
    }

    QSqlQuery a_query;
    // DDL query - создаём новую таблицу
    QString str = "CREATE TABLE my_table ("
            "number integer PRIMARY KEY NOT NULL, "
            "address VARCHAR(255), "
            "age integer"
            ");";
    bool b = a_query.exec(str);
    if (!b) {
        qDebug() << "Не могу создать таблицу CREATE TABLE!";
    }

    // DML
    QString str_insert = "INSERT INTO my_table(number, address, age) "
            "VALUES (%1, '%2', %3);";
    str = str_insert.arg("14")
            .arg("hello world str.")
            .arg("37");
    b = a_query.exec(str);
    if (!b) {
        qDebug() << "Кажется данные не вставляются, проверьте дверь, может она закрыта?";
    }
    //.....
    if (!a_query.exec("SELECT * FROM my_table")) {
        qDebug() << "Даже селект не получается, я пас.";
        return -2;
    }
    QSqlRecord rec = a_query.record();
    int number = 0,
            age = 0;
    QString address = "";

    while (a_query.next()) {
        number = a_query.value(rec.indexOf("number")).toInt();
        age = a_query.value(rec.indexOf("age")).toInt();
        address = a_query.value(rec.indexOf("address")).toString();

        qDebug() << "number is " << number
                 << ". age is " << age
                 << ". address" << address;
    }
    return 0;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SQLiteTest();

    MainWindow w;
    w.show();
    
    return a.exec();
}
