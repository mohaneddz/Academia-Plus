#ifndef TEACHERFRAME_H
#define TEACHERFRAME_H

#include <QWidget>
#include "Classes.h"
#include "mainwindow.h"

namespace Ui
{
    class teacherframe;
}

class teacherframe : public QWidget
{
    Q_OBJECT

signals:
    void trigger();

public:
    explicit teacherframe(QWidget *parent = nullptr);
    ~teacherframe();

private slots:

    void on_btn_unassignon_clicked();
    void on_btnGroups_clicked();
    void on_btnEdit_clicked();
    void on_btnPerformance_clicked();
    void on_btnCourses_clicked();
    void on_btnViewSchedule_clicked();

private:
    Ui::teacherframe *ui;
};

#endif // TEACHERFRAME_H
