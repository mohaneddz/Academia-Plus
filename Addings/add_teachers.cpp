#include "add_teachers.h"
#include "ui_add_teachers.h"

add_teachers::add_teachers(QWidget *parent)
    : QDialog(parent), ui(new Ui::add_teachers)
{
    ui->setupUi(this);

    // Create a new scroll area
    QScrollArea *scrollArea = new QScrollArea();

    // Create a new widget to hold the checkboxes
    QWidget *checkboxWidget = new QWidget();

    // Create a new layout for the checkbox widget

    // Add the checkboxes to the layout
    for (Courses *course : ENSIA.getCourses())
    {
        QCheckBox *checkbox = new QCheckBox(course->getName().c_str());
        layout.addWidget(checkbox);
    }

    // Set the layout for the checkbox widget
    checkboxWidget->setLayout(&layout);

    // Set the checkbox widget as the widget for the scroll area
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(checkboxWidget);

    // Set the scroll area as the widget for List_courses
    ui->List_courses->setViewport(scrollArea);
}
add_teachers::~add_teachers()
{
    delete ui;
}

void add_teachers::on_Cancel_clicked()
{
    this->close();
};
void add_teachers::on_Add_clicked()
{

    // check if any group is checked
    if (ui->Line_name->text().isEmpty() ||
        ui->Line_email->text().isEmpty() ||
        ui->Line_phone->text().isEmpty() ||
        ui->Line_address->text().isEmpty() ||
        ui->Line_password->text().isEmpty() ||
        ui->L_Day->text().isEmpty() ||
        ui->L_Month->text().isEmpty() ||
        ui->L_Year->text().isEmpty() ||
        // check if any course is checked &
        // check all the groups 1 - 12
        (ui->g1->isChecked() && (ui->course_1->isChecked() == false && ui->tuto_1->isChecked() == false && ui->lab_1->isChecked() == false)) ||
        (ui->g2->isChecked() && (ui->course_2->isChecked() == false && ui->tuto_2->isChecked() == false && ui->lab_2->isChecked() == false)) ||
        (ui->g3->isChecked() && (ui->course_3->isChecked() == false && ui->tuto_3->isChecked() == false && ui->lab_3->isChecked() == false)) ||
        (ui->g4->isChecked() && (ui->course_4->isChecked() == false && ui->tuto_4->isChecked() == false && ui->lab_4->isChecked() == false)) ||
        (ui->g5->isChecked() && (ui->course_5->isChecked() == false && ui->tuto_5->isChecked() == false && ui->lab_5->isChecked() == false)) ||
        (ui->g6->isChecked() && (ui->course_6->isChecked() == false && ui->tuto_6->isChecked() == false && ui->lab_6->isChecked() == false)) ||
        (ui->g7->isChecked() && (ui->course_7->isChecked() == false && ui->tuto_7->isChecked() == false && ui->lab_7->isChecked() == false)) ||
        (ui->g8->isChecked() && (ui->course_8->isChecked() == false && ui->tuto_8->isChecked() == false && ui->lab_8->isChecked() == false)) ||
        (ui->g9->isChecked() && (ui->course_9->isChecked() == false && ui->tuto_9->isChecked() == false && ui->lab_9->isChecked() == false)) ||
        (ui->g10->isChecked() && (ui->course_10->isChecked() == false && ui->tuto_10->isChecked() == false && ui->lab_10->isChecked() == false)) ||
        (ui->g11->isChecked() && (ui->course_11->isChecked() == false && ui->tuto_11->isChecked() == false && ui->lab_11->isChecked() == false)) ||
        (ui->g12->isChecked() && (ui->course_12->isChecked() == false && ui->tuto_12->isChecked() == false && ui->lab_12->isChecked() == false)))
    {
        // Show an error message and return
        QMessageBox::critical(this, "Input error", "All fields must be filled out");
        return;
    }

    int *day = new int(ui->L_Day->text().toInt());
    int *month = new int(ui->L_Month->text().toInt());
    int *year = new int(ui->L_Year->text().toInt());

    bool *groups = new bool[12]{false};
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

    string *name = new string(ui->Line_name->text().toStdString());
    string *email = new string(ui->Line_email->text().toStdString());
    string *phone = new string(ui->Line_phone->text().toStdString());
    string *address = new string(ui->Line_address->text().toStdString());
    string *password = new string(ui->Line_password->text().toStdString());
    int type[12]{0};

    // empty courses vector
    vector<Courses *> courses;

    Teachers *teacher = new Teachers(*name, *password, *email, *phone, *address, courses, groups, *day, *month, *year, type);

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

    // for every checked checkbox in the list of courses, add the corresponding position to be true in assignedcourses bool vector
    for (int i = 0; i < layout.count(); i++)
    {
        QCheckBox *checkbox = qobject_cast<QCheckBox *>(layout.itemAt(i)->widget());
        if (checkbox)
        {
            if (checkbox->isChecked())
            {
                cout << "Course " << i << " checked" << endl;
                teacher->addCourse(ENSIA.getCourses().at(i));
            }
            else
            {
                cout << "Course " << i << " not checked" << endl;
                teacher->removeCourse(i);
            }
        }
    }

    delete year;
    delete month;
    delete day;
    delete name;
    delete email;
    delete phone;
    delete address;
    delete password;
    delete[] groups;


    this->close();
}

void add_teachers::on_Auto_clicked()
{
    // set default values for all qlines
    ui->Line_name->setText("Teacher");
    ui->Line_email->setText("email");
    ui->Line_phone->setText("phone");
    ui->Line_address->setText("address");
    ui->Line_password->setText("password");

    ui->L_Day->setText("1");
    ui->L_Month->setText("1");
    ui->L_Year->setText("2000");

    ui->g1->setChecked(true);
    ui->g2->setChecked(true);
    ui->g3->setChecked(true);
    ui->g4->setChecked(true);

    ui->course_1->setChecked(true);
    ui->tuto_2->setChecked(true);
    ui->course_3->setChecked(true);
    ui->lab_4->setChecked(true);
}
