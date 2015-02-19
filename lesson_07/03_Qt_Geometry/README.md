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

[mainwindow.cpp](mainwindow.cpp)

