#include "add_courses.h"
#include "ui_add_courses.h"
#include <QScrollArea>
#include <QMessageBox>

Add_Courses::Add_Courses(QWidget *parent)
    : QDialog(parent), ui(new Ui::Add_Courses)
{
    ui->setupUi(this);

    // Create a new scroll area
    QScrollArea *scrollArea = new QScrollArea();

    // Create a new widget to hold the checkboxes
    QWidget *checkboxWidget = new QWidget();

    // Create a new layout for the checkbox widget
    QVBoxLayout *layout = new QVBoxLayout();

    // Add the teacher list frames to the layout
    for (int i = 0; i < ENSIA.getTeachers().size(); i++)
    {
        if (ENSIA.getTeachers().at(i) != nullptr)
        {
            teacher_list_frame *frame = new teacher_list_frame(this, i);
            frames.push_back(frame);
            layout->addWidget(frame);
        }
    }

    // Set the layout for the checkbox widget
    checkboxWidget->setLayout(layout);

    // Set the checkbox widget as the widget for the scroll area
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(checkboxWidget);

    // Set the scroll area as the widget for List_teachers
    ui->List_teachers->setViewport(scrollArea);
}

Add_Courses::~Add_Courses()
{
    delete ui;
}

void Add_Courses::on_Add_clicked()
{
    // validate the input
    // groups

    if (ui->Line_coursename->text().isEmpty() || (ui->g1->isChecked() == false && ui->g2->isChecked() == false && ui->g3->isChecked() == false && ui->g4->isChecked() == false && ui->g5->isChecked() == false && ui->g6->isChecked() == false && ui->g7->isChecked() == false && ui->g8->isChecked() == false && ui->g9->isChecked() == false && ui->g10->isChecked() == false && ui->g11->isChecked() == false && ui->g12->isChecked() == false))
    {
        ui->Line_coursename->setStyleSheet("border: 1px solid red");
        QMessageBox::critical(this, "Input error", "All fields must be filled out");
        return;
    }

    string *coursename = new string(ui->Line_coursename->text().toStdString());

    string *schedule = new string[7];
    schedule[0] = ui->sunday_start->text().toStdString() + " - " + ui->sunday_end->text().toStdString();
    schedule[1] = ui->monday_start->text().toStdString() + " - " + ui->monday_end->text().toStdString();
    schedule[2] = ui->tuesday_start->text().toStdString() + " - " + ui->tuesday_end->text().toStdString();
    schedule[3] = ui->wednesday_start->text().toStdString() + " - " + ui->wednesday_end->text().toStdString();
    schedule[4] = ui->thursday_start->text().toStdString() + " - " + ui->thursday_end->text().toStdString();
    schedule[5] = ui->friday_start->text().toStdString() + " - " + ui->friday_end->text().toStdString();
    schedule[6] = ui->saturday_start->text().toStdString() + " - " + ui->saturday_end->text().toStdString();

    bool *groups = new bool[13]{false};
    groups[0] = ui->g1->isChecked();
    groups[1] = ui->g2->isChecked();
    groups[2] = ui->g3->isChecked();
    groups[3] = ui->g4->isChecked();
    groups[4] = ui->g5->isChecked();
    groups[5] = ui->g6->isChecked();
    groups[6] = ui->g7->isChecked();
    groups[7] = ui->g8->isChecked();
    groups[8] = ui->g9->isChecked();
    groups[9] = ui->g10->isChecked();
    groups[10] = ui->g11->isChecked();
    groups[11] = ui->g12->isChecked();

    // Courses(const string &newName, string newSchedule[7], const bool newgroups[13]);
    Courses *course = new Courses(*coursename, schedule, groups);

    // add the course to the teachers checked in ( if they havent been added before)
    for (int i = 0; i < frames.size(); i++)
    {
        teacher_list_frame *frame = frames[i];
        // use the check function on each teacher list frame
        if (frame->check())
        {
            // add the course to the teacher
            ENSIA.getTeachers()[i]->addCourse(course);
        }
    }

    for (auto i : ENSIA.getCourses())
    {
        cout << i->getName() << endl;
    }

    Courses::totalcourses--;

    delete[] schedule;
    delete[] groups;

    this->close();
}

void Add_Courses::on_Auto_clicked()
{
    ui->Line_coursename->setText("name");
    ui->sunday_start->setText("08:00");
    ui->sunday_end->setText("10:00");
    ui->monday_start->setText("08:00");
    ui->monday_end->setText("10:00");
    ui->tuesday_start->setText("08:00");
    ui->tuesday_end->setText("10:00");
    ui->wednesday_start->setText("08:00");
    ui->wednesday_end->setText("10:00");
    ui->thursday_start->setText("08:00");
    ui->thursday_end->setText("10:00");

    ui->g1->setChecked(true);
    ui->g2->setChecked(true);
    ui->g3->setChecked(true);
    ui->g4->setChecked(true);
}

void Add_Courses::on_Cancel_clicked()
{
    this->close();
}
