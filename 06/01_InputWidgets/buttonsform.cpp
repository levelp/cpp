#include "buttonsform.h"
#include "ui_buttonsform.h"

ButtonsForm::ButtonsForm(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::ButtonsForm) {
  ui->setupUi(this);
}

ButtonsForm::~ButtonsForm() {
  delete ui;
}
