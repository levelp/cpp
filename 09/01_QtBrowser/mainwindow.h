#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebKit>
#include "urlworker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public UrlWorker {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

  void DoURL(QString URL);

 private slots:
  void on_pushButton_clicked();

 private:
  Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
