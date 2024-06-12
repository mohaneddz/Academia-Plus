#include "view_absences.h"
#include "ui_view_absences.h"
#include <QTime>
#include <QMessageBox>

view_absences::view_absences(QWidget *parent, Members *s)
    : QDialog(parent), ui(new Ui::view_absences)
{
    ui->setupUi(this);
    ss = s;

    ui->ab1->setPlaceholderText("d/M/yyyy H:mm");
    ui->ab2->setPlaceholderText("d/M/yyyy H:mm");
    ui->ab3->setPlaceholderText("d/M/yyyy H:mm");

    int absences = 0;
    for (int i = 0; i < 3; i++)
    {
        if (s->getAttendance()[i] != "")
        {
            absences++;
            switch (absences)
            {
            case 1:
                ui->checkBox->setChecked(true);
                ui->ab1->setText(QString::fromStdString(s->getAttendance()[i]));
                break;
            case 2:
                ui->checkBox_2->setChecked(true);
                ui->ab2->setText(QString::fromStdString(s->getAttendance()[i]));
                break;
            case 3:
                ui->checkBox_3->setChecked(true);
                ui->ab3->setText(QString::fromStdString(s->getAttendance()[i]));
                break;

            default:
                cout << "AN error has occured";
                break;
            }
        }
    }
}

view_absences::~view_absences()
{
    delete ui;
}

void view_absences::on_pushButton_2_clicked()
{

    // // Verify if the time entered is correct in each QLineEdit
    // Verify if the time entered is correct in each QLineEdit
    QDateTime dateTime1 = QDateTime::fromString(ui->ab1->text(), "d/M/yyyy H:mm");
    QDateTime dateTime2 = QDateTime::fromString(ui->ab2->text(), "d/M/yyyy H:mm");
    QDateTime dateTime3 = QDateTime::fromString(ui->ab3->text(), "d/M/yyyy H:mm");

    if (ui->checkBox->isChecked())
    {
        if (!dateTime1.isValid())
        {
            QMessageBox::warning(this, "Invalid Input", "Time in ab1 is not valid");
            return;
        }
        if (ui->ab1->text().isEmpty())
        {
            QMessageBox::warning(this, "Empty Field", "Field ab1 is empty");

            return;
        }
        ss->getAttendance()[0] = ui->ab1->text().toStdString();
    }
    else
        ss->getAttendance()[0] = "";
    if (ui->checkBox_2->isChecked())
    {
        if (!dateTime2.isValid())
        {
            QMessageBox::warning(this, "Invalid Input", "Time in ab2 is not valid");
            return;
        }
        if (ui->ab2->text().isEmpty())
        {
            QMessageBox::warning(this, "Empty Field", "Field ab2 is empty");
            return;
        }
        ss->getAttendance()[1] = ui->ab2->text().toStdString();
    }
    else
        ss->getAttendance()[1] = "";

    if (ui->checkBox_3->isChecked())
    {
        if (!dateTime3.isValid())
        {
            QMessageBox::warning(this, "Invalid Input", "Time in ab3 is not valid");
            return;
        }
        if (ui->ab3->text().isEmpty())
        {
            QMessageBox::warning(this, "Empty Field", "Field ab3 is empty");
            return;
        }
        ss->getAttendance()[2] = ui->ab3->text().toStdString();
    }
    else
        ss->getAttendance()[2] = "";

    this->close();
}
