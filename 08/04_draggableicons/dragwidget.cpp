#include <QtWidgets>

#include "dragwidget.h"

QLabel* cur = NULL;

void DragWidget::loadIcon(const char filename[],
                          int x, int y) {
  QLabel* boatIcon = new QLabel(this);
  boatIcon->setPixmap(QPixmap(filename));
  boatIcon->move(x, y);
  boatIcon->show();
  boatIcon->setAttribute(Qt::WA_DeleteOnClose);
}

DragWidget::DragWidget(QWidget* parent)
  : QFrame(parent) {
  setMinimumSize(200, 200);
  setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);

  // Этот объект принимает
  // "перетащенные" в него объекты"
  setAcceptDrops(true);

  loadIcon(":/images/boat.png", 10, 10);
  loadIcon(":/images/car.png", 100, 10);
  loadIcon(":/images/house.png", 10, 80);
}

void DragWidget::dragEnterEvent(QDragEnterEvent* event) {
  if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
    if (event->source() == this) {
      event->setDropAction(Qt::MoveAction);
      event->accept();
    } else
      event->acceptProposedAction();
  } else
    event->ignore();
}

void DragWidget::dragMoveEvent(QDragMoveEvent* event) {
  if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
    if (event->source() == this) {
      event->setDropAction(Qt::MoveAction);
      event->accept();
    } else
      event->acceptProposedAction();
  } else
    event->ignore();
}

void DragWidget::dropEvent(QDropEvent* event) {
  if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
    QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
    QDataStream dataStream(&itemData, QIODevice::ReadOnly);

    QPixmap pixmap;
    QPoint offset;
    dataStream >> pixmap >> offset;

    // Hide old QLabel
    cur->hide();

    QLabel* newIcon = new QLabel(this);
    newIcon->setPixmap(pixmap);
    newIcon->move(event->pos() - offset);
    newIcon->show();
    newIcon->setAttribute(Qt::WA_DeleteOnClose);

    if (event->source() == this) {
      event->setDropAction(Qt::MoveAction);
      event->accept();
    } else
      event->acceptProposedAction();
  } else
    event->ignore();
}

//! [1]
void DragWidget::mousePressEvent(QMouseEvent* event) {
  QLabel* child = static_cast<QLabel*>(childAt(event->pos()));

  if (!child)
    return;

  QPixmap pixmap = *child->pixmap();

  QByteArray itemData;
  QDataStream dataStream(&itemData, QIODevice::WriteOnly);
  dataStream << pixmap << QPoint(event->pos() - child->pos());

  // Save QLabel
  cur = child;

  QMimeData* mimeData = new QMimeData;
  mimeData->setData("application/x-dnditemdata", itemData);

  QDrag* drag = new QDrag(this);
  drag->setMimeData(mimeData);
  drag->setPixmap(pixmap);
  drag->setHotSpot(event->pos() - child->pos());

  QPixmap tempPixmap = pixmap;
  QPainter painter;
  painter.begin(&tempPixmap);
  painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
  painter.end();

  child->setPixmap(tempPixmap);

  if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
    child->close();
  else {
    child->show();
    child->setPixmap(pixmap);
  }
}
