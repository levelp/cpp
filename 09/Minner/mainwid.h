#ifndef MAINWID_H
#define MAINWID_H

#include "common.h"
#include <QWidget>
#include "minner.h"
#include <QtGui>
#include <QApplication>
#include <QPushButton>
#include <QObject>
#include "buttons.h"

class Buttons;

class mainWid : public QWidget {
  Q_OBJECT
 public:

  mainWid(QWidget* mainwid = 0, int width = 10, int height = 10,  int mine = 10);
  ~mainWid();

  void setupField();
  void setMines();
  void setWeights();

  int getFieldWidth() {
    return fieldWidth;
  }

  int getFieldHeight() {
    return fieldHeight;
  }

  int getMines() {
    return mines;
  }

  friend class Minner;

  void Win();
  void GameOver();

  void checkNear(Buttons* pbt);
  Buttons** arrayButton;
  QVector<int> clickedButton;
  QVector<int> minePosition;

 private :
  int   fieldWidth;
  int   fieldHeight;
  int   mines;

 private slots:
  void onClick();
};

#endif // MAINWID_H
