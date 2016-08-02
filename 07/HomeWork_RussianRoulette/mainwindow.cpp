/// Задание "Русская рулетка"
/// -------------------------
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "random.h"
#include "time.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  round(0), // Сначала мы сыграли 0 раундов
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  /// Очищаем лог игры
  ///-->
  ui->gameLog->clear();
  ///<--

  /// Инициализируем генератор случайных
  /// чисел по таймеру
  ///-->
  qsrand(time(0));
  ///<--
}

MainWindow::~MainWindow() {
  delete ui;
}

/// Добавление строки в "протокол" (log) игры
///-->
void MainWindow::log(QString s) {
  ui->gameLog->append(s);
}
///<--

void MainWindow::on_playButton_clicked() {
  /// Один раунд игры
  ///-->
  round++;
  log(QString("<strong>Раунд %1:</strong>").arg(round));

  // Ставка
  double bet = ui->betEdit->value();
  // На какое число ставим
  int betNumber = ui->numberEdit->value();
  log(QString("Ваша ставка %1 на %2.").
      arg(bet).arg(betNumber));

  // Крутим рулетку
  // qrand() 0..MAX_INT = 2^31-1
  int randNumber = random(1, 10); // Число 1..10
  log(QString("Выпало: %1.").arg(randNumber));

  // Пересчитываем баланс
  // QString.toDouble() - преобразует строку
  //  вида "213.1" в число типа double
  double balance = ui->balanceLabel->text().toDouble();
  // Запоминаем баланс
  double prev = balance;

  if(randNumber == betNumber) {
    balance += bet * 10;
    log(QString("Выйграли! Новый счёт: %1 + %2 = %3")
        .arg(prev).arg(balance - prev).arg(balance));
  } else {
    balance -= bet;
    log(QString("Проиграли! Новый счёт: %1 - %2 = %3")
        .arg(prev).arg(prev - balance).arg(balance));
  }

  // Баланс показываем в интерфейсе
  ui->balanceLabel->setText(
    QString("%1").arg(balance, 0, 'f', 1)
  );
  ///<--
}
