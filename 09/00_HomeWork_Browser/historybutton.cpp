#include "historybutton.h"

HistoryButton::HistoryButton(
  QWidget* parent,
  QString url) :
  QPushButton(parent),
  _url(url) {
  setText(_url.left(15));
  setToolTip(_url);

  // При нажатии на кнопку переходим на адрес
  connect(this, SIGNAL(clicked()),
          parent, SLOT(on_goToHistory_clicked()));
}

HistoryButton::~HistoryButton() {

}

