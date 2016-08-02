#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

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

  void on_removeButton_clicked();

 private:
  Ui::MainWindow* ui;

  // Модель: контейнер (массив) для записей
  // Хранилище строк для отображения в списке
  QStandardItemModel* listModel;
};

#endif // MAINWINDOW_H
