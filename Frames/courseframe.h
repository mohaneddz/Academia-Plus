#ifndef COURSEFRAME_H
#define COURSEFRAME_H

#include <QWidget>
#include "Classes.h"
#include "mainwindow.h"


namespace Ui
{
    class CourseFrame;
}

class CourseFrame : public QWidget
{
    Q_OBJECT

signals:
    void trigger();

public:

    explicit CourseFrame(QWidget *parent = nullptr);
    ~CourseFrame();

private slots:

    void on_btn_delete_clicked();
    void on_btn_edit_clicked();
    void on_btn_teachers_clicked();

private:
    Ui::CourseFrame *ui;
};

#endif // COURSEFRAME_H
