#include "edit_exams.h"
#include "ui_edit_exams.h"
#include "mainwindow.h"
#include "Classes.h"
#include <QMessageBox>

edit_exams::edit_exams(QWidget *parent, int index)
    : QDialog(parent), ui(new Ui::edit_exams), id(index)
{
    ui->setupUi(this);

    Exams *exam = ENSIA.getExams()[id];

    // set everything to it's value
    for (Courses *course : ENSIA.getCourses())
    {
        ui->Combo_Module->addItem(QString::fromStdString(course->getName()));
    }

    int responsibleIndex = 0;
    for (Teachers *teacher : ENSIA.getTeachers())
    {

        ui->responsible->addItem(QString::fromStdString(teacher->getName()));
        if (teacher->getName() == exam->getResponsible())
        {
            responsibleIndex = teacher->getId();
        }
    }
    ui->responsible->setCurrentIndex(responsibleIndex);

    ui->L_Day->setText(QString::number(exam->getStartDate().getDay()));
    ui->L_Month->setText(QString::number(exam->getStartDate().getMonth()));
    ui->L_Year->setText(QString::number(exam->getStartDate().getYear()));

    // set the groups
    ui->g1->setChecked(exam->getGroups()[0]);
    ui->g2->setChecked(exam->getGroups()[1]);
    ui->g3->setChecked(exam->getGroups()[2]);
    ui->g4->setChecked(exam->getGroups()[3]);
    ui->g5->setChecked(exam->getGroups()[4]);
    ui->g6->setChecked(exam->getGroups()[5]);
    ui->g7->setChecked(exam->getGroups()[6]);
    ui->g8->setChecked(exam->getGroups()[7]);
    ui->g9->setChecked(exam->getGroups()[8]);
    ui->g10->setChecked(exam->getGroups()[9]);
    ui->g11->setChecked(exam->getGroups()[10]);
    ui->g12->setChecked(exam->getGroups()[11]);

    // set the time
    ui->start->setTime(QTime(exam->getStartDate().getHour(), exam->getStartDate().getMinute()));
    ui->end->setTime(QTime(exam->getEndDate().getHour(), exam->getEndDate().getMinute()));

    // set the combobox index to be the index of the course->getModule
    ui->Combo_Module->setCurrentIndex(exam->getModule()->getId() + 1);
    examId = exam->getid();
}

edit_exams::~edit_exams()
{
    delete ui;
}

void edit_exams::on_btnCancelExam_clicked()
{
    this->close();
}

void edit_exams::on_btnEditExam_clicked()
{

    // validate the input ( if all times are empty)
    if (ui->Combo_Module->currentText().isEmpty() || (ui->g1->isChecked() == false && ui->g2->isChecked() == false && ui->g3->isChecked() == false && ui->g4->isChecked() == false && ui->g5->isChecked() == false && ui->g6->isChecked() == false && ui->g7->isChecked() == false && ui->g8->isChecked() == false && ui->g9->isChecked() == false && ui->g10->isChecked() == false && ui->g11->isChecked() == false && ui->g12->isChecked() == false) || ui->L_Day->text().isEmpty() || ui->L_Month->text().isEmpty() || ui->L_Year->text().isEmpty() || ui->responsible->currentText().isEmpty())
    {
        QMessageBox::critical(this, "Input error", "All fields must be filled out");
        return;
    }

    // check if the exam name is already taken, unless it's the same exam
    // the name of the module from ui->Combo_Module->currentText()
    for (Exams *exam : ENSIA.getExams())
    {
        if (exam->getModule()->getName() == ui->Combo_Module->currentText().toStdString() && exam->getid() != examId)
        {

            QMessageBox::critical(this, "Input error", "This exam name is already taken");
            return;
        }
    }

    if(ui->start->time() > ui->end->time())
    {
        QMessageBox::critical(this, "Input error", "The start time must be before the end time");
        return;
    }

    // if the teacher does not have this module in his courses
    // first get the teacher object
    Teachers *teacher = nullptr;
    for (Teachers *t : ENSIA.getTeachers())
    {
        if (t->getName() == ui->responsible->currentText().toStdString())
        {
            teacher = t;
            break;
        }
    }

    bool courseFound = false; // Flag to indicate if the course is found
    for (Courses *course : teacher->getCourses())
    {
        if (course->getName() == ui->Combo_Module->currentText().toStdString())
        {
            courseFound = true; // Course found, set the flag to true
            break;
        }
    }

    if (!courseFound) // Check if the course was not found after checking all courses
    {
        QMessageBox::critical(this, "Input error", "This teacher does not have this module in his courses!");
        return;
    }

    Exams *exam = ENSIA.getExams()[id];
    for (Courses *course : ENSIA.getCourses())
    {
        if (course->getName() == ui->Combo_Module->currentText().toStdString())
        {
            exam->setModule(course);
            break;
        }
    }
    // APPLY the changes
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

    Time *start = new Time(ui->start->time().hour(), ui->start->time().minute(), ui->L_Day->text().toInt(), ui->L_Month->text().toInt(), ui->L_Year->text().toInt());
    Time *end = new Time(ui->end->time().hour(), ui->end->time().minute(), ui->L_Day->text().toInt(), ui->L_Month->text().toInt(), ui->L_Year->text().toInt());

    exam->setGroups(groups);
    exam->setDate(*start, *end);

    if(exam->fixschedule())
    {
        QMessageBox::critical(this, "Input error", "The exam schedule is conflicting with another exam");
        delete start;
        delete end;
        delete[] groups;
        ENSIA.removeExam(exam->getid());
        delete exam;
        return;
    }

    exam->setResponsible(ui->responsible->currentText().toStdString());

    delete start;
    delete end;
    delete[] groups;

    this->close();
}
