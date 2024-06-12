#include "view_group.h"
#include "ui_view_group.h"
#include <QLabel>
#include <QScrollArea>

view_group::view_group(QWidget *parent, Teachers *t)
    : QDialog(parent)
    , ui(new Ui::view_groups)
{
    ui->setupUi(this);

    QScrollArea *scrollArea = new QScrollArea();
    QWidget *list = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    //add each group to the listview as a label with the group name
    for (int i = 0; i < 12; i++)
    {
        if(t->getGroups()[i] == 1)
        {
            QLabel *label = new QLabel("Group " + QString::number(i + 1));

            layout->addWidget(label);
        }
    }

        // Set the layout for the checkbox widget
    list->setLayout(layout);

    // Set the checkbox widget as the widget for the scroll area
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(list);

    // Set the scroll area as the widget for List_teachers
    ui->List_groups->setViewport(scrollArea);

}

view_group::~view_group()
{
    delete ui;
}

void view_group::on_pushButton_clicked()
{
    this->close();
}

