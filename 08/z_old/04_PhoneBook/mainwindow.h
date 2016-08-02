#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  void on_deleteButton_clicked();

  void on_addButton_clicked();

 private:
  Ui::MainWindow* ui;

  QSqlTableModel* model;
};

#endif // MAINWINDOW_H
