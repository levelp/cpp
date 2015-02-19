#ifndef HISTORYBUTTON_H
#define HISTORYBUTTON_H

#include <QPushButton>
#include <QHBoxLayout>

class HistoryButton : public QPushButton {
  QString _url;
 public:
  HistoryButton(QWidget* parent,
                QString url);
  ~HistoryButton();
  QString url() const {
    return _url;
  }
};

#endif // HISTORYBUTTON_H
