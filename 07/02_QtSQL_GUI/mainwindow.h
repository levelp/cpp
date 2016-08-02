#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

  bool createConnection();

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();


 private slots:
  void on_submitChangesButton_clicked();

 private:
  Ui::MainWindow* ui;

  QSqlTableModel* model;
};

#endif // MAINWINDOW_H
