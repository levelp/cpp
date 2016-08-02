#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  setState(ENTER_NUMBER);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::clearDisplay() {
  ui->display->setText("0");
  setState(ENTER_NUMBER);
}

void MainWindow::on_digit_clicked() {
  switch (calcState) {
    case OPERATION:
      // Очищаем дисплей
      clearDisplay();
      break;

    default:
      break;
  }

  // UTF-8
  QString s = ui->display->text();

  QPushButton* button = (QPushButton*)QObject::sender();

  if(button == NULL)
    return;

  QChar zero('0');

  // Удаляем из s все лидирующие нули
  if(s.at(0) == zero)
    s.remove(0, 1);

  s += button->text();

  ui->display->setText(s);
}

void MainWindow::on_PointButton_clicked() {
  QString s = ui->display->text();
  int points = s.count(".");

  if(points == 0) {
    s += ".";
    ui->display->setText(s);
  }
}

void MainWindow::on_display_textChanged(const QString& arg1) {
  // Изменяем состояние всех кнопок

  // Можно нажимать ".",
  // только если на дисплее точек ещё нет
  int points = ui->display->text().count(".");
  ui->PointButton->setEnabled(points == 0);
}

void MainWindow::on_PlusButton_clicked() {
  if(calcState == OPERATION)
    return;

  // Складываем содержимое экрана и память
  QString as = ui->memory->text();
  QString bs = ui->display->text();
  double a = as.toDouble();
  double b = bs.toDouble();
  double res = a + b;
  QString strTemplate("%1");
  QString strRes = strTemplate.arg(res);

  // Запоминаем содержимое экрана
  ui->display->setText(strRes);
  ui->memory->setText(strRes);

  setState(OPERATION);
}

void MainWindow::setState(CalcStates state) {
  calcState = state;

  switch (calcState) {
    case OPERATION:
      ui->state->setText("Операция");
      break;

    case ENTER_NUMBER:
      ui->state->setText("Вводим число");
      break;

    default:
      ui->state->setText("Надо добавить описание :)");
      break;
  }
}

void MainWindow::on_ClearButton_clicked() {
  clearDisplay();
}
