#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QFile>

// Состояние игры и логика игрового мира
enum State {
    X_MOVE, // Ход крестиков
    O_MOVE, // Ход ноликов
    X_WIN,  // Крестики выйграли
    O_WIN,  // Нолики выйграли
    DRAW    // Ничья
};

// Все что происодит на поле
// Ходы, выйгрыш/проигрыш
class Game
{
    State move; // Чей сейчас ход
    char Map[3][3]; // Игровое поле
public:
    Game();
    QString getMove();
    // Совершаем ход, возвращает строку для клетки на форме
    QString makeMove(int row, int col);
    // Проверяем на окончание игры
    void checkGameOver();
    // Проверка выйгрыша
    void line(char a, char b, char c);
    // Сохранение игры
    void save(QString fileName);
    // Загрузка игры
    void load(QString fileName);
};

#endif // GAME_H
