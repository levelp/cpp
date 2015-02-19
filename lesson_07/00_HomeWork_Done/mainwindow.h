#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class Form1 : public QMainWindow {
  Q_OBJECT

 public:
  explicit Form1(QWidget* parent = 0);
  ~Form1();

 public slots:
  void on_downButton_clicked();

  void on_rightButton_clicked();

  void on_leftButton_clicked();

  void on_upButton_clicked();

  void on_incFont_clicked();

  void on_decFont_clicked();

  void on_incFont_2_clicked();

  void on_decFont_2_clicked();

 private:
  Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
