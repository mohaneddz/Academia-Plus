#include "view_result_single.h"
#include "ui_view_result_single.h"

View_result_single::View_result_single(QWidget *parent, Students *s, int index, string n)
    : QWidget(parent)
    , ui(new Ui::View_result_single)
{
    ui->setupUi(this);
    ui->name->setText(QString::fromStdString(n));
    
    double grade = s->getResultsValue()[index];
    ui->result->setText(QString::number(grade));
 
    if (grade < 10)
    {
        ui->passed->setStyleSheet("color: red;");
    }
    else
    {
        //checkbod if the student is passed
        ui->passed->setChecked(true);
        ui->passed->setStyleSheet("color: green;");
    }
}

View_result_single::~View_result_single()
{
    delete ui;
}
