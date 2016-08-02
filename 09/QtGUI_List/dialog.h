#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

// Вторая форма
class Dialog : public QDialog {
  Q_OBJECT

  // Ссылка на первую форму
  QWidget* form;

 public:
  explicit Dialog(QWidget* parent = 0);
  ~Dialog();

  void setFrom(QWidget* f) {
    form = f;
  }

 private slots:
  void on_switchBackButton_clicked();

 private:
  Ui::Dialog* ui;
};

#endif // DIALOG_H
