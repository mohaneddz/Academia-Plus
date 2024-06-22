#include "view_result_single.h"
#include "ui_view_result_single.h"

View_result_single::View_result_single(QDialog *parent, string n, double g)
    : QDialog(parent), ui(new Ui::View_result_single)
{
    ui->setupUi(this);
    ui->name->setText(QString::fromStdString(n));
    ui->result->setText(QString::number(g));

    if (g < 10)
    {
        ui->passed->setStyleSheet("color: red;");
    }
    else
    {
        // checkbod if the student is passed
        ui->passed->setChecked(true);
        ui->passed->setStyleSheet("color: green;");
    }
}

View_result_single::~View_result_single()
{
    delete ui;
}
string View_result_single::getName()
{
    return ui->name->text().toStdString();
}
double View_result_single::getResult()
{
    return ui->result->text().toDouble();
}
