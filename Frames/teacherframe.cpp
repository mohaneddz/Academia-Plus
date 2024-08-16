#include "teacherframe.h"
#include "ui_teacherframe.h"
#include "mainwindow.h"
#include "Editing/edit_teachers.h"
#include "Views/view_group.h"
#include "Views/view_courses.h"
#include "Views/view_performance.h"
#include "Views/view_schedule.h"

teacherframe::teacherframe(QWidget *parent)
    : QWidget(parent), ui(new Ui::teacherframe)
{
    ui->setupUi(this);
}

teacherframe::~teacherframe()
{
    delete ui;
}

void teacherframe::on_btn_unassignon_clicked()
{
    cout << "Delete button clicked\n";
    int index = ui->L_ID->text().toInt();

    cout << "Index to be removed : " << index << endl;

    // Remove the Exam from the school
    ENSIA.removeTeacher(index);
    emit trigger();
}

void teacherframe::on_btnGroups_clicked()
{
    int index = ui->L_ID->text().toInt();
    Teachers *t = ENSIA.getTeachers()[index];
    view_group *view = new view_group(nullptr, t);
    view->show();
}

void teacherframe::on_btnCourses_clicked()
{
    int index = ui->L_ID->text().toInt();
    Teachers *t = ENSIA.getTeachers()[index];
    view_courses *view = new view_courses(nullptr, t);
    view->show();
}

void teacherframe::on_btnEdit_clicked()
{
    int index = ui->L_ID->text().toInt();
    auto edit = new edit_Teachers(nullptr, index);
    connect(edit, &QDialog::finished, this, &teacherframe::trigger);
    edit->setWindowTitle("Editing Options");
    edit->setModal(true);
    edit->exec();
}

void teacherframe::on_btnPerformance_clicked()
{
    int index = ui->L_ID->text().toInt();
    Teachers *t = ENSIA.getTeachers()[index];
    view_performance *view = new view_performance(nullptr, t);
    view->show();

    // Perform actions related to teacher performance
}

void teacherframe::on_btnViewSchedule_clicked()
{
    int index = ui->L_ID->text().toInt();
    Teachers *t = ENSIA.getTeachers()[index];
    view_schedule *view = new view_schedule(nullptr, t);
    view->show();
}
