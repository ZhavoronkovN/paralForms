#include "sub_window.h"
#include <QDebug>

sub_window::sub_window(int t,QWidget * parent):QWidget(parent),type(t)
{
    this->setMinimumSize(QSize(400,300));
    but_play = new QPushButton(this);
    but_reset = new QPushButton(this);
    but_play->setText("Pause");
    but_reset->setText("Reset");
    but_play->setMinimumSize(QSize(100,50));
    but_reset->setMinimumSize(QSize(100,50));
    QObject::connect(but_play,SIGNAL(clicked()),this,SLOT(slot_play()));
    QObject::connect(but_reset,SIGNAL(clicked()),this,SLOT(slot_reset()));
    lab = new QLabel(this);
    mov = new QMovie(QString(QString("D:\\")+QString::number(type)+QString(".gif")),QByteArray(),this);
    mov->setScaledSize(QSize(400,400));
    mov->start();
    lab->setMovie(mov);
    QHBoxLayout * hlay = new QHBoxLayout();
    hlay->setSpacing(20);
    hlay->addWidget(but_play);
    hlay->addWidget(but_reset);
    QVBoxLayout * vlay = new QVBoxLayout();
    vlay->setSpacing(20);
    vlay->addWidget(lab);
    vlay->addLayout(hlay);
    this->setLayout(vlay);
}
void sub_window::slot_play(){
    if(but_play->text()=="Play"){
            mov->start();
            but_play->setText("Pause");
    }
    else {
        mov->setPaused(true);
        but_play->setText("Play");
    }
}
void sub_window::slot_pause(){
    mov->setPaused(true);
    but_play->setText("Play");
}
void sub_window::slot_reset(){
    mov->stop();
    but_play->setText("Play");
    mov->start();
    mov->setPaused(true);
}
