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

[mainwindow.cpp](mainwindow.cpp)

