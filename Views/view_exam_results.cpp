#include "view_exam_results.h"
#include "ui_view_exam_results.h"
#include <QScrollArea>
#include <QLabel>
#include <QMessageBox>

view_exam_results::view_exam_results(QWidget *parent, Exams *e)
    : QDialog(parent), ui(new Ui::view_exam_results)
{
    ui->setupUi(this);

    exam = e;
    QScrollArea *scrollArea = new QScrollArea();
    QWidget *list = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(list);

    for (int i = 0; i < 12; i++)
    {
        if (e->getGroups()[i] == 0)
        {
            continue;
        }
        for (int j = 0; j < ENSIA.getGroup(i + 1).size(); j++)
        {
            // if the student is not in the group, skip
            if (ENSIA.getGroup(i + 1)[j]->getResultsValue().size() == 0)
            {
                continue;
            }
            // search for the index of this exam in the student's results
            for (int k = 0; k < ENSIA.getGroup(i + 1)[j]->getResults().size(); k++)
            {
                if (ENSIA.getGroup(i + 1)[j]->getResults()[k]->getid() == e->getid())
                {
                    View_result_single *singleResult = new View_result_single(this, ENSIA.getGroup(i + 1)[j]->getName(), ENSIA.getGroup(i + 1)[j]->getResultsValue()[k]);
                    layout->addWidget(singleResult);
                    break;
                }
            }
        }

        list->setLayout(layout);
        scrollArea->setWidgetResizable(true);
        scrollArea->setWidget(list);
        ui->List_exam_results->setViewport(scrollArea);
        sa = scrollArea;
    
    }
}

view_exam_results::~view_exam_results()
{
    delete ui;
}

void view_exam_results::on_pushButton_clicked()
{
    // Assuming 'scrollArea' is the QScrollArea you've added the 'list' widget to.
    QWidget *listWidget = sa->widget(); // Get the widget set on the QScrollArea
    if (!listWidget)
        return; // Safety check

    // Clear previous results
    resultsvalue.clear();

    // Iterate through all children of the list widget, which should be your View_result_single widgets
    const auto children = listWidget->findChildren<View_result_single *>();
    for (auto *result : children)
    {
        if (result)
        { // This check is probably redundant, as findChildren should only return non-null pointers
            resultsvalue.push_back(result->getResult());
        }
    }

    // Check if the results are valid
    for (auto value : resultsvalue)
    {
        if (value > 20 || value < 0 || isnan(value))
        {
            QMessageBox::warning(this, "Error", "Please enter a valid result for all students");
            return;
        }
    }
    int k = 0;
    // update the results
    for (int i = 0; i < 12; i++)
    {
        if (exam->getGroups()[i] == 0)
        {
            continue;
        }
        for (int j = 0; j < ENSIA.getGroup(i + 1).size(); j++)
        {
            // if the student is not in the group, skip
            if (ENSIA.getGroup(i + 1)[j]->getResultsValue().size() == 0)
            {
                continue;
            }

            ENSIA.getGroup(i + 1)[j]->setResultvalue(exam, resultsvalue[k]);
            k++;
        }
    }

    this->close();
}
