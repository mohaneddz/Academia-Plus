#ifndef PERFORMANCE_EVENT_H
#define PERFORMANCE_EVENT_H

#include <QWidget>
#include "Classes.h"


namespace Ui {
class performance_event;
}

class performance_event : public QWidget
{
    Q_OBJECT

public:
    explicit performance_event(QWidget *parent = nullptr, Members *m = nullptr, int index = 0);
    ~performance_event();
    void setEvent(Teachers *t);
    int num;
    Members *t;

    Ui::performance_event *ui;
private:
};

#endif // PERFORMANCE_EVENT_H
