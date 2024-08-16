#ifndef EDIT_COURSES_H
#define EDIT_COURSES_H

#include <QDialog>
#include <QVBoxLayout>
#include "Classes.h"
#include "Views/teacher_list_frame.h"
#include "Frames/courseframe.h"

namespace Ui
{
    class edit_courses;
}

class edit_courses : public QDialog
{
    Q_OBJECT

signals:
    void trigger();

public:
    explicit edit_courses(int courseId, QWidget *parent = nullptr);
    ~edit_courses();
    QVBoxLayout layout;
    vector<teacher_list_frame *> frames;

private slots:
    void on_btnCanceleditCourse_clicked();
    void on_btnEditCourse_clicked();

private:
    Ui::edit_courses *ui;
    int courseId;
};

#endif // EDIT_COURSES_H
