#include "view_exam_averages.h"
#include "ui_view_exam_averages.h"
#include <QScrollArea>
#include <QLabel>
#include <QMessageBox>

view_exam_averages::view_exam_averages(QWidget *parent, Exams *e, Students *s)
    : QDialog(parent), ui(new Ui::view_exam_averages)
{
    ui->setupUi(this);

    QScrollArea *scrollArea = new QScrollArea();
    QWidget *list = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    if (s == nullptr && e != nullptr)
    {
        double totalAverage = 0;
        int totalGroups = 0; // To keep track of non-empty groups for accurate total average calculation
        for (int i = 0; i < 12; i++)
        {
            if (e->getGroups()[i] == 0)
            {
                continue;
            }
            double groupAverage = 0;
            int groupCount = 0;
            for (int j = 0; j < ENSIA.getGroup(i + 1).size(); j++)
            {
                if (ENSIA.getGroup(i + 1)[j]->getResultsValue().size() == 0)
                {
                    continue;
                }

                for (int k = 0; k < ENSIA.getGroup(i + 1)[j]->getResultsValue().size(); k++)
                {
                    if (ENSIA.getGroup(i + 1)[j]->getResults()[k]->getid() == e->getid())
                    {
                        groupAverage += ENSIA.getGroup(i + 1)[j]->getResultsValue()[k];
                        groupCount++;
                        continue;
                    }
                }
            }

            if (groupCount > 0)
            { // Ensure division by zero is avoided
                groupAverage /= groupCount;
                totalAverage += groupAverage; // Sum of group averages for total calculation
                totalGroups++;                // Increment the count of non-empty groups

                View_result_single *groupResult = new View_result_single(this, "Group " +  to_string(i + 1) + " Average", groupAverage);
                layout->addWidget(groupResult);
            }
        }

        if (totalGroups > 0)
        {                                // Ensure division by zero is avoided
            totalAverage /= totalGroups; // Calculate the total average based on group averages
            // Create and add the total average View_result_single here
            View_result_single *totalResult = new View_result_single(this, "Total Average", totalAverage);
            layout->insertWidget(0, totalResult); // Inserting at the top
        }

        list->setLayout(layout);
        scrollArea->setWidgetResizable(true);
        scrollArea->setWidget(list);
        ui->List_exam_results->setViewport(scrollArea);
    }
    // averages for the student , combine all the exams with similiar modules and their results, and devide by the number of exams, and create view_result_single for module, and the total average ( if he has no exams, the average is 0, always present)
    // Depricated: This block of code is not used in the current version of the application, with the latest release
    else
    {
        double totalAverage = 0;

        for (int i = 0; i < s->getResults().size(); i++)
        {
            double average = 0;
            int count = 1;
            for (int j = 0; j < s->getResults().size(); j++)
            {
                if (s->getResults()[i]->getModule()->getName() == s->getResults()[j]->getModule()->getName())
                {
                    average += s->getResultsValue()[j];
                    count++;
                }
            }
            average /= count;
            View_result_single *singleResult = new View_result_single(this, s->getResults()[i]->getModule()->getName(), average);
            layout->addWidget(singleResult);
        }

        for (int i = 0; i < s->getResults().size(); i++)
        {
            totalAverage += s->getResultsValue()[i];
        }
        totalAverage /= s->getResults().size();
        View_result_single *singleResult = new View_result_single(this, "Total Average", totalAverage);
        layout->addWidget(singleResult);
        list->setLayout(layout);
        scrollArea->setWidgetResizable(true);
        scrollArea->setWidget(list);
        ui->List_exam_results->setViewport(scrollArea);
    }
}

view_exam_averages::~view_exam_averages()
{
    delete ui;
}

void view_exam_averages::on_pushButton_clicked()
{
    this->close();
}
