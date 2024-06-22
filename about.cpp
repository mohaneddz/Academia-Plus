#include "about.h"
#include "ui_about.h"
#include <QGraphicsDropShadowEffect>
#include <QApplication>

About::About(QDialog *parent)
    : QDialog(parent), ui(new Ui::About)
{
    ui->setupUi(this);

    QPixmap pixmap("://icon/information.png");
    pixmap = pixmap.scaled(ui->picture->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(10);
    effect->setXOffset(5);
    effect->setYOffset(5);

    ui->picture->setPixmap(pixmap);
    ui->picture->setGraphicsEffect(effect);
    ui->Text->setGraphicsEffect(effect);

    ui->picture->setAlignment(Qt::AlignCenter);

    // we will use HTML to display the information
    // couple thanks words, and other stuff
    QString t = QString(
        "<head/>"
        "<html>"
        "<body>"
        "<h1 align=\"center\" style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
        "<span style=\" font-size:xx-large; font-weight:700;\">About</span>"
        "</h1>"
        "<p align=\"center\"><span>Thank you for using our application</span></p>"
        "<p align=\"center\"><span>This Program was built upon 20+ days of consistant Hardwork</span></p>"
        "<p align=\"center\"><span>We hope you liked it</span></p>"
        "<p align=\"center\"><span>-For more context check the readme file-</span></p>"
        "<p align=\"center\"><span>Developed by: </span></p>"
        "<p align=\"center\"><span>Manaa Mohaned</span></p>"

        // done
        "</body>"
        "</html>");
    ui->Text->setText(t);
}

About::~About()
{
    delete ui;
}
