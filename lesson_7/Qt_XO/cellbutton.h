#ifndef CELLBUTTON_H
#define CELLBUTTON_H

#include <QPushButton>
#include <QDebug>
#include "game.h"

// Одна клетка поля, наследник Кнопки
class CellButton : public QPushButton
{
    Q_OBJECT

    int row; // Строка для этой клетки
    int col; // Столбец для этой клетки
    Game *game; // Для передачи информации в "игру"
public:
    explicit CellButton(const char *,
                        QWidget *parent,
                        int row, int col, // Строка и столбец
                        Game &game);

signals:

public slots:
    void slotCellClicked();
};

#endif // CELLBUTTON_H
