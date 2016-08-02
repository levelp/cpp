#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::Dialog) {
  ui->setupUi(this);
}

Dialog::~Dialog() {
  delete ui;
}

void Dialog::on_switchBackButton_clicked() {
  // Мы находимся внутри формы 2
  // Скрываем себя
  hide();
  // Переключаемся обратно
  form->show();
}
