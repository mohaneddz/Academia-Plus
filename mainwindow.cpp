#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Addings/add_courses.h"
#include "Addings/add_teachers.h"
#include "Addings/add_exams.h"
#include "Addings/add_students.h"
#include "Frames/courseframe.h"
#include "Frames/teacherframe.h"
#include "Frames/studentframe.h"
#include "Frames/examframe.h"

#include "Classes.cpp"
#include <cstring>

#include <QGraphicsDropShadowEffect>
#include <QFormLayout>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QPair>
#include <QInputDialog>
#include <QStandardItem>
#include <QListView>
#include <QMessageBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QGroupBox>
#include <QString>
#include <string>
#include <optional>
#include <QSize>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{

    courseNameInput = new QLineEdit(this);
    ui->setupUi(this);

    // Create a QLabel for the course name
    courseNameLabel = new QLabel(this);
    QFont fancyFont;
    fancyFont.setPointSize(14);             // Set the size
    fancyFont.setFamily("Times New Roman"); // Set the font family
    fancyFont.setBold(true);                // Make it bold
    courseNameLabel->setFont(fancyFont);    // Apply the font to the label

    // Set the text
    QGraphicsDropShadowEffect *intro_effect = new QGraphicsDropShadowEffect();
    intro_effect->setBlurRadius(10);
    intro_effect->setXOffset(1);
    intro_effect->setYOffset(1);
    intro_effect->setColor(QColor("black"));
    ui->intro->setGraphicsEffect(intro_effect);
    ui->full_menu_widget->hide();

    // Set the text
    QGraphicsDropShadowEffect *LOGO_effect = new QGraphicsDropShadowEffect();
    LOGO_effect->setBlurRadius(8);
    LOGO_effect->setXOffset(1);
    LOGO_effect->setYOffset(1);
    LOGO_effect->setColor(QColor("black"));
    ui->LOGO->setGraphicsEffect(LOGO_effect);

    connect(ui->user_btn, &QPushButton::clicked, [this]()
            { ui->stackedWidget->setCurrentIndex(6); });

    QPixmap teacherImage(":/path/to/teacher/image.png");
    QPixmap studentImage(":/path/to/student/image.png");
}
MainWindow::~MainWindow()
{
    delete ui;
}

// Course Image Assignment ( Depricatede  )
QString MainWindow::assignImage(const QString &courseName)
{
    if (courseName == "OOP")
    {
        return ":/courses/icon/Courses/oop.png";
    }
    else if (courseName == "statistics")
    {
        return ":/courses/icon/Courses/statistics.png";
    }
    else if (courseName == "linear algebra")
    {
        return ":/courses/icon/Courses/linear_algebra.png";
    }
    else if (courseName == "analysis")
    {
        return ":/courses/icon/Courses/analysis.png";
    }
    else if (courseName == "linux")
    {
        return ":/courses/icon/Courses/linux.png";
    }
    else if (courseName == "English")
    {
        return ":/courses/icon/Courses/English..png";
    }
    else
    {
        return ""; // Default image or empty string
    }
}

// Buttons Navigation
void MainWindow::on_home_btn_1_toggled()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_home_btn_2_toggled()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_courses_btn_1_toggled()
{
    ui->stackedWidget->setCurrentIndex(1);
    loadCourses();
}
void MainWindow::on_courses_btn_2_toggled()
{
    ui->stackedWidget->setCurrentIndex(1);
    loadCourses();
}
void MainWindow::on_exams_btn_1_toggled()
{
    ui->stackedWidget->setCurrentIndex(2);
    loadExams();
}
void MainWindow::on_exams_btn_2_toggled()
{
    ui->stackedWidget->setCurrentIndex(2);
    loadExams();
}
void MainWindow::on_teachers_btn_1_toggled()
{
    ui->stackedWidget->setCurrentIndex(3);
    loadTeachers();
}
void MainWindow::on_teachers_btn_2_toggled()
{
    ui->stackedWidget->setCurrentIndex(3);
    loadTeachers();
}
void MainWindow::on_students_btn_1_toggled()
{
    ui->stackedWidget->setCurrentIndex(4);
    loadStudents();
}
void MainWindow::on_students_btn_2_toggled()
{
    ui->stackedWidget->setCurrentIndex(4);
    loadStudents();
}
void MainWindow::on_search_btn_toggled()
{
    ui->stackedWidget->setCurrentIndex(5);
    cout << "Search Started";
    search(ui->search_input->text().toStdString());
}
void MainWindow::on_user_btn_toggled()
{
    ui->stackedWidget->setCurrentIndex(6);
}

// Loading Data

void MainWindow::loadCourses()
{
    // Clear the layout of scrollCourses
    QLayout *layout = ui->scrollCourses->layout();

    // Check if the layout is not null, to remove all items inside
    if (layout != nullptr)
    {
        // Remove all items from the layout
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr)
        {
            // Remove the widget from the layout item
            delete item->widget();
            // Delete the layout item
            delete item;
        }
    }

    cout << "Loading courses..." << endl;
    for (auto course : ENSIA.getCourses())
    {
        // cout << "Course found" << endl;
        if (course == nullptr)
        {
            // cout << "Course is null" << endl;
            break;
        }

        string *groups = new string[12 + 12];
        string *teachers = new string;

        // Create a new QWidget
        QWidget *widget = new QWidget();

        // Set the layout for the new QWidget
        widget->setLayout(new QVBoxLayout());

        // Create a new courseframe
        CourseFrame *courseFrame = new CourseFrame();
        connect(courseFrame, &CourseFrame::trigger, this, &MainWindow::loadCourses);

        for (int i = 0; i < 12; i++)
        {
            if (course->getGroups()[i] == 1)
            {
                if (groups->empty())
                {
                    *groups += to_string(i + 1);
                }
                else
                {
                    *groups += " " + to_string(i + 1);
                }
            }
        }

        courseFrame->findChild<QLineEdit *>("L_name")->setText(QString::fromStdString(course->getName()));
        courseFrame->findChild<QLineEdit *>("L_ID")->setText(QString::number(course->getId()));
        courseFrame->findChild<QLineEdit *>("L_Groups")->setText(QString::fromStdString(*groups));

        // Add the CourseFrame to the layout of widget
        widget->layout()->addWidget(courseFrame);

        // Add the widget to the scroll area
        ui->scrollCourses->layout()->addWidget(widget);
        // cout << "Course loaded successfully" << endl;
    }
}
void MainWindow::loadTeachers()
{
    // Clear the layout of scrollCourses
    QLayout *layout = ui->scrollTeachers->layout();

    // Check if the layout is not null, to remove all items inside
    if (layout != nullptr)
    {
        // Remove all items from the layout
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr)
        {
            // Remove the widget from the layout item
            delete item->widget();
            // Delete the layout item
            delete item;
            cout << "Item deleted" << endl;
        }
    }

    cout << "Loading teachers..." << endl;
    for (auto teacher : ENSIA.getTeachers())
    {
        if (teacher == nullptr)
        {
            cout << "Teacher is null" << endl;
            break;
        }

        // Create a new QWidget
        QWidget *widget = new QWidget();

        // Set the layout for the new QWidget
        widget->setLayout(new QVBoxLayout());

        // Create a new teacherFrame
        teacherframe *teacher_Frame = new teacherframe();
        connect(teacher_Frame, &teacherframe::trigger, this, &MainWindow::loadTeachers);

        // Find the Jobs :
        bool found1 = false, found2 = false, found3 = false;
        string *jobs = new string;
        for (int i = 0; i < 12; i++)
        {
            if (teacher->getType()[i] == 1 && !found1)
            {
                *jobs += "Course ";
                found1 = true;
            }
            if (teacher->getType()[i] == 2 && !found2)
            {
                *jobs += "Tutorial ";
                found2 = true;
            }
            if (teacher->getType()[i] == 3 && !found3)
            {
                *jobs += "Lab ";
                found3 = true;
            }
        }

        teacher_Frame->findChild<QLineEdit *>("L_Job")->setText(QString::fromStdString(*jobs));
        teacher_Frame->findChild<QLineEdit *>("L_Name")->setText(QString::fromStdString(teacher->getName()));
        teacher_Frame->findChild<QLineEdit *>("L_ID")->setText(QString::number(teacher->getId()));
        teacher_Frame->findChild<QLineEdit *>("L_Email")->setText(QString::fromStdString(teacher->getEmail()));
        teacher_Frame->findChild<QLineEdit *>("L_Phone")->setText(QString::fromStdString(teacher->getPhone()));
        teacher_Frame->findChild<QLineEdit *>("L_Address")->setText(QString::fromStdString(teacher->getAddress()));
        teacher_Frame->findChild<QLineEdit *>("L_BD")->setText(QString::number(teacher->getBirthDate().getDay()) + "/" + QString::number(teacher->getBirthDate().getMonth()) + "/" + QString::number(teacher->getBirthDate().getYear()));

        widget->layout()->addWidget(teacher_Frame);
        ui->scrollTeachers->layout()->addWidget(widget);

        delete jobs;
    }
}
void MainWindow::loadExams()
{
    // Clear the layout of scrollExams
    QLayout *layout = ui->scrollExams->layout();

    // Check if the layout is not null, to remove all items inside
    if (layout != nullptr)
    {
        // Remove all items from the layout
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr)
        {
            // Remove the widget from the layout item
            delete item->widget();
            // Delete the layout item
            delete item;
        }
    }

    cout << "Loading Exams..." << endl;
    for (auto exam : ENSIA.getExams())
    {
        if (exam == nullptr)
        {
            cout << "Exam is null" << endl;
            break;
        }

        string *groups = new string[12 + 12];
        string *teachers = new string;

        for (int i = 0; i < 12; i++)
        {
            if (exam->getGroups()[i] == 1)
            {
                if (groups->empty())
                {
                    *groups += to_string(i + 1);
                }
                else
                {
                    *groups += " " + to_string(i + 1);
                }
            }
        }

        // Create a new QWidget
        QWidget *widget = new QWidget();

        // Set the layout for the new QWidget
        widget->setLayout(new QVBoxLayout());

        // fix the minutes to be 2 digits
        QString minutesStart = QString("%1").arg(exam->getTimeStart().getMinute(), 2, 10, QChar('0'));
        QString minutesEnd = QString("%1").arg(exam->getTimeEnd().getMinute(), 2, 10, QChar('0'));

        // Create a new examframe
        ExamFrame *examFrame = new ExamFrame();
        connect(examFrame, &ExamFrame::trigger, this, &MainWindow::loadExams);
        examFrame->findChild<QLineEdit *>("L_name")->setText(QString::fromStdString(exam->getModule()->getName()));
        examFrame->findChild<QLineEdit *>("L_ID")->setText(QString::number(exam->getid()));
        examFrame->findChild<QLineEdit *>("L_Groups")->setText(QString::fromStdString(*groups));
        examFrame->findChild<QLineEdit *>("L_date")->setText(QString::number(exam->getTimeStart().getDay()) + "/" + QString::number(exam->getTimeStart().getMonth()) + "/" + QString::number(exam->getTimeStart().getYear()) + " " + QString::number(exam->getTimeStart().getHour()) + ":" + minutesStart + " To " + QString::number(exam->getTimeEnd().getHour()) + ":" + minutesEnd);
        examFrame->findChild<QLineEdit *>("L_Teachers")->setText(QString::fromStdString(exam->getResponsible()));
        for (auto teacher : ENSIA.getTeachers())
        {
            if (teacher == nullptr)
            {
                cout << "Teachers is null" << endl;
                break;
            }
            for (auto teachercourse : teacher->getCourses())
            {
                if (teachercourse == nullptr)
                {
                    cout << "Teacher course is null" << endl;
                    break;
                }

                if (teachercourse == exam->getModule())
                {

                    *teachers += " " + teacher->getName();
                    break;
                }
                else
                {
                    cout << "Teacher course not found" << endl;
                }
            }
        }

        // Add the CourseFrame to the layout of widget
        widget->layout()->addWidget(examFrame);

        // Add the widget to the scroll area
        ui->scrollExams->layout()->addWidget(widget);
        cout << "Exams loaded successfully" << endl;

        delete[] groups;
        delete teachers;
    }
};
void MainWindow::loadStudents()
{
    // Clear the layout of scrollCourses
    QLayout *layout = ui->scrollStudents->layout();

    // Check if the layout is not null, to remove all items inside
    if (layout != nullptr)
    {
        // Remove all items from the layout
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr)
        {
            // Remove the widget from the layout item
            delete item->widget();
            // Delete the layout item
            delete item;
        }
    }

    cout << "Loading students..." << endl;
    for (auto student : ENSIA.getStudents())
    {
        cout << "students found" << endl;
        if (student == nullptr)
        {
            cout << "students is null" << endl;
            break;
        }

        // Create a new QWidget
        QWidget *widget = new QWidget();

        // Set the layout for the new QWidget
        widget->setLayout(new QVBoxLayout());

        // Create a new teacherFrame
        studentframe *student_Frame = new studentframe();
        connect(student_Frame, &studentframe::trigger, this, &MainWindow::loadStudents);

        int *section = new int;

        // 3 Sections : 1-4 / 5-8 / 9-12

        if (student->getGroup() < 5 && student->getGroup() > 0)
        {
            *section = 1;
        }
        else if (student->getGroup() < 9 && student->getGroup() > 4)
        {
            *section = 2;
        }
        else
        {
            *section = 3;
        }

        student_Frame->findChild<QLineEdit *>("L_Name")->setText(QString::fromStdString(student->getName()));
        student_Frame->findChild<QLineEdit *>("L_ID")->setText(QString::number(student->getId()));
        student_Frame->findChild<QLineEdit *>("L_Email")->setText(QString::fromStdString(student->getEmail()));
        student_Frame->findChild<QLineEdit *>("L_Phone")->setText(QString::fromStdString(student->getPhone()));
        student_Frame->findChild<QLineEdit *>("L_Address")->setText(QString::fromStdString(student->getAddress()));
        student_Frame->findChild<QLineEdit *>("L_BD")->setText(QString::number(student->getBirthDate().getDay()) + "/" + QString::number(student->getBirthDate().getMonth()) + "/" + QString::number(student->getBirthDate().getYear()));
        student_Frame->findChild<QLineEdit *>("L_Group")->setText(QString::number(student->getGroup()));
        student_Frame->findChild<QLineEdit *>("L_Year")->setText(QString::number(student->getYear()));
        student_Frame->findChild<QLineEdit *>("L_Section")->setText(QString::number(*section));

        delete section;

        widget->layout()->addWidget(student_Frame);

        // Add the widget to the scroll area
        ui->scrollStudents->layout()->addWidget(widget);
        cout << "Students loaded successfully" << endl;
    }
};

// Adding Frames

void MainWindow::on_Add_courses_btn_clicked()
{

    Add_Courses add_courses;
    add_courses.setModal(true);
    add_courses.exec();
    loadCourses();
}
void MainWindow::on_Add_Teachers_btn_clicked()
{
    add_teachers add_teachers;
    add_teachers.setModal(true);
    add_teachers.exec();
    loadTeachers();
}
void MainWindow::on_Add_Exams_btn_clicked()
{
    add_exams add_exams;
    add_exams.setModal(true);
    add_exams.exec();
    loadExams();
}
void MainWindow::on_Add_Students_btn_clicked()
{
    add_students add_students;
    add_students.setModal(true);
    add_students.exec();
    loadStudents();
}

// Searching for Frames

void MainWindow::search(string Nsearch = "")
{
    // searches for that name in all of the data : ENSIA.getStudents() , ENSIA.getTeachers() , ENSIA.getCourses() , ENSIA.getExams()
    // if found , it will display the data of that person in the search page

    // Clear the layout of scrollStudents_2
    QLayout *layout = ui->scrollSearch->layout();

    // Check if the layout is not null, to remove all items inside
    if (layout != nullptr)
    {
        // Remove all items from the layout
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr)
        {
            // Remove the widget from the layout item
            delete item->widget();
            // Delete the layout item
            delete item;
        }
    }

    // Searching For Students :

    for (auto student : ENSIA.getStudents())
    {
        cout << "students found" << endl;
        if (student == nullptr)
        {
            break;
        }

        if (student->getName() != Nsearch)
        {
            continue;
        }
        // Create a new QWidget
        QWidget *widget = new QWidget();

        // Set the layout for the new QWidget
        widget->setLayout(new QVBoxLayout());

        // Create a new teacherFrame
        studentframe *student_Frame = new studentframe();
        connect(student_Frame, &studentframe::trigger, this, [this, Nsearch]()
                { MainWindow::search(Nsearch); });

        int *section = new int;

        // 3 Sections : 1-4 / 5-8 / 9-12

        if (student->getGroup() < 5 && student->getGroup() > 0)
        {
            *section = 1;
        }
        else if (student->getGroup() < 9 && student->getGroup() > 4)
        {
            *section = 2;
        }
        else
        {
            *section = 3;
        }

        student_Frame->findChild<QLineEdit *>("L_Name")->setText(QString::fromStdString(student->getName()));
        student_Frame->findChild<QLineEdit *>("L_ID")->setText(QString::number(student->getId()));
        student_Frame->findChild<QLineEdit *>("L_Email")->setText(QString::fromStdString(student->getEmail()));
        student_Frame->findChild<QLineEdit *>("L_Phone")->setText(QString::fromStdString(student->getPhone()));
        student_Frame->findChild<QLineEdit *>("L_Address")->setText(QString::fromStdString(student->getAddress()));
        student_Frame->findChild<QLineEdit *>("L_BD")->setText(QString::number(student->getBirthDate().getDay()) + "/" + QString::number(student->getBirthDate().getMonth()) + "/" + QString::number(student->getBirthDate().getYear()));
        student_Frame->findChild<QLineEdit *>("L_Group")->setText(QString::number(student->getGroup()));
        student_Frame->findChild<QLineEdit *>("L_Year")->setText(QString::number(student->getYear()));
        student_Frame->findChild<QLineEdit *>("L_Section")->setText(QString::number(*section));
        delete section;

        widget->layout()->addWidget(student_Frame);

        // Add the widget to the scroll area
        ui->scrollSearch->layout()->addWidget(widget);
    }

    // Searching For Exams :

    for (auto exam : ENSIA.getExams())
    {
        if (exam == nullptr)
        {
            break;
        }

        if (exam->getModule()->getName() != Nsearch)
        {
            continue;
        }

        string *groups = new string[12 + 12];
        string *teachers = new string;

        for (int i = 0; i < 12; i++)
        {

            if (exam->getModule() == nullptr)
            {
                break;
            }

            if (exam->getModule()->getGroups()[i] == true)
            {
                *groups += std::to_string(i) + " ";
            }
        }

        // Create a new QWidget
        QWidget *widget = new QWidget();

        // Set the layout for the new QWidget
        widget->setLayout(new QVBoxLayout());

        // Create a new examframe
        ExamFrame *examFrame = new ExamFrame();
        connect(examFrame, &ExamFrame::trigger, this, [this, Nsearch]()
                { MainWindow::search(Nsearch); });

        examFrame->findChild<QLineEdit *>("L_name")->setText(QString::fromStdString(exam->getModule()->getName()));
        examFrame->findChild<QLineEdit *>("L_ID")->setText(QString::number(exam->getid()));
        examFrame->findChild<QLineEdit *>("L_Groups")->setText(QString::fromStdString(*groups));

        for (auto teacher : ENSIA.getTeachers())
        {
            if (teacher == nullptr)
            {
                cout << "Teachers is null" << endl;
                break;
            }
            for (auto teachercourse : teacher->getCourses())
            {
                if (teachercourse == nullptr)
                {
                    cout << "Teacher course is null" << endl;
                    break;
                }

                if (teachercourse == exam->getModule())
                {

                    *teachers += " " + teacher->getName();
                    break;
                }
                else
                {
                    cout << "Teacher course not found" << endl;
                }
            }
        }

        // Add the CourseFrame to the layout of widget
        widget->layout()->addWidget(examFrame);

        // Add the widget to the scroll area
        ui->scrollSearch->layout()->addWidget(widget);
        cout << "Exams loaded successfully" << endl;

        delete[] groups;
        delete teachers;
    }

    // Searching For Teachers :

    for (auto teacher : ENSIA.getTeachers())
    {
        if (teacher == nullptr)
        {
            cout << "Teacher is null" << endl;
            break;
        }

        if (teacher->getName() != Nsearch)
        {
            continue;
        }

        // Create a new QWidget
        QWidget *widget = new QWidget();

        // Set the layout for the new QWidget
        widget->setLayout(new QVBoxLayout());

        // Create a new teacherFrame
        teacherframe *teacher_Frame = new teacherframe();
        connect(teacher_Frame, &teacherframe::trigger, this, [this, Nsearch]()
                { MainWindow::search(Nsearch); });

        teacher_Frame->findChild<QLineEdit *>("L_Name")->setText(QString::fromStdString(teacher->getName()));
        teacher_Frame->findChild<QLineEdit *>("L_ID")->setText(QString::number(teacher->getId()));
        teacher_Frame->findChild<QLineEdit *>("L_Email")->setText(QString::fromStdString(teacher->getEmail()));
        teacher_Frame->findChild<QLineEdit *>("L_Phone")->setText(QString::fromStdString(teacher->getPhone()));
        teacher_Frame->findChild<QLineEdit *>("L_Address")->setText(QString::fromStdString(teacher->getAddress()));
        teacher_Frame->findChild<QLineEdit *>("L_BD")->setText(QString::number(teacher->getBirthDate().getDay()) + "/" + QString::number(teacher->getBirthDate().getMonth()) + "/" + QString::number(teacher->getBirthDate().getYear()));

        widget->layout()->addWidget(teacher_Frame);
        ui->scrollSearch->layout()->addWidget(widget);
    }

    // Searching For Courses :

    for (auto course : ENSIA.getCourses())
    {
        // cout << "Course found" << endl;
        if (course == nullptr)
        {
            // cout << "Course is null" << endl;
            break;
        }

        if (course->getName() != Nsearch)
        {
            continue;
        }

        string *groups = new string[12 + 12];
        string *teachers = new string;

        for (int i = 0; i < 12; i++)
        {
            if (course->getGroups()[i] == true)
            {
                *groups += std::to_string(i) + " ";
            }
        }

        // Create a new QWidget
        QWidget *widget = new QWidget();

        // Set the layout for the new QWidget
        widget->setLayout(new QVBoxLayout());

        // Create a new courseframe
        CourseFrame *courseFrame = new CourseFrame();
        connect(courseFrame, &CourseFrame::trigger, this, [this, Nsearch]()
                { MainWindow::search(Nsearch); });

        courseFrame->findChild<QLineEdit *>("L_name")->setText(QString::fromStdString(course->getName()));
        courseFrame->findChild<QLineEdit *>("L_ID")->setText(QString::number(course->getId()));

        for (auto teacher : ENSIA.getTeachers())
        {
            if (teacher == nullptr)
            {
                break;
            }
            for (auto teachercourse : teacher->getCourses())
            {
                if (teachercourse == nullptr)
                {
                    break;
                }

                if (teachercourse == course)
                {

                    if (!teachers->empty())
                    {
                        *teachers += " , ";
                    }
                    *teachers += teacher->getName();
                    cout << "Teacher name: " << teacher->getName() << endl;
                    break;
                }
            }
        }

        if (courseFrame != nullptr && teachers != nullptr)
        {
            QLineEdit *teacherLineEdit = courseFrame->findChild<QLineEdit *>("L_Teachers");
            if (teacherLineEdit != nullptr)
            {
                teacherLineEdit->setText(QString::fromStdString(*teachers));
            }
            else
            {
                cout << "No QLineEdit named 'L_Teachers' found in courseFrame" << endl;
            }
        }

        else
        {
            if (courseFrame == nullptr)
            {
                cout << "courseFrame is nullptr" << endl;
            }
            if (teachers == nullptr)
            {
                cout << "teachers is nullptr" << endl;
            }
        }

        // Add the CourseFrame to the layout of widget
        widget->layout()->addWidget(courseFrame);

        // Add the widget to the scroll area
        ui->scrollSearch->layout()->addWidget(widget);
        // cout << "Course loaded successfully" << endl;
    }
}
void MainWindow::on_search_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    cout << "Search Started";
    search(ui->search_input->text().toStdString());
}
