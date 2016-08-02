/// Работа с QString
/// ----------------
/// http://doc.qt.io/qt-5/
/// http://doc.qt.io/qt-5/qstring.html
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString& arg1) {
  QString s1 = ui->lineEdit->text();
  QString s2 = ui->lineEdit_2->text();
  qDebug() << s1 << s2;

  // Печать в строчку по шаблону
  QString sum = QString("%1 + %2 = %3")
                .arg(2).arg(3).arg(2.2 + 3.3);
  qDebug() << sum;

  // Определение длины строчки
  QString res = QString("%1 (%2) %3 (%4)")
                .arg(s1).arg(s1.length())
                .arg(s2).arg(s2.length());


  // Печать в QString с помощью sprintf()
  char* buf = "Test";
  QString r2;
  r2.sprintf("%d %d [%s]",
             s1.length(), s2.length(),
             buf);

  ui->concatLineEdit->setText(
    //QString("%1 - %2").arg(s1).arg(s2)
    res + r2
  );

  // indexOf - поиск подстроки
  ui->concatLineEdit->setText(
    QString("\"%1\".indexOf(\"%2\") - %3").
    arg(s1, s2)
    .arg(s1.indexOf(s2))
  );

  // s1 заканчивается на s2
  s1.endsWith(s2);
  // s1 начинается c s2
  s1.startsWith(s2);

  // Поменять s1 и s2 значениями
  s1.swap(s2);
  qDebug() << s1 << s2;

  QString num;
  // 7 - число 2 - система счисления
  num.setNum(7, 2);
  ui->concatLineEdit->setText(num);

  // Добавить символ в конец
  QString.append('C');
  // Добавить строчку в конец
  QString.append("Строчка");

  // Сравнение строк
  QString A("A"), B("B");
  if(A < B) {
    ...
  }

  // Разбор чисел
  QString S("10");
  int i = S.toInt();
  long l = S.toLong();
  long long ll = S.toLongLong();
  \
  QString S2("2.3");
  double d = S2.toDouble();
  float f = S2.toFloat();

  // В нижний регистр (строчные буквы)
  QString sl = S.toLower();
  // В верхний регистр (прописные буквы)
  QString su = S.toUpper();

  /*QChar c1('A');
  QString manyA(10, c1);
  qDebug() << manyA;
  ui->concatLineEdit->setText(manyA);
  */
}


void MainWindow::on_lineEdit_3_textChanged(const QString& arg1) {

}

void MainWindow::on_decEdit_textChanged(const QString& arg1) {
  // Получаем число в десятичной системе счисления
  QString decStr = ui->decEdit->text();
  bool OK;
  int N = decStr.toInt(&OK);
  QString hexStr;
  hexStr.sprintf("%04X", N);
  ui->hexEdit->setText(hexStr);
}
