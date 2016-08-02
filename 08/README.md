<!-- doc.py -->
продолжаем вводить число
бинарную операцию
[00_HomeWork_Done/CalcStates.h](00_HomeWork_Done/CalcStates.h)

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
Получаем компонент
Складываем содержимое экрана и память
Запоминаем нажатую кнопку - следующую операцию
Показываем значение на экране
[00_HomeWork_Done/mainwindow.cpp](00_HomeWork_Done/mainwindow.cpp)

Когда нажимаем на любую
кнопку с цифрой
вызывается этот слот
[00_HomeWork_Done/mainwindow.h](00_HomeWork_Done/mainwindow.h)

﻿Виды отладки: отладчик, трассировка (логгирование), модульные тесты, визуализаторы процесса выполнения
------------------------------------------------------------------------------------------------------




Этот объект принимает
"перетащенные" в него объекты"
Hide old QLabel
! [1]
Save QLabel
[02_draggableicons/dragwidget.cpp](02_draggableicons/dragwidget.cpp)

Создаём модель в динамической памяти
Первый список строк
Задаём как модель для дерева
Задаём как модель для таблицы
Когда нажимаем на кнопку "Добавить"
Добавляем запись в listView (текст берём из интерфейса)
Удалить выделенную запись
Массив (коллекция) по которой надо пробежать
[03_QListViewDemo/mainwindow.cpp](03_QListViewDemo/mainwindow.cpp)

Модель: контейнер (массив) для записей
Хранилище строк для отображения в списке
[03_QListViewDemo/mainwindow.h](03_QListViewDemo/mainwindow.h)

Сохраняем все изменения
Обновляем модель
TODO: разобраться с id autoincrement
[04_PhoneBook/mainwindow.cpp](04_PhoneBook/mainwindow.cpp)

Отслеживаем движение мыши
QMessageBox::information(this, "Ну, конечно же...",
"А мы и не сомневались!");
return;
Остальные типы диалогов
Параметры: parent, title, message
Создаём объект
Обработчик движения мыши
qDebug() << x << y << "in" << rect.x() << rect.y();
[04_Qt_MouseMove/mainwindow.cpp](04_Qt_MouseMove/mainwindow.cpp)

Обработчик движения мыши
Сюда будем выводить координаты мыши
Обработчик при нажатии на кнопку "Да"
[04_Qt_MouseMove/mainwindow.h](04_Qt_MouseMove/mainwindow.h)

Перенаправляем все сообщения
которые программа выводит в текстовую
консоль в файл
freopen("stdout.txt", "w", stdout);
freopen("stderr.txt", "w", stderr);
system("pause");
[05_QtDebug/main.cpp](05_QtDebug/main.cpp)

Добавить запись в дерево
ui->treeWidget->selectionModel()->selection()
Сортировка
[05_TreeWidget/mainwindow.cpp](05_TreeWidget/mainwindow.cpp)

Работа с файлами в Qt
=====================
Работа с файлами при помощи QFile
``` cpp
  // Выводить в текстовый файл с помощью Qt
  QFile file("qt_output.txt");
  file.open(QIODevice::WriteOnly | QIODevice::Text);
  // QIODevice::WriteOnly - создаём файл для записи
  // QIODevice::Text - к выводу применяются правила
  //   для текстового файла

  QTextStream out(&file);
  out.setCodec("UTF-8");
  out << QString("Любой текст!") << endl;
  out << QString("2 * 3 = ") << (2 * 3) << endl;
  out << 2 + 2 + 3 << " Текст " << endl;

  file.close();

  // Теперь прочитаем всё что записали
  QFile inFile("qt_output.txt");
  inFile.open(QIODevice::ReadOnly | QIODevice::Text);
  QTextStream in(&inFile);
  // Читаем целую строку из файла
  QString str = in.readLine();
  qDebug() << str;

  inFile.close(); // Закрываем файл

  // Открываем файл второй раз и дописываем текст
  QFile f3("qt_output.txt");

  if(!f3.open(QIODevice::Append | QIODevice::Text)) {
    qDebug() << f3.errorString();
    return -1;
  }

  QTextStream out3(&f3);
  out3 << "Дописываем ещё текст" << endl;
  f3.close();
```

[06_QFile/main.cpp](06_QFile/main.cpp)

MainWindow w;
[06_QWidgets/main.cpp](06_QWidgets/main.cpp)

Открыть файл для записи
Вывод как в cout
Закрыть файл
[07_ReadWriteTextStl/main.cpp](07_ReadWriteTextStl/main.cpp)

__stdcall
typedef int(*myfun)(int a, void *b)
[FunctionTypedef/main.cpp](FunctionTypedef/main.cpp)

﻿Мой собственный Браузер
=======================

Чтобы работал QWebView надо добавить модуль **webkitwidgets** в **.pro** файл.

Нужно
-----
* Реализовать сохранение сайта в *Избранное* (специальная панель)
* Переходы по сайтам из избранного (при нажатии на кнопку)

Создание кнопки и добавление на панель
--------------------------------------
``` cpp
// Создаём новую кнопку
QPushButton *button = new QPushButton(this);
  // parent = this чтобы кнопки удалились при закрытии окна
// Сохраняем текущий URL в текст кнопки
button->setText(ui->urlEdit->text());

// При нажатии на кнопку переходим на адрес
// Соединяем сигнал clicked() с нужным слотом
connect(button, SIGNAL(clicked()), this, SLOT(on_goToHistory_clicked()));

// Добавляем кнопку на панель
ui->historyTools->addWidget(button);
```

Как получить нажатую кнопку в обработчике (в слоте):
``` cpp
// Кто отправил сигнал?
QPushButton *button = (QPushButton *)QObject::sender();
if(button == NULL){
  qDebug() << "Должны быть только объекты QPushButton";
  return;
}

// Получаем URL с кнопки
QString url = button->text();
// Выводим URL для отладки
qDebug() << "URL:" << url;
// Переходим по заданному адресу
ui->webView->setUrl(url);
```


При нажатии на кнопку Go переходим на адрес
Добавление адреса сайта в закладки
TODO: реализовать
Переход по кнопке из избранного
TODO: реализовать
Когда меняется URL в webView => меняем и URL в строке адреса
[HomeWork_Browser/mainwindow.cpp](HomeWork_Browser/mainwindow.cpp)

Подключаю вторую форму чтобы использовать
её из первой
Создаём поле
button->setVisible(true);
QObject::sender() - указатель на отправителя сигнала
проблема в том что этот указатель не того типа
Он типа QObject*, а не QPushButton*
Поэтому мы его приводим к нужному типу
a = (double)(23423 + 32424)
Выключаем поле
[Miner/mainwindow.cpp](Miner/mainwindow.cpp)

Свой Qt-класс
[Miner/mainwindow.h](Miner/mainwindow.h)

VisualStudioExample.cpp : Defines the entry point for the console application.

[VisualStudioExample/VisualStudioExample/VisualStudioExample.cpp](VisualStudioExample/VisualStudioExample/VisualStudioExample.cpp)

stdafx.cpp : source file that includes just the standard includes
VisualStudioExample.pch will be the pre-compiled header
stdafx.obj will contain the pre-compiled type information
TODO: reference any additional headers you need in STDAFX.H
and not in this file
[VisualStudioExample/VisualStudioExample/stdafx.cpp](VisualStudioExample/VisualStudioExample/stdafx.cpp)

stdafx.h : include file for standard system include files,
or project specific include files that are used frequently, but
are changed infrequently

TODO: reference additional headers your program requires here
[VisualStudioExample/VisualStudioExample/stdafx.h](VisualStudioExample/VisualStudioExample/stdafx.h)

The following macros define the minimum required platform.  The minimum required platform
is the earliest version of Windows, Internet Explorer etc. that has the necessary features to run
your application.  The macros work by enabling all features available on platform versions up to and
including the version specified.
Modify the following defines if you have to target a platform prior to the ones specified below.
Refer to MSDN for the latest info on corresponding values for different platforms.
[VisualStudioExample/VisualStudioExample/targetver.h](VisualStudioExample/VisualStudioExample/targetver.h)

C:/Users/gtee/Desktop/cpp/lesson_08/HomeWork_Browser/icons/star.png
icons
star.png
:
:/icons
:/icons/star.png
[build-HomeWork_Browser-Desktop_Qt_5_4_0_MinGW_32bit-Debug/debug/qrc_icons.cpp](build-HomeWork_Browser-Desktop_Qt_5_4_0_MinGW_32bit-Debug/debug/qrc_icons.cpp)

C:/Users/gtee/Desktop/cpp/lesson_08/02_draggableicons/images/boat.png
C:/Users/gtee/Desktop/cpp/lesson_08/02_draggableicons/images/house.png
C:/Users/gtee/Desktop/cpp/lesson_08/02_draggableicons/images/car.png
images
boat.png
house.png
car.png
:
:/images
:/images/boat.png
:/images/car.png
:/images/house.png
[build-draggableicons-Desktop_Qt_5_4_0_MinGW_32bit-Debug/debug/qrc_draggableicons.cpp](build-draggableicons-Desktop_Qt_5_4_0_MinGW_32bit-Debug/debug/qrc_draggableicons.cpp)


