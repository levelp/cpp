#include "demowidgetswindow.h"
#include "ui_demowidgetswindow.h"
#include <QDebug>
#include <string>
#include <sstream>

using namespace std;

DemoWidgetsWindow::DemoWidgetsWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::DemoWidgetsWindow) {
  ui->setupUi(this);
}

DemoWidgetsWindow::~DemoWidgetsWindow() {
  delete ui;
}

void DemoWidgetsWindow::on_sumButton_clicked() {
  qDebug() << "on_sumButton_clicked"; // endl;
  QString AStr = ui->AEdit->text();
  double A = AStr.toDouble();
  double B = ui->BEdit->text().toDouble();
  qDebug() << "A =" << A << "  B =" << B;
  double sum = A + B;
  qDebug() << "sum =" << sum;

  QString resTemplate("res = %1");
  qDebug() << "resTemplate =" << resTemplate;
  QString res = resTemplate.arg(sum);
  qDebug() << "res =" << res;

  /// Печать в строку как в поток
  ///-->
  ostringstream sstream;
  sstream << sum;
  ///<--

  ui->sumEdit->setText(res);
}
