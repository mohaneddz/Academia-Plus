#include "view_courses.h"
#include "ui_view_courses.h"
#include "view_courses_frame.h"
#include <QCheckBox>
#include <QScrollArea>
#include <QLabel>

view_courses::view_courses(QWidget *parent, Members *t)
    : QDialog(parent), ui(new Ui::view_courses)
{
    ui->setupUi(this);
    // Create a scroll area
    QScrollArea *scrollArea = new QScrollArea();

    // Create a widget to hold the list of groups
    QWidget *list = new QWidget();

    // Create a vertical layout for the groups
    QVBoxLayout *layout = new QVBoxLayout();

    // Iterate over the courses
    cout << "Courses of teacher: " << t->getName() << ": " << endl;
    for (const auto &course : t->getCourses())
    {
        // create a view courses frame object to display the course
        // create it inside a Qframe to display the course

        view_courses_frame *frame = new view_courses_frame(this, t, course->getId());
        layout->addWidget(frame);
    
    }

    // Set the layout for the group widget
    list->setLayout(layout);

    // Set the group widget as the widget for the scroll area
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(list);

    // Set the scroll area as the viewport for List_teachers
    ui->List_courses->setViewport(scrollArea);


}

view_courses::~view_courses()
{
    delete ui;
}

void view_courses::on_pushButton_clicked()
{
    this->close();
}

