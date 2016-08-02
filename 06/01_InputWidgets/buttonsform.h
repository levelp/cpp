#ifndef BUTTONSFORM_H
#define BUTTONSFORM_H

#include <QMainWindow>

namespace Ui {
class ButtonsForm;
}

class ButtonsForm : public QMainWindow {
  Q_OBJECT

 public:
  explicit ButtonsForm(QWidget* parent = 0);
  ~ButtonsForm();

 private:
  Ui::ButtonsForm* ui;
};

#endif // BUTTONSFORM_H
