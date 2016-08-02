#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 protected slots:
  void slot1();
  void slot2();

 private:
  Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
