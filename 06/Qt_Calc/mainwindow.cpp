#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  operation(NULL) {
  ui->setupUi(this);

  //  Источник сигнала -> слот (приёмник сигнала)
  /*connect(ui->b1, SIGNAL(clicked()),
          this, SLOT(on_digit_clicked()));
  connect(ui->b2, SIGNAL(clicked()),
          this, SLOT(on_digit_clicked()));
  connect(ui->b3, SIGNAL(clicked()), this, SLOT(on_digit_clicked()));
  connect(ui->b4, SIGNAL(clicked()), this, SLOT(on_digit_clicked()));
  connect(ui->b5, SIGNAL(clicked()), this, SLOT(on_digit_clicked())); */
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_b0_clicked() {
  QString s = ui->display->text();
  s += "0";
  ui->display->setText(s);
}

void MainWindow::on_digit_clicked() {
  // QObject::sender() - Объект,
  // который отправил текущий сигнал
  QPushButton* button = dynamic_cast<QPushButton*> (QObject::sender());

  if(button != NULL) {
    // Если состояние - ввод нового числа
    if(ui->state->text() == "new") {
      // Очищаем экран
      on_clearButton_clicked();
      // Меняем состяние
      ui->state->setText("enter");
    }

    QString s = ui->display->text();
    if(s == "0")
      s = "";
    // Получаем текст с кнопки
    s += button->text();
    ui->display->setText(s);
  }
}


void MainWindow::on_clearButton_clicked() {
  ui->display->setText("0");
}

void MainWindow::on_plusButton_clicked() {
  commonOperation("+");
  class PlusOperation : public Operation {
    long calc(long a, long b) {
      return a + b;
    }
  };
  operation = new PlusOperation;
}

void MainWindow::on_calcButton_clicked() {
  // Первый операнд в памяти
  QString op1 = ui->memory->text();
  // Второй операнд на экране
  QString op2 = ui->display->text();
  // Операция тоже в памяти
  QString op = ui->operation->text();

  long a = op1.toLong();
  long b = op2.toLong();

  long res = operation->calc(a, b);

  // Результат на экран
  ui->display->setText(QString("%1").arg(res));
  // Очищаем память
  ui->memory->setText("0");
  ui->operation->setText("");
  ui->state->setText("");
}

void MainWindow::commonOperation(QString operationName) {
  ui->memory->setText(ui->display->text());
  ui->state->setText("new");
  ui->operation->setText(operationName);
}

void MainWindow::on_minusButton_clicked() {
  commonOperation("-");
  class Minus : public Operation {
    long calc(long a, long b) {
      return a - b;
    }
  };
  operation = new Minus;
}

void MainWindow::on_mulButton_clicked() {
  commonOperation("*");
  class Mul : public Operation {
    long calc(long a, long b) {
      return a * b;
    }
  };
  operation = new Mul;

}

void MainWindow::on_divButton_clicked() {
  commonOperation("/");
  class Div : public Operation {
    long calc(long a, long b) {
      return a / b;
    }
  };
  operation = new Div;
}
