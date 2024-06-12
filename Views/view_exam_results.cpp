#include "view_exam_results.h"
#include "ui_view_exam_results.h"

view_exam_results::view_exam_results(QWidget *parent, Exams *e)
    : QDialog(parent), ui(new Ui::view_exam_results)
{
    ui->setupUi(this);

    for (auto student : ENSIA.getStudents())
    {
        for (int i = 0; i < student->getResults().size(); i++)
        {
            // create a new single result widget
            View_result_single *result_widget = new View_result_single(this, student, student->getResultsValue()[i]);
            ui->scrollArea->layout()->addWidget(result_widget);
        }
    }
}

view_exam_results::~view_exam_results()
{
    delete ui;
}

void view_exam_results::on_pushButton_clicked()
{
    this->close();
}

