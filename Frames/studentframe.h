#ifndef STUDENTFRAME_H
#define STUDENTFRAME_H

#include <QWidget>

namespace Ui {
class studentframe;
}

class studentframe : public QWidget
{
    Q_OBJECT

signals:
    void trigger();

public:
    explicit studentframe(QWidget *parent = nullptr);
    ~studentframe();

private slots:

    void on_btn_edit_clicked();
    void on_btn_attendance_clicked();

    void on_btn_performance_clicked();
    void on_btn_unassign_clicked();
    void on_btn_courses_clicked();
    void on_btn_schedule_clicked();

private:
    Ui::studentframe *ui;
};

#endif // STUDENTFRAME_H
