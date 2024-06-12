#ifndef VIEW_GROUP_H
#define VIEW_GROUP_H

#include "Classes.h"
#include <QDialog>

namespace Ui {
class view_groups;
}

class view_group : public QDialog
{
    Q_OBJECT

public:
    explicit view_group(QWidget *parent = nullptr, Teachers *t = nullptr);
    ~view_group();

private slots:
    void on_pushButton_clicked();

private:
    Ui::view_groups *ui;
};

#endif // VIEW_GROUP_H
