#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <string>
#include <QDir>
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Загрузка текста из файла
  // Utf-8
  QString q("Пример");

  qDebug() << "Current dir: " <<
           QDir::currentPath();

  ifstream in("../QtReadTextToInterface/text.txt");

  if(!in.good())
    return;

  while(!in.eof()) {
    string s;
    in >> s;
    QString qString = QString::fromStdString(s);
    ui->textEdit->append(qString);
  }

  in.close();

}

MainWindow::~MainWindow() {
  delete ui;
}
