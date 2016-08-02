#include <QCoreApplication>
#include <QThread>
#include "timerperformer.h"
#include "threadedperformer.h"
#include "ourthread.h"
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <QList>
#include <QDebug>

#include <QString>

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  QDir dir;

  QList<QFileInfo> infos = dir.entryInfoList();

  // foreach C++ 11
  for (QFileInfo info : infos) {
    qDebug() << info.absoluteFilePath();
    QFile file(info.absoluteFilePath());

    if (file.open(QIODevice::ReadOnly))
      qDebug() << file.read(5);
    else
      qDebug() << "File can't be opened";
  }

  TimerPerformer timerPerformer;

  //    timerPerformer.printString(54, QStringLiteral("some Name"), 10.465, QStringLiteral("Title"));
  return 0;//a.exec();
}
