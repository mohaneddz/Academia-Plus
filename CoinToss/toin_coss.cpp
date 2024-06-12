#include "toin_coss.h"
#include "ui_toin_coss.h"

Toin_Coss::Toin_Coss(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Toin_Coss)
{
    ui->setupUi(this);
}

Toin_Coss::~Toin_Coss()
{
    delete ui;
}

