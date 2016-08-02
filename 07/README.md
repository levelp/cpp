<!-- doc.py -->
﻿SQL (на примере sqlite), QtSql
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




Доступ к свойствам
------------------
Если свойство называется имяСвойства
То для получения значения надо вызвать
метод имяСвойства(), и он вернёт значение свойства.
Причём это значение - копия реального значения.
Для изменения свойства вызвать:
setИмяСвойства(новоеЗначение)
Так сделать не получится:
``` cpp
ui->textEdit->geometry().translate(0, 10);
```
[00_HomeWork_Done/mainwindow.cpp](00_HomeWork_Done/mainwindow.cpp)

Перечисления (enum)
-------------------
Зачем?
Удобная замена константам
которые соответствуют разным элементам
одного и того же типа.
Направления движения:
вверх - 0, вниз - 1,
влево - 2, вправо - 3
``` cpp
const int X_UP = 0;
const int X_DOWN = 1;
const int X_LEFT = 2;
const int X_RIGHT = 3;
int direction = X_UP;

// Вводим специальный тип
enum Direction {
  UP = 4 /* 0 */, DOWN = 13 /* 1 */,
  LEFT = (1L << 31) - 1 /* 2 */,
  RIGHT = 7 /* 3 */
};

// Используем значения для констант
// в перечислении по-умолчанию
// т.е. 0, 1, 2...
enum DirectionX {
  T_UP /* 0 */, T_DOWN /* 1 */,
  T_NEW_SUPER_DIRECTION, /* 2 */
  T_LEFT /* 2->3 */, T_RIGHT /* 3->4 */
};
// Способы избежать "сдвига" констант в перечислении:
// 1. Задавать значения констант явно
// 2. Добавлять новые значения ТОЛЬКО в конец

// Когда используются перечисления:
// 1. Мы их можем перечислить сразу (при создании
//  приложения) и добавление каждой новой
//  константы требует изменения логики
// 2 (доп). Когда констант относительно немного
// Чтобы добавить новый элемент в перечисление
// надо перекомпилировать программу.
// Т.е. если при добавлении нового элемента
// скорее надо будет добавить/изменить код
// => всё равно перекомпилировать программу
// => используйте перечисление
```

Последовательная нумерация
[01_Enums/main.cpp](01_Enums/main.cpp)

Глобальная переменная в **vars.h**
``` cpp
extern int globalVar;
```

[02_Extern_vars/module1.cpp](02_Extern_vars/module1.cpp)

Определение глобальной переменной
в **module1.cpp**
``` cpp
int globalVar = 2;
```

В **module2.cpp** тоже можно
использовать **globalVar**
``` cpp
void v2() {
  D(globalVar = 2);
  SHOW(globalVar);
}

void show2() {
  SHOW(globalVar);
}
```

[02_Extern_vars/module2.cpp](02_Extern_vars/module2.cpp)

Работа с QString
----------------
http://doc.qt.io/qt-5/
http://doc.qt.io/qt-5/qstring.html
[03_QString/mainwindow.cpp](03_QString/mainwindow.cpp)

Задание "Русская рулетка"
-------------------------
Очищаем лог игры
``` cpp
  ui->gameLog->clear();
```

Инициализируем генератор случайных
чисел по таймеру
``` cpp
  qsrand(time(0));
```

Добавление строки в "протокол" (log) игры
``` cpp
void MainWindow::log(QString s) {
  ui->gameLog->append(s);
}
```

Один раунд игры
``` cpp
  round++;
  log(QString("<strong>Раунд %1:</strong>").arg(round));

  // Ставка
  double bet = ui->betEdit->value();
  // На какое число ставим
  int betNumber = ui->numberEdit->value();
  log(QString("Ваша ставка %1 на %2.").
      arg(bet).arg(betNumber));

  // Крутим рулетку
  // qrand() 0..MAX_INT = 2^31-1
  int randNumber = random(1, 10); // Число 1..10
  log(QString("Выпало: %1.").arg(randNumber));

  // Пересчитываем баланс
  // QString.toDouble() - преобразует строку
  //  вида "213.1" в число типа double
  double balance = ui->balanceLabel->text().toDouble();
  // Запоминаем баланс
  double prev = balance;

  if(randNumber == betNumber) {
    balance += bet * 10;
    log(QString("Выйграли! Новый счёт: %1 + %2 = %3")
        .arg(prev).arg(balance - prev).arg(balance));
  } else {
    balance -= bet;
    log(QString("Проиграли! Новый счёт: %1 - %2 = %3")
        .arg(prev).arg(prev - balance).arg(balance));
  }

  // Баланс показываем в интерфейсе
  ui->balanceLabel->setText(
    QString("%1").arg(balance, 0, 'f', 1)
  );
```

[HomeWork_RussianRoulette/mainwindow.cpp](HomeWork_RussianRoulette/mainwindow.cpp)

Генерация случайного целого числа в диапазоне
low..high
``` cpp
int random(int low, int high) {
  return low + qrand() % (high - low + 1);
}
```

[HomeWork_RussianRoulette/random.cpp](HomeWork_RussianRoulette/random.cpp)

Генерация случайного целого числа
в диапазоне low..high
``` cpp
int random(int low, int high);
```

[HomeWork_RussianRoulette/random.h](HomeWork_RussianRoulette/random.h)


﻿1. Перетаскивание (завершить пример)
2. Кнопка своей формы (с картинкой и т.д.)
3. Консоль в Windows приложениях
4. Внешние файлы стилей.

Занятие 9:
4. Способы оформления QML/CSS и т.д.
5. QML - обработка событий


Печать в строку как в поток
``` cpp
  ostringstream sstream;
  sstream << sum;
```

[z_old/01_QtWidgets/demowidgetswindow.cpp](z_old/01_QtWidgets/demowidgetswindow.cpp)

Создание класса в C++ по его идентификатору
-------------------------------------------
Иерархия классов
``` cpp
struct MyClass {
  virtual void show() = 0;
};

struct MyClass1 : public MyClass {
  MyClass1() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
  void show() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
};

struct MyClass2 : public MyClass {
  MyClass2() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
  void show() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
};

```

Первый способ
-------------
Функция - фабрика
``` cpp
MyClass* CreateInstance(int id) {
  switch(id) {
    case 1:
      return new MyClass1();

    case 2:
      return new MyClass2();

    default:
      cout << "TODO: " << __FUNCTION__ << " for " << id << endl;
  }

  throw id;
}
```

Использование
``` cpp
  MyClass* a = CreateInstance(1);
  a->show();
  MyClass* b = CreateInstance(2);
  b->show();
```

Второй способ
-------------
Спецификация шаблона для определённых значений
``` cpp
template<int id>
MyClass* Create() {
  throw "Need specialization";
}

template<>
MyClass* Create<1>() {
  return new MyClass1();
}

template<>
MyClass* Create<2>() {
  return new MyClass2();
}
```

Использование
``` cpp
  MyClass* a1 = Create<1>(), *a2 = Create<2>();
  a1->show();
  a2->show();
```

[z_old/02_AbstractFactory/main.cpp](z_old/02_AbstractFactory/main.cpp)

﻿``` delphi
type
  TMyClass = class
  end;

  TMyClass2 = class(TMyClass)
  end;

  TMyClassType = class of TMyClass;

  procedure CreateClass;
  var
    MyClassType: TMyClassType;
    MyClassObj: TMyClass;
  begin
    MyClassType := TMyClass;
    MyClassObj := MyClassType.Create; // эквивалентно MyClassObj := TMyClass.Create

    MyClassType := TMyClass2;
    MyClassObj := MyClassType.Create; // эквивалентно MyClassObj := TMyClass2.Create

    // ps: вся прелесть в том что MyClassType - переменная, которая может
    //     принимать как значение тип класса любого обьекта совместимого с
    //     TMyClass
  end;
```

Положение и размеры виджетов
----------------------------
``` cpp
  QRect r = ui->object->geometry();
  r.setBottom(r.bottom() - ui->step->value());
  r.moveTop(r.top() - ui->step->value());
  ui->object->setGeometry(r);
```

``` cpp
  // Получаем прямоугольник с координатами перемещаемого объекта
  QRect r = ui->object->geometry();
  // Двигаем прямоугольник
  r.translate(0, ui->step->value());
  // Задаём новое положение объекта
  ui->object->setGeometry(r);
```

[z_old/03_Qt_Geometry/mainwindow.cpp](z_old/03_Qt_Geometry/mainwindow.cpp)

Исключения
----------
[z_old/05_Exceptions/main.cpp](z_old/05_Exceptions/main.cpp)

Изменение свойств объектов по событиям
======================================
``` cpp
void MainWindow::on_incFontSizeButton_clicked() {
  // Получаем у кнопки её шрифт
  QFont font = ui->pushButton->font();
  font.setPointSize(font.pointSize() + 1);
  ui->pushButton->setFont(font);
  ui->pushButton->setText("Привет");
}
```

[z_old/05_Qt/01_QtGUI_Properties/mainwindow.cpp](z_old/05_Qt/01_QtGUI_Properties/mainwindow.cpp)

Отладка Qt приложений
=====================
* Точки останова
* Логгирование
``` cpp
class string {
  static int count; // Общая переменная
  int id; // Идентификатор объекта
 public:
  char* Str; // Строка
  int size() { // Длина строки
    return strlen(Str);
  }
 public:
  string(string&); // Конструктор копирования
  string(char* str) {
    Str = new char[size() + 1]; // Добавляем 1,
    // потому что в строке символ 0 - окончание строки
    strcpy(Str, str);
    id = ++count;
  }
  void show() {
    std::cout << "#" << id << " (" << count << ") " << " " << Str
              << "  Адрес: " << ((int)Str)
              << std::endl;
  }
  int operator ==(string& right) {
    return Str == right.Str;
  }
  int operator !=(string& right) {
    return Str != right.Str;
  }
};
```

Создает копии динамических переменных и ресурсов:
``` cpp
string::string(string& right) {
  Str = new char[right.size() + 1];
  strcpy(Str, right.Str); // strcpy - копирование строки
  id = ++count;
  std::cout << "string copy contructor" << std::endl;
}
```

[z_old/05_Qt/02_Qt_console_debug/main.cpp](z_old/05_Qt/02_Qt_console_debug/main.cpp)

Когда нажимаем на цифру:
``` cpp
  switch (calcState) {
    case OPERATION: // Если сейчас операция
      // Очищаем дисплей
      clearDisplay();
      break;

    default:
      break;
  }

  // UTF-8
  QString s = ui->display->text();

  // (QPushButton *)QObject::sender() -
  //  отправитель текущего сигнала
  QPushButton* digitButton =
    (QPushButton*)QObject::sender();

  if(digitButton == NULL)
    return;

  QChar zero('0');

  // Удаляем из s все лидирующие нули
  if(s.at(0) == zero)
    s.remove(0, 1);

  // Дописываем новую цифру на экран
  s += digitButton->text();

  ui->display->setText(s);
```

[z_old/05_Qt/04_QtCalc/mainwindow.cpp](z_old/05_Qt/04_QtCalc/mainwindow.cpp)

Размер поля игры (глобальная переменная)
[z_old/05_Qt/10_Qt_XO/map_size.h](z_old/05_Qt/10_Qt_XO/map_size.h)

Свой калькулятор на Qt
----------------------
Задание:
* Добавить "-" и "*"
``` cpp
MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Пока нет операции
  operation = ' ';

  // Сейчас будем вводить новое число
  // Это состояние в самом начале работы,
  // а также после каждой операции
  newNumber = true;
}
```

``` cpp
// xbutton_clicked - слот, который может принимать
// сигналы от разных кнопок: '1','2'...'9','0'
void MainWindow::xbutton_clicked() {
  // Если сейчас вводим новое число
  // то все "старые" цифры с дисплея убираем
  if(newNumber) {
    arg = ui->display->text().toDouble();
    ui->display->setText("");
  }

  newNumber = false;

  // Узнаём, от какой кнопки пришёл сигнал
  QPushButton* b = (QPushButton*)
                   QObject::sender();

  if(b == NULL)
    return;

  // Добавляем новую цифру на дисплей
  ui->display->setText(
    ui->display->text() +  // Берём текст с дисплея..
    b->text() // добавляем ещё одну цифру..
  );
}
```

Узнаём, от какой кнопки пришёл сигнал
``` cpp
  QPushButton* b = (QPushButton*)
                   QObject::sender();
```

``` cpp
  operation = b->text().toLocal8Bit().at(0);

  // Выводим полученную с кнопки операцию в консоль
  qDebug() << "operation: " << operation;
```

``` cpp
void MainWindow::on_calcButton_clicked() {
  // Получаем второй аргумент
  number arg2 = ui->display->text().toDouble();

  // Вычисляем результат
  number res;

  switch (operation) {
    case '+': // Сложение
      res = arg + arg2;
      break;

    case '-': // Вычитание
      res = arg - arg2;
      break;

    case '*': // Умножение
      res = arg * arg2;
      break;

    case '/': //Деление
      res = arg / arg2;
      break;

    default:
      res = -100000; // Чтобы сразу было видно, что
      // операция не реализована
      break;
  }

  // Показываем целое число в интерфейсе
  ui->display->setText(QString::number(res));

  operation = '=';

  newNumber = true;
}
```

``` cpp
void MainWindow::on_pointButton_clicked() {
  QString s = ui->display->text();
  // Добавляем точку
  s = s + ".";
  //try{
  bool ok;
  s.toDouble(&ok);

  if(ok)
    ui->display->setText(s);
  else
    qDebug() << s << " - incorrect double";

  //} catch(){
  //    qDebug() << s << " - incorrect double";
  //}
}
```

[z_old/05_Qt/QtCalc/mainwindow.cpp](z_old/05_Qt/QtCalc/mainwindow.cpp)

``` cpp
  typedef double number;

  // Последняя операция
  char operation;
  // Запоминаем число набранное на калькуляторе
  number arg;
  // Сейчас будем вводить новое число
  bool newNumber;
```

[z_old/05_Qt/QtCalc/mainwindow.h](z_old/05_Qt/QtCalc/mainwindow.h)

Сигналы и слоты
===============
Связываем слот и сигнал из кода:
``` cpp
  connect(ui->pushButton,    // Откуда сигнал (объект)
          SIGNAL(clicked()), // Какой сигнал
          this,  // Куда отправить (объект)
          SLOT(mySlot())); // в какой слот
```

Меняем стили из кода:
``` cpp
  ui->pushButton->setStyleSheet("color: #FFFF00");
```

[z_old/05_Qt/QtSlotsSignals/mainwindow.cpp](z_old/05_Qt/QtSlotsSignals/mainwindow.cpp)

Главная форма в динамической памяти
-----------------------------------
Создание главной формы:
``` cpp
  MainWindow* w = new MainWindow;
  // Вызов главной формы через указатель
  w->show();

  // Сохраняем результат выполнения...
  int res = a.exec();

  // ...чтобы очистить память...
  delete w;
  // ...и только потом выйти!
  return res;
```

[z_old/QtButtonTextToEdit2/main.cpp](z_old/QtButtonTextToEdit2/main.cpp)

При нажатии на любую клавишу с текстом
``` cpp
  // Получаем источник сигнала :)
  QPushButton* button = (QPushButton*)QObject::sender();

  // Если это не кнопка, показываем сообщение и выходим
  if(button == NULL) {
    // Сообщение об ошибке
    QMessageBox::critical(this, "Ошибка", "on_digitButton_clicked() работает только для QPushButton",
                          QMessageBox::Ok);
    return;
  }

  // TODO: дописать
  QString s = button->text();
  // Получим строчку из lineEdit
  QString line = ui->lineEdit->text();
  // Соединим две строки
  QString res = line + s;
  // Отправим результат в интерфейс
  ui->lineEdit->setText(res);
```

[z_old/QtButtonTextToEdit2/mainwindow.cpp](z_old/QtButtonTextToEdit2/mainwindow.cpp)

Задание: работа с базой данных
------------------------------
[z_old/QtDatabase/main.cpp](z_old/QtDatabase/main.cpp)

