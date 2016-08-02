#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

// Состояние калькулятора
//enum CalcState {
//   ENTER_NUMBER, // Вводим число
//  NEW_NUMBER, // Перед вводом нового числа
//};

// Абстрактный класс операции
class Operation {
 public:
  // Чистый виртуальный метод вычисления
  virtual long calc(long a, long b) = 0;
};


class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

  void commonOperation(QString operationName);

 private slots:
  void on_b0_clicked();

  void on_digit_clicked();
  void on_clearButton_clicked();

  void on_plusButton_clicked();

  void on_calcButton_clicked();

  void on_minusButton_clicked();

  void on_mulButton_clicked();

  void on_divButton_clicked();

 private:
  Ui::MainWindow* ui;

  Operation* operation;
};

#endif // MAINWINDOW_H
