#include "edit_courses.h"
#include "ui_edit_courses.h"
#include "Classes.h"
#include "ui_teacher_list_frame.h"
#include "Views/teacher_list_frame.h"
#include <QScrollArea>
#include <QMessageBox>

edit_courses::edit_courses(int courseId, QWidget *parent)
    : QDialog(parent), ui(new Ui::edit_courses), courseId(courseId)
{
    ui->setupUi(this);

    Courses *course = ENSIA.getCourses()[courseId];

    // set the fields :
    findChild<QLineEdit *>("Line_coursename")->setText(QString::fromStdString(course->getName()));

    ui->g1->setChecked(course->getGroups()[0]);
    ui->g2->setChecked(course->getGroups()[1]);
    ui->g3->setChecked(course->getGroups()[2]);
    ui->g4->setChecked(course->getGroups()[3]);
    ui->g5->setChecked(course->getGroups()[4]);
    ui->g6->setChecked(course->getGroups()[5]);
    ui->g7->setChecked(course->getGroups()[6]);
    ui->g8->setChecked(course->getGroups()[7]);
    ui->g9->setChecked(course->getGroups()[8]);
    ui->g10->setChecked(course->getGroups()[9]);
    ui->g11->setChecked(course->getGroups()[10]);
    ui->g12->setChecked(course->getGroups()[11]);

    // set the schedule
    ui->sunday_start->setText(QString::fromStdString(course->getSchedule()[0][0]));
    ui->sunday_end->setText(QString::fromStdString(course->getSchedule()[0][1]));
    ui->monday_start->setText(QString::fromStdString(course->getSchedule()[1][0]));
    ui->monday_end->setText(QString::fromStdString(course->getSchedule()[1][1]));
    ui->tuesday_start->setText(QString::fromStdString(course->getSchedule()[2][0]));
    ui->tuesday_end->setText(QString::fromStdString(course->getSchedule()[2][1]));
    ui->wednesday_start->setText(QString::fromStdString(course->getSchedule()[3][0]));
    ui->wednesday_end->setText(QString::fromStdString(course->getSchedule()[3][1]));
    ui->thursday_start->setText(QString::fromStdString(course->getSchedule()[4][0]));
    ui->thursday_end->setText(QString::fromStdString(course->getSchedule()[4][1]));
    ui->friday_start->setText(QString::fromStdString(course->getSchedule()[5][0]));
    ui->friday_end->setText(QString::fromStdString(course->getSchedule()[5][1]));
    ui->saturday_start->setText(QString::fromStdString(course->getSchedule()[6][0]));
    ui->saturday_end->setText(QString::fromStdString(course->getSchedule()[6][1]));

    // set the teachers
    // Create a new scroll area
    QScrollArea *scrollArea = new QScrollArea();

    // Create a new widget to hold the checkboxes
    QWidget *checkboxWidget = new QWidget();

    // Create a new layout for the checkbox widget
    QVBoxLayout *layout = new QVBoxLayout();

    // Add the checkboxes to the layout
    // Add the teacher list frames to the layout
    for (int i = 0; i < ENSIA.getTeachers().size(); i++)
    {
        if (ENSIA.getTeachers().at(i) != nullptr)
        {
            teacher_list_frame *frame = new teacher_list_frame(this, i);
            frames.push_back(frame);
            layout->addWidget(frame);
            // if the teacher is aready assigned to this course, check the checkbox and set the type inside
            std::vector<Courses *> courses = ENSIA.getTeachers()[i]->getCourses();
            for (int j = 0; j < courses.size(); j++)
            {
                Courses *c = courses[j];
                if (c->getId() == courseId)
                {
                    frame->ui->assigned->setChecked(true);
                    frame->ui->course->setChecked(ENSIA.getTeachers()[i]->getType()[i] == 1);
                    frame->ui->tutorial->setChecked(ENSIA.getTeachers()[i]->getType()[i] == 2);
                    frame->ui->lab->setChecked(ENSIA.getTeachers()[i]->getType()[i] == 3);
                }
            }
        }

        checkboxWidget->setLayout(layout);
        scrollArea->setWidgetResizable(true);
        scrollArea->setWidget(checkboxWidget);
        ui->List_teachers->setViewport(scrollArea);
    }
}
edit_courses::~edit_courses()
{
    delete ui;
}

void edit_courses::on_btnCanceleditCourse_clicked()
{
    this->close();
}

void edit_courses::on_btnEditCourse_clicked()
{
    // validate the input
    // at least one group must be selected, name must not be empty, and the schedule must be valid
    if (ui->Line_coursename->text().isEmpty() || (ui->g1->isChecked() == false && ui->g2->isChecked() == false && ui->g3->isChecked() == false && ui->g4->isChecked() == false && ui->g5->isChecked() == false && ui->g6->isChecked() == false && ui->g7->isChecked() == false && ui->g8->isChecked() == false && ui->g9->isChecked() == false && ui->g10->isChecked() == false && ui->g11->isChecked() == false && ui->g12->isChecked() == false))
    {
        ui->Line_coursename->setStyleSheet("border: 1px solid red");
        QMessageBox::critical(this, "Input error", "All fields must be filled out");
        return;
    }

    // apply the changes :
    Courses *course = ENSIA.getCourses()[courseId];
    course->setName(ui->Line_coursename->text().toStdString());
    course->setGroups(new bool[13]{ui->g1->isChecked(), ui->g2->isChecked(), ui->g3->isChecked(), ui->g4->isChecked(), ui->g5->isChecked(), ui->g6->isChecked(), ui->g7->isChecked(), ui->g8->isChecked(), ui->g9->isChecked(), ui->g10->isChecked(), ui->g11->isChecked(), ui->g12->isChecked()});
    course->setSchedule(new string[7][2]{
        {ui->sunday_start->text().toStdString(), ui->sunday_end->text().toStdString()},
        {ui->monday_start->text().toStdString(), ui->monday_end->text().toStdString()},
        {ui->tuesday_start->text().toStdString(), ui->tuesday_end->text().toStdString()},
        {ui->wednesday_start->text().toStdString(), ui->wednesday_end->text().toStdString()},
        {ui->thursday_start->text().toStdString(), ui->thursday_end->text().toStdString()},
        {ui->friday_start->text().toStdString(), ui->friday_end->text().toStdString()},
        {ui->saturday_start->text().toStdString(), ui->saturday_end->text().toStdString()}});

    // get this courses index

    for (int i = 0; i < ENSIA.getTeachers().size(); i++)
    {
        // if the child number i is checked then assign the teacher to the course , and set the type according to the radio buttons
        if (frames[i]->check())
        {
            ENSIA.getTeachers()[i]->addCourse(course);
            
            for (int j = 0; j < 7; j++)
            {
                if (ENSIA.getTeachers()[i]->getCourses()[0]->getSchedule()[j][0] != "")
                {
                    ENSIA.getTeachers()[i]->setSchedule(j, 0, ENSIA.getTeachers()[i]->getCourses()[0]->getSchedule()[j][0]);
                    ENSIA.getTeachers()[i]->setSchedule(j, 1, ENSIA.getTeachers()[i]->getCourses()[0]->getSchedule()[j][1]);
                }
            }
        }
        else
        {
            ENSIA.getTeachers()[i]->removeCourse(courseId);
        }
    }

    this->close();
}
