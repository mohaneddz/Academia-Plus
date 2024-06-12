#ifndef VIEW_ABSENCES_H
#define VIEW_ABSENCES_H

#include <QDialog>
#include "Classes.h"

namespace Ui {
class view_absences;
}

class view_absences : public QDialog
{
    Q_OBJECT

public:
    explicit view_absences(QWidget *parent = nullptr, Members *s = nullptr);
    ~view_absences();
    Members *ss;
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::view_absences *ui;
};

#endif // VIEW_ABSENCES_H
