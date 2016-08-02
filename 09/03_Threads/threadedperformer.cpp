#include "threadedperformer.h"
#include <QDebug>
#include <QThread>

ThreadedPerformer::ThreadedPerformer(QObject* parent) :
  QObject(parent) {
}

void ThreadedPerformer::someSlot(int someArg) {
  qDebug() << Q_FUNC_INFO << QThread::currentThread() << someArg;
}
