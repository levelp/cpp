#include "ourthread.h"
#include <QDebug>

OurThread::OurThread(QObject* parent) :
  QThread(parent) {
}

void OurThread::someSlot() {
  qDebug() << Q_FUNC_INFO << QThread::currentThread();
}

//void OurThread::run()
//{
//    forever {
//        qDebug() << Q_FUNC_INFO << QThread::currentThread();
//        QThread::msleep(700);
//    }
//}
