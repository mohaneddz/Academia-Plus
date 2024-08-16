#include "studentframe.h"
#include "Views/view_courses.h"
#include "ui_studentframe.h"
#include "mainwindow.h"
#include "Editing/edit_students.h"
#include "Views/view_absences.h"
#include "Views/view_student_results.h"
#include "Views/view_schedule.h"

studentframe::studentframe(QWidget *parent)
    : QWidget(parent), ui(new Ui::studentframe)
{
    ui->setupUi(this);
}

studentframe::~studentframe()
{
    delete ui;
}

void studentframe::on_btn_unassign_clicked()
{
    int index = ui->L_ID->text().toInt();

    // Remove the Exam from the school
    ENSIA.removeStudent(index);
    emit trigger();
}

void studentframe::on_btn_edit_clicked()
{
    int index = ui->L_ID->text().toInt();
    auto edit = new edit_Students(nullptr, index);
    connect(edit, &QDialog::finished, this, &studentframe::trigger);
    edit->setWindowTitle("Editing Options");
    edit->setModal(true);
    edit->exec();
}

void studentframe::on_btn_attendance_clicked()
{
    int index = ui->L_ID->text().toInt();
    auto edit = new view_absences(nullptr, ENSIA.getStudents()[index]);
    edit->setModal(true);
    edit->exec();
}

void studentframe::on_btn_performance_clicked()
{
    int index = ui->L_ID->text().toInt();
    auto edit = new view_student_results(nullptr, ENSIA.getStudents()[index]);
    edit->setModal(true);
    edit->exec();
}

void studentframe::on_btn_courses_clicked()
{
    int index = ui->L_ID->text().toInt();
    auto edit = new view_courses(nullptr, ENSIA.getStudents()[index]);
    edit->setModal(true);
    edit->exec();
}

void studentframe::on_btn_schedule_clicked()
{
    int index = ui->L_ID->text().toInt();
    auto edit = new view_schedule(nullptr, ENSIA.getStudents()[index]);
    edit->setModal(true);
    edit->exec();
}
