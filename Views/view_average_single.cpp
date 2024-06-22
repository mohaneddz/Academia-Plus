#include "view_average_single.h"
#include "ui_view_average_single.h"

view_average_single::view_average_single(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::view_average_single)
{
    ui->setupUi(this);
}

view_average_single::~view_average_single()
{
    delete ui;
}
