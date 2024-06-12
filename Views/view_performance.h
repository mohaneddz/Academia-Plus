#ifndef VIEW_PERFORMANCE_H
#define VIEW_PERFORMANCE_H

#include <QDialog>

namespace Ui {
class view_performance;
}

class view_performance : public QDialog
{
    Q_OBJECT

public:
    explicit view_performance(QWidget *parent = nullptr);
    ~view_performance();

private:
    Ui::view_performance *ui;
};

#endif // VIEW_PERFORMANCE_H
