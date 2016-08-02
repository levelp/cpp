#include "dialogs.h"

Dialogs::Dialogs(QString a) {
  label.setText(a);
  ok.setText(tr("New Game"));
  connect(&ok, SIGNAL(clicked()), this, SLOT(ok_presed()));
  cancel.setText(tr("Cancel"));
  connect(&cancel, SIGNAL(clicked()), this, SLOT(cancel_presed()));
  hi.addWidget(&label);
  lo.addWidget(&ok);
  lo.addWidget(&cancel);
  lay.addLayout(&hi);
  lay.addLayout(&lo);
  this->setLayout(&lay);
}

void Dialogs::ok_presed() {
  emit this->accepted();
  this->close();
}

void Dialogs::cancel_presed() {
  emit exits();
  this->close();
}

