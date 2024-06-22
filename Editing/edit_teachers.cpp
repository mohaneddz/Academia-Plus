#include "edit_teachers.h"
#include "ui_edit_teachers.h"
#include "Classes.h"
#include <QScrollArea>
#include <QMessageBox>

edit_Teachers::edit_Teachers(QWidget *parent, int teacherid)
    : QDialog(parent), ui(new Ui::edit_Teachers), teacherid(teacherid)
{
    ui->setupUi(this);

    Teachers *teacher = ENSIA.getTeachers()[teacherid];

    // set the fields :
    ui->Line_name->setText(QString::fromStdString(teacher->getName()));
    ui->Line_email->setText(QString::fromStdString(teacher->getEmail()));
    ui->Line_password->setText(QString::fromStdString(teacher->getPassword()));
    ui->Line_phone->setText(QString::fromStdString(teacher->getPhone()));
    ui->Line_address->setText(QString::fromStdString(teacher->getAddress()));

    // set the groups
    ui->g1->setChecked(teacher->getGroups()[0]);
    ui->g2->setChecked(teacher->getGroups()[1]);
    ui->g3->setChecked(teacher->getGroups()[2]);
    ui->g4->setChecked(teacher->getGroups()[3]);
    ui->g5->setChecked(teacher->getGroups()[4]);
    ui->g6->setChecked(teacher->getGroups()[5]);
    ui->g7->setChecked(teacher->getGroups()[6]);
    ui->g8->setChecked(teacher->getGroups()[7]);
    ui->g9->setChecked(teacher->getGroups()[8]);
    ui->g10->setChecked(teacher->getGroups()[9]);
    ui->g11->setChecked(teacher->getGroups()[10]);
    ui->g12->setChecked(teacher->getGroups()[11]);

    ui->L_Year->setText(QString::number(teacher->getBirthDate().getYear()));
    ui->L_Month->setText(QString::number(teacher->getBirthDate().getMonth()));
    ui->L_Day->setText(QString::number(teacher->getBirthDate().getDay()));

    // set the type for every single group : course, tutorial, lab for course_1 ..etc

    if (teacher->getType()[0] == 1)
    {
        ui->course_1->setChecked(true);
    }
    else if (teacher->getType()[0] == 2)
    {
        ui->tuto_1->setChecked(true);
    }
    else if (teacher->getType()[0] == 3)
    {
        ui->lab_1->setChecked(true);
    }

    if (teacher->getType()[1] == 1)
    {
        ui->course_2->setChecked(true);
    }
    else if (teacher->getType()[1] == 2)
    {
        ui->tuto_2->setChecked(true);
    }
    else if (teacher->getType()[1] == 3)
    {
        ui->lab_2->setChecked(true);
    }

    if (teacher->getType()[2] == 1)
    {
        ui->course_3->setChecked(true);
    }
    else if (teacher->getType()[2] == 2)
    {
        ui->tuto_3->setChecked(true);
    }
    else if (teacher->getType()[2] == 3)
    {
        ui->lab_3->setChecked(true);
    }

    if (teacher->getType()[3] == 1)
    {
        ui->course_4->setChecked(true);
    }
    else if (teacher->getType()[3] == 2)
    {
        ui->tuto_4->setChecked(true);
    }
    else if (teacher->getType()[3] == 3)
    {
        ui->lab_4->setChecked(true);
    }

    if (teacher->getType()[4] == 1)
    {
        ui->course_5->setChecked(true);
    }
    else if (teacher->getType()[4] == 2)
    {
        ui->tuto_5->setChecked(true);
    }
    else if (teacher->getType()[4] == 3)
    {
        ui->lab_5->setChecked(true);
    }

    if (teacher->getType()[5] == 1)
    {
        ui->course_6->setChecked(true);
    }
    else if (teacher->getType()[5] == 2)
    {
        ui->tuto_6->setChecked(true);
    }
    else if (teacher->getType()[5] == 3)
    {
        ui->lab_6->setChecked(true);
    }

    if (teacher->getType()[6] == 1)
    {
        ui->course_7->setChecked(true);
    }
    else if (teacher->getType()[6] == 2)
    {
        ui->tuto_7->setChecked(true);
    }
    else if (teacher->getType()[6] == 3)
    {
        ui->lab_7->setChecked(true);
    }

    if (teacher->getType()[7] == 1)
    {
        ui->course_8->setChecked(true);
    }
    else if (teacher->getType()[7] == 2)
    {
        ui->tuto_8->setChecked(true);
    }
    else if (teacher->getType()[7] == 3)
    {
        ui->lab_8->setChecked(true);
    }

    if (teacher->getType()[8] == 1)
    {
        ui->course_9->setChecked(true);
    }
    else if (teacher->getType()[8] == 2)
    {
        ui->tuto_9->setChecked(true);
    }
    else if (teacher->getType()[8] == 3)
    {
        ui->lab_9->setChecked(true);
    }

    if (teacher->getType()[9] == 1)
    {
        ui->course_10->setChecked(true);
    }
    else if (teacher->getType()[9] == 2)
    {
        ui->tuto_10->setChecked(true);
    }
    else if (teacher->getType()[9] == 3)
    {
        ui->lab_10->setChecked(true);
    }

    if (teacher->getType()[10] == 1)
    {
        ui->course_11->setChecked(true);
    }
    else if (teacher->getType()[10] == 2)
    {
        ui->tuto_11->setChecked(true);
    }
    else if (teacher->getType()[10] == 3)
    {
        ui->lab_11->setChecked(true);
    }

    if (teacher->getType()[11] == 1)
    {
        ui->course_12->setChecked(true);
    }
    else if (teacher->getType()[11] == 2)
    {
        ui->tuto_12->setChecked(true);
    }
    else if (teacher->getType()[11] == 3)
    {
        ui->lab_12->setChecked(true);
    }

    // Create a new scroll area
    QScrollArea *scrollArea = new QScrollArea();

    // Create a new widget to hold the checkboxes
    QWidget *checkboxWidget = new QWidget();

    // Create a new layout for the checkbox widget

    // Add the checkboxes to the layout
    for (int i = 0; i < ENSIA.getCourses().size(); i++)
    {
        QCheckBox *checkbox = new QCheckBox(ENSIA.getCourses()[i]->getName().c_str());
        layout.addWidget(checkbox);

        // iterate over the teachers vector and check the checkbox if the teacher is assigned to the course
        for (Courses *course : teacher->getCourses())
        {
            if (course->getId() == i)
            {
                checkbox->setChecked(true);
                break;
            }
            else
            {
                checkbox->setChecked(false);
            }
        }
    }

    // Set the layout for the checkbox widget
    checkboxWidget->setLayout(&layout);

    // Set the checkbox widget as the widget for the scroll area
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(checkboxWidget);

    // Set the scroll area as the widget for List_courses
    ui->List_courses->setViewport(scrollArea);
}

edit_Teachers::~edit_Teachers()
{
    delete ui;
}

void edit_Teachers::on_CloseTeacherbtn_clicked()
{
    this->close();
}

void edit_Teachers::on_EditTeacherbtn_clicked()
{
    // validate the input
    if (ui->Line_name->text().isEmpty() || ui->Line_email->text().isEmpty() || ui->Line_password->text().isEmpty() || ui->Line_phone->text().isEmpty() || ui->Line_address->text().isEmpty())
    {
        QMessageBox::critical(this, "Input error", "All fields must be filled out");
        return;
    }

    // apply the changes :
    Teachers *teacher = ENSIA.getTeachers()[teacherid];
    teacher->setName(ui->Line_name->text().toStdString());
    teacher->setEmail(ui->Line_email->text().toStdString());
    teacher->setPassword(ui->Line_password->text().toStdString());
    teacher->setPhone(ui->Line_phone->text().toStdString());
    teacher->setAddress(ui->Line_address->text().toStdString());

    // for every checked checkbox in the list of courses, add the corresponding position to be true in assignedcourses bool vector
    for (int i = 0; i < layout.count(); i++)
    {
        QCheckBox *checkbox = qobject_cast<QCheckBox *>(layout.itemAt(i)->widget());
        if (checkbox)
        {
            if (checkbox->isChecked())
            {
                cout << "Course " << i << " checked" << endl;
                // check if the teacher is already assigned to the course
                bool found = false;
                for (Courses *course : teacher->getCourses())
                {
                    if (course->getId() == i)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    teacher->addCourse(ENSIA.getCourses()[i]);
                }
            }
            else
            {
                cout << "Course " << i << " not checked" << endl;
                teacher->removeCourse(i);
            }
        }
    }

    // set the type
    teacher->setType(0, ui->course_1->isChecked() ? 1 : ui->tuto_1->isChecked() ? 2
                                                    : ui->lab_1->isChecked()    ? 3
                                                                                : 0);
    teacher->setType(1, ui->course_2->isChecked() ? 1 : ui->tuto_2->isChecked() ? 2
                                                    : ui->lab_2->isChecked()    ? 3
                                                                                : 0);
    teacher->setType(2, ui->course_3->isChecked() ? 1 : ui->tuto_3->isChecked() ? 2
                                                    : ui->lab_3->isChecked()    ? 3
                                                                                : 0);
    teacher->setType(3, ui->course_4->isChecked() ? 1 : ui->tuto_4->isChecked() ? 2
                                                    : ui->lab_4->isChecked()    ? 3
                                                                                : 0);
    teacher->setType(4, ui->course_5->isChecked() ? 1 : ui->tuto_5->isChecked() ? 2
                                                    : ui->lab_5->isChecked()    ? 3
                                                                                : 0);
    teacher->setType(5, ui->course_6->isChecked() ? 1 : ui->tuto_6->isChecked() ? 2
                                                    : ui->lab_6->isChecked()    ? 3
                                                                                : 0);
    teacher->setType(6, ui->course_7->isChecked() ? 1 : ui->tuto_7->isChecked() ? 2
                                                    : ui->lab_7->isChecked()    ? 3
                                                                                : 0);
    teacher->setType(7, ui->course_8->isChecked() ? 1 : ui->tuto_8->isChecked() ? 2
                                                    : ui->lab_8->isChecked()    ? 3
                                                                                : 0);
    teacher->setType(8, ui->course_9->isChecked() ? 1 : ui->tuto_9->isChecked() ? 2
                                                    : ui->lab_9->isChecked()    ? 3
                                                                                : 0);
    teacher->setType(9, ui->course_10->isChecked() ? 1 : ui->tuto_10->isChecked() ? 2
                                                     : ui->lab_10->isChecked()    ? 3
                                                                                  : 0);
    teacher->setType(10, ui->course_11->isChecked() ? 1 : ui->tuto_11->isChecked() ? 2
                                                      : ui->lab_11->isChecked()    ? 3
                                                                                   : 0);
    teacher->setType(11, ui->course_12->isChecked() ? 1 : ui->tuto_12->isChecked() ? 2
                                                      : ui->lab_12->isChecked()    ? 3
                                                                                   : 0);


    // reset the schedule
    for (int i = 0; i < 7; i++)
    {
        teacher->setSchedule(i, 0, "");
        teacher->setSchedule(i, 1, "");
    }
    // sets the schedule according to the courses assigned
    for (int i = 0; i < teacher->getCourses().size(); i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (teacher->getCourses()[i]->getSchedule()[j][0] != "")
            {
                teacher->setSchedule(j, 0, teacher->getCourses()[i]->getSchedule()[j][0]);
                teacher->setSchedule(j, 1, teacher->getCourses()[i]->getSchedule()[j][1]);
            }
        }
    }

    teacher->getBirthDate().setDay(ui->L_Day->text().toInt());
    teacher->getBirthDate().setMonth(ui->L_Month->text().toInt());
    teacher->getBirthDate().setYear(ui->L_Year->text().toInt());

    teacher->setGroups(new bool[13]{ui->g1->isChecked(), ui->g2->isChecked(), ui->g3->isChecked(), ui->g4->isChecked(), ui->g5->isChecked(), ui->g6->isChecked(), ui->g7->isChecked(), ui->g8->isChecked(), ui->g9->isChecked(), ui->g10->isChecked(), ui->g11->isChecked(), ui->g12->isChecked()});

    this->close();
}