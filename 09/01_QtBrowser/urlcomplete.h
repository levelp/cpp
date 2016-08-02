#ifndef URLCOMPLETE_H
#define URLCOMPLETE_H

#include <QString>
#include "urlworker.h"

class UrlComplete {
  UrlWorker* uw;
 public:
  UrlComplete(UrlWorker* uw);
  void complete(QString URL);
};

#endif // URLCOMPLETE_H
