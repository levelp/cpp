#ifndef CELLBUTTON_H
#define CELLBUTTON_H

#include <QPushButton>
#include <QDebug>
#include "game.h"

// Одна клетка поля, наследник стандартной Qt-кнопки
class CellButton : public QPushButton {
  Q_OBJECT

  int row; // Строка для этой клетки на поле
  int col; // Столбец для этой клетки на поле

  Game* game; // Для передачи информации в "игру"

 public:
  // Параметры:
  //  text - текст на кнопке
  //  parent - окно, в котором кнопка будет расположена
  //    для корретного удаления кнопки
  //  row - строка, col - столбец на поле
  //  game - ссылка на игру
  explicit CellButton(const char*,
                      QWidget* parent,
                      int row, int col, // Строка и столбец
                      Game& game);

 signals:

 public slots:
  // Нажатие на кнопку
  void slotCellClicked();
};

#endif // CELLBUTTON_H
