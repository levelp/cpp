#ifndef WND_H
#define WND_H

#include <QObject>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QLineEdit>
#include <QString>

#include "datetime.h"

class TWindow : public QMainWindow {
  Q_OBJECT

  TDateTime* datetime;

  QMenuBar* menuBar;
  QLineEdit* e1;
  QLabel*   l1;
  QLabel*   l2;
  QLabel*   l3;

  void createMenu();

 public:

  TWindow();
  ~TWindow();

 public slots:

  void dt1();
  void dt2();
  void dt3();
  void dt4();
  void dt5();
  void op1();
  void op2();

};

#endif // WND_H
