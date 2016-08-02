#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class Form1;
}

class Form1 : public QMainWindow {
  Q_OBJECT

 public:
  explicit Form1(QWidget* parent = 0);
  ~Form1();

  QMainWindow* form2;

 private slots:
  void on_gotoForm2_triggered();

 private:
  Ui::Form1* ui;
};

#endif // MAINWINDOW_H
