#include "smart.h"

Smart::Smart(QObject *parent, const QStringList& list) :
    QObject(parent)
{
}

int Smart::max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int Smart::min(int a, int b)
{
    if(a < b)
        return a;
    return b;
}