#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSql>
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
  void on_addButton_clicked();

  void on_deleteSelectedButton_clicked();

  void on_filterEdit_textChanged(const QString& arg1);

 private:
  Ui::MainWindow* ui;

  QSqlDatabase dbase;

  QSqlTableModel* model;
};

#endif // MAINWINDOW_H
