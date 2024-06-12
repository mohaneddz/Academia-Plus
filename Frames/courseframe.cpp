#include "courseframe.h"
#include "mainwindow.h"
#include "ui_courseframe.h"
#include "Editing/edit_courses.h"
#include "Views/view_teachers.h"

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
    cout << "Delete button clicked\n";
    int index = ui->L_ID->text().toInt();

    cout << "Index to be removed : " << index << endl;

    // Remove the course from the school
    ENSIA.removeCourse(index);
    emit trigger();
}
void CourseFrame::on_btn_edit_clicked()
{
    cout << "Edit button clicked\n";
    int index = ui->L_ID->text().toInt();

    cout << "Index to be edited : " << index << endl;
    edit_courses edit(index);
    edit.setModal(true);
    edit.exec();

    emit trigger();
}
void CourseFrame::on_btn_teachers_clicked()
{
    // starts the view_teachers instance
    cout << "Edit button clicked\n";
    int index = ui->L_ID->text().toInt();

    cout << "Index to be edited : " << index << endl;
    view_teachers view(index);
    view.setModal(true);
    view.exec();
}
