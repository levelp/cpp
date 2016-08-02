#ifndef ENCRYPTTHREAD_H
#define ENCRYPTTHREAD_H

#include <QThread>
#include <QProgressBar>

class EncryptThread : public QThread {
  Q_OBJECT
 public:
  QString srcFileName;
  QString dstFileName;
  QString password;
  QProgressBar* progressBar;

  explicit EncryptThread(QObject* parent = 0);
  //    ~EncryptThread(){
  //
  //    }

 signals:
  // Сигнал при обновлении процентов
  percentsUpdated(int value);

 protected:
  void run();
};

#endif // ENCRYPTTHREAD_H
