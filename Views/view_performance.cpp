#include "view_performance.h"
#include <QScrollArea>
#include "ui_view_performance.h"

view_performance::view_performance(QWidget *parent, Members *m)
    : QDialog(parent), ui(new Ui::view_performance)
{
    ui->setupUi(this);
    t = dynamic_cast<Teachers *>(m);

    // Create a scroll area
    QScrollArea *scrollArea = new QScrollArea();

    // Create a widget to hold the list of events
    QWidget *list = new QWidget();

    // Create a vertical layout for the events
    QVBoxLayout *layout = new QVBoxLayout();

    // for eevery event in the teacher's event list, create a new performance_event object
    for (int i = 0; i < t->getevents()->size(); i++)
    {
        performance_event *pe = new performance_event(this, m, i);
        layout->addWidget(pe);
    }

    // Set the layout for the group widget
    list->setLayout(layout);

    // Set the group widget as the widget for the scroll area
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(list);

    // Set the scroll area as the viewport for List_teachers
    ui->List_events->setViewport(scrollArea);
}

view_performance::~view_performance()
{
    delete ui;
}

void view_performance::on_new_event_clicked()
{

    // get the index of the last event in the teacher's event list
    int s = t->getevents()->size();
    Teachers *teacher  = dynamic_cast<Teachers *>(t);

    // set the event name and time
    QDateTime dateTime = QDateTime::currentDateTime();
    t->setevent("New Event", dateTime, s);

    // Create a new performance_event object
    performance_event *pe = new performance_event(this, teacher, s);
    eventslist.push_back(pe);

    // Get the scroll area
    QScrollArea *scrollArea = dynamic_cast<QScrollArea *>(ui->List_events->viewport());

    // Get the container widget
    QWidget *container = scrollArea->widget();

    // Get the layout of the container widget
    QVBoxLayout *layout = dynamic_cast<QVBoxLayout *>(container->layout());

    // Add the performance_event object to the layout
    layout->addWidget(pe);

    // Update the container widget
    container->setLayout(layout);

    // Update the scroll area
    scrollArea->setWidget(container);

}

void view_performance::on_pushButton_clicked()
{
    // for every performance_event object in the layout, set the event
    Teachers *t = dynamic_cast<Teachers *>(this->t);

    for (auto event : eventslist)
    {
        event->setEvent(t);
    }

    this->close();
}

