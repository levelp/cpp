#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Отслеживаем движение мыши
  setMouseTracking(true);

  ui->centralWidget->setMouseTracking(true);
  ui->noButton->setMouseTracking(true);

  mousePosition = new QLabel("Координаты мыши");
  mousePosition->setAlignment(Qt::AlignHCenter);
  mousePosition->setMinimumSize(mousePosition->sizeHint());

  statusBar()->addWidget(mousePosition);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_yesButton_clicked() {
  // QMessageBox::information(this, "Ну, конечно же...",
  //        "А мы и не сомневались!");
  // return;

  // Остальные типы диалогов
  // Параметры: parent, title, message
  QMessageBox::warning(this, "Заголовок окна",
                       "Предупреждение!");

  QMessageBox::critical(this, "Заголовок окна",
                        "Сообщение об ошибке!");

  QMessageBox::about(this, "Заголовок окна",
                     "about :)");

  // Создаём объект
  QMessageBox msgBox;
  msgBox.setText("Заголовок окна");
  msgBox.setInformativeText("Do you want to save your changes?");
  msgBox.setStandardButtons(QMessageBox::Save |
                            QMessageBox::Discard | QMessageBox::Cancel);
  msgBox.setDefaultButton(QMessageBox::Save);
  int ret = msgBox.exec();

  switch (ret) {
    case QMessageBox::Save:
      QMessageBox::information(this, "Информация",
                               "Пользователь выбрал сохранить изменения");
      break;

    case QMessageBox::Discard:
      QMessageBox::information(this, "Информация",
                               "Пользователь выбрал не сохранять изменения");
      break;

    default:
      break;
  };
}

// Обработчик движения мыши
void MainWindow::mouseMoveEvent(QMouseEvent* event) {
  QString temp("Мышь: %1 %2");
  int x = event->pos().x(), y = event->pos().y();
  mousePosition->setText(temp.arg(x).arg(y));

  QRect rect = ui->noButton->geometry();

  while(rect.contains(x, y)) {
    //qDebug() << x << y << "in" << rect.x() << rect.y();
    int step = 100;
    rect.translate(rand() % step - step / 2, rand() % step - step / 2);

    if(rect.top() < 0)
      rect.translate(0, 100);

    if(rect.bottom() > geometry().bottom())
      rect.translate(0, -100);

    if(rect.left() < 0)
      rect.translate(rect.width() * 2, 0);

    if(rect.right() > geometry().right())
      rect.translate(-rect.width() * 2, 0);
  }

  ui->noButton->setGeometry(rect);
}
