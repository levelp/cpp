<!-- doc.py -->
MyThread thread;
QObject::connect(&thread, SIGNAL(currentValue(int)), ui->lcdNumber_2, SLOT(display(int)));
QObject::connect(&thread, SIGNAL(finished()), this, SLOT(close()));
thread.run();
[minner.cpp](minner.cpp)

