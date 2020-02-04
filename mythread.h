#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <sub_window.h>

class MyThread : public QThread
{
    Q_OBJECT
    sub_window * w;
    int id;
public:
    MyThread(int id,QObject * parent=0);
public slots:
    void slot_start();
    void slot_pause();
    void slot_play();
    void slot_kill();
};

#endif // MYTHREAD_H
