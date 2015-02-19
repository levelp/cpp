#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

//-->
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  // parent - объект при уничтожении которого
  //  должен быть уничтожен и этот объект
  // Обычно основное (главное) окно программы
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  // Слоты - методы-обработчики сигналов
  void on_pushButton_clicked();

  void on_closeButton_clicked();

  void on_concatButton_clicked();

  void on_enableButton_clicked();

 private:
  Ui::MainWindow* ui;
};
//<--

#endif // MAINWINDOW_H
