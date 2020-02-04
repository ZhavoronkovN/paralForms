#include "main_widget.h"

main_widget::main_widget(QWidget * parent):QWidget(parent)
{
    this->setMinimumSize(QSize(500,100));
    but_start_new = new QPushButton(this);
    but_pause = new QPushButton(this);
    but_kill = new QPushButton(this);
    but_start_new->setText("Start new");
    but_pause->setText("Pause all");
    but_kill->setText("Kill all");
    but_start_new->setMinimumSize(QSize(100,50));
    but_kill->setMinimumSize(QSize(100,50));
    but_pause->setMinimumSize(QSize(100,50));
    QObject::connect(but_start_new,SIGNAL(clicked()),this,SLOT(slot_but_start_clicked()));
    QObject::connect(but_pause,SIGNAL(clicked()),this,SLOT(slot_but_pause_clicked()));
    QObject::connect(but_kill,SIGNAL(clicked()),this,SLOT(slot_but_kill_clicked()));
    QHBoxLayout * lay = new QHBoxLayout();
    lay->setSpacing(20);
    lay->addWidget(but_start_new);
    lay->addWidget(but_pause);
    lay->addWidget(but_kill);
    this->setLayout(lay);
}
void main_widget::slot_but_start_clicked(){
    emit signal_start_new();
}
void main_widget::slot_but_pause_clicked(){
    if(but_pause->text()=="Pause all"){
        but_pause->setText("Play all");
        emit signal_pause();
    }
    else {
        but_pause->setText("Pause all");
        emit signal_play();
    }
}
void main_widget::slot_but_kill_clicked(){
    emit signal_kill();
}
