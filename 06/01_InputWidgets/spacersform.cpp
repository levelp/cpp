#include "spacersform.h"
#include "ui_spacersform.h"

SpacersForm::SpacersForm(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::SpacersForm) {
  ui->setupUi(this);
}

SpacersForm::~SpacersForm() {
  delete ui;
}
