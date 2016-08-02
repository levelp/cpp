#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QFrame>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class DragWidget : public QFrame {
 public:
  explicit DragWidget(QWidget* parent = 0);
  void loadIcon(const char filename[], int x, int y);
 protected:
  void dragEnterEvent(QDragEnterEvent* event) Q_DECL_OVERRIDE;
  void dragMoveEvent(QDragMoveEvent* event) Q_DECL_OVERRIDE;
  void dropEvent(QDropEvent* event) Q_DECL_OVERRIDE;
  void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
};

#endif // DRAGWIDGET_H
