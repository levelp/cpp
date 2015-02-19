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

[mainwindow.cpp](mainwindow.cpp)

