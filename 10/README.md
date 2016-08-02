<!-- doc.py -->
﻿Системы контроля версий. Git
============================

Бесплатный хостинг для репозиториев (различные системы контроля версий)
-----------------------------------------------------------------------
* https://github.com - git
* https://bitbucket.org - git + mercurial
* https://code.google.com - svn + git + mercurial

``` bash
apt-get install git
```

Клиенты для Windows
-------------------
* Для Windows: https://msysgit.github.io
* GUI-клиент для Windows: https://code.google.com/p/tortoisegit/

Книга: http://git-scm.com/book/ru/v1

Введение в паттерны проектирования
==================================

Классификация шаблонов проектирования: Архитектурные паттерны, Паттерны проектирования, Идиомы
----------------------------------------------------------------------------------------------

Паттерны проектирования классов/обьектов: адаптер, декоратор, заместитель, фасад и т.д.
---------------------------------------------------------------------------------------

Паттерны проектирования поведения классов/обьектов
--------------------------------------------------

Порождающие паттерны проектирования: фабрика, Singleton, Prototype, Фабричный метод
-----------------------------------------------------------------------------------

﻿Модульное тестирование в Qt
===========================

Модульные тесты:
  Входные данные -> Тестируемый класс -> Ожидаемый результат

Если мы не знаем какой результат ожидать => мы не можем написать тест.

Но запустив тест один раз и посмотрев результат мы можем
написать так называемый **регрессионный тест**.
Т.е. тест, который страхует нас от **регрессий** - ухудшения качества ПО
(когда что-то что уже работало в какой-то версии "ломается" в следующей).

Для использования модульных тестов надо подключить модуль **testlib**.

``` pro
# testlib - библиотека для модульного тестирования
QT       += testlib core gui
```

Пример
------

Тестируемая функция:
``` cpp
// Сумма: a + b
int sum(int a, int b){
  return a + b;
}
```

Модульный тест к ней:
``` cpp
// Класс, который содержит тесты
class AllTests : public QObject {
  Q_OBJECT
private slots: // должны быть приватными
  // Тестирование функции суммирования
  void testSum(){
    QCOMPARE(sum(2,2), 4);
    QCOMPARE(sum(2,3), 5);
  }
};
```

В основной программе все тесты можно запустить так:
```cpp
  QTest::qExec(new AllTests, argc, argv);
```


Подключаем все модули для тестирования
``` cpp
#include "inttostr.h"
#include "functions.h"
#include "myclass.h"
#include "squareeq.h"
// И свой заголовочный файл
#include "alltests.h"
```

Тестирование вычисления максимума
``` cpp
  MyClass a(this);
  // QCOMPARE( вызов_тестируемой_функции, ожидаемое_значение );
  QCOMPARE(a.max(2, 3), 3);  // 1 тест
  QCOMPARE(a.max(2, 4), 4);  // 2 тест
  QCOMPARE(a.max(5, 1), 5);
  QCOMPARE(a.max(1, 2), 2);
  QCOMPARE(a.max(-10, -20), -10);
```

Тестирование вычисления факториала
``` cpp
  QCOMPARE( ::factorial(1), 1LL );
  QCOMPARE( ::factorial(2), 2 * 1LL );
  QCOMPARE( ::factorial(3), 3 * 2 * 1LL );
  QCOMPARE( ::factorial(4), 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(5), 5 * 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(6), 6 * 5 * 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(7), 7 * 6 * 5 * 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(8), 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(9), 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1LL );

  // Проверка исключения (ожидаемое исключение)
  try {
    ::factorial(-1);
    // Если мы оказались в этом месте программы,
    // то метод факториал не сгенерировал исключение
    QFAIL("Exception expected!");
  } catch(QString q) {
    QCOMPARE( q, QString("N > 0"));
  }

```

Квадратное уравнение
TDD - Test Driven Development
``` cpp
  SquareEq a;
  Roots roots = a.quadraticEquation(1, 0, 0);

  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], 0.0);

  roots = a.quadraticEquation(4, 0, 0);
  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], 0.0);

  roots = a.quadraticEquation(1, 0, -1);
  QCOMPARE(roots.numberOfRoots, 2);
  QCOMPARE(roots.x[0], 1.0);
  QCOMPARE(roots.x[1], -1.0);

  roots = a.quadraticEquation(1, 0, 1);
  QCOMPARE(roots.numberOfRoots, 0);

  roots = a.quadraticEquation(0, 1, 1);
  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], -1.0);

  roots = a.quadraticEquation(0, 0, 1);
  QCOMPARE(roots.numberOfRoots, 0);

  roots = a.quadraticEquation(0, 2, 1);
  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], -0.5);
  QCOMPARE(a.calc(0, 2, 1, roots.x[0]), 0.0);

  // 0*x*x + 0*x + 0 = 0
  try {
    a.quadraticEquation(0, 0, 0);
    QFAIL("Exception expected!");
  } catch(QString q) {
    QCOMPARE( q, QString("Бесконечное число решений"));
  }

```

Число в строку
[01_QtTest/alltests.cpp](01_QtTest/alltests.cpp)

Класс, который содержит тесты
Тестирование вычисления максимума
Новый тест для вычисления факториала
Тест для квадратного уравнения
Число в строку до 100
Число в строку от 100 до 199
Число в строку от 200 до 999
Число в строку от 1000 до 999999
Тестирование функции суммирования
[01_QtTest/alltests.h](01_QtTest/alltests.h)

Сумма: a + b
Факториал
Численное интегрирование
Метод трапеций

[01_QtTest/functions.cpp](01_QtTest/functions.cpp)

Сумма: a + b = c
Факториал
function - указатель на функцию возвращающую 1
Численное интегрирование
Метод трапеций
[01_QtTest/functions.h](01_QtTest/functions.h)

Константная функция
Константная функция
y = x   0..1  -> 0.5
y = x^2  x^3/3   0..1  -> 1/3
[01_QtTest/integraltest.cpp](01_QtTest/integraltest.cpp)

Тестирование интегрирования константной функции
[01_QtTest/integraltest.h](01_QtTest/integraltest.h)

#define DEBUG1
Число в строку
Обрезаем лишние пробелы в начале и конце
Первая буква в верхнем регистре
[01_QtTest/inttostr.cpp](01_QtTest/inttostr.cpp)

Модуль с функцией для тестирования
Целое число N в строку
[01_QtTest/inttostr.h](01_QtTest/inttostr.h)

Подключаем модульные тесты
Вывод числа в строку
Выведем все числа в файл (чтобы посмотреть на них вручную)
freopen("testing.txt", "w", stdout);
QTest::qExec(new SimpleTests());
QTest::qExec(new AllTests, argc, argv);
writeNumbersToFile();
[01_QtTest/main.cpp](01_QtTest/main.cpp)

return 10;
[01_QtTest/myclass.cpp](01_QtTest/myclass.cpp)

Тестируемый класс
Вычисление максимума
Вычисление минимума
[01_QtTest/myclass.h](01_QtTest/myclass.h)

И
QCOMPARE(2 * 2 + 1, 4);
[01_QtTest/simpletests.cpp](01_QtTest/simpletests.cpp)

Вызывается при инициализации
всех тестов
[01_QtTest/simpletests.h](01_QtTest/simpletests.h)

Генерируем исключение
Нет решений
Линейное уравнение
Квадратное уравнение
[01_QtTest/squareeq.cpp](01_QtTest/squareeq.cpp)

Корни квадратного уравнения
Решение квадратного уравнения
[01_QtTest/squareeq.h](01_QtTest/squareeq.h)

TDD - Test Driven Development
=============================

Разработка через тестирование (по-русски).

Три закона TDD:
---------------
1. Новый рабочий код пишется только после того,
как будет написан модульный тест,
который не проходит.
2. Вы пишете ровно такой объем кода
модульного теста, какой необходим
для того, чтобы этот тест не проходил
(если код теста не компилируется,
считается, что он не проходит).
3. Вы пишете ровно такой объем рабочего кода,
какой необходим для прохождения модульного теста,
который в данный момент не проходит.

Подсчёт количества делителей
Входные данные:
N - целое число
Результат: количество делителей
[01_QtTest_Task/divisors.cpp](01_QtTest_Task/divisors.cpp)

Подсчёт количества делителей
Входные данные:
N - целое число
Результат: количество делителей
Медленная, но надёжная реализация :)
[01_QtTest_Task/divisors.h](01_QtTest_Task/divisors.h)

Подключаем библиотеку для тестирования
Подключаем наши тесты
Постановка задачи:
Протестировать, правильно
ли работает функция вычисляющая
количество делителей числа
[01_QtTest_Task/main.cpp](01_QtTest_Task/main.cpp)

``` cpp
  QCOMPARE( calcDiv(1), 1 );
  // 2 -> {1, 2}
  QCOMPARE( calcDiv(2), 2 );
  // 3 -> {1, 3}
  QCOMPARE( calcDiv(3), 2 );
  // 4 -> {1, 2, 4}
  QCOMPARE( calcDiv(4), 3 );
  // 11 -> {1, 11}
  QCOMPARE( calcDiv(11), 2 );

  QCOMPARE( calcDiv(1000), 16 );

  // 1000000000 -> {1, ..???., 1000000000}
  QCOMPARE( calcDiv(1000000000), 100 );

  QCOMPARE( calcDiv(1234567890), 48 );
```

Регрессионное тестирование
``` cpp
  for(int N = 1; N < 10000; ++N)
    QCOMPARE( calcDiv(N), calcDivSlow(N) );

```

[01_QtTest_Task/tests.cpp](01_QtTest_Task/tests.cpp)

Деструктор
[01_WindowParentChilds/mainwindow.cpp](01_WindowParentChilds/mainwindow.cpp)

freopen("debug.txt", "w", stdout);
[02_QtTest_Simple/main.cpp](02_QtTest_Simple/main.cpp)

Тестируемый класс
с одним методом
[02_QtTest_Simple/myclass.h](02_QtTest_Simple/myclass.h)

Количество делителей
[02_QtTest_Simple/sum.cpp](02_QtTest_Simple/sum.cpp)

Функция для тестирования
Определить количество делителей у числа
10 -> 1, 2, 5, 10 - всего 4 делителя
[02_QtTest_Simple/sum.h](02_QtTest_Simple/sum.h)

Все тесты
1 тест
2 тест
[02_QtTest_Simple/tests.h](02_QtTest_Simple/tests.h)

Регулярные выражения
====================

Поиск e-mail
------------

(\w+@(?:\w+\.)+\w+) \-? (\w+)

mail1@mail.ru - Petrov  mail2@mail.ru.com  Ivanov
mail2@mail.ru.ww.com - Sidorov

>> mail1@mail.ru  Petrov
>> mail2@mail.ru.com  Ivanov
>> mail2@mail.ru.ww.com  Sidorov

PCRE - Perl Comp Reg Exp

Работа с регулярными выражениями
Запуск модульных тестов
[03_QRegExp/main.cpp](03_QRegExp/main.cpp)

Сразу при старте приложения применяется регулярное выражение
Каталог "Мои документы"
Когда текст выражения меняется, его надо заново применить
Когда текст меняется, заново применяем регулярное выражение
Очищаем окно результатов
Создаём новое регулярное выражение на основе строки
Создаём экземпляр регулярного выражения
Задаём "жадность регулярного выражения"
Если регулярное выражение некорректно,
то сразу выходим и выводим сообщение об ошибке в консоль
Текст для применения регулярного выражения
http://qt-project.org/doc/qt-5/qregexp.html#indexIn
Длина найденного куска
Собираем группы в скобках в одну строку
rx.captureCount() - количество найденных групп символов
rx.cap(i) - i-ая группа
rx.cap(1) + " - " + rx.cap(2));
QString("  len = %1").arg(len));
Защита от зацикливания программы
Сохраняем текст в текстовый файл
QFileDialog содержит статические методы для вызова различных стандартных диалогов
Мои документы
C:\\Users\\Денис\\Desktop
Загрузка текстового файла
Мои документы
Рабочий стол текущего пользователя
QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)
QDir::homePath() + "\\Desktop",
Второй вариант: QString data = QString::fromUtf8(array);
Выбор шрифта пользователем
Пользователем выбран новый шрифт
Диалог отменён
[03_QRegExp/mainwindow.cpp](03_QRegExp/mainwindow.cpp)

Применение регулярного выражения к тексту
с выводом результата обратно на форму
Сохранение текста в файл
Загрузка текста из файла
При обновлении текста
[03_QRegExp/mainwindow.h](03_QRegExp/mainwindow.h)

Символы
Поиск подстроки
Выделяем цифры из строки
c  - с помощью регулярных выражений можно искать обычные подстроки
\c A character that follows a backslash matches the character itself, except as specified below. e.g., To match a literal caret at the beginning of a string, write \^.
\a Matches the ASCII bell (BEL, 0x07).
\f Matches the ASCII form feed (FF, 0x0C).
\n Matches the ASCII line feed (LF, 0x0A, Unix newline).
ASCII 10 - Начало строки
\r Matches the ASCII carriage return (CR, 0x0D).
\t Matches the ASCII horizontal tab (HT, 0x09).
\v Matches the ASCII vertical tab (VT, 0x0B).
\xhhhh Matches the Unicode character corresponding to the hexadecimal number hhhh (between 0x0000 and 0xFFFF).
QCOMPARE(QRegExp("\\xD0BF").exactMatch("П"), true);
\0ooo (i.e., \zero ooo)    matches the ASCII/Latin1 character for the octal number ooo (between 0 and 0377).
. (dot)    Matches any character (including newline).
Группы символов
Кванторы
+ - один и больше
* - ноль и больше
[03_QRegExp/qregexptest.cpp](03_QRegExp/qregexptest.cpp)

Тестирование стандартных выражений QRegExp (PCRE - Perl Comp Reg Exp)
Символы
Группы символов
Кванторы
[03_QRegExp/qregexptest.h](03_QRegExp/qregexptest.h)

# Регулярные выражения
* Поиск e-mail

regex_match example
using explicit flags:
[04_regexp_cpp11/regexp11.cpp](04_regexp_cpp11/regexp11.cpp)

Singletone - одиночка
---------------------
Singletone
Дружественный класс
Конструктор
Деструктор
Простейшая реализация Singletone - сделать
все методы и поля статическими
Инициализация генератора случайных чисел
A a1, a2; // Не компилируется
A *a2 = new A(); // Тоже не компилируется
[05_Pattern_Singletone/main.cpp](05_Pattern_Singletone/main.cpp)

Если объект ещё не создан
Создаём его
Можно вызывать private конструктор, т.к.
мы внутри класса T
[05_Pattern_Singletone/singletone.cpp](05_Pattern_Singletone/singletone.cpp)

T - из какого класса хотим сделать Singletone
-static uniqueInstance
Один-единственный экземпляр класса T
+static instance()
Если объект ещё не создан
Создаём его
Можно вызывать private конструктор, т.к.
мы внутри класса T
Первоначально экземпляр класса не создан
[05_Pattern_Singletone/singletone.h](05_Pattern_Singletone/singletone.h)

Абстрактная фабрика
-------------------
Билет
Prototype
Номер рейса
Является ли копией?
Фабрика "билетов"
Смысл фабрики в том, что мы один раз её настраиваем
и потом "производим" / "выпускаем" однотипные объекты
Номер рейса
Получение билета
Создаём и настраиваем фабрику
[06_AbstractFactory/main.cpp](06_AbstractFactory/main.cpp)

Работа с сетью
==============
Таймер опроса "кто онлайн"
``` cpp
  QTimer* timer = new QTimer(this);
  // Соединяем сигнал со слотом
  connect(timer,
          SIGNAL(timeout()),
          this,
          SLOT(refreshOnlineList()));
  timer->start(1000);
```

Создание UDP-чата
``` cpp
void MainWindow::UdpChat(QString nick, int port) {
  // Если соединение уже открыто, то закрываем его
  if(socket != NULL) {
    socket->close();
    delete socket;
    socket = NULL;
  }

  // Создание чата
  socket = new QUdpSocket(this);
  // QHostAddress("192.168.1.104") - конкретный IP, с которого можно подключиться

  // QHostAddress::Any - принимать
  //   сообщения со всех IP адресов
  if(socket->bind(QHostAddress::Any, port)) {
    // При получении данных (сигнал readyRead)
    // вызываем метод (слот) read, который
    connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
  } else {
    // Какая-то программа на этом компьютере уже
    // заняла порт port
    qDebug() << "Port " << port << " in use. Change port!";
    return;
  }

  send(nick + " - в чате", USUAL_MESSAGE);
}
```

Нажимаем на кнопку "Войти в чат"
``` cpp
void MainWindow::on_enterChatButton_clicked() {
  QString nick = ui->nicknameEdit->text();
  UdpChat(nick,
          ui->portNumEdit->text().toInt());
  // Разрешаем отправлять сообщения только когда уже в чате
  ui->sendButton->setEnabled(true);
}
```

Отправка сообщения в сеть
``` cpp
void MainWindow::send(QString str, qint8 type) {
  // Полный пакет данных будет в массиве data
  QByteArray data; // Массив данных для отправки

  // Последовательно выводим в него байты
  QDataStream out(&data, QIODevice::WriteOnly);
  out << qint8(type); // Тип сообщения
  out << str; // Само сообщение

  // Отправляем полученный массив данных всем в локальный сети
  // на порт указанный в интерфейсе
  socket->writeDatagram(data,
                        QHostAddress::Broadcast,
                        ui->portNumEdit->text().toInt() );
}
```

Получение сообщения по UDP
``` cpp
void MainWindow::saveToLogFile(QString str) {
  QFile file("log.txt");
  file.open(QIODevice::WriteOnly | QIODevice::Text
            | QIODevice::Append );
  QTextStream log(&file);
  log.setCodec("UTF-8");
  log << str << endl;
  file.close();
}

void MainWindow::read() {
  // Массив для полученных данных
  QByteArray data;
  // Устанавливаем массиву размер
  // соответствующий размеру полученного пакета данных
  data.resize(socket->pendingDatagramSize());
  QHostAddress* address = new QHostAddress();
  socket->readDatagram(data.data(), data.size(), address);
  qDebug() << "Message from IP: " <<
           address->toString() << " size: "
           << data.size();

  // Разбор полученного пакета
  QDataStream in(&data, QIODevice::ReadOnly);

  // Получаем тип пакета
  qint8 type = 0;
  in >> type;

  if (type == USUAL_MESSAGE) {
    QString str;
    in >> str;

    if(str.length() == 0)
      return;

    // Записываем входящие сообщения в файл
    saveToLogFile(str);

    // Отображаем строчку в интерфейсе
    ui->plainTextEdit->appendPlainText(str);
  } else if (type == PERSON_ONLINE) {
    // Добавление пользователя с считанным QHostAddress
    QString str;
    in >> str;
    QStringList list = str.split(" ");
    QString timeStr = list.at(0);
    // Время выделили, дальше вырезаем
    // из строки ник.
    // Ищем в списке, если есть => обновляем
    // Если нет, добавляем.
    QString nick = str.right(timeStr.length());

    ui->onlineList->addItem(str);
  } else if (type == WHO_IS_ONLINE) {
    QTime now = QTime::currentTime();
    QString nowStr = now.toString("hh:mm:ss");
    send(nowStr + " " +
         ui->nicknameEdit->text(),
         qint8(PERSON_ONLINE));
  }
}
```

Нажимаем на кнопку "Отправить сообщение"
``` cpp
void MainWindow::on_sendButton_clicked() {
  // Вся строка сообщения: "ник: сообщение"
  send(ui->nicknameEdit->text() + ": " +
       ui->messageEdit->text(),
       USUAL_MESSAGE);

  ui->messageEdit->clear();
}
```

Обновляем список тех кто online
``` cpp
void MainWindow::refreshOnlineList() {
  // TODO: хранить время, когда последний раз этот человек был в сети

  // Удаляем тех, от кого давно не было сообщений
  for(int i = 0; i < ui->onlineList->count(); ++i) {
    // Получаем i-ую запись из списка
    QListWidgetItem* item = ui->onlineList->item(i);
    //
    QString str = item->text();
    QStringList list = str.split(" ");
    QString dateStr = list.at(0);
    QTime time = QTime::fromString(dateStr, "hh:mm:ss");
    QTime now = QTime::currentTime();
    int diff = time.msecsTo(now);

    qDebug() << time << now << diff;

    // Удаляем запись из списка
    if(diff > 2000)
      ui->onlineList->takeItem(i);
  }

  send("", WHO_IS_ONLINE);
}
```

[06_QtNetwork/mainwindow.cpp](06_QtNetwork/mainwindow.cpp)

#include <QTcpServer>
Тип сообщения
``` cpp
enum MessageType {
  USUAL_MESSAGE, // Обычный текст
  PERSON_ONLINE, // Сообщение "Я-онлайн"
  WHO_IS_ONLINE, // Запрос о статусе пользователей
};
```

== ЧАТ ==
``` cpp
  // Для работы по UDP-протоколу в
  // локальной сети
  QUdpSocket* socket;

  // Открываем соединение
  // и отправляем первое сообщение
  void UdpChat(QString nick, int port);

  // Отправить сообщение
  void send(QString str, qint8 type);

 private slots:
  // Получаем сообщения
  void read();
```

[06_QtNetwork/mainwindow.h](06_QtNetwork/mainwindow.h)

Абстрактный класс (интерфейс)
Исполнитель по-умолчанию
Предпочитаемый исполнитель
[07_Bridge/main.cpp](07_Bridge/main.cpp)

Каждый компонент умеет себя "показывать" -
т.е. выполнять метод show
Лист (нижний уровень дерева)
просто выводит строчку на экран
Составной объект состоит из нескольких компонент
Содержит несколько компонент (является контейнером)
[08_Composite/main.cpp](08_Composite/main.cpp)

Стратегия (strategy)
Поведенческий шаблон
Стратегия - абстрактный класс
Стратегия стек
Стратегия очередь

[09_Strategy/main.cpp](09_Strategy/main.cpp)

Автоматическое удаление при указании parent
-------------------------------------------
delete obj;
[AutoDeleteDemo/mainwindow.cpp](AutoDeleteDemo/mainwindow.cpp)

Деструктор
[AutoDeleteDemo/myclass.cpp](AutoDeleteDemo/myclass.cpp)

Конструктор
Деструктор
[AutoDeleteDemo/myclass.h](AutoDeleteDemo/myclass.h)

﻿Графика в Qt
============

TODO: Базовая + OpenGL

Упакованный массив
------------------
Использовать битовые поля не получится
``` cpp
struct OneBitStruct {
  int OneBit : 1;
};

// Размер массива вовсе не 1 байт
OneBitStruct array[8];
```

``` cpp
// Массив, в котором хранится size элементов.
// Каждый элемент должен занимать bits бит.
// Например:
//   массив из 8 элементов по 1 биту должен занимать
//   1 байт
//
//  00000000
//    1
//    0
// Сдвигаем на bits влево
//  и меняем её в массиве
//
//   5
//  00000000111111112222222233333333 - байты
//  0000011111222223333344444     - элементы

// bits - количество бит на одно число
// size - размер массива
// ValueType
template <int bits, int size, typename ValueType>
struct CalcBits {
  // Размер ValueType в битах
  // размер каждой ячейки массива в битах
  static const int BITS = sizeof(ValueType) * 8;

  // Номер ячейки массива
  // Элемент может занимать одну ячейку i
  // либо две ячейки массива i и i+1
  int i;
  // Номер первого бита значения в ячейке
  int idxIn;
  // Битов в i-ой ячейке
  int bits1;
  // Битов в i+1-ой ячейке
  int bits2;
  // Создаём две маски
  //  mask - биты используемые в i-ой ячейке 1
  //  mask2 - биты используемые в i+1-ой ячейке 1
  int mask, mask2;

  CalcBits(int index) {
    // Номер первого бита значения относительно
    // начала массива
    //  0000011111222223333344444     - элементы
    int bitIdx = index * bits;
    // Номер ячейки массива
    i = bitIdx / BITS;
    // Номер бита в i-ой ячейке массива
    idxIn = bitIdx % BITS;
    // Сколько бит в i-ой ячейке
    // BITS - idxIn - сколько осталось бит
    // bits - сколько требуется для хранения значения
    bits1 = min(bits, BITS - idxIn);
    // Сколько бит осталось на i+1 ячейку
    bits2 = bits - bits1;
    // Создаём маску для i-ой ячейки
    //  Хочу получить маску длины N
    //    1 << N  - единицу на N бит влево
    //  N = 3
    //    1000
    //  Вычитаю 1 из двоичного числа
    //    0111
    //  И дальше её сдвигаю влево на idxIn бит
    //     01110000
    mask = ((1 << bits1) - 1) << idxIn;
    // Получаю маску из bits2 для i+1 ячейки
    mask2 = (1 << bits2) - 1;
  }
};
```

``` cpp
// bits - количество бит на одно число
// size - размер массива
template <int bits, int size, typename ValueType = unsigned char>
class PackedArray {
  static const int BITS = sizeof(ValueType) * 8;
  ValueType data[(size * bits + BITS - 1) / BITS];
 public:
  void setValue(int index, ValueType value) {
    // Вычисляю биты, где будет расположено значение
    // value
    CalcBits<bits, size, ValueType> x(index);
    // Младшая часть числа
    // ~x.mask - побитовое НЕ (инвертирование)
    data[x.i] &= ~x.mask; // Очищаем биты
    data[x.i] |= (value << x.idxIn); // Новое значение

    // Старшая часть числа
    if(x.bits2 > 0) {
      data[x.i + 1] &= ~x.mask2; // Очищаем биты
      data[x.i + 1] |= (value >> x.bits1); // Новое значение
    }
  }
  // Получить значение
  ValueType getValue(int index) {
    CalcBits<bits, size, ValueType> x(index);
    // Младшая часть
    int v1 = (data[x.i] & x.mask) >> x.idxIn;

    if(x.bits2 == 0)
      return v1;

    // Старшая часть числа
    int v2 = (data[x.i + 1] & x.mask2);
    return v1 | (v2 << x.bits1);
  }
  // TODO: реализовать перегрузку operator[]
};
```

Тестирование
Массив из 10 бит
``` cpp
  PackedArray<1, 10> pa;

  for(int i = 0; i < 10; ++i)
    for(int v = 0; v <= 1; ++v) {
      pa.setValue(i, v);
      assert(pa.getValue(i) == v);
    }

```

Случайный тест
``` cpp
  for(int t = 0; t < 1000; ++t) {
    int i = rand() % 10;
    int v = rand() % 2;
    pa.setValue(i, v);
    assert(pa.getValue(i) == v);
  }

```

Из 10 элементов по 4 бита
``` cpp
  PackedArray<4, 10> pa2;

  for(int t = 0; t < 10000; ++t) {
    int i = rand() % 10;
    int v = rand() % (1 << 4);
    pa2.setValue(i, v);
    assert(pa2.getValue(i) == v);
  }

```

По 5 бит, с перехлёстом байтов
``` cpp
  CalcBits<5, 10, unsigned char> cb(1);
  assert( cb.i == 0 );
  assert( cb.idxIn == 5 );
  assert( cb.bits1 == 3 );
  assert( cb.bits2 == 2 );
  assert( cb.mask == 0b11100000 );
  assert( cb.mask2 == 0b00000011 );

  PackedArray<5, 10> pa5;

  for(int t = 0; t < 10000; ++t) {
    int i = rand() % 10;
    int v = rand() % (1 << 5);
    pa5.setValue(i, v);
    assert(pa5.getValue(i) == v);
  }

```

С другим типом данных и перехлёстом
``` cpp
  PackedArray<11, 10, unsigned int> pa11;

  for(int t = 0; t < 10000; ++t) {
    int i = rand() % 10;
    int v = rand() % (1 << 11);
    pa11.setValue(i, v);
    //SHOW(i);
    //SHOW(v);
    //SHOW(pa11.getValue(i));
    assert(pa11.getValue(i) == v);
  }

```

[Qt_PackedArrays/main.cpp](Qt_PackedArrays/main.cpp)


