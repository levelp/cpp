#include "wnd.h"

TWindow::TWindow() : QMainWindow() {
  setWindowTitle("DATETIME");
  setFixedSize(400, 300);

  createMenu();

  l1 = new QLabel("Entry data:", this);
  l1->setGeometry(10, 40, 180, 20);
  e1 = new QLineEdit(this);
  e1->setGeometry(200, 40, 180, 20);
  l2 = new QLabel("Date and Time:", this);
  l2->setGeometry(10, 70, 180, 20);
  l3 = new QLabel(this);
  l3->setGeometry(200, 70, 180, 20);

  datetime = NULL;
};

TWindow::~TWindow() {
  if (datetime != NULL)
    delete datetime;

  delete menuBar;
  delete l1;
  delete l2;
  delete l3;
  delete e1;
};

void TWindow::createMenu() {
  QAction* a;
  QMenu*   m;

  menuBar = new QMenuBar(this);

  m = new QMenu("Constructors", this);

  a = new QAction("From seconds", this);
  connect(a, SIGNAL(triggered()), this, SLOT(dt1()));
  m->addAction(a);

  a = new QAction("Current", this);
  connect(a, SIGNAL(triggered()), this, SLOT(dt2()));
  m->addAction(a);
  a = new QAction("From Time", this);
  connect(a, SIGNAL(triggered()), this, SLOT(dt3()));
  m->addAction(a);
  a = new QAction("From Date", this);
  connect(a, SIGNAL(triggered()), this, SLOT(dt4()));
  m->addAction(a);
  a = new QAction("From Date and Time", this);
  connect(a, SIGNAL(triggered()), this, SLOT(dt5()));
  m->addAction(a);
  menuBar->addMenu(m);

  m = new QMenu("Operations", this);
  a = new QAction("operator +", this);
  m->addAction(a);
  connect(a, SIGNAL(triggered()), this, SLOT(op1()));
  a = new QAction("operator +=", this);
  connect(a, SIGNAL(triggered()), this, SLOT(op2()));
  m->addAction(a);
  menuBar->addMenu(m);

  a = new QAction("Exit", this);
  menuBar->addAction(a);
  connect(a, SIGNAL(triggered()), this, SLOT(close()));

  setMenuBar(menuBar);
}

void TWindow::dt1() {
  if (datetime != NULL)
    delete datetime;

  datetime = new TDateTime(e1->text().toUInt());
  l2->setText(datetime->toString("dd.MM.yyyy hh:mm:ss"));
}

void TWindow::dt2() {
  if (datetime != NULL)
    delete datetime;

  datetime = new TDateTime();
  l2->setText(datetime->toString("dd.MM.yyyy hh:mm:ss"));
}

void TWindow::dt3() {
  if (datetime != NULL)
    delete datetime;

  datetime = new TDateTime(QTime::fromString(e1->text()));
  l2->setText(datetime->toString("dd.MM.yyyy hh:mm:ss"));
}

void TWindow::dt4() {
  if (datetime != NULL)
    delete datetime;

  datetime = new TDateTime(QDate::fromString(e1->text(), "dd.MM.yyyy"));
  l2->setText(datetime->toString("dd.MM.yyyy hh:mm:ss"));
}

void TWindow::dt5() {
  if (datetime != NULL)
    delete datetime;

  datetime = new TDateTime(e1->text());
  l2->setText(datetime->toString("dd.MM.yyyy hh:mm:ss"));
}

void TWindow::op1() {
  TDateTime dt;
  uint t = (e1->text()).toUInt();
  dt = (*datetime + t);
  l2->setText(dt.toString("dd.MM.yyyy hh:mm:ss"));
}

void TWindow::op2() {
  *datetime += (e1->text()).toUInt();
  l2->setText(datetime->toString("dd.MM.yyyy hh:mm:ss"));
}
