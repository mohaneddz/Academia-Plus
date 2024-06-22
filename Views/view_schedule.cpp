#include "view_schedule.h"
#include "ui_view_schedule.h"

view_schedule::view_schedule(QWidget *parent, Members *e, Courses *c)
    : QDialog(parent), ui(new Ui::view_schedule)
{
    ui->setupUi(this);

    if(e != nullptr)
    {
    ui->sunday_start->setText(QString::fromStdString(e->getSchedule()[0][0]));
    ui->sunday_end->setText(QString::fromStdString(e->getSchedule()[0][1]));

    ui->monday_start->setText(QString::fromStdString(e->getSchedule()[1][0]));
    ui->monday_end->setText(QString::fromStdString(e->getSchedule()[1][1]));

    ui->tuesday_start->setText(QString::fromStdString(e->getSchedule()[2][0]));
    ui->tuesday_end->setText(QString::fromStdString(e->getSchedule()[2][1]));

    ui->wednesday_start->setText(QString::fromStdString(e->getSchedule()[3][0]));
    ui->wednesday_end->setText(QString::fromStdString(e->getSchedule()[3][1]));

    ui->thursday_start->setText(QString::fromStdString(e->getSchedule()[4][0]));
    ui->thursday_end->setText(QString::fromStdString(e->getSchedule()[4][1]));
    }else if (c != nullptr)
    {
    ui->sunday_start->setText(QString::fromStdString(c->getSchedule()[0][0]));
    ui->sunday_end->setText(QString::fromStdString(c->getSchedule()[0][1]));

    ui->monday_start->setText(QString::fromStdString(c->getSchedule()[1][0]));
    ui->monday_end->setText(QString::fromStdString(c->getSchedule()[1][1]));

    ui->tuesday_start->setText(QString::fromStdString(c->getSchedule()[2][0]));
    ui->tuesday_end->setText(QString::fromStdString(c->getSchedule()[2][1]));

    ui->wednesday_start->setText(QString::fromStdString(c->getSchedule()[3][0]));
    ui->wednesday_end->setText(QString::fromStdString(c->getSchedule()[3][1]));

    ui->thursday_start->setText(QString::fromStdString(c->getSchedule()[4][0]));
    ui->thursday_end->setText(QString::fromStdString(c->getSchedule()[4][1]));
    }
}

view_schedule::~view_schedule()
{
    delete ui;
}

void view_schedule::on_ok_clicked()
{
    this->close();
}
