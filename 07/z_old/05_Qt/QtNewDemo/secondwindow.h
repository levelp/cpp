#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit SecondWindow(QWidget* parent = 0);
  ~SecondWindow();

 private:
  Ui::SecondWindow* ui;
};

#endif // SECONDWINDOW_H
