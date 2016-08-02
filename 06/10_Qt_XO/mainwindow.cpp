#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug> // Для qDebug()
#include <QFileDialog> // Диалог выбора имени файла
#include <QMessageBox> // Диалоговое окно с сообщением
#include "gamesettings.h"
#include "map_size.h"

void MainWindow::resizeButtonsArray() {
  cells.resize(MapSize);

  for(int i = 0; i < MapSize; ++i)
    cells[i].resize(MapSize);
}

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Скрываем кнопку с прототипом
  ui->fontPrototypeButton->setVisible(false);

  // Задаём размер массиву кнопок
  resizeButtonsArray();

  // Заполним весь массив кнопок поля NULL
  for(int i = 0; i < MapSize; i++)
    for(int j = 0; j < MapSize; j++)
      cells[i][j] = NULL;

  // Начало игры
  qDebug() << "Constructor >>> ";
  newGame();
  qDebug() << "<<< Constructor";
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::exit_application() {
  // Выход из программы
  QApplication::exit();
}

void MainWindow::slot1() {
  //ui->lineEdit_1->setText(QString("1"));
  qDebug() << "slot1() " << 1 << " !!";
}

void MainWindow::slot2() {
  //ui->lineEdit_2->setText(QString("2"));
  qDebug() << "slot2()";
}

// После изменения состояния игры
void MainWindow::updateWindow() {
  qDebug() << "updateWindow()";
  ui->moveLabel->setText(game.getStateString());
  // Подстраиваем размер, т.к. эта метка не в Layout
  ui->moveLabel->adjustSize();
  int windowSize = this->geometry().width();
  QRect rect = ui->moveLabel->geometry();
  qDebug() << windowSize << "  Width: " << rect.width();

  int borderSize = 10; // Бордюр справа
  rect.moveLeft(windowSize - rect.width() - borderSize);

  ui->moveLabel->setGeometry(rect);
}

void MainWindow::newGame() { // Новая игра
  game.newGame();
  updateWindow();
  updateGameButtons();
}

void MainWindow::updateGameButtons() {
  int cellSize = 60; // Размер кнопки
  int cellSpace = 6; // Отступ
  int topSpace = 80; // Отступ сверху
  int leftSpace = 50; // Отступ слева
  int randOffset = 5;

  for(unsigned int i = 0; i < cells.size(); ++i)
    for(unsigned int j = 0; j < cells[i].size(); ++j) {
      qDebug() << "Delete: " << i << " " << j;

      if(cells[i][j] != NULL)
        delete cells[i][j];
    }

  resizeButtonsArray();

  // Создаём массив MapSize на MapSize из QPushButton
  for(int i = 0; i < MapSize; i++)
    for(int j = 0; j < MapSize; j++) {
      cells[i][j] = new CellButton(game.getCell(i, j), this, i, j, game);
      // Шрифт как в прототипе
      cells[i][j]->setFont(ui->fontPrototypeButton->font());
      // Задаём размеры и положение кнопки
      cells[i][j]->setGeometry(
        (cellSize + cellSpace) * j + leftSpace + (rand() % randOffset),
        (cellSize + cellSpace) * i + topSpace + (rand() % randOffset),
        cellSize, // Ширина кнопки
        cellSize  // Высота кнопки
      );

      cells[i][j]->setVisible(true);

      connect(cells[i][j], SIGNAL(clicked()),
              cells[i][j], SLOT(slotCellClicked()));

      connect(cells[i][j], SIGNAL(clicked()),
              this, SLOT(updateWindow()));
    }
}

void MainWindow::saveGame() { // Сохранить игру в файл
  QString filename = QFileDialog::getSaveFileName(
                       this, "Сохранить игру", "", // C:\\Users\\Денис\\Desktop
                       "Игра XO (*.game)"); // "Как картинку (*.jpg);;Игра XO (*.game)"
  qDebug() << filename;

  if(filename.isEmpty())
    return;

  game.save(filename);
}

void MainWindow::loadGame() { // Загрузить игру из файла
  QString filename = QFileDialog::getOpenFileName(
                       this, "Загрузить игру", "",
                       "Игра XO (*.game)");

  try {
    game.load(filename);
  } catch(QString q) {
    // critical(QWidget * parent, const QString & title,
    // const QString & text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton)
    QMessageBox::critical(this,
                          QString("Ошибка при чтении файла"),
                          q);
  }

  updateWindow();

  updateGameButtons();
}

void MainWindow::on_exitButton_clicked() {

}

void MainWindow::myNewSlot() {
  qDebug() << "myNewSlot()";
}

void MainWindow::on_action_triggered() {

}

void MainWindow::on_action_2_triggered() {

}

void MainWindow::on_setFieldSize_triggered() {
  // Вызываем окно настройки размера поля
  GameSettings gs(this);
  gs.exec();

  // После изменения размера поля
  // перестартуем игру
  newGame();
}
