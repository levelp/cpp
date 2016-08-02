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
  void on_fontComboBox_currentIndexChanged(const QString& arg1);

  void on_fontComboBox_activated(const QString& arg1);

  void on_spacersButton_clicked();

  void on_actionGroupBox_triggered();

  void on_action_triggered();

 private:
  Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
