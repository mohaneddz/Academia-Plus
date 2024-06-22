#include "view_courses_frame.h"
#include "ui_view_courses_frame.h"
#include "view_courses.h"
#include "ui_view_courses.h"
#include <QLabel>
#include <QScrollArea>

view_courses_frame::view_courses_frame(QWidget *parent, Members *ts, int index)
    : QWidget(parent), ui(new Ui::view_courses_frame)
{
    ui->setupUi(this);

    t = dynamic_cast<Teachers *>(ts);
    s = dynamic_cast<Students *>(ts);
    // rename the Course to the Course name & the Role to the integer value of the role

    if (t)
    {
        ui->Course->setText(ENSIA.getCourses()[index]->getName().c_str());
        // if type = 1 then the role is a Course
        // if type = 2 then the role is a Tutorial
        // if type = 3 then the role is a Lab

        if (t->getType()[index] == 1)
        {
            ui->Role->setText("Course");
        }
        else if (t->getType()[index] == 2)
        {
            ui->Role->setText("Lab");
        }
        else if (t->getType()[index] == 3)
        {
            ui->Role->setText("Tutorial");
        }
    }

    if (s)
    {
        // course number and then course name

        ui->Course->setText("Course " + QString::number(index + 1));
        ui->Role->setText(ENSIA.getCourses()[index]->getName().c_str());

    }


}

view_courses_frame::~view_courses_frame()
{
    delete ui;
}
