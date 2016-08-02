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
  // Применение регулярного выражения к тексту
  // с выводом результата обратно на форму
  void applyRegExp();

  // Сохранение текста в файл
  void saveText();

  // Загрузка текста из файла
  void loadText();

  void myNewSlot();

  // При обновлении текста
  void on_sourceText_textChanged();

  void on_chooseFontsAction_triggered();

 private:
  Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
