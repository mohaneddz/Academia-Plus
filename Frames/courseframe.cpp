#include "courseframe.h"
#include "ui_courseframe.h"
#include "mainwindow.h"
#include "Editing/edit_courses.h"
#include "Views/view_teachers.h"
#include "Views/view_schedule.h"

CourseFrame::CourseFrame(QWidget *parent)
    : QWidget(parent), ui(new Ui::CourseFrame)
{
    ui->setupUi(this);
}

CourseFrame::~CourseFrame()
{
    delete ui;
}

void CourseFrame::on_btn_delete_clicked()
{
    int index = ui->L_ID->text().toInt();

    // Remove the course from the school
    ENSIA.removeCourse(index);
    emit trigger();
}
void CourseFrame::on_btn_edit_clicked()
{
    int index = ui->L_ID->text().toInt();
    auto edit = new edit_courses(index, nullptr);
    connect(edit, &QDialog::finished, this, &CourseFrame::trigger);
    edit->setWindowTitle("Editing Options");
    edit->setModal(true);
    edit->exec();
}
void CourseFrame::on_btn_teachers_clicked()
{
    // starts the view_teachers instance
    int index = ui->L_ID->text().toInt();

    view_teachers view(index);
    view.setModal(true);
    view.exec();
}

void CourseFrame::on_btn_schedule_clicked()
{
    int index = ui->L_ID->text().toInt();

    view_schedule view(this, 0, ENSIA.getCourses()[index]);
    view.setModal(true);
    view.exec();
}
