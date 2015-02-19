#ifndef BUTTONS_H
#define BUTTONS_H

#include <common.h>
#include <QPushButton>
#include <QMouseEvent>

class Buttons : public QPushButton {
  Q_OBJECT
 public:
  Buttons(QWidget* mainwid = 0): QPushButton(mainwid), weight(0), butCol(0), butRow(0), bomb(0) {}
  friend class mainWid;
  int GetbutRow() {
    return butRow;
  }
  int GetbutCol() {
    return butCol;
  }
  bool GetBomb() {
    return bomb;
  }
  int GetWeight() {
    return weight;
  }
  void SetBomb() {
    bomb = 1;
  }

 private:
  int weight;
  int butCol;
  int butRow;
  bool bomb;

 private slots:
  void mousePressEvent(QMouseEvent* event) {
    if (event->buttons() == Qt::RightButton ) {
      if (!isDown()) {
        setIcon(QIcon(QString("im2.png")));
        setDown(true);
      } else setDown(false);

      setIcon(QIcon(QString("im3.png")));
    }

    if (event->buttons() == Qt::LeftButton)
      click();
  }
};

#endif // BUTTONS_H
