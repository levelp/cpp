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

[01_QtGUI_Properties/mainwindow.cpp](01_QtGUI_Properties/mainwindow.cpp)

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

[02_Qt_console_debug/main.cpp](02_Qt_console_debug/main.cpp)

продолжаем вводить число
бинарную операцию
[04_QtCalc/CalcStates.h](04_QtCalc/CalcStates.h)

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
[04_QtCalc/mainwindow.cpp](04_QtCalc/mainwindow.cpp)

Когда нажимаем на любую
кнопку с цифрой
вызывается этот слот
[04_QtCalc/mainwindow.h](04_QtCalc/mainwindow.h)

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
[10_Qt_XO/cellbutton.cpp](10_Qt_XO/cellbutton.cpp)

Одна клетка поля, наследник стандартной Qt-кнопки
Параметры:
text - текст на кнопке
parent - окно, в котором кнопка будет расположена
для корретного удаления кнопки
row - строка, col - столбец на поле
game - ссылка на игру
Нажатие на кнопку
[10_Qt_XO/cellbutton.h](10_Qt_XO/cellbutton.h)

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
[10_Qt_XO/game.cpp](10_Qt_XO/game.cpp)

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
[10_Qt_XO/game.h](10_Qt_XO/game.h)

Записываем текущий размер поля
Берём новое значение размера поля
из интерфейса и записываем как MapSize
[10_Qt_XO/gamesettings.cpp](10_Qt_XO/gamesettings.cpp)

Мы можем создать второе такое же окно
MainWindow w2;
w2.show();
Обработка событий - основной цикл работы программы
[10_Qt_XO/main.cpp](10_Qt_XO/main.cpp)

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
[10_Qt_XO/mainwindow.cpp](10_Qt_XO/mainwindow.cpp)

Новый слот
[10_Qt_XO/mainwindow.h](10_Qt_XO/mainwindow.h)

Размер поля игры (глобальная переменная)
const int MapSize = 3;
[10_Qt_XO/map_size.h](10_Qt_XO/map_size.h)

freopen("log.txt", "w", stdout);
return -1;
[Airports_qt/main.cpp](Airports_qt/main.cpp)

Модель данных (массив 9 на 9 элементов)
В таблице в интерфейсе будет показываться именно
эта модель
Добавляем таблицу чисел
[QTableViewDemo/mainwindow.cpp](QTableViewDemo/mainwindow.cpp)

Модель: контейнер (массив) для ячеек таблицы
[QTableViewDemo/mainwindow.h](QTableViewDemo/mainwindow.h)

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

[QtCalc/mainwindow.cpp](QtCalc/mainwindow.cpp)

``` cpp
  typedef double number;

  // Последняя операция
  char operation;
  // Запоминаем число набранное на калькуляторе
  number arg;
  // Сейчас будем вводить новое число
  bool newNumber;
```

[QtCalc/mainwindow.h](QtCalc/mainwindow.h)

Поиск минимума в двухмерном массиве
Инициализируем максимальным числом для типа int
[QtConsoleExample/main.cpp](QtConsoleExample/main.cpp)

Консольное приложение на Qt для
вычисления факториала
[QtConsole/main.cpp](QtConsole/main.cpp)

Получаем 2 строки из интерфейса
Конкатенация строк
Передаём результат в интерфейс
Генерация случайной строки
Любая буква английского алфавита
Генерируем первую строку
Генерируем вторую строку
[QtDemo/mainwindow.cpp](QtDemo/mainwindow.cpp)

Генерация случайной строки
[QtDemo/mainwindow.h](QtDemo/mainwindow.h)

Получаем строчку из первого (верхнего) поля
Получаем строчку из второго поля
Складываем числа
Результат в строчку
..используем строку форматирования..
Помещаем результат обратно в интерфейс
[QtFirstApplication/mainwindow.cpp](QtFirstApplication/mainwindow.cpp)

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
[QtGame/mainwindow.cpp](QtGame/mainwindow.cpp)

Создаём Qt-приложение
Создаём основное окно
Показываем его
Обработка событий приложения
[QtNewDemo/main.cpp](QtNewDemo/main.cpp)

Получаем 2 строки из интерфейса
Соединяем строки
Результат в интерфейс
[QtNewDemo/mainwindow.cpp](QtNewDemo/mainwindow.cpp)

Главное окно программы
Текущее окно приложения
[QtNewDemo/mainwindow.h](QtNewDemo/mainwindow.h)

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

[QtSlotsSignals/mainwindow.cpp](QtSlotsSignals/mainwindow.cpp)

Получаем строку из интерфейса

QListWidgetItem *newItem = new QListWidgetItem(ui->listWidget);
newItem->setText(str);
[QtWidgets2/mainwindow.cpp](QtWidgets2/mainwindow.cpp)

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
[qt_console/a.cpp](qt_console/a.cpp)

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
[qt_console/main.cpp](qt_console/main.cpp)

Операция конкатенации
TODO: сумму чисел
TODO: Как сделать проще?
TODO: Собрать с QWebView
[qt_qui/mainwindow.cpp](qt_qui/mainwindow.cpp)

