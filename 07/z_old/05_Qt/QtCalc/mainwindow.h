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

 private slots:
  void xbutton_clicked();

  void on_operation_clicked();

  void on_calcButton_clicked();

  void on_pointButton_clicked();

 private:
  Ui::MainWindow* ui;

  //-->
  typedef double number;

  // Последняя операция
  char operation;
  // Запоминаем число набранное на калькуляторе
  number arg;
  // Сейчас будем вводить новое число
  bool newNumber;
  //<--
};

#endif // MAINWINDOW_H
