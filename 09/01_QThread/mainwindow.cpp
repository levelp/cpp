#include <QThread>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

class FindPrimesThread : public QThread {
 public:
  QListWidget* primesList;
  // Границы для поиска простых чисел
  long long from, to;
 protected:
  void run() {
    // Цикл от from до to
    for(long long n = from; n <= to ; n++)
      if(isPrime(n) && (n % 1000 == 567))
        primesList->addItem(QString("%1").arg(n));
  }
 private:
  bool isPrime(long long n) {
    for(long long i = 2; i * i <= n; i++)
      if(n % i == 0)
        return false;
    return true;
  }
};

void MainWindow::on_startFindPrimesButton_clicked() {
  // Запуск отдельного потока для поиска чисел
  FindPrimesThread* thread = new FindPrimesThread();
  // Передаём внутрь потока указатель на элемент интерфейса,
  // в который следует выводить результат
  thread->primesList = ui->primesList;
  // Передаём внутрь потока границы для поиска
  thread->from = ui->fromValue->value();
  thread->to = ui->toValue->value();
  // Запускаем поток на выполнение
  thread->start();
}
