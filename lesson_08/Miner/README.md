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
[mainwindow.cpp](mainwindow.cpp)

Свой Qt-класс
[mainwindow.h](mainwindow.h)

