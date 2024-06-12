#include "view_performance.h"
#include "ui_view_performance.h"

view_performance::view_performance(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::view_performance)
{
    ui->setupUi(this);
}

view_performance::~view_performance()
{
    delete ui;
}
