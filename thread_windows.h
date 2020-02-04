#ifndef THREAD_WINDOWS_H
#define THREAD_WINDOWS_H

#include <QObject>
#include <vector>
#include "mythread.h"

class thread_windows : public QObject
{
    Q_OBJECT
    std::vector<MyThread *> vec;
    int cnt;
public:
    thread_windows(QObject * parent=0);
    ~thread_windows(){}
public slots:
    void slot_start();
    void slot_pause();
    void slot_play();
    void slot_kill();
signals:
    void signal_pause();
    void signal_play();
    void signal_kill();
};

#endif // THREAD_WINDOWS_H
