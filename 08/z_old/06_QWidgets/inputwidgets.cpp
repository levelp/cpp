#include "inputwidgets.h"
#include "ui_inputwidgets.h"
#include <QFont>

InputWidgets::InputWidgets(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::InputWidgets) {
  ui->setupUi(this);
}

InputWidgets::~InputWidgets() {
  delete ui;
}


void InputWidgets::on_fontComboBox_currentIndexChanged(int index) {
  QFont font;
  font = ui->fontComboBox->currentFont();
  ui->centralwidget->setFont(font);
}
