#include "view_teachers.h"
#include "ui_view_teachers.h"
#include "Classes.h"

view_teachers::view_teachers(int id, QWidget *parent)
    : QDialog(parent), courseid(id), ui(new Ui::view_teachers)
{
    ui->setupUi(this);

    // // Find the teachers
    bool found1 = false, found2 = false, found3 = false;
    for (Teachers *teacher : ENSIA.getTeachers())
    {
        found1 = false, found2 = false, found3 = false;
        for (Courses *course : teacher->getCourses())
        {
            if (course->getId() == id)
            {
                // get his type : TD, TP, COURS
                for (int i = 0; i < 12; i++)
                {
                    if (teacher->getType()[i] == 1 && !found1)
                    {
                        // add the teacher's name to the list to the existing names
                        ui->L_Course->setText(ui->L_Course->text() + QString::fromStdString(teacher->getName()) + " ");
                        found1 = true;
                    }
                    if (teacher->getType()[i] == 2 && !found2)
                    {
                        // add the teacher's name to the list to the existing names
                        ui->L_Tutorial->setText(ui->L_Course->text() + QString::fromStdString(teacher->getName()) + " ");
                        found2 = true;
                    }
                    if (teacher->getType()[i] == 3 && !found3)
                    {
                        // add the teacher's name to the list to the existing names
                        ui->L_Lab->setText(ui->L_Course->text() + QString::fromStdString(teacher->getName()) + " ");
                        found3 = true;
                    }
                }
            }
        }
    }
}

// set the teachers

view_teachers::~view_teachers()
{
    delete ui;
}
