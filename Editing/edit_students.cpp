#include "edit_students.h"
#include "ui_edit_students.h"
#include "Classes.h"
#include <QScrollArea>
#include <QMessageBox>

edit_Students::edit_Students(QWidget *parent, int studentid)
    : QDialog(parent), ui(new Ui::edit_Students), studentid(studentid)
{
    ui->setupUi(this);
    Students *student = ENSIA.getStudents()[studentid];
    // set the fields :
    ui->Line_name->setText(QString::fromStdString(student->getName()));
    ui->Line_email->setText(QString::fromStdString(student->getEmail()));
    ui->Line_password->setText(QString::fromStdString(student->getPassword()));
    ui->Line_phone->setText(QString::fromStdString(student->getPhone()));
    ui->Line_address->setText(QString::fromStdString(student->getAddress()));
    // set the year
    switch (student->getYear())
    {
    case 1:
        ui->y1->setChecked(true);
        break;
    case 2:
        ui->y2->setChecked(true);
        break;
    case 3:
        ui->y3->setChecked(true);
        break;
    case 4:
        ui->y4->setChecked(true);
        break;
    case 5:
        ui->y5->setChecked(true);
        break;
    }
    // set the group
    ui->Combo_Student->setCurrentIndex(student->getGroup() - 1);
    // set the birth date
    ui->L_Year_3->setText(QString::number(student->getBirthDate().getYear()));
    ui->L_Month_3->setText(QString::number(student->getBirthDate().getMonth()));
    ui->L_Day_3->setText(QString::number(student->getBirthDate().getDay()));
}

void edit_Students::on_btnEditStudent_clicked()
{

    // validate the input
    if (ui->Line_name->text().isEmpty() || ui->Line_email->text().isEmpty() || ui->Line_password->text().isEmpty() || ui->Line_phone->text().isEmpty() || ui->Line_address->text().isEmpty())
    {
        QMessageBox::critical(this, "Input error", "All fields must be filled out");
        return;
    }

    Students *student = ENSIA.getStudents()[studentid];
    student->setName(ui->Line_name->text().toStdString());
    student->setEmail(ui->Line_email->text().toStdString());
    student->setPassword(ui->Line_password->text().toStdString());
    student->setPhone(ui->Line_phone->text().toStdString());
    student->setAddress(ui->Line_address->text().toStdString());

    // apply the year
    if (ui->y1->isChecked())
        student->setYear(1);
    else if (ui->y2->isChecked())
        student->setYear(2);
    else if (ui->y3->isChecked())
        student->setYear(3);
    else if (ui->y4->isChecked())
        student->setYear(4);
    else if (ui->y5->isChecked())
        student->setYear(5);

    // apply the group
    ENSIA.popstudent(student, student->getGroup() + 1); 
    student->setGroup(ui->Combo_Student->currentIndex() + 1);

    // apply the birth date
    student->setBirthDate(ui->L_Year_3->text().toInt(), ui->L_Month_3->text().toInt(), ui->L_Day_3->text().toInt());

    ENSIA.pushstudent(student, student->getGroup() + 1);

    emit trigger();
    this->close();
};

edit_Students::~edit_Students()
{
    delete ui;
}

void edit_Students::on_btnCancelStudent_clicked()
{
    this->close();
}
