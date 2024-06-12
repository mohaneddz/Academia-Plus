#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

using std::string;

login::login(QWidget *parent)
    : QDialog(parent), ui(new Ui::login)
{
    ui->setupUi(this);
}

void login::on_pushButton_clicked()
{
    this->username = ui->name->text().toStdString();
    this->password = ui->pass->text().toStdString();

    // check if the teacher/student/admin is checked

    if (ui->tbutton->isChecked())
    {
        this->job = "teacher";
    }
    else if (ui->sbutton->isChecked())
    {
        this->job = "student";
    }
    else if (ui->abutton->isChecked())
    {
        this->job = "admin";
    }
    else
    {
        QMessageBox::warning(this, "Error", "Please select a user type");
        return;
    }

    this->close();
}
login::~login()
{
    delete ui;
}


void login::on_pushButton_2_clicked()
{
    this->close();
}

