<!-- doc.py -->
﻿Создание приложения в Qt
------------------------
* Запускаем Qt Creator
* Создаём главную форму
* Добавляем виджеты
* Используем сигналы и слоты

Основная программа на Qt
``` cpp
#include "mainwindow.h"
#include <QApplication>
#include <QDebug> // Отладочный вывод в консоль
#include <iostream>

using namespace std;


/// * argc - количество аргументов
/// * argv - параметры командной строки
``` cpp
int main(int argc, char* argv[]) {
  // Печатаем количество аргументов
  cout << "argc: " << argc << endl;

  // И сами аргументы
  for(int i = 0; i < argc; ++i)
    cout << argv[i] << endl;

  // Обработка сигналов
  // Связь сигнал -> слот
  QApplication a(argc, argv);

  // Создаём основное окно
  MainWindow w;
  // Показываем основное окно
  w.show();

  cout << "Starting..." << endl;

  // Запуск основного цикла обработки событий
  int res = a.exec();

  cout << "Closing... res = " << res << endl;
  return res;
}
```

[main.cpp](main.cpp)

Слот (обработчик сигнала) - реализуется как обычный метод
``` cpp
void MainWindow::on_closeButton_clicked() {
  qDebug() << "on_closeButton_clicked()";
}

void MainWindow::on_concatButton_clicked() {
  // ui - Ui::MainWindow *ui;
  // Указатель на сгенерированный
  // по *.ui файлу класс Ui::MainWindow
  QLineEdit* line1 = ui->lineEdit_1;
  // line1 - указатель на виджет
  // Чтобы получить текст мы вызываем
  // метод text()
  // который возвращает QString
  QString s1 = line1->text();
  qDebug() << s1;
  qDebug() << ui->lineEdit_2->text();

  // Свойство называется так:
  //    имяСвойства
  // Чтобы получить значение вызываем метод:
  //    имяСвойства()
  // Чтобы поменять значение вызываем метод:
  //   setИмяСвойства(Новое_значение)
  ui->resEdit->setText(s1 +
                       ui->lineEdit_2->text());
}
```

[mainwindow.cpp](mainwindow.cpp)

``` cpp
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  // parent - объект при уничтожении которого
  //  должен быть уничтожен и этот объект
  // Обычно основное (главное) окно программы
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  // Слоты - методы-обработчики сигналов
  void on_pushButton_clicked();

  void on_closeButton_clicked();

  void on_concatButton_clicked();

  void on_enableButton_clicked();

 private:
  Ui::MainWindow* ui;
};
```

[mainwindow.h](mainwindow.h)


