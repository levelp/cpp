#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

namespace Ui {
class MainWindow;
}

// Первая форма
class MainWindow : public QMainWindow {
  Q_OBJECT

  // Ссылка на форму 2
  Dialog* f;

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  void on_addToListButton_clicked();

  void on_actionSwitchToForm2_triggered();

 private:
  Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
