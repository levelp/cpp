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
  void on_pushButton_clicked();

  void on_generateStr1_triggered();

  void on_generateStr2_triggered();

 private:
  Ui::MainWindow* ui;

  // Генерация случайной строки
  QString generateRandomString();
};

#endif // MAINWINDOW_H
