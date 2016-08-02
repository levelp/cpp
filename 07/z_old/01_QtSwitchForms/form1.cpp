#include "form1.h"
#include <iostream>

Form1::Form1(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::Form1) {
  ui->setupUi(this);
}

Form1::~Form1() {
  delete ui;
}

void Form1::on_gotoForm2_triggered() {
  std::cout << __FUNCTION__ << std::endl;
  hide();
  form2->show();
}
