#include "view_student_results.h"
#include "ui_view_student_results.h"
#include "view_result_single.h"
#include "QScrollArea"

view_student_results::view_student_results(QWidget *parent, Students *e)
    : QDialog(parent), ui(new Ui::view_student_results)
{
    ui->setupUi(this);

    // Create a scroll area
    QScrollArea *scrollArea = new QScrollArea(this);

    // Create a widget to hold the list of results
    QWidget *list = new QWidget();

    // Create a vertical layout for the results
    QVBoxLayout *layout = new QVBoxLayout();

    for (int i = 0; i < e->getResults().size(); i++)
    {
        // add a new single result frame
        View_result_single *singleResult = new View_result_single(this, e, i, e->getResults()[i]->getModule()->getName());
        layout->addWidget(singleResult);
    }

    // Set the layout for the list widget
    list->setLayout(layout);

    // Set the list widget as the widget for the scroll area
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(list);

    // Add the scroll area to the layout where you want the scrollable list to appear
    ui->scrollResults->setViewport(scrollArea); 
}

view_student_results::~view_student_results()
{
    delete ui;
}

void view_student_results::on_pushButton_clicked()
{
    this->close();
}

