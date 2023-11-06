#ifndef WIDGET_H
#define WIDGET_H
#include "styleheader.h"
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    struct rgb_color
    {
        int r;
        int g;
        int b;
        rgb_color(int r_a, int g_b, int b_c)
        {
            r = r_a;
            g = g_b;
            b = b_c;
        }
        rgb_color()
        {
            r = g =b = 0;
        }
    };
    char textLineEdit;
private:
    Ui::Widget *ui;
    void setMatrix();
    QPushButton * button[6][6];
    QPushButton * button1[6][6];
    void setStyle();
    rgb_color arr[36];
    void setEncryption();
    QPushButton * but;
    QLineEdit *lineEdit;
public slots:
    void setText();
};


#endif // WIDGET_H
