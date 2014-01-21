#include "game.h"
#include <QTextStream>

Game::Game()
{
    move = X_MOVE;
    // Заполняем поле пустыми клетками, без крестиков и ноликов
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            Map[i][j] = ' ';
}

QString Game::getMove(){
    switch(move){
    case X_MOVE:
        return QString("Ход крестиков");
    case O_MOVE:
        return QString("Ход ноликов");
    case X_WIN:
        return QString("Крестики выйграли!");
    case O_WIN:
        return QString("Нолики выйграли!");
    case DRAW:
        return QString("Ничья! :)");
    }
    return QString("Что-то совсем не так :)");
}

// Совершаем ход
QString Game::makeMove(int row, int col){
    if(Map[row][col] != ' '){
        return QString("!");
    }

    switch (move) {
    case X_MOVE:
        Map[row][col] = 'X';
        move = O_MOVE;
        break;
    case O_MOVE:
        Map[row][col] = 'O';
        move = X_MOVE;
        break;
    default:
        return QString(" ");
    }
    checkGameOver();
    return QString(Map[row][col]);
}

// Три крестика или три нолика
void Game::line(char a, char b, char c){
    // Если не три равных => не подходит
    if (!((a == b) && (b == c))) return;
    // Если не крестики и не нолики, то не подходит
    if (a != 'X' && a != 'O') return;
    // Кто-то выйграл :)
    switch(a){
    case 'X':
        move = X_WIN;
        break;
    case 'O':
        move = O_WIN;
        break;
    }
}

void Game::checkGameOver(){
    // Проверяем диагонали
    line(Map[0][0], Map[1][1], Map[2][2]);
    line(Map[2][0], Map[1][1], Map[0][2]);
    // Вертикальные и горизонтальные линии
    for(int i = 0; i < 3; i++){
        line(Map[0][i], Map[1][i], Map[2][i]);
        line(Map[i][0], Map[i][1], Map[i][2]);
    }
    // Ничья = все клетки заполнены и никто не выйграл
    int cnt = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(Map[i][j] == 'X' || Map[i][j] == 'O')
                cnt++;
    if(cnt == 0)
        move = DRAW;
}

void Game::save(QString fileName){ // Сохранение игры
    QFile f(fileName);
    f.open(QIODevice::WriteOnly);
    // Сохраняем данные
    QTextStream out(&f);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            out << Map[i][j];
        out << endl;
    }
    f.close();
}

void Game::load(QString fileName){ // Загрузка игры
    QFile f(fileName);
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    // Сохраняем данные
    QTextStream in(&f);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            in >> Map[i][j];
        in.readLine();
    }
    f.close();
}

