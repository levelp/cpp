#ifndef MOCKURLWORKER_H
#define MOCKURLWORKER_H

#include <QString>
#include "urlworker.h"

// Объявление объекта-заглушки
class MockUrlWorker : public UrlWorker {
 public:
  QString expected;
  void DoURL(QString URL);
};

#endif // MOCKURLWORKER_H
