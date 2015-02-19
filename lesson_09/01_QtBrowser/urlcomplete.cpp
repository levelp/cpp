#include "urlcomplete.h"

UrlComplete::UrlComplete(UrlWorker* uw) {
  this->uw = uw;
}

void UrlComplete::complete(QString URL) {
  if(URL.startsWith("http"))
    uw->DoURL(URL);
  else
    uw->DoURL(QString("http://") + URL);
}
