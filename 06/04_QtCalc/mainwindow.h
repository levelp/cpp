#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <CalcStates.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

  void clearDisplay();
 private slots:
  void on_digit_clicked();

  void on_PointButton_clicked();

  void on_display_textChanged(const QString& arg1);

  void on_PlusButton_clicked();

  void on_ClearButton_clicked();

 private:
  Ui::MainWindow* ui;

  CalcStates calcState;
  void setState(CalcStates state);
};

#endif // MAINWINDOW_H
