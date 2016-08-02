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
  void on_concButton_clicked();

  void on_openSecondWindowButton_clicked();

 private:
  // Главное окно программы
  // Текущее окно приложения
  Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
