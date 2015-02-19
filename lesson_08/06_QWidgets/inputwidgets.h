#ifndef INPUTWIDGETS_H
#define INPUTWIDGETS_H

#include <QMainWindow>

namespace Ui {
class InputWidgets;
}

class InputWidgets : public QMainWindow {
  Q_OBJECT

 public:
  explicit InputWidgets(QWidget* parent = 0);
  ~InputWidgets();

 private slots:
  void on_fontComboBox_currentIndexChanged(int index);

 private:
  Ui::InputWidgets* ui;
};

#endif // INPUTWIDGETS_H
