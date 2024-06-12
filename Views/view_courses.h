#ifndef VIEW_COURSES_H
#define VIEW_COURSES_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class view_courses;
}

class view_courses : public QDialog
{
    Q_OBJECT

public:
    explicit view_courses(QWidget *parent = nullptr, Members *t = nullptr);
    ~view_courses();

private slots:
    void on_pushButton_clicked();

private:
    Ui::view_courses *ui;
};

#endif // VIEW_COURSES_H
