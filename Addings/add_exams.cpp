#include "add_exams.h"
#include "ui_add_exams.h"
#include <QMessageBox>
#include <QTimeEdit>

add_exams::add_exams(QWidget *parent)
    : QDialog(parent), ui(new Ui::Add_Exams)
{
    ui->setupUi(this);
    for (Courses *course : ENSIA.getCourses())
    {
        ui->Combo_Module->addItem(QString::fromStdString(course->getName()));
    }
    for (Teachers *teacher : ENSIA.getTeachers())
    {
        ui->responsible->addItem(QString::fromStdString(teacher->getName()));
    }
}

add_exams::~add_exams()
{
    delete ui;
}

void add_exams::on_btnAddExam_clicked()
{

    // validate the input ( if all times are empty)
    if (ui->Combo_Module->currentText().isEmpty() || (ui->g1->isChecked() == false && ui->g2->isChecked() == false && ui->g3->isChecked() == false && ui->g4->isChecked() == false && ui->g5->isChecked() == false && ui->g6->isChecked() == false && ui->g7->isChecked() == false && ui->g8->isChecked() == false && ui->g9->isChecked() == false && ui->g10->isChecked() == false && ui->g11->isChecked() == false && ui->g12->isChecked() == false) || ui->L_Day->text().isEmpty() || ui->L_Month->text().isEmpty() || ui->L_Year->text().isEmpty() || ui->responsible->currentText().isEmpty())
    {
        ui->Combo_Module->setStyleSheet("border: 1px solid red");
        QMessageBox::critical(this, "Input error", "All fields must be filled out");
        return;
    }

    string *coursename = new string(ui->Combo_Module->currentText().toStdString());

    // iterate over the vector of courses, and add each course name to the module combo box as an optioon in the list

    bool *groups = new bool[13];
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

    float *marks = new float[7]{10, 10, 10, 10, 10, 10, 10};

    for (Courses *course : ENSIA.getCourses())
    {
        if (course->getId() == course->getId())
        {
            Time *start = new Time(ui->start->time().hour(), ui->start->time().minute(), ui->L_Day->text().toInt(), ui->L_Month->text().toInt(), ui->L_Year->text().toInt());
            Time *end = new Time(ui->end->time().hour(), ui->end->time().minute(), ui->L_Day->text().toInt(), ui->L_Month->text().toInt(), ui->L_Year->text().toInt());
            Exams *exam = new Exams(course, marks, start, end, groups);
            exam->setResponsible(ui->responsible->currentText().toStdString());

            // Iterate over each group
            for (int i = 0; i < 12; i++)
            {
                if (exam->getGroups()[i] != i)
                {
                    continue;
                }

                for (Students* student : ENSIA.getGroup(i))
                {
                    student->pushExam(exam);
                }
            }

            // Exams(Courses *Module, float Marks[7], string Date);
            cout << "EXAM ADDED!\n";

            // add the exam to the school
            delete coursename;
            delete start;
            delete end;
            delete[] groups;

            this->close();

            return;
        }
    }

    delete coursename;
    delete[] marks;
    delete[] groups;

    this->close();
}

void add_exams::on_btnCancelExam_clicked()
{
    this->close();
}

void add_exams::on_Auto_clicked()
{
    ui->Combo_Module->setCurrentIndex(1);
    ui->g1->setChecked(true);
    ui->g2->setChecked(true);
    ui->g3->setChecked(true);
    ui->g4->setChecked(true);

    ui->start->setTime(QTime(8, 0));
    ui->end->setTime(QTime(10, 0));

    ui->L_Day->setText("1");
    ui->L_Month->setText("1");
    ui->L_Year->setText("2021");
}
