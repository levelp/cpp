#include "mainwid.h"


mainWid::mainWid(QWidget* mainwid, int width, int height, int mine): QWidget(mainwid) {

  mines = mine;
  fieldWidth = width;
  fieldHeight = height;

  arrayButton = new Buttons* [fieldWidth];

  QGridLayout* lay = new QGridLayout(this);

  lay->setSpacing(0);

  for (int i = 0; i < fieldWidth; i++) {
    arrayButton[i] = new Buttons[fieldHeight];

    for (int j = 0; j < fieldHeight; j++) {
      arrayButton[i][j].setMaximumSize(20, 20);
      lay->addWidget(&arrayButton[i][j], i, j);

      arrayButton[i][j].butCol = i;
      arrayButton[i][j].butRow = j;

      connect(&arrayButton[i][j], SIGNAL(clicked()), this, SLOT(onClick()));

      arrayButton[i][j].show();
    }
  }
}

mainWid::~mainWid() {
  clickedButton.clear();
  minePosition.clear();
}

void mainWid::setupField() {
  setMines();
  setWeights();
}

void mainWid::onClick() {
  Buttons* but = (Buttons*)sender();

  clickedButton.push_back(but->GetbutCol());
  clickedButton.push_back(but->GetbutRow());

  but->setEnabled(false);

  if (but->GetBomb() == 1) {
    but->setIcon(QIcon(QString(":/img/im.png")));
    GameOver();
  } else {
    if (but->GetWeight() != 0 ) but->setText(QString("%1").arg(but->GetWeight()));

    else  checkNear(but);
  }
}


void mainWid::setMines() {

  qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

  for (int i = 0; i < mines; i++) {
    int randRow = qrand() % (fieldWidth);
    int randCol = qrand() % (fieldHeight);
    minePosition.push_back(randCol);
    minePosition.push_back(randRow);
    arrayButton[randCol][randRow].bomb = 1;
  }
}


void mainWid::setWeights() {
  for (int i = 0; i < fieldWidth; i++) {
    for (int j = 0; j < fieldHeight; j++) {
      if (arrayButton[i][j].bomb == 1) {
        if ((arrayButton[i][j].butCol + 1) < fieldWidth) arrayButton[i + 1][j].weight++;

        if ((arrayButton[i][j].butCol - 1) >= 0)  arrayButton[i - 1][j].weight++;

        if ((arrayButton[i][j].butRow - 1) >= 0)  arrayButton[i][j - 1].weight++;

        if ((arrayButton[i][j].butRow + 1) < fieldHeight)  arrayButton[i][j + 1].weight++;

        if (((arrayButton[i][j].butCol - 1 >= 0)) && ((arrayButton[i][j].butRow - 1) >= 0))  arrayButton[i - 1][j - 1].weight++;

        if (((arrayButton[i][j].butCol + 1) < fieldWidth) && ((arrayButton[i][j].butRow - 1) >= 0))  arrayButton[i + 1][j - 1].weight++;

        if (((arrayButton[i][j].butCol + 1) < fieldWidth) && ((arrayButton[i][j].butRow + 1) < fieldHeight))  arrayButton[i + 1][j + 1].weight++;

        if (((arrayButton[i][j].butCol - 1) >= 0) && ((arrayButton[i][j].butRow + 1) < fieldHeight)) arrayButton[i - 1][j + 1].weight++;
      }
    }
  }
}

void mainWid::checkNear(Buttons* pbt) {
  int i = pbt->GetbutCol();
  int j = pbt->GetbutRow();

  if (((i + 1) < fieldWidth) && ((j + 1) < fieldHeight)) arrayButton[i + 1][j + 1].click();

  if (((i + 1) < fieldWidth) && ((j - 1) >= 0)) arrayButton[i + 1][j - 1].click();

  if (((i - 1) >= 0) && ((j + 1) < fieldHeight)) arrayButton[i - 1][j + 1].click();

  if (((i + 1) < fieldWidth) && ((j - 1) >= 0)) arrayButton[i + 1][j - 1].click();

  if ((i + 1) < fieldWidth) arrayButton[i + 1][j].click();

  if ((i - 1) >= 0) arrayButton[i - 1][j].click();

  if ((j + 1) < fieldHeight) arrayButton[i][j + 1].click();

  if ((j - 1) >= 0) arrayButton[i][j - 1].click();

}

void mainWid::GameOver() {
  Dialogs* dial = new Dialogs(tr("Game Over"));
  connect(dial, SIGNAL(accepted()), this, SLOT(newGame()));
  connect(dial, SIGNAL(exits()), this, SLOT(close()));
  dial->exec();
}

void mainWid::Win() {
  QString a(tr("Your Win"));
  Dialogs* dial = new Dialogs(a);
  connect(dial, SIGNAL(accepted()), this, SLOT(newGame()));
  connect(dial, SIGNAL(exits()), this, SLOT(close()));
  dial->exec();
}

