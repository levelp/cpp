#include "mockurlworker.h"

#include <QDebug>

void MockUrlWorker::DoURL(QString URL) {
  qDebug() << URL;
}
