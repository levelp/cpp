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

[main.cpp](main.cpp)

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
[mainwindow.cpp](mainwindow.cpp)

