#ifndef VIEW_TEACHERS_H
#define VIEW_TEACHERS_H

#include <QDialog>

namespace Ui {
class view_teachers;
}

class view_teachers : public QDialog
{
    Q_OBJECT

public:
    explicit view_teachers(int id = 0, QWidget *parent = nullptr);
    ~view_teachers();

private slots:
    void on_pushButton_clicked();

private:
    Ui::view_teachers *ui;
    int courseid;
};

#endif // VIEW_TEACHERS_H
