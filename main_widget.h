#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class main_widget: public QWidget
{
    Q_OBJECT
    QPushButton * but_start_new;
    QPushButton * but_pause;
    QPushButton * but_kill;
public:
    main_widget(QWidget* parent=0);
    virtual ~main_widget(){}
signals:
    void signal_start_new();
    void signal_pause();
    void signal_play();
    void signal_kill();
private slots:
    void slot_but_start_clicked();
    void slot_but_pause_clicked();
    void slot_but_kill_clicked();
};


#endif // MAIN_WIDGET_H
