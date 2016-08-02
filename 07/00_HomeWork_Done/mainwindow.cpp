/// Доступ к свойствам
/// ------------------
/// Если свойство называется имяСвойства
/// То для получения значения надо вызвать
/// метод имяСвойства(), и он вернёт значение свойства.
/// Причём это значение - копия реального значения.
/// Для изменения свойства вызвать:
///   setИмяСвойства(новоеЗначение)
#include "mainwindow.h"
#include "ui_mainwindow.h"

Form1::Form1(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

Form1::~Form1() {
  delete ui;
}

void Form1::on_downButton_clicked() {
  ui->textEdit->append("Вниз");
  /// Так сделать не получится:
  /// ``` cpp
  /// ui->textEdit->geometry().translate(0, 10);
  /// ```
  QRect rect = ui->textEdit->geometry();
  // translate перемещает объект
  rect.translate(0, ui->speedValue->value());
  ui->textEdit->setGeometry(rect);
}

void Form1::on_rightButton_clicked() {
  ui->textEdit->append("Вправо");
  QRect rect = ui->textEdit->geometry();
  rect.translate(ui->speedValue->value(), 0);
  ui->textEdit->setGeometry(rect);
}

void Form1::on_leftButton_clicked() {
  ui->textEdit->append("Влево");
  QRect rect = ui->textEdit->geometry();
  rect.translate(-ui->speedValue->value(), 0);
  ui->textEdit->setGeometry(rect);
}

void Form1::on_upButton_clicked() {
  ui->textEdit->append("Вверх");
  QRect rect = ui->textEdit->geometry();
  rect.translate(0, -ui->speedValue->value());
  ui->textEdit->setGeometry(rect);
}

void Form1::on_incFont_clicked() {
  // Получаем текущий шрифт формы
  QFont f(font());
  // Меняем размер шрифта
  f.setPointSize(f.pointSize() + 1);
  // Заменяем шрифт у всей формы
  setFont(f);
}

void Form1::on_decFont_clicked() {
  // Получаем текущий шрифт формы
  QFont f(font());
  // Меняем размер шрифта
  f.setPointSize(f.pointSize() - 1);
  // Заменяем шрифт у всей формы
  setFont(f);
}

void Form1::on_incFont_2_clicked() {
  QFont f(ui->decFont->font());
  f.setPointSize(f.pointSize() + 1);
  ui->incFont->setFont(f);
  ui->decFont->setFont(f);
}

void Form1::on_decFont_2_clicked() {
  QFont f(ui->decFont->font());
  f.setPointSize(f.pointSize() - 1);
  ui->incFont->setFont(f);
  ui->decFont->setFont(f);
}
