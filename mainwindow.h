#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <Classes.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    // User Info
    // std::optional<std::tuple<QString, QString, QString, QString>> promptAndDisplayUserInfo();
    void displayReturnedUserInfo();

    // Data Loading
    void loadTeachers();
    void loadExams();
    void loadStudents();
    void loadCourses();
    Ui::MainWindow *ui;

public slots:
    // Slots
    void on_Add_courses_btn_clicked();
    void on_Add_Teachers_btn_clicked();
    void on_Add_Exams_btn_clicked();
    void on_Add_Students_btn_clicked();

    void on_home_btn_1_toggled();
    void on_home_btn_2_toggled();
    void on_courses_btn_1_toggled();
    void on_courses_btn_2_toggled();
    void on_exams_btn_1_toggled();
    void on_exams_btn_2_toggled();
    void on_teachers_btn_1_toggled();
    void on_teachers_btn_2_toggled();
    void on_students_btn_1_toggled();
    void on_students_btn_2_toggled();
    void on_search_btn_toggled();
    void on_user_btn_toggled();
    void search(string Nsearch);

private slots:

    void on_search_btn_clicked();

    void on_About_clicked();

    void on_About_btn1_clicked();

private:
    // Helper Functions
    // QString assignImage(const QString &courseName);

    // UI Elements
    QLineEdit *courseNameInput;
    QLabel *courseNameLabel;
    QStringList groupNumbersList;
    QStringList groups;
};

#endif // MAINWINDOW_H
