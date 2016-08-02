#ifndef MINNER_H
#define MINNER_H

#include "common.h"
#include "mainwid.h"
#include <QMainWindow>
#include <QPushButton>
#include "dialogs.h"

namespace Ui {
class Minner;
}
class mainWid;

class Minner : public QMainWindow {
  Q_OBJECT
 public:
  Minner(QWidget* parent = 0);
  ~Minner();
  friend class mainWid;
  void NewGame(int width, int height,  int mine);
  mainWid* a;
  void clear();

  void Readbi();

  QVector<int> restartVectorBut;
  QVector<int> restartMinPos;
  int restartWidth;
  int restartHeight;
  int restartMine;

 protected:
  void changeEvent(QEvent* e);

 private:
  Ui::Minner* ui;

 private slots:
  void newGame();
  void setFieldSize();
  void setFieldSize2();
  void setFieldSize3();
  void Restart();
  void Savebi();
};

#endif // MINNER_H
