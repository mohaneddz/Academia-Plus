#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "Classes.h"

using  std::string;

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
    // if the username and password are empty
    if (this->username.empty() || this->password.empty())
    {
        QMessageBox::warning(this, "Error", "Please fill out all fields");
        return;
    }
    // if the user is admin and the password is admin
    if (this->job == "admin" && this->username == "admin" && this->password == "admin")
    {
        QMessageBox::information(this, "Success", "Welcome Admin");
        this->accept();
        return;
    }
    // else, if the user is teacher :
    if (this->job == "teacher")
    {
        bool found = false;
        for (Teachers *teacher : ENSIA.getTeachers())
        {
            if (teacher->getName() == this->username && teacher->getPassword() == this->password)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            QMessageBox::information(this, "Success", "Welcome Teacher");
            this->accept();
            return;
        }
        else
        {
            QMessageBox::warning(this, "Error", "Invalid username or password");
            return;
        }
    }
    // else, if the user is student :
    if (this->job == "student")
    {
        bool found = false;
        for (Students *student : ENSIA.getStudents())
        {
            if (student->getName() == this->username && student->getPassword() == this->password)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            QMessageBox::information(this, "Success", "Welcome Student");
            this->accept();
            return;
        }
        else
        {
            QMessageBox::warning(this, "Error", "Invalid username or password");
            return;
        }
    }

    this->close();
}
login::~login()
{
    delete ui;
}

void login::on_pushButton_2_clicked()
{
    this->reject();
}
