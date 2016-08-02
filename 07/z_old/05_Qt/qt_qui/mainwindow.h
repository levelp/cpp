#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow2(QWidget* parent = 0);
  ~MainWindow2();

 private slots:
  void on_sumButton_clicked();

  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_checkBox_stateChanged(int arg1);

  void on_checkBox_toggled(bool checked);

 private:
  Ui::MainWindow2* ui;

  void moveSumButton(int dy);
};

#endif // MAINWINDOW_H
