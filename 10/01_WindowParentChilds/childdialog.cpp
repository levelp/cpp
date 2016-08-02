#include "childdialog.h"
#include "ui_childdialog.h"
#include <QDebug>

ChildDialog::ChildDialog(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::ChildDialog) {
  ui->setupUi(this);
}

ChildDialog::~ChildDialog() {
  qDebug() << "ChildDialog::~ChildDialog()";
  delete ui;
}

QString ChildDialog::getLogin() {
  return ui->loginEdit->text();
}

