#ifndef TEST_SMART_H
#define TEST_SMART_H

#include <QObject>

class Test_Smart : public QObject
{
    Q_OBJECT
public:
    explicit Test_Smart(QObject *parent = 0);

private slots: // должны быть приватными
    void max(); // int max(int, int)
    
};

#endif // TEST_SMART_H