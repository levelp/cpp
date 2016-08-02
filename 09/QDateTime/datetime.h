#ifndef DATETIME_H
#define DATETIME_H

#include <QObject>
#include <QDateTime>

class TDateTime : QDateTime {

  friend class TWindow;

 public:

  TDateTime();
  TDateTime(uint);
  TDateTime(QDate);
  TDateTime(QTime);
  TDateTime(QString);

  TDateTime operator+ (uint);
  TDateTime operator+= (uint);

};

#endif // DATETIME_H
