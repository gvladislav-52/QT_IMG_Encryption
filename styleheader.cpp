#include "styleheader.h"

QString styleheader::button(int a, int b, int c)
{
    return "QPushButton {"
           "background: rgb("+QString::number(a)+","+QString::number(b)+","+QString::number(c)+");"
           "border-radius: 1px;"
           "}";
}
