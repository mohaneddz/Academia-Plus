#include "performance_event.h"
#include "ui_performance_event.h"

performance_event::performance_event(QWidget *parent, Members *m, int index)
    : QWidget(parent), ui(new Ui::performance_event)
{
    ui->setupUi(this);
    Teachers *t = dynamic_cast<Teachers *>(m);
    num = index;

    // set the event name
    ui->L_event->setText(QString::fromStdString(t->getevent(index)));
    // set the event time
    ui->L_time->setDateTime(t->geteventtime(index));

    cout << t->getName() << " " << t->getevent(index) << " " << t->geteventtime(index).toString().toStdString() << endl;
}

performance_event::~performance_event()
{
    delete ui;
}

void performance_event::setEvent(Teachers *t)
{
    QDateTime dateTime = ui->L_time->dateTime();
    t->setevent(ui->L_event->text().toStdString(), dateTime, num);
}
