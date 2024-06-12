#ifndef EDIT_TEACHERS_H
#define EDIT_TEACHERS_H

#include <QDialog>
#include <QVBoxLayout>

namespace Ui
{
    class edit_Teachers;
}

class edit_Teachers : public QDialog
{
    Q_OBJECT

public:
    explicit edit_Teachers(QWidget *parent = nullptr, int teacherid = 0);
    ~edit_Teachers();
    QVBoxLayout layout;

private slots:
    void on_CloseTeacherbtn_clicked();
    void on_EditTeacherbtn_clicked();

private:
    Ui::edit_Teachers *ui;
    int teacherid;
};

#endif // EDIT_TEACHERS_H
