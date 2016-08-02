#ifndef FORM2_H
#define FORM2_H

#include <QMainWindow>

namespace Ui {
class Form2;
}

class Form2 : public QMainWindow {
  Q_OBJECT

 public:
  explicit Form2(QWidget* parent = 0);
  ~Form2();

  QMainWindow* form1;

 private slots:
  void on_gotoForm1_triggered();

 private:
  Ui::Form2* ui;
};

#endif // FORM2_H
