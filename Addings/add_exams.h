#ifndef ADD_EXAMS_H
#define ADD_EXAMS_H

#include <QDialog>
#include "Classes.h"

namespace Ui
{
    class Add_Exams;
}

class add_exams : public QDialog
{
    Q_OBJECT

public:
    explicit add_exams(QWidget *parent = nullptr);


    ~add_exams();



private slots:
    void on_Auto_clicked();

    void on_btnAddExam_clicked();
    void on_btnCancelExam_clicked();

private:
    Ui::Add_Exams *ui;
};

#endif // ADD_EXAMS_H
