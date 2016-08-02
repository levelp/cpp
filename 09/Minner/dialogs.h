#ifndef DIALOGS_H
#define DIALOGS_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Dialogs : public QDialog {
  Q_OBJECT
 public:
  Dialogs();

  QHBoxLayout hi, lo;
  QVBoxLayout lay;
  QLabel label;
  QPushButton ok, cancel;

 public:
  Dialogs(QString);

 private slots:
  void ok_presed();
  void cancel_presed();

 signals:
  void exits();
};

#endif // DIALOGS_H
