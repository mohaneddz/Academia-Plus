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

    for (Teachers *teacher : ENSIA.getTeachers())
    {

        ui->responsible->addItem(QString::fromStdString(teacher->getName()));
        if(teacher->getName() == exam->getResponsible())
        {
            ui->responsible->setCurrentIndex(teacher->getId() + 1);
        }

    }

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

    // set the combobox index to be the index of the course->getModule
    ui->Combo_Module->setCurrentIndex(exam->getModule()->getId() + 1);
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
        ui->Combo_Module->setStyleSheet("border: 1px solid red");
        QMessageBox::critical(this, "Input error", "All fields must be filled out");
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

    delete start;
    delete end;
    delete[] groups;

    this->close();
}
