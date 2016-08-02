#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

// Свой Qt-класс
class A : public QObject {
  Q_OBJECT

 private slots:
  void pp() {}
};

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  void on_pushButton_clicked();

  void s();

 private:
  Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
