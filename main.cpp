#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/icon/icon.ico"));

    QFile style_file("://style.qss");
    if (style_file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream style_stream(&style_file);
        a.setStyleSheet(style_stream.readAll());
        style_file.close();
    }
    QLabel *label = new QLabel;
    QPixmap pixmap("://");
    label->setPixmap(pixmap);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(10);
    effect->setXOffset(5);
    effect->setYOffset(5);

    label->setGraphicsEffect(effect);

    ENSIA.setCourses(Courses::load());
    ENSIA.setExams(Exams::load());
    ENSIA.setTeachers(Teachers::load());
    ENSIA.setStudents(Students::load());

    login h;
    h.setWindowTitle("Login");

    if (h.exec() == QDialog::Rejected)
        return 0;

    string *Susername = new string(h.username);
    string *Spassword = new string(h.password);
    string *Semail = new string("admin@gmail.com");
    string *Sphone = new string("0123456789");
    string *Sproffession = new string(h.job);

    QString userInfoHtml = QString(
                               "<head/>"
                               "<html>"
                               "<body>"
                               "<h1 align=\"center\" style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                               "<span style=\" font-size:xx-large; font-weight:700;\">User Information</span>"
                               "</h1>"
                               "<p align=\"center\"><span>Username: %1</span></p>"
                               "<p align=\"center\"><span>Email: %2</span></p>"
                               "<p align=\"center\"><span>Phone: %3</span></p>"
                               "<p align=\"center\"><span>Profession: %4</span></p>"
                               "<p align=\"center\"><span>Password: %5</span></p>"
                               "</body>"
                               "</html>")
                               .arg(QString::fromStdString(*Susername), QString::fromStdString(*Semail), QString::fromStdString(*Sphone), QString::fromStdString(*Sproffession), QString(QString::fromStdString(*Spassword).length(), '*'));

    MainWindow w;
    w.setWindowTitle("Academia Plus©");


    if (h.job == "student")
    {
        QPixmap teacherImage("://icon/studentuser.png");
        teacherImage = teacherImage.scaled(w.ui->userBig->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        w.ui->userBig->setPixmap(teacherImage);
    }
    else
    {
        QPixmap studentImage("://icon/teacheruser.png");
        studentImage = studentImage.scaled(w.ui->userBig->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        w.ui->userBig->setPixmap(studentImage);
    }

    w.ui->userInfo->setText(userInfoHtml);
    w.show();

    return a.exec();

    return 0;
}
