#include "view_schedule.h"
#include "ui_view_schedule.h"

view_schedule::view_schedule(QWidget *parent, Members *e)
    : QDialog(parent)
    , ui(new Ui::view_schedule)
{
    ui->setupUi(this);
}

view_schedule::~view_schedule()
{
    delete ui;
}
