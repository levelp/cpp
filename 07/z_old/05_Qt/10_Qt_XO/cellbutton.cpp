#include "cellbutton.h"

// Параметры:
//  text - текст на кнопке
//  parent - окно, в котором кнопка будет расположена
//    для корретного удаления кнопки
//  row - строка, col - столбец на поле
//  game - ссылка на игру
CellButton::CellButton(const char* text,
                       QWidget* parent,
                       int row, int col,
                       Game& game) :
  QPushButton(text, parent),
  row(row), col(col), game(&game) {
  //this->game = &game;
  // Если на кнопке написан крестик или нолик,
  // то нажимать на неё нельзя
  if(text[0] == X || text[0] == O)
    setEnabled(false);
}

// При нажатии на клетку
void CellButton::slotCellClicked() {
  // Выводим координаты нажатия для отладки
  qDebug() << "row = " << row << "   col = " << col;
  // Делаем ход => получаем результат
  // для данной клетки
  setText( game->makeMove(row, col) );
  // Больше не можем нажимать на эту клетку поля
  // (эту кнопку)
  setEnabled(false);
}
