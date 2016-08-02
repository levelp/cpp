/// Работа с сетью
/// ==============
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  socket = NULL;

  on_enterChatButton_clicked();

  // Таймер опроса "кто онлайн"
  ///-->
  QTimer* timer = new QTimer(this);
  // Соединяем сигнал со слотом
  connect(timer,
          SIGNAL(timeout()),
          this,
          SLOT(refreshOnlineList()));
  timer->start(1000);
  ///<--
}

MainWindow::~MainWindow() {
  delete ui;
}

/// Создание UDP-чата
///-->
void MainWindow::UdpChat(QString nick, int port) {
  // Если соединение уже открыто, то закрываем его
  if(socket != NULL) {
    socket->close();
    delete socket;
    socket = NULL;
  }

  // Создание чата
  socket = new QUdpSocket(this);
  // QHostAddress("192.168.1.104") - конкретный IP, с которого можно подключиться

  // QHostAddress::Any - принимать
  //   сообщения со всех IP адресов
  if(socket->bind(QHostAddress::Any, port)) {
    // При получении данных (сигнал readyRead)
    // вызываем метод (слот) read, который
    connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
  } else {
    // Какая-то программа на этом компьютере уже
    // заняла порт port
    qDebug() << "Port " << port << " in use. Change port!";
    return;
  }

  send(nick + " - в чате", USUAL_MESSAGE);
}
///<--

/// Нажимаем на кнопку "Войти в чат"
///-->
void MainWindow::on_enterChatButton_clicked() {
  QString nick = ui->nicknameEdit->text();
  UdpChat(nick,
          ui->portNumEdit->text().toInt());
  // Разрешаем отправлять сообщения только когда уже в чате
  ui->sendButton->setEnabled(true);
}
///<--


/// Отправка сообщения в сеть
///-->
void MainWindow::send(QString str, qint8 type) {
  // Полный пакет данных будет в массиве data
  QByteArray data; // Массив данных для отправки

  // Последовательно выводим в него байты
  QDataStream out(&data, QIODevice::WriteOnly);
  out << qint8(type); // Тип сообщения
  out << str; // Само сообщение

  // Отправляем полученный массив данных всем в локальный сети
  // на порт указанный в интерфейсе
  socket->writeDatagram(data,
                        QHostAddress::Broadcast,
                        ui->portNumEdit->text().toInt() );
}
///<--

/// Получение сообщения по UDP
///-->
void MainWindow::saveToLogFile(QString str) {
  QFile file("log.txt");
  file.open(QIODevice::WriteOnly | QIODevice::Text
            | QIODevice::Append );
  QTextStream log(&file);
  log.setCodec("UTF-8");
  log << str << endl;
  file.close();
}

void MainWindow::read() {
  // Массив для полученных данных
  QByteArray data;
  // Устанавливаем массиву размер
  // соответствующий размеру полученного пакета данных
  data.resize(socket->pendingDatagramSize());
  QHostAddress* address = new QHostAddress();
  socket->readDatagram(data.data(), data.size(), address);
  qDebug() << "Message from IP: " <<
           address->toString() << " size: "
           << data.size();

  // Разбор полученного пакета
  QDataStream in(&data, QIODevice::ReadOnly);

  // Получаем тип пакета
  qint8 type = 0;
  in >> type;

  if (type == USUAL_MESSAGE) {
    QString str;
    in >> str;

    if(str.length() == 0)
      return;

    // Записываем входящие сообщения в файл
    saveToLogFile(str);

    // Отображаем строчку в интерфейсе
    ui->plainTextEdit->appendPlainText(str);
  } else if (type == PERSON_ONLINE) {
    // Добавление пользователя с считанным QHostAddress
    QString str;
    in >> str;
    QStringList list = str.split(" ");
    QString timeStr = list.at(0);
    // Время выделили, дальше вырезаем
    // из строки ник.
    // Ищем в списке, если есть => обновляем
    // Если нет, добавляем.
    QString nick = str.right(timeStr.length());

    ui->onlineList->addItem(str);
  } else if (type == WHO_IS_ONLINE) {
    QTime now = QTime::currentTime();
    QString nowStr = now.toString("hh:mm:ss");
    send(nowStr + " " +
         ui->nicknameEdit->text(),
         qint8(PERSON_ONLINE));
  }
}
///<--

/// Нажимаем на кнопку "Отправить сообщение"
///-->
void MainWindow::on_sendButton_clicked() {
  // Вся строка сообщения: "ник: сообщение"
  send(ui->nicknameEdit->text() + ": " +
       ui->messageEdit->text(),
       USUAL_MESSAGE);

  ui->messageEdit->clear();
}
///<--

void MainWindow::on_messageEdit_returnPressed() {
  on_sendButton_clicked();
}

/// Обновляем список тех кто online
///-->
void MainWindow::refreshOnlineList() {
  // TODO: хранить время, когда последний раз этот человек был в сети

  // Удаляем тех, от кого давно не было сообщений
  for(int i = 0; i < ui->onlineList->count(); ++i) {
    // Получаем i-ую запись из списка
    QListWidgetItem* item = ui->onlineList->item(i);
    //
    QString str = item->text();
    QStringList list = str.split(" ");
    QString dateStr = list.at(0);
    QTime time = QTime::fromString(dateStr, "hh:mm:ss");
    QTime now = QTime::currentTime();
    int diff = time.msecsTo(now);

    qDebug() << time << now << diff;

    // Удаляем запись из списка
    if(diff > 2000)
      ui->onlineList->takeItem(i);
  }

  send("", WHO_IS_ONLINE);
}
///<--
