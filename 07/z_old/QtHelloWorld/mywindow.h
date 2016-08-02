#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>

namespace Ui {
class MyWindow;
}

class MyWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MyWindow(QWidget* parent = 0);
  ~MyWindow();

 private slots:
  void on_onButton_clicked();

  void on_offButton_clicked();

  void on_exitButton_clicked();

  void close();

 private:
  Ui::MyWindow* ui;
};

#endif // MYWINDOW_H
