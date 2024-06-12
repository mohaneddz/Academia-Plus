#ifndef VIEW_RESULT_SINGLE_H
#define VIEW_RESULT_SINGLE_H

#include <QWidget>
#include "Classes.h"

namespace Ui
{
    class View_result_single;
}

class View_result_single : public QWidget
{
    Q_OBJECT

public:
    explicit View_result_single(QWidget *parent = nullptr, Students *s = nullptr, int index = 0, string n = "");
    ~View_result_single();

private:
    Ui::View_result_single *ui;
};

#endif // VIEW_RESULT_SINGLE_H
