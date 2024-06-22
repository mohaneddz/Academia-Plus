#ifndef EXAMFRAME_H
#define EXAMFRAME_H

#include <QWidget>

namespace Ui
{
    class examframe;
}

class ExamFrame : public QWidget
{
    Q_OBJECT

signals:
    void trigger();

public:
    explicit ExamFrame(QWidget *parent = nullptr);
    ~ExamFrame();

private slots:
    void on_btn_delete_clicked();
    void on_btn_edit_clicked();

    void on_btn_results_clicked();

    void on_btn_averages_clicked();

private:
    Ui::examframe *ui;
};

#endif // EXAMFRAME_H
