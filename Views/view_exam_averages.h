#ifndef VIEW_EXAM_AVERAGES_H
#define VIEW_EXAM_AVERAGES_H

#include <QDialog>
#include <QWidget>
#include "Classes.h"
#include "view_result_single.h"

namespace Ui {
class view_exam_averages;
}

class view_exam_averages : public QDialog
{
    Q_OBJECT

public:
    explicit view_exam_averages(QWidget *parent = nullptr, Exams *e = nullptr, Students *s = nullptr);
    ~view_exam_averages();

private slots:
    void on_pushButton_clicked();

private:
    Ui::view_exam_averages *ui;
};

#endif // VIEW_EXAM_AVERAGES_H
