#ifndef ADD_TEACHERS_H
#define ADD_TEACHERS_H

#include <QDialog>
#include "Classes.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QMessageBox>

namespace Ui
{
    class add_teachers;
}

class add_teachers : public QDialog
{
    Q_OBJECT

public:
    explicit add_teachers(QWidget *parent = nullptr);
    ~add_teachers();
    QVBoxLayout layout;

private slots:

    void on_Auto_clicked();
    void on_Add_clicked();
    void on_Cancel_clicked();

private:
    Ui::add_teachers *ui;
};

#endif // ADD_TEACHERS_H
