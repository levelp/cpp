SQL (на примере sqlite), QtSql 
==============================

https://lisiynos.googlecode.com/git/dp/cpp_6_sql.html

Firefox Plugin:
https://addons.mozilla.org/ru/firefox/addon/sqlite-manager/


Язык SQL: SELECT, INSERT, UPDATE, DELETE 
----------------------------------------

**SQL (structured query language - «структурированный язык запросов»)** - формальный непроцедурный язык программирования, 
применяемый для создания, модификации и управления данными в произвольной реляционной базе данных, 
управляемой соответствующей системой управления базами данных (СУБД). SQL основывается на исчислении кортежей.

**Data Definition Language (DDL)** - язык описания данных: CREATE.

``` sql
SELECT * FROM имяТаблицы  -- Получить все записи из таблицы
SELECT поле1 FROM имяТаблицы  -- Получить только поле поле1 из таблицы
SELECT поле1,поле2 FROM имяТаблицы
SELECT * FROM имяТаблицы WHERE поле1 = 'Значение' -- Только записи где поле1 равно значению 
```

Выбираем Фамилию, Имя, Отчество через пробел как одну строчку:

``` sql
SELECT surname || ' ' || name || ' ' || middlename FROM contacts
```

Убираем пробелы в начале и конце строк:

``` sql
UPDATE contacts SET name = trim(name), surname=trim(surname), middlename=trim(middlename)
```

``` sql
SELECT * FROM contacts WHERE name='Иван' AND surname='Иванов'
```

``` sql
SELECT contacts.surname, contacts.name, contacts.middlename, 
   phones.phone, 
   phone_type.name AS type  
  FROM phones JOIN contacts ON phones.id_contact = contacts.id 
    JOIN phone_type ON phones.id_type = phone_type.id
```

LEFT JOIN - строки из таблицы слева всегда присутствуют.

``` sql 
SELECT contacts.surname, contacts.name, contacts.middlename, phones.phone, phone_type.name AS type  
FROM contacts LEFT JOIN phones ON phones.id_contact = contacts.id LEFT JOIN phone_type ON phones.id_type = phone_type.id
``

``` sql
-- Ищем нужные данные
SELECT * FROM contacts WHERE surname = 'Сидоров'
-- Обновляем записи
UPDATE contacts SET middlename='Петрович' WHERE surname = 'Сидоров'
```

``` sql
INSERT INTO contacts(surname, name, middlename, sex) VALUES('Иванов', 'Сидор', 'Матвеевич', 'M')
```

``` sql 
DELETE FROM contacts WHERE surname = 'Иванов'
```

```sql
BEGIN TRANSACTION  -- Начало транзакции
COMMIT -- Фискируем изменения 
ROLLBACK -- Отменяем все изменения
```

Подключение к Базе Данных из Qt 
-------------------------------

Класс **QSqlDatabase** представляет подключение к базе данных.

Соединение предоставляет доступ к базе данных через один из поддерживаемых драйверов баз данных, которые унаследованы от QSqlDriver.

Как написать собственный драйвер БД:
http://doc.crossplatform.ru/qt/4.5.0/sql-driver.html#how-to-write-your-own-database-driver

Названия драйверов для Qt: http://qt-project.org/doc/qt-5/sql-driver.html

Как создать и открыть соединение по умолчанию к базе данных **PostgreSQL**:
``` cpp
QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
db.setHostName("acidalia");
db.setDatabaseName("customdb");
db.setUserName("mojito");
db.setPassword("J0a1m8");
bool ok = db.open();
```

``` cpp
  // Подключаем драйвер для работы с SQLite
  QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
  // Имя файла с SQLite базой данных
  dbase.setDatabaseName("my_db.sqlite");
    // Для других БД - строка соединения 
  if (!dbase.open()) {
    qDebug() << "Не получилось открыть/создать файл с базой данных!";
    return -1;
  }
```

Выполнение инструкций SQL. Выполнение запроса и навигация по результирующей выборке
-----------------------------------------------------------------------------------

``` cpp
  // -- Создание схемы БД --
  // DDL query - создаём новую таблицу
  // Data Definition Language (DDL) - язык описания данных
  // Создаём табалицу контактов
  SQL_Execute("CREATE TABLE contacts ("
              "id INTEGER PRIMARY KEY AUTOINCREMENT,"
              "name TEXT,"
              "surname TEXT,"
              "birthday TEXT);");
  // Создаём таблицу телефонов
  SQL_Execute("CREATE TABLE phones ("
              "contact_id NUMERIC,"
              "phone TEXT);");
```

Вставка, изменение и удаление записей 
-------------------------------------



Транзакции 
----------

Использование классов-моделей SQL (модель запроса, модель таблицы). Отображение данных в таблице-представлении 
--------------------------------------------------------------------------------------------------------------



Сетевое программирование. QtNetwork 
===================================

Клиент-серверные приложения. Общие принципы. Обработка подключений в отдельном потоке 
-------------------------------------------------------------------------------------

Написание HTTP- и FTP-клиентов с помощью классов QHttp и QFtp 
-------------------------------------------------------------

Использование TCP с помощью классов QTcpSocket и QTcpServer 
-----------------------------------------------------------

Многопоточное программирование 
------------------------------

Системы контроля версий, git. Юнит-тестирование. QtTest. Shell 
==============================================================

Системы контроля версий: централизованные (SVN), децентрализованные (git)
-------------------------------------------------------------------------

Основные команды git (pull, push, commit, fetch..). Использование TortoiseGit. Хостинг на github и bitbucket 
------------------------------------------------------------------------------------------------------------
* https://github.com
* https://bitbucket.org
* https://code.google.com

Виды тестов: модульные, приёмочные (общее и отличия). Ручное тестирование. Модульные тесты в С/C++: CUnit, CppUnit (возможности) 
--------------------------------------------------------------------------------------------------------------------------------

QtTest 
------

Test Driven Development - разработка через тестирование ("красная" и "зелёная" полоса, цикл: тест - разработка - рефакторинг)
-----------------------------------------------------------------------------------------------------------------------------

Объекты заглушки (MockObjects) и их использование (цели, применимость) 
----------------------------------------------------------------------




Регулярные выражения
====================

Что такое регулярные выражения? 
-------------------------------

Математический аппарат конечных автоматов, теория формальных языков и грамматик 
-------------------------------------------------------------------------------

Базовые понятия: перечисление, группировка, квантификация
---------------------------------------------------------

Наборы символов. Утверждения
----------------------------

Использование QRegExp
---------------------



