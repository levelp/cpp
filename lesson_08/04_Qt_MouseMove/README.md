Отслеживаем движение мыши
QMessageBox::information(this, "Ну, конечно же...",
"А мы и не сомневались!");
return;
Остальные типы диалогов
Параметры: parent, title, message
Создаём объект
Обработчик движения мыши
qDebug() << x << y << "in" << rect.x() << rect.y();
[mainwindow.cpp](mainwindow.cpp)

Обработчик движения мыши
Сюда будем выводить координаты мыши
Обработчик при нажатии на кнопку "Да"
[mainwindow.h](mainwindow.h)

