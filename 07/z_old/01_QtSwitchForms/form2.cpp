#include "form2.h"
#include "ui_form2.h"

Form2::Form2(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::Form2) {
  ui->setupUi(this);
}

Form2::~Form2() {
  delete ui;
}

void Form2::on_gotoForm1_triggered() {
  hide();
  form1->show();
}
