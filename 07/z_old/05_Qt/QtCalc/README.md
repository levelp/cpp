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

[mainwindow.cpp](mainwindow.cpp)

``` cpp
  typedef double number;

  // Последняя операция
  char operation;
  // Запоминаем число набранное на калькуляторе
  number arg;
  // Сейчас будем вводить новое число
  bool newNumber;
```

[mainwindow.h](mainwindow.h)

