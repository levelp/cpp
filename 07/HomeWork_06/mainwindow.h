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
  int X = 160;
  int Y = 50;

 private slots:
  void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);



  void on_right_clicked();

  void on_left_clicked();

  void on_up_clicked();

  void on_down_clicked();


 private:
  Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
