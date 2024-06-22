#ifndef ADD_COURSES_H
#define ADD_COURSES_H

#include <QDialog>
#include "Classes.h"
#include "Views/teacher_list_frame.h"


namespace Ui
{
    class Add_Courses;
}

class Add_Courses : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Courses(QWidget *parent = nullptr);
    ~Add_Courses();
    vector<teacher_list_frame *> frames ;

private slots:

    void on_Auto_clicked();
    void on_Add_clicked();
    void on_Cancel_clicked();


private:
    Ui::Add_Courses *ui;
};

#endif // ADD_COURSES_H
