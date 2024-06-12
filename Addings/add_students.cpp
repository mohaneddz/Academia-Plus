#include "add_students.h"
#include "ui_add_students.h"
#include <Classes.h>
#include <QCheckBox>
#include <QMessageBox>

add_students::add_students(QWidget *parent)
    : QDialog(parent), ui(new Ui::add_students)
{
    ui->setupUi(this);
    connect(ui->Auto, SIGNAL(clicked()), this, SLOT(on_Auto_clicked()));
    connect(ui->Add, SIGNAL(clicked()), this, SLOT(on_Add_Clicked()));
}

add_students::~add_students()
{
    delete ui;
}

void add_students::on_Add_Clicked()
{

    // verify the given values
    if (ui->Line_name->text().isEmpty() ||
        ui->Line_email->text().isEmpty() ||
        ui->Line_phone->text().isEmpty() ||
        ui->Line_address->text().isEmpty() ||
        ui->Line_password->text().isEmpty() ||
        ui->Combo_Student->currentText().isEmpty())

    {
        // Show an error message and return
        QMessageBox::critical(this, "Input error", "All fields must be filled out");
        return;
    }

    int *day = new int(ui->L_Day->text().toInt());
    int *month = new int(ui->L_Month->text().toInt());
    int *year = new int(ui->L_Year->text().toInt());

    string *name = new string(ui->Line_name->text().toStdString());
    string *email = new string(ui->Line_email->text().toStdString());
    string *phone = new string(ui->Line_phone->text().toStdString());
    string *address = new string(ui->Line_address->text().toStdString());
    string *password = new string(ui->Line_password->text().toStdString());
    int *studyYear = new int(0);

    if (ui->y1->isChecked())
    {
        *studyYear = 1;
    }
    else if (ui->y2->isChecked())
    {
        *studyYear = 2;
    }
    else if (ui->y3->isChecked())
    {
        *studyYear = 3;
    }
    else if (ui->y4->isChecked())
    {
        *studyYear = 4;
    }
    else if (ui->y5->isChecked())
    {
        *studyYear = 5;
    }

    // Remove the word "Group" from the combo box
    string groupname = ui->Combo_Student->currentText().toStdString();

    int *group = new int(stoi(groupname.substr(6, groupname.length() - 6)));
    int *section = new int(0);

    // from group 1-4 section 1
    if (*group >= 1 && *group <= 4)
    {
        *section = 1;
    }
    // from group 5-8 section 2
    else if (*group >= 5 && *group <= 8)
    {
        *section = 2;
    }
    // from group 9-12 section 3
    else if (*group >= 9 && *group <= 12)
    {
        *section = 3;
    }

    // create a vector size of courses list

    vector<Courses *> *courses = new vector<Courses *>();

    // scan each course's groups and assign them to the student
    for (int i = 0; i < ENSIA.getCourses().size(); i++)
    {
        if (ENSIA.getCourses()[i]->getGroups()[*group - 1])
        {
            courses->push_back(ENSIA.getCourses()[i]);
        }
    }

    // Students(string name, long int id, string password, string email, string phone, string address, std::vector<Courses *> course, int Group);
    Students *student = new Students(*name, *password, *email, *phone, *address, *courses, *group, *studyYear, *section, *day, *month, *year);

    // push him into the ENSIA students group according ot his group
    ENSIA.pushstudent(student, student->getGroup() + 1);

    // delete the pointers
    delete name;
    delete email;
    delete phone;
    delete address;
    delete password;
    delete group;
    delete courses;
    delete year;
    delete day;
    delete month;
    delete section;

    this->close();
}

void add_students::on_Auto_clicked()
{
    ui->Line_name->setText("name");
    ui->Line_email->setText("email");
    ui->Line_phone->setText("phone");
    ui->Line_address->setText("address");
    ui->Line_password->setText("password");

    ui->L_Day->setText("1");
    ui->L_Month->setText("1");
    ui->L_Year->setText("2000");

    ui->Combo_Student->setCurrentIndex(0);
    // check radio box y1
    ui->y1->setChecked(true);

    // this->close();
}

void add_students::on_Cancel_clicked()
{
    this->close();
}
