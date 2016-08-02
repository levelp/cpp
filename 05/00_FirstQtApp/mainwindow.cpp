#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h" // Подключаю вторую форму
#include <QDebug> // Вывод сообщений в консоль отладки

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->manualSignalSlotButton, SIGNAL(clicked()),
          this, SLOT(close()));
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  Dialog* dialog = new Dialog(this);
  dialog->show();
}

/// Слот (обработчик сигнала) - реализуется как обычный метод
//-->
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
//<--

void MainWindow::on_enableButton_clicked() {
  ui->concatButton->setEnabled(
    !ui->concatButton->isEnabled()
  );
  ui->enableButton->setText(
    ui->concatButton->isEnabled() ?
    "Запретить" : "Разрешить"
  );
}
