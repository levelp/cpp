Мой собственный Браузер
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
[mainwindow.cpp](mainwindow.cpp)

