#ifndef VIEW_RESULT_SINGLE_H
#define VIEW_RESULT_SINGLE_H

#include <QWidget>
#include <QDialog>>
#include "Classes.h"

namespace Ui
{
    class View_result_single;
}

class View_result_single : public QDialog
{
    Q_OBJECT

public:
    explicit View_result_single(QDialog *parent, string n = "", double g = 0);
    ~View_result_single();
    string getName();
    double getResult();
    Exams *exam;

private:
    Ui::View_result_single *ui;
};

#endif // VIEW_RESULT_SINGLE_H
