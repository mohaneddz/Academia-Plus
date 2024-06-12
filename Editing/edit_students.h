#ifndef EDIT_STUDENTS_H
#define EDIT_STUDENTS_H

#include <QDialog>
#include <QVBoxLayout>

namespace Ui {
class edit_Students;
}

class edit_Students : public QDialog
{
    Q_OBJECT

signals:
    void trigger();

public:
    explicit edit_Students(QWidget *parent = nullptr, int studentid = 0);
    ~edit_Students();
    QVBoxLayout layout;

private slots:

    void on_btnEditStudent_clicked();

    void on_btnCancelStudent_clicked();

private:
    Ui::edit_Students *ui;
    int studentid;
};

#endif // EDIT_STUDENTS_H
