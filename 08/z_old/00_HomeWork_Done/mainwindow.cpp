#include "mainwindow.h"
#include "ui_mainwindow.h"

const char NO_OPERATION = '#';

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->operation->setText(QChar(NO_OPERATION));

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
  /// Когда нажимаем на цифру:
  ///-->
  switch (calcState) {
    case OPERATION: // Если сейчас операция
      // Очищаем дисплей
      clearDisplay();
      break;

    default:
      break;
  }

  // UTF-8
  QString s = ui->display->text();

  // (QPushButton *)QObject::sender() -
  //  отправитель текущего сигнала
  QPushButton* digitButton =
    (QPushButton*)QObject::sender();

  if(digitButton == NULL)
    return;

  QChar zero('0');

  // Удаляем из s все лидирующие нули
  if(s.at(0) == zero)
    s.remove(0, 1);

  // Дописываем новую цифру на экран
  s += digitButton->text();

  ui->display->setText(s);
  ///<--
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

void MainWindow::on_operation_clicked() {
  if(calcState == OPERATION)
    return;

  // Получаем компонент
  QPushButton* operButton =
    dynamic_cast<QPushButton*>
    (QObject::sender());

  // Складываем содержимое экрана и память
  QString as = ui->memory->text();
  QString bs = ui->display->text();
  double a = as.toDouble();
  double b = bs.toDouble();
  double res = 0;
  QString nextOp = operButton->text();

  switch (ui->operation->text().at(0).toLatin1()) {
    case '+':
      res = a + b;
      break;

    case '-':
      res = a - b;
      break;

    case '*':
      res = a * b;
      break;

    case '/':
      res = a / b;
      break;

    case '=':
      res = b;
      nextOp = QChar(NO_OPERATION);
      break;

    case NO_OPERATION:
      res = b;
      break;

    default:
      throw new QString("Unknown operation: " + operButton->text());
  }

  // Запоминаем нажатую кнопку - следующую операцию
  if(nextOp == QStringLiteral("="))
    ui->operation->setText(QChar(NO_OPERATION));
  else
    ui->operation->setText(nextOp);

  QString strTemplate("%1");
  QString strRes = strTemplate.arg(res);

  // Показываем значение на экране
  ui->display->setText(strRes);
  ui->memory->setText(strRes); // + " +");

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
