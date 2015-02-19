<!-- doc.py -->
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
translate перемещает объект
Получаем текущий шрифт формы
Меняем размер шрифта
Заменяем шрифт у всей формы
Получаем текущий шрифт формы
Меняем размер шрифта
Заменяем шрифт у всей формы
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

enum DirectionX {
  T_UP /* 0 */, T_DOWN /* 1 */,
  T_LEFT /* 2 */, T_RIGHT /* 3 */
};
```

Упаковка
#pragma pack(4)
Последовательная нумерация
[01_Enums/main.cpp](01_Enums/main.cpp)

Форме один даём ссылку на форму 2
Форме 2 даём ссылку на форму 1
[01_QtSwitchForms/main.cpp](01_QtSwitchForms/main.cpp)

Печать в строку как в поток
``` cpp
  ostringstream sstream;
  sstream << sum;
```

[01_QtWidgets/demowidgetswindow.cpp](01_QtWidgets/demowidgetswindow.cpp)

Определение глобальной переменной
в **module1.cpp**
``` cpp
int globalVar = 2;
```

[01_extern_vars/module1.cpp](01_extern_vars/module1.cpp)

В **module2.cpp** тоже можно
использовать **globalVar**
``` cpp
void v2() {
  D(globalVar = 2);
  SHOW(globalVar);
}

void show2() {
  D(SHOW(globalVar));
}
```

[01_extern_vars/module2.cpp](01_extern_vars/module2.cpp)

Глобальная переменная в **vars.h**
``` cpp
extern int globalVar;
```

[01_extern_vars/vars.h](01_extern_vars/vars.h)

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

[02_AbstractFactory/main.cpp](02_AbstractFactory/main.cpp)

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

Работа с QString
----------------
http://doc.qt.io/qt-5/
http://doc.qt.io/qt-5/qstring.html
QString("%1 - %2").arg(s1).arg(s2)
s1 заканчивается на s2
Получаем число в десятичной системе счисления
[02_QString/mainwindow.cpp](02_QString/mainwindow.cpp)

C:/Users/gtee/Desktop/cpp/lesson_07/02_QtDesign/img/bigRedButton.png
img
bigRedButton.png
:
:/img
:/img/img
:/img/img/bigRedButton.png
[02_QtDesign/debug/qrc_images.cpp](02_QtDesign/debug/qrc_images.cpp)

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

[03_Qt_Geometry/mainwindow.cpp](03_Qt_Geometry/mainwindow.cpp)

Исключения
----------
QString("Square root: x = %1 < 0").arg(d);
throw QString("ERROR");
[05_Exceptions/main.cpp](05_Exceptions/main.cpp)

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

[05_Qt/01_QtGUI_Properties/mainwindow.cpp](05_Qt/01_QtGUI_Properties/mainwindow.cpp)

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

[05_Qt/02_Qt_console_debug/main.cpp](05_Qt/02_Qt_console_debug/main.cpp)

продолжаем вводить число
бинарную операцию
[05_Qt/04_QtCalc/CalcStates.h](05_Qt/04_QtCalc/CalcStates.h)

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

Изменяем состояние всех кнопок
Можно нажимать ".",
только если на дисплее точек ещё нет
Складываем содержимое экрана и память
Показываем значение на экране
Складываем содержимое экрана и память
TODO: применять последнюю операцию
Показываем значение на экране
[05_Qt/04_QtCalc/mainwindow.cpp](05_Qt/04_QtCalc/mainwindow.cpp)

Когда нажимаем на любую
кнопку с цифрой
вызывается этот слот
[05_Qt/04_QtCalc/mainwindow.h](05_Qt/04_QtCalc/mainwindow.h)

Параметры:
text - текст на кнопке
parent - окно, в котором кнопка будет расположена
для корретного удаления кнопки
row - строка, col - столбец на поле
game - ссылка на игру
this->game = &game;
Если на кнопке написан крестик или нолик,
то нажимать на неё нельзя
При нажатии на клетку
Выводим координаты нажатия для отладки
Делаем ход => получаем результат
для данной клетки
Больше не можем нажимать на эту клетку поля
(эту кнопку)
[05_Qt/10_Qt_XO/cellbutton.cpp](05_Qt/10_Qt_XO/cellbutton.cpp)

Одна клетка поля, наследник стандартной Qt-кнопки
Параметры:
text - текст на кнопке
parent - окно, в котором кнопка будет расположена
для корретного удаления кнопки
row - строка, col - столбец на поле
game - ссылка на игру
Нажатие на кнопку
[05_Qt/10_Qt_XO/cellbutton.h](05_Qt/10_Qt_XO/cellbutton.h)

При старте программы сразу начинается новая игра
Новая игра
Первыми ходят всегда крестики
Заполняем поле пустыми клетками, без крестиков и ноликов
Совершаем ход

QMessageBox::information(NULL, "Ход",
QString("Ход в клетку: (%1; %2)")
.arg(row+1).arg(col+1));
Три крестика или три нолика
Если не все элементы равны => не подходит
Кто-то выйграл :)
== Проверяем диагонали ==
Основная диагональ
Дополнительная диагональ
(0,0) (0,1) [0,2]
(1,0) [1,1] (1,2)
[2,0] (2,1) (2,2)
Вертикальные и горизонтальные линии
Вертикальная линия
копируем в a i-ый столбец
Горизонтальная линия
Проверяем что крестики или нолики
выйграли и выходим
Ничья = не осталось пустых клеток
Сохранение игры
Сохраняем данные
Загрузка (чтение) сохранённой игры из файла
Читаем данные
Считываем размер карты
Проверяем количество крестиков и ноликов
[05_Qt/10_Qt_XO/game.cpp](05_Qt/10_Qt_XO/game.cpp)

Состояние игры
Все что происодит на поле и логика игрового мира
Ходы, выйгрыш/проигрыш
Игровое поле
Проверка выйгрыша
проверяется одна строка
один столбец или одна диагональ
Конструктор
Новая игра без пересоздания объекта
Получаем строку, соответствующую состоянию игры
Совершаем ход, возвращает строку для клетки на форме
Проверяем на окончание игры
Сохранение игры
Загрузка игры
Состояние ячейки
[05_Qt/10_Qt_XO/game.h](05_Qt/10_Qt_XO/game.h)

Записываем текущий размер поля
Берём новое значение размера поля
из интерфейса и записываем как MapSize
[05_Qt/10_Qt_XO/gamesettings.cpp](05_Qt/10_Qt_XO/gamesettings.cpp)

Мы можем создать второе такое же окно
MainWindow w2;
w2.show();
Обработка событий - основной цикл работы программы
[05_Qt/10_Qt_XO/main.cpp](05_Qt/10_Qt_XO/main.cpp)

Скрываем кнопку с прототипом
Задаём размер массиву кнопок
Заполним весь массив кнопок поля NULL
Начало игры
Выход из программы
ui->lineEdit_1->setText(QString("1"));
ui->lineEdit_2->setText(QString("2"));
После изменения состояния игры
Подстраиваем размер, т.к. эта метка не в Layout
Создаём массив MapSize на MapSize из QPushButton
Шрифт как в прототипе
Задаём размеры и положение кнопки
critical(QWidget * parent, const QString & title,
const QString & text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton)
Вызываем окно настройки размера поля
После изменения размера поля
перестартуем игру
[05_Qt/10_Qt_XO/mainwindow.cpp](05_Qt/10_Qt_XO/mainwindow.cpp)

Новый слот
[05_Qt/10_Qt_XO/mainwindow.h](05_Qt/10_Qt_XO/mainwindow.h)

Размер поля игры (глобальная переменная)
const int MapSize = 3;
[05_Qt/10_Qt_XO/map_size.h](05_Qt/10_Qt_XO/map_size.h)

freopen("log.txt", "w", stdout);
return -1;
[05_Qt/Airports_qt/main.cpp](05_Qt/Airports_qt/main.cpp)

Модель данных (массив 9 на 9 элементов)
В таблице в интерфейсе будет показываться именно
эта модель
Добавляем таблицу чисел
[05_Qt/QTableViewDemo/mainwindow.cpp](05_Qt/QTableViewDemo/mainwindow.cpp)

Модель: контейнер (массив) для ячеек таблицы
[05_Qt/QTableViewDemo/mainwindow.h](05_Qt/QTableViewDemo/mainwindow.h)

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

1. Получаем текст с кнопки
2. Переводим из QString (UTF-8) в обычную C-строку
3. Берём только первый символ
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

[05_Qt/QtCalc/mainwindow.cpp](05_Qt/QtCalc/mainwindow.cpp)

``` cpp
  typedef double number;

  // Последняя операция
  char operation;
  // Запоминаем число набранное на калькуляторе
  number arg;
  // Сейчас будем вводить новое число
  bool newNumber;
```

[05_Qt/QtCalc/mainwindow.h](05_Qt/QtCalc/mainwindow.h)

Поиск минимума в двухмерном массиве
Инициализируем максимальным числом для типа int
[05_Qt/QtConsoleExample/main.cpp](05_Qt/QtConsoleExample/main.cpp)

Консольное приложение на Qt для
вычисления факториала
[05_Qt/QtConsole/main.cpp](05_Qt/QtConsole/main.cpp)

Получаем 2 строки из интерфейса
Конкатенация строк
Передаём результат в интерфейс
Генерация случайной строки
Любая буква английского алфавита
Генерируем первую строку
Генерируем вторую строку
[05_Qt/QtDemo/mainwindow.cpp](05_Qt/QtDemo/mainwindow.cpp)

Генерация случайной строки
[05_Qt/QtDemo/mainwindow.h](05_Qt/QtDemo/mainwindow.h)

Получаем строчку из первого (верхнего) поля
Получаем строчку из второго поля
Складываем числа
Результат в строчку
..используем строку форматирования..
Помещаем результат обратно в интерфейс
[05_Qt/QtFirstApplication/mainwindow.cpp](05_Qt/QtFirstApplication/mainwindow.cpp)

Получаем текущее расположение кнопки
Изменяем координаты кнопки
Передаём изменённые координаты обратно в интерфейс
Получаем текущее расположение кнопки
Изменяем координаты кнопки
Передаём изменённые координаты обратно в интерфейс
Получаем текущее расположение кнопки
Изменяем координаты кнопки
Передаём изменённые координаты обратно в интерфейс
Получаем текущее расположение кнопки
Изменяем координаты кнопки
Передаём изменённые координаты обратно в интерфейс
[05_Qt/QtGame/mainwindow.cpp](05_Qt/QtGame/mainwindow.cpp)

Создаём Qt-приложение
Создаём основное окно
Показываем его
Обработка событий приложения
[05_Qt/QtNewDemo/main.cpp](05_Qt/QtNewDemo/main.cpp)

Получаем 2 строки из интерфейса
Соединяем строки
Результат в интерфейс
[05_Qt/QtNewDemo/mainwindow.cpp](05_Qt/QtNewDemo/mainwindow.cpp)

Главное окно программы
Текущее окно приложения
[05_Qt/QtNewDemo/mainwindow.h](05_Qt/QtNewDemo/mainwindow.h)

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

[05_Qt/QtSlotsSignals/mainwindow.cpp](05_Qt/QtSlotsSignals/mainwindow.cpp)

Получаем строку из интерфейса

QListWidgetItem *newItem = new QListWidgetItem(ui->listWidget);
newItem->setText(str);
[05_Qt/QtWidgets2/mainwindow.cpp](05_Qt/QtWidgets2/mainwindow.cpp)

template<ПАРАМЕТРЫ>
class Имя_класса{}
Тип_возвращаемого_значения Функция(параметры)
ПАРАМЕТРЫ:
int aa, char A, class T / typename T
template<template<int> class X>
X
Стек на основе массива
По-умолчанию private
Stack() { count = 0; }
Поместить на вершину стека
Получить значение с вершины стека
vector<тип> имя_переменной(количество, начальное_значение)
Добавляем в конец вектора
Тип_вектора::iterator
Множество
Добавляем элементы
if(intSet.find(1))
cout << "1 exists" << endl;
Удаляем элемент
map - словарь
map<тип_ключа, тип_значения>
m.insert('D', 30);
[05_Qt/qt_console/a.cpp](05_Qt/qt_console/a.cpp)

Подсчитать количество одинаковых элементов
Вывести в виде Значение элемента -> Количество
Пробежим по всем значениям в векторе
Если такого значения ещё нет, добавим в m значение 1
Если есть, то увеличим на 1
Выведем набор Ключ => Значение
map - словарь
map<тип_ключа, тип_значения>
Вывод отдельной пары
cout << pair.first << " " << pair.second << endl;
m.insert('D', 30);
Ключ             Значение
Количество вхождений элемента A
cout << m.count('A') << endl;
Удаляем элемент
m.erase('A');
cout << m.count('A') << endl;
[05_Qt/qt_console/main.cpp](05_Qt/qt_console/main.cpp)

Операция конкатенации
TODO: сумму чисел
TODO: Как сделать проще?
TODO: Собрать с QWebView
[05_Qt/qt_qui/mainwindow.cpp](05_Qt/qt_qui/mainwindow.cpp)

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

Назначаем имя файлу
Открываем БД
Создаём экземпляр класса QSqlQuery чтобы выполнить запрос
Выполняем запрос, если ошибка в запросе,
то метод возвращает false
Выводим подробное сообщение об ошибке
[HomeWork_SQL/main.cpp](HomeWork_SQL/main.cpp)

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

[QtButtonTextToEdit2/main.cpp](QtButtonTextToEdit2/main.cpp)

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

Ещё один обработчик для кнопки 1 :)
[QtButtonTextToEdit2/mainwindow.cpp](QtButtonTextToEdit2/mainwindow.cpp)

Задание: работа с базой данных
------------------------------
0. Создаём БД для работы нашего приложения
1. Подключаем драйвер нужной БД
2. Подкчаемся к самой БД
3. Выполняем SQL-операторы
4. Получаем результаты их выполнения
5. Связываем с интерфейсом
[QtDatabase/main.cpp](QtDatabase/main.cpp)

Загрузка текста из файла
Utf-8
[QtReadTextToInterface/mainwindow.cpp](QtReadTextToInterface/mainwindow.cpp)

ui->gridLayout->
TODO: Вывести сообщение: а мы и не сомневались!
[QtWidgets/mainwindow.cpp](QtWidgets/mainwindow.cpp)

1. Получаем данные из интерфейса
2. Соединяем 2 строки в одну (конкатенация)
3. Отправляем результат в интерфейс
[StringConcat/mainwindow.cpp](StringConcat/mainwindow.cpp)

C:/Users/gtee/Desktop/cpp/lesson_07/03_QtDesignQML/MainForm.ui.qml
C:/Users/gtee/Desktop/cpp/lesson_07/03_QtDesignQML/main.qml
MainForm.ui.qml
main.qml
:
:/MainForm.ui.qml
:/main.qml
[build-03_QtDesignQML-Desktop_Qt_5_4_0_MinGW_32bit-Debug/debug/qrc_qml.cpp](build-03_QtDesignQML-Desktop_Qt_5_4_0_MinGW_32bit-Debug/debug/qrc_qml.cpp)


﻿1. Перетаскивание (завершить пример)
2. Кнопка своей формы (с картинкой и т.д.)
3. Консоль в Windows приложениях
4. Внешние файлы стилей.

Занятие 9:
4. Способы оформления QML/CSS и т.д.
5. QML - обработка событий


