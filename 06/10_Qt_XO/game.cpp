#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <cassert>
#include "game.h"
#include "map_size.h"
#include "map_size.h"

Game::Game() {
  // При старте программы сразу начинается новая игра
  newGame();
}

// Новая игра
void Game::mapResize() {
  Map.resize(MapSize);

  for(int i = 0; i < MapSize; ++i)
    Map[i].resize(MapSize);
}

void Game::newGame() {
  mapResize();

  // Первыми ходят всегда крестики
  state = O_MOVE;

  // Заполняем поле пустыми клетками, без крестиков и ноликов
  for(int i = 0; i < MapSize; i++)
    for(int j = 0; j < MapSize; j++)
      Map[i][j] = ' ';
}

QString Game::getStateString() {
  switch(state) {
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

    default:
      return QString("Ошибка в программе!");
      assert(false);
  }

  return QString("Непредусмотренное состояние игры!");
}

// Совершаем ход
QString Game::makeMove(int row, int col) {
  //
  //QMessageBox::information(NULL, "Ход",
  //   QString("Ход в клетку: (%1; %2)")
  //                  .arg(row+1).arg(col+1));
  if(Map[row][col] != ' ') {
    QMessageBox::critical(NULL, "Ошибка",
                          "Нельзя ходить в занятую клетку");
    return QString("!");
  }

  switch (state) {
    case X_MOVE:
      Map[row][col] = X;
      state = O_MOVE;
      break;

    case O_MOVE:
      Map[row][col] = O;
      state = X_MOVE;
      break;

    default:
      return QString(" ");
  }

  checkGameOver();
  return QString(Map[row][col]);
}

// Три крестика или три нолика
void Game::checkLine(std::vector<char> a) {
  // Если не все элементы равны => не подходит
  for(int i = 1; i < MapSize; ++i)
    if(a[i - 1] != a[i])
      return;

  // Кто-то выйграл :)
  switch(a[0]) {
    case X:
      state = X_WIN;
      break;

    case O:
      state = O_WIN;
      break;

    default:
      break; // Если не крестики и не нолики, то не подходит
  }
}

void Game::checkGameOver() {
  std::vector<char> a(MapSize);

  // == Проверяем диагонали ==
  // Основная диагональ
  for(int i = 0; i < MapSize; ++i)
    a[i] = Map[i][i];

  checkLine(a);

  // Дополнительная диагональ
  //   (0,0) (0,1) [0,2]
  //   (1,0) [1,1] (1,2)
  //   [2,0] (2,1) (2,2)
  for(int i = 0; i < MapSize; ++i)
    a[i] = Map[MapSize - i - 1][i];

  checkLine(a);

  // Вертикальные и горизонтальные линии
  for(int i = 0; i < MapSize; ++i) {
    // Вертикальная линия
    // копируем в a i-ый столбец
    for(int j = 0; j < MapSize; ++j)
      a[j] = Map[j][i];

    checkLine(a);

    // Горизонтальная линия
    checkLine(Map[i]);
  }

  // Проверяем что крестики или нолики
  // выйграли и выходим
  switch(state) {
    case X_WIN:
    case O_WIN:
      return;

    default:
      ; // Do nothing
  }

  // Ничья = не осталось пустых клеток
  int cnt = 0; // Количество пустых клеток

  for(int i = 0; i < MapSize; i++)
    for(int j = 0; j < MapSize; j++)
      if(Map[i][j] == ' ')
        cnt++;

  qDebug() << "cnt = " << cnt;

  if(cnt == 0)
    state = DRAW;
}

// Сохранение игры
void Game::save(QString fileName) {
  QFile f(fileName); // QFile позволяет работать с файлами
  f.open(QIODevice::WriteOnly | QIODevice::Text);
  // Сохраняем данные
  QTextStream out(&f);
  out << MapSize << endl;

  for(int i = 0; i < MapSize; i++) {
    for(int j = 0; j < MapSize; j++)
      out << Map[i][j];

    out << endl;
  }

  f.close();
}

// Загрузка (чтение) сохранённой игры из файла
void Game::load(QString fileName) { // Загрузка игры
  QFile f(fileName); // Создаем объект - файл
  f.open(QIODevice::ReadOnly | QIODevice::Text); // Открываем его для чтения
  // Читаем данные
  QTextStream in(&f);
  // Считываем размер карты
  in >> MapSize;
  in.readLine();
  mapResize(); // Изменяем размер карты в памяти

  int x_cnt = 0, o_cnt = 0; // Количество крестиков и ноликов

  for(int i = 0; i < MapSize; i++) {
    for(int j = 0; j < MapSize; j++) {
      in >> Map[i][j]; // Очередной символ

      switch(Map[i][j]) {
        case X:
          x_cnt++;
          break;

        case O:
          o_cnt++;
          break;

        case ' ': // Пробелы просто пропускаем
          break;

        default:
          throw QString("Ошибка при чтении файла %1\n: строка %2 столбец %3 символ '%4' вместо X или O")
          .arg(fileName).arg(i).arg(j).arg(Map[i][j]);
      }
    }

    in.readLine(); // Строчка должна была закончиться
  }

  f.close();

  // Проверяем количество крестиков и ноликов
  if((x_cnt >= 2) && (o_cnt == 0))
    throw QString("Все крестики!");

  if((o_cnt >= 2) && (x_cnt == 0))
    throw QString("Все нолики!");

  if(x_cnt > (o_cnt + 1))
    throw QString("Слишком много крестиков в файле :)");

  if(o_cnt > (x_cnt + 1))
    throw QString("Слишком много ноликов в файле :)");

  if(x_cnt > o_cnt)
    state = O_MOVE;
  else
    state = X_MOVE;

  checkGameOver();
}

const char* Game::getCell(int i, int j) {
  static char buf[2];
  sprintf(buf, "%c", Map[i][j]);
  return buf;
}

