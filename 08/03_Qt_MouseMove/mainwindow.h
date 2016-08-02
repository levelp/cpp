#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 protected:
  // Обработчик движения мыши
  virtual void mouseMoveEvent(QMouseEvent* event);
  // Сюда будем выводить координаты мыши
  QLabel* mousePosition;

 private slots:
  // Обработчик при нажатии на кнопку "Да"
  void on_yesButton_clicked();

 private:
  Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
