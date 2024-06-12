#ifndef VIEW_SCHEDULE_H
#define VIEW_SCHEDULE_H

#include <QDialog>
#include "Classes.h"

namespace Ui {
class view_schedule;
}

class view_schedule : public QDialog
{
    Q_OBJECT

public:
    explicit view_schedule(QWidget *parent = nullptr, Members *e = nullptr);
    ~view_schedule();

private:
    Ui::view_schedule *ui;
};

#endif // VIEW_SCHEDULE_H
