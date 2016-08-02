#ifndef DEMOWIDGETSWINDOW_H
#define DEMOWIDGETSWINDOW_H

#include <QMainWindow>

namespace Ui {
class DemoWidgetsWindow;
}

class DemoWidgetsWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit DemoWidgetsWindow(QWidget* parent = 0);
  ~DemoWidgetsWindow();

 private slots:
  void on_sumButton_clicked();

 private:
  Ui::DemoWidgetsWindow* ui;
};

#endif // DEMOWIDGETSWINDOW_H
