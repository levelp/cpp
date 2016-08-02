#include "minner.h"

Minner::Minner(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::Minner) {
  ui->setupUi(this);
  QTime time;
  time.start();

  a = NULL;

  connect(ui->prof3, SIGNAL(activated()), this, SLOT(setFieldSize()));
  connect(ui->prof2, SIGNAL(activated()), this, SLOT(setFieldSize2()));
  connect(ui->prof, SIGNAL(activated()), this, SLOT(setFieldSize3()));
  connect(ui->Creat, SIGNAL(clicked()), this, SLOT(newGame()));
  connect(ui->Load, SIGNAL(activated()), this, SLOT(Restart()));
  connect(ui->Save, SIGNAL(activated()), this, SLOT(Savebi()));

  NewGame(10, 10, 10);
}

Minner::~Minner() {

  clear();
  restartVectorBut.clear();;
  restartMinPos.clear();;
  delete ui;
}

void Minner::changeEvent(QEvent* e) {
  QMainWindow::changeEvent(e);

  switch (e->type()) {
    case QEvent::LanguageChange:
      ui->retranslateUi(this);
      break;

    default:
      break;
  }
}

void Minner::NewGame(int width, int height, int mine) {
  clear();

  a = new mainWid(ui->centralWidget, width, height, mine);

  //MyThread thread;

  //QObject::connect(&thread, SIGNAL(currentValue(int)), ui->lcdNumber_2, SLOT(display(int)));
  //QObject::connect(&thread, SIGNAL(finished()), this, SLOT(close()));
  //thread.run();



  a->setupField();

  ui->verticalLayout->addWidget(a);

  ui->verticalLayout->setSpacing(2);

  a->show();

  ui->lcdNumber->display(mine);
}

void Minner::newGame() {
  NewGame(a->getFieldWidth(), a->getFieldWidth(), a->getMines());
}

void Minner::setFieldSize() {
  NewGame(10, 10, 10);
}

void Minner::setFieldSize2() {
  NewGame(16, 16, 40);
}

void Minner::setFieldSize3() {
  NewGame(25, 25, 100);
}

void Minner::clear() {
  if(a != NULL) {
    ui->verticalLayout->removeWidget(a);

    for (int i = 0; i < a->getFieldWidth(); i++)  delete [] a->arrayButton[i];

    delete []  a->arrayButton;
    delete a;
  }
}

void Minner::Savebi() {
  QFile file("FileForSave.bin");

  if(file.open(QIODevice::WriteOnly)) {
    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_4_6);
    stream << a->getFieldWidth() << a->getFieldHeight()  << a->getMines() << a->clickedButton << a->minePosition;

    if (stream.status() != QDataStream::Ok)
      qDebug() << "Error in save";
  }

  file.close();
}

void Minner::Readbi() {
  QFile file("FileForSave.bin");

  if(file.open(QIODevice::ReadOnly)) {
    QDataStream stream (&file);
    stream.setVersion(QDataStream::Qt_4_6);
    stream >> restartWidth >> restartHeight >> restartMine  >> restartVectorBut >> restartMinPos;

    if (stream.status() != QDataStream::Ok)
      qDebug() << "error in reading";
  }

  file.close();
}

void Minner::Restart() {
  if(a != NULL) {
    ui->verticalLayout->removeWidget(a);
    delete [] a->arrayButton;
    delete a;
  }

  Readbi();
  a = new mainWid(ui->centralWidget, restartWidth, restartWidth, restartMine);

  ui->verticalLayout->addWidget(a);
  ui->verticalLayout->setSpacing(2);

  for (int i = 0; i < restartMinPos.size() - 1;  i = i + 2)

    a->arrayButton[restartMinPos[i]][restartMinPos[i + 1]].SetBomb();

  a->setWeights();

  for (int i = 0; i < restartVectorBut.size() - 1;  i = i + 2)
    a->arrayButton[restartVectorBut[i]][restartVectorBut[i + 1]].click();


  a->show();

}



