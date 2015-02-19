#ifndef URLWORKER_H
#define URLWORKER_H

#include <QString>

// Интерфейс, который может обрабатывать URL
class UrlWorker {
 public:
  virtual void DoURL(QString URL) = 0;
};

#endif // URLWORKER_H
