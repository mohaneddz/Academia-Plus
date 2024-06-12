#ifndef TOIN_COSS_H
#define TOIN_COSS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Toin_Coss;
}
QT_END_NAMESPACE

class Toin_Coss : public QMainWindow
{
    Q_OBJECT

public:
    Toin_Coss(QWidget *parent = nullptr);
    ~Toin_Coss();

private:
    Ui::Toin_Coss *ui;
};
#endif // TOIN_COSS_H
