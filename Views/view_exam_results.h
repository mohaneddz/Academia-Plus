#ifndef VIEW_EXAM_RESULTS_H
#define VIEW_EXAM_RESULTS_H

#include <QDialog>
#include <QScrollArea>
#include "Classes.h"
#include "view_result_single.h"

namespace Ui
{
    class view_exam_results;
}

class view_exam_results : public QDialog
{
    Q_OBJECT

public:
    explicit view_exam_results(QWidget *parent = nullptr, Exams *e = nullptr);
    ~view_exam_results();
    vector<double> resultsvalue;
    Exams *exam;
    QScrollArea *sa;

private slots:
    void on_pushButton_clicked();

private:
    Ui::view_exam_results *ui;
};

#endif // VIEW_EXAM_RESULTS_H
