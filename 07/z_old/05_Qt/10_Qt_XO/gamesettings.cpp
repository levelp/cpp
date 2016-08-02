#include "gamesettings.h"
#include "ui_gamesettings.h"
#include "game.h"
#include "map_size.h"

GameSettings::GameSettings(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::GameSettings) {
  ui->setupUi(this);

  // Записываем текущий размер поля
  ui->spinBox->setValue(MapSize);
}

GameSettings::~GameSettings() {
  delete ui;
}

void GameSettings::on_buttonBox_accepted() {
  // Берём новое значение размера поля
  // из интерфейса и записываем как MapSize
  MapSize = ui->spinBox->value();
}
