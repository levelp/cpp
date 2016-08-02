#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

/// При нажатии на любую клавишу с текстом
void MainWindow::on_digitButton_clicked() {
  ///-->
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
  ///<--
}

void MainWindow::on_button1_clicked() {
  // Ещё один обработчик для кнопки 1 :)
}
