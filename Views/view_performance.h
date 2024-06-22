#ifndef VIEW_PERFORMANCE_H
#define VIEW_PERFORMANCE_H

#include <QDialog>
#include "Classes.h"
#include "performance_event.h"

namespace Ui {
class view_performance;
}

class view_performance : public QDialog
{
    Q_OBJECT

public:
    explicit view_performance(QWidget *parent = nullptr, Members *m = nullptr);
    ~view_performance();
    Members *t;
    vector<performance_event *> eventslist;

private slots:
    void on_new_event_clicked();
    void on_pushButton_clicked();
    // vector of all the performance_event objects

private:
    Ui::view_performance *ui;
};

#endif // VIEW_PERFORMANCE_H
