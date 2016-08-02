#ifndef DEMOWINDOW_H
#define DEMOWINDOW_H

#include <QMainWindow>

namespace Ui {
class DemoWindow;
}

class DemoWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit DemoWindow(QWidget* parent = 0);
  ~DemoWindow();

 private:
  Ui::DemoWindow* ui;
};

#endif // DEMOWINDOW_H
