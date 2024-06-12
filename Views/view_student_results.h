#ifndef VIEW_STUDENT_RESULTS_H
#define VIEW_STUDENT_RESULTS_H

#include <QDialog>
#include "Classes.h"

namespace Ui {
class view_student_results;
}

class view_student_results : public QDialog
{
    Q_OBJECT

public:
    explicit view_student_results(QWidget *parent = nullptr, Students *e = nullptr);
    ~view_student_results();

private slots:
    void on_pushButton_clicked();

private:
    Ui::view_student_results *ui;
};

#endif // VIEW_STUDENT_RESULTS_H
