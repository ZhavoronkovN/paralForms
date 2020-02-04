#include "thread_windows.h"

thread_windows::thread_windows(QObject * parent):QObject(parent)
{
    cnt = 0;
    vec.reserve(16);
}
void thread_windows::slot_start(){
    MyThread * thr = new MyThread(cnt++,this);
    vec.push_back(thr);
    QObject::connect(this,SIGNAL(signal_pause()),thr,SLOT(slot_pause()));
    QObject::connect(this,SIGNAL(signal_play()),thr,SLOT(slot_play()));
    QObject::connect(this,SIGNAL(signal_kill()),thr,SLOT(slot_kill()));
    thr->start();
}
void thread_windows::slot_pause(){
    emit signal_pause();
}
void thread_windows::slot_play(){
    emit signal_play();
}
void thread_windows::slot_kill(){
    vec.clear();
    emit signal_kill();
}
