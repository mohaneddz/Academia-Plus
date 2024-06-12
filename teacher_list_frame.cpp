#include "teacher_list_frame.h"
#include "ui_teacher_list_frame.h"
#include <QMessageBox>

teacher_list_frame::teacher_list_frame(QWidget *parent, int index)
    : QWidget(parent), ui(new Ui::teacher_list_frame)
{
    ui->setupUi(this);
    t = ENSIA.getTeachers()[index];
    cout << t->getName() << endl;
    ui->teacher->setText(QString::fromStdString(t->getName()));

}

teacher_list_frame::~teacher_list_frame()
{
    delete ui;
}

bool teacher_list_frame::check()
{

    // if the checkbox is checked, then the teacher is assigned to the course / tutorial / lab
    if (ui->assigned->isChecked())
    {
        // at least one radio must be checked
        if (!ui->course->isChecked() && !ui->tutorial->isChecked() && !ui->lab->isChecked())
        {
            // throw an error
            QMessageBox::warning(this, "Error", "Please select a role for the teacher");
            return false;
        }
        // if the course radio is checked, set k according to the type
        int k = (ui->course->isChecked()) ? 1 : (ui->tutorial->isChecked()) ? 2
                                                                            : 3;

        for (int i = 0; i < 12; i++)
        {
            if (t->getGroups()[i] == 1)
            {
                t->setType(i, k);
            }
        }
        return true;
    }
    return false;
}
