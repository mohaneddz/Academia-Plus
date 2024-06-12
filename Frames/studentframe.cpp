#include "studentframe.h"
#include "Views/view_courses.h"
#include "ui_studentframe.h"
#include "mainwindow.h"
#include "Editing/edit_students.h"
#include "Views/view_absences.h"
#include "Views/view_student_results.h"

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
    cout << "Delete button clicked\n";
    int index = ui->L_ID->text().toInt();

    cout << "Index to be removed : " << index << endl;

    // Remove the Exam from the school
    ENSIA.removeStudent(index);
    emit trigger();
}

void studentframe::on_btn_edit_clicked()
{
    int index = ui->L_ID->text().toInt();
    auto edit = new edit_Students(nullptr, index);
    connect(edit, &QDialog::finished, this, &studentframe::trigger);
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

void studentframe::on_btn_assign_clicked()
{
    int index = ui->L_ID->text().toInt();
    auto edit = new view_courses(nullptr, ENSIA.getStudents()[index]);
    edit->setModal(true);
    edit->exec();
}

