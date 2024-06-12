#ifndef VIEW_COURSES_FRAME_H
#define VIEW_COURSES_FRAME_H

#include <QWidget>
#include "Classes.h"

namespace Ui {
class view_courses_frame;
}

class view_courses_frame : public QWidget
{
    Q_OBJECT

public:
    explicit view_courses_frame(QWidget *parent = nullptr, Members *ts = nullptr, int index = 0);
    ~view_courses_frame();
    Teachers *t;

private:
    Ui::view_courses_frame *ui;
};

#endif // VIEW_COURSES_FRAME_H
