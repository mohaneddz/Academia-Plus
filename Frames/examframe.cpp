#include "examframe.h"
#include "ui_examframe.h"
#include "mainwindow.h"
#include "Editing/edit_exams.h"
#include "Views/view_exam_results.h"
#include "Views/view_exam_averages.h"
#include <QDialog>

ExamFrame::ExamFrame(QWidget *parent)
    : QWidget(parent), ui(new Ui::examframe)
{
    ui->setupUi(this);
}

ExamFrame::~ExamFrame()
{
    delete ui;
}

void ExamFrame::on_btn_delete_clicked()
{
    cout << "Delete button clicked\n";
    int index = ui->L_ID->text().toInt();

    cout << "Index to be removed : " << index << endl;

    // Remove the Exam from the school
    ENSIA.removeExam(index);
    emit trigger();
}

void ExamFrame::on_btn_edit_clicked()
{
    int index = ui->L_ID->text().toInt();
    auto edit = new edit_exams(nullptr, index);
    connect(edit, &QDialog::finished, this, &ExamFrame::trigger);
    edit->setWindowTitle("Editing Options");
    edit->setModal(true);
    edit->exec();
}

void ExamFrame::on_btn_results_clicked()
{
    int index = ui->L_ID->text().toInt();
    view_exam_results *results = new view_exam_results(nullptr, ENSIA.getExams()[index]);
    results->setModal(true);
    results->exec();
}


void ExamFrame::on_btn_averages_clicked()
{
    int index = ui->L_ID->text().toInt();
    view_exam_averages *averages = new view_exam_averages(nullptr, ENSIA.getExams()[index]);
    averages->setModal(true);
    averages->exec();
}

