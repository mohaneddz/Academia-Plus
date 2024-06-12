#ifndef EDIT_EXAMS_H
#define EDIT_EXAMS_H

#include <QDialog>
#include <QVBoxLayout>

namespace Ui
{
    class edit_exams;
}

class edit_exams : public QDialog
{
    Q_OBJECT

public:
    explicit edit_exams(QWidget *parent = nullptr, int id = 0);
    ~edit_exams();
    QVBoxLayout layout;

private slots:
    void on_btnCancelExam_clicked();
    void on_btnEditExam_clicked();

private:
    Ui::edit_exams *ui;
    int id;
};

#endif // EDIT_EXAMS_H
