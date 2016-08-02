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
  void on_chooseSrcFileButton_clicked();

  void on_chooseDstFileButton_clicked();

  void on_encodeDecodeButton_clicked();

  // Слот для сигнала про обновление процентов
  void updateProgress(int percents);

 private:
  Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
