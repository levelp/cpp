#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::LoginForm) {
  ui->setupUi(this);
}

LoginForm::~LoginForm() {
  delete ui;
}
