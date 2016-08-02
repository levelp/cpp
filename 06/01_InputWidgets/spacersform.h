#ifndef SPACERSFORM_H
#define SPACERSFORM_H

#include <QMainWindow>

namespace Ui {
class SpacersForm;
}

class SpacersForm : public QMainWindow {
  Q_OBJECT

 public:
  explicit SpacersForm(QWidget* parent = 0);
  ~SpacersForm();

 private:
  Ui::SpacersForm* ui;
};

#endif // SPACERSFORM_H
