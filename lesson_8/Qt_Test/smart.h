#ifndef SMART_H
#define SMART_H

#include <QObject>
#include <QStringList>

class Smart : public QObject
{
    Q_OBJECT
public:
    explicit Smart(QObject *parent, const QStringList& list);
    
public slots:
    int max(int a, int b);
    int min(int a, int b);

};
#endif
