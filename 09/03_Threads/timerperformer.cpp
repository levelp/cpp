#include "timerperformer.h"
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QTimerEvent>
#include <QThread>
#include "threadedperformer.h"

TimerPerformer::TimerPerformer(QObject* parent) :
  QObject(parent) {

  //    QTimer *timer = new QTimer(this);
  //    connect(timer, &QTimer::timeout, this, &TimerPerformer::timerTimeout);
  //    connect(this, &TimerPerformer::firstSignal, this, &TimerPerformer::firstSlot, Qt::QueuedConnection);
  //    connect(this, &TimerPerformer::secondSignal, this, &TimerPerformer::secondSlot, Qt::DirectConnection);
  //    timer->setTimerType(Qt::CoarseTimer);
  //    timer->start(600);

  //    m_timerId = startTimer(600, Qt::PreciseTimer);
}

void TimerPerformer::printString(int id, const QString& name, float count, const QString& title) {
  QString strTemplate = QStringLiteral("ID: %1; name: %2; count: %3; title: %4");
  QString str = strTemplate.arg(id, 6, 16)
                .arg(name)
                .arg(count)
                .arg(title);
  QString str2 = strTemplate.arg(id)
                 .arg(title)
                 .arg(count)
                 .arg(name);
  qDebug() << Q_FUNC_INFO << "\n" << str << "\n" << str2;
}

void TimerPerformer::timerTimeout() {
  static long long lastTime = 0;
  QMetaObject::invokeMethod(m_threadedPerformer, "someSlot", Q_ARG(int, 42));
  //    m_threadedPerformer->someSlot();
  emit firstSignal();
  //    emit secondSignal();
  //    qDebug() << Q_FUNC_INFO << (lastTime ? QDateTime::currentMSecsSinceEpoch()-lastTime : 0 );
  lastTime = QDateTime::currentMSecsSinceEpoch();
}

void TimerPerformer::firstSlot() {
  //    qDebug() << Q_FUNC_INFO << QThread::currentThread();
}

void TimerPerformer::secondSlot() {
  //    qDebug() << Q_FUNC_INFO;
}

void TimerPerformer::timerEvent(QTimerEvent* ev) {
  //    if (ev->timerId() == m_timerId)
  //        qDebug() << Q_FUNC_INFO;
}
