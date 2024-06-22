#ifndef TEACHER_LIST_FRAME_H
#define TEACHER_LIST_FRAME_H

#include "Classes.h"
#include <QWidget>

namespace Ui
{
    class teacher_list_frame;
}

class teacher_list_frame : public QWidget
{
    Q_OBJECT

public:
    explicit teacher_list_frame(QWidget *parent = nullptr, int index = 0);
    ~teacher_list_frame();
    bool check();
    int index;
    Teachers *t;

    Ui::teacher_list_frame *ui;

private:
};

#endif // TEACHER_LIST_FRAME_H
