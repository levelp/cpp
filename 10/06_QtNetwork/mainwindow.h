#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
//#include <QTcpServer>


/// Тип сообщения
///-->
enum MessageType {
  USUAL_MESSAGE, // Обычный текст
  PERSON_ONLINE, // Сообщение "Я-онлайн"
  WHO_IS_ONLINE, // Запрос о статусе пользователей
};
///<--

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

  void saveToLogFile(QString str);
 private slots:
  void on_enterChatButton_clicked();
  void on_sendButton_clicked();

  void on_messageEdit_returnPressed();
  void refreshOnlineList();

 private:
  Ui::MainWindow* ui;

  /// == ЧАТ ==
  ///-->
  // Для работы по UDP-протоколу в
  // локальной сети
  QUdpSocket* socket;

  // Открываем соединение
  // и отправляем первое сообщение
  void UdpChat(QString nick, int port);

  // Отправить сообщение
  void send(QString str, qint8 type);

 private slots:
  // Получаем сообщения
  void read();
  ///<--

};

#endif // MAINWINDOW_H
