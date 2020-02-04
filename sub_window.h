#ifndef SUB_WINDOW_H
#define SUB_WINDOW_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMovie>
#include <QLabel>
#include <QString>
#include <QByteArray>
#include <cmath>

class sub_window : public QWidget
{
    Q_OBJECT
    QPushButton * but_play;
    QPushButton * but_reset;
    QLabel * lab;
    QMovie * mov;
    int type;
public:
    sub_window(int t,QWidget * parent = 0);
    ~sub_window(){}
public slots:
    void slot_play();
    void slot_pause();
private slots:
    void slot_reset();
};

#endif // SUB_WINDOW_H
