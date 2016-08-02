#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QFile>
#include <vector>

const char X = 'X'; //'1';
const char O = 'O'; //'Y';

// Состояние игры
enum State {
  X_MOVE, // Ход крестиков
  O_MOVE, // Ход ноликов
  X_WIN,  // Крестики выйграли
  O_WIN,  // Нолики выйграли
  DRAW    // Ничья
};

// Все что происодит на поле и логика игрового мира
// Ходы, выйгрыш/проигрыш
class Game {
  State state; // Текущее состояние игры
  // Игровое поле
  std::vector<std::vector<char> > Map;
  // Проверка выйгрыша
  // проверяется одна строка
  // один столбец или одна диагональ
  void checkLine(std::vector<char> a);
 public:
  // Конструктор
  Game();
  // Новая игра без пересоздания объекта
  void newGame();
  // Получаем строку, соответствующую состоянию игры
  QString getStateString();
  // Совершаем ход, возвращает строку для клетки на форме
  QString makeMove(int row, int col);
  // Проверяем на окончание игры
  void checkGameOver();
  // Сохранение игры
  void save(QString fileName);
  // Загрузка игры
  void load(QString fileName);
  // Состояние ячейки
  const char* getCell(int i, int j);
  void resizeMap();
  void mapResize();
};

#endif // GAME_H
