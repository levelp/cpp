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
  void on_goButton_clicked();

  void on_toolButton_clicked();

  void on_goToHistory_clicked();

  void on_webView_urlChanged(const QUrl& url);

 private:
  Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
