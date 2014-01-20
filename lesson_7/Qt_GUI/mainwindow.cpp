#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug> // Для qDebug()
#include <QFileDialog> // Диалог выбора имени файла

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect(ui->exitMenu, SIGNAL(aboutToShow())

    // Скрываем кнопку с прототипом
    ui->fontPrototypeButton->setVisible(false);

    // Начало игры
    updateWindow();

    int cellSize = 60; // Размер кнопки
    int cellSpace = 10; // Отступ
    int topSpace = 80; // Отступ сверху
    int leftSpace = 50; // Отступ слева

    // Создаём массив 3 на 3 из QPushButton
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            cells[i][j] = new CellButton(" ", this, i, j, game);
            // Шрифт как в прототипе
            cells[i][j]->setFont(ui->fontPrototypeButton->font());
            // Задаём размеры и положение кнопки
            cells[i][j]->setGeometry(
                        (cellSize + cellSpace) * j + leftSpace,
                        (cellSize + cellSpace) * i + topSpace,
                        cellSize, // Ширина кнопки
                        cellSize  // Высота кнопки
                        );

            connect(cells[i][j], SIGNAL(clicked()),
                    cells[i][j], SLOT(slotCellClicked()));

            connect(cells[i][j], SIGNAL(clicked()),
                    this, SLOT(updateWindow()));
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exit_application()
{
    // Выход из программы
    QApplication::exit();
}

void MainWindow::slot1()
{
    ui->lineEdit_1->setText(QString("1"));
    qDebug() << "slot1() " << 1 << " !!";
}

void MainWindow::slot2()
{
    ui->lineEdit_2->setText(QString("2"));
    qDebug() << "slot2()";
}

void MainWindow::updateWindow(){
    qDebug() << "updateWindow()";
    ui->moveLabel->setText(game.getMove());
    // Подстраиваем размер, т.к. эта метка не в Layout
    ui->moveLabel->adjustSize();
}

void MainWindow::newGame(){ // Новая игра
}

void MainWindow::saveGame(){ // Сохранить игру в файл
    QString filename = QFileDialog::getSaveFileName(this, "Сохранить игру", "", "*.game");
    game.save(filename);
}

void MainWindow::loadGame(){ // Загрузить игру из файла
    QString filename = QFileDialog::getSaveFileName(this, "Загрузить игру", "", "*.game");
    game.load(filename);
}

