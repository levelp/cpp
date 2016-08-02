#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "childdialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_childWindowButton_clicked() {
  ChildDialog cd(this);
  cd.exec();
  qDebug() << "Before addItem()";
  ui->listWidget->addItem(
    QString("Login: %1").arg(cd.getLogin())
  );
  qDebug() << "After addItem()";
  // Деструктор
}

void MainWindow::on_notModalButton_clicked() {
  ChildDialog* cd = new ChildDialog(this);
  cd->show();

  connect(cd, SIGNAL(accepted()),
          this, SLOT(dialogClosed()));
}

void MainWindow::dialogClosed() {
  ChildDialog* cd = (ChildDialog*) QObject::sender();

  ui->listWidget->addItem(
    QString("Login: %1").arg(cd->getLogin())
  );
}
