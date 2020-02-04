#include "mainwindow.h"

#include <QApplication>
#include "main_widget.h"
#include "thread_windows.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    main_widget * w = new main_widget();
    thread_windows * thrpool = new thread_windows(w);
    QObject::connect(w,SIGNAL(signal_start_new()),thrpool,SLOT(slot_start()));
    QObject::connect(w,SIGNAL(signal_pause()),thrpool,SLOT(slot_pause()));
    QObject::connect(w,SIGNAL(signal_play()),thrpool,SLOT(slot_play()));
    QObject::connect(w,SIGNAL(signal_kill()),thrpool,SLOT(slot_kill()));
    w->show();
    return a.exec();
}
