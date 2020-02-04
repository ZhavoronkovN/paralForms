#include "mythread.h"

MyThread::MyThread(int id,QObject * parent):QThread(parent),id(id)
{
    w = new sub_window(id%4);
    QObject::connect(this,SIGNAL(started()),this,SLOT(slot_start()));
    QObject::connect(this,SIGNAL(finished()),w,SLOT(deleteLater()));
    QObject::connect(w,SIGNAL(destroyed()),this,SLOT(quit()));
}
void MyThread::slot_start(){
    w->show();
}
void MyThread::slot_pause(){
    w->slot_pause();
}
void MyThread::slot_play(){
    w->slot_play();
}
void MyThread::slot_kill(){
    this->exit(0);
}
