#include "styleheader.h"

QString styleheader::button(int a, int b, int c)
{
    return "QPushButton {"
           "background: rgb("+QString::number(a)+","+QString::number(b)+","+QString::number(c)+");"
           "border-radius: 1px;"
           "}";
}

QString styleheader::NewButtonStyle(int a, int b, int c)
{
    return "QPushButton {"
           "background: inherit;"
           "background: rgb("+QString::number(a%255)+","+QString::number(b%255)+","+QString::number(c%255)+");"
                                                                                        "border-radius: 1px;"
                                                                                        "}";
}
