#ifndef VIEW_AVERAGE_SINGLE_H
#define VIEW_AVERAGE_SINGLE_H

#include <QWidget>

namespace Ui {
class view_average_single;
}

class view_average_single : public QWidget
{
    Q_OBJECT

public:
    explicit view_average_single(QWidget *parent = nullptr);
    ~view_average_single();

private:
    Ui::view_average_single *ui;
};

#endif // VIEW_AVERAGE_SINGLE_H
