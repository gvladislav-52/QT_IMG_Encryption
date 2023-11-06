#include "widget.h"
#include "ui_widget.h"
#include <iostream>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setStyle();
    setMatrix();
    setEncryption();
    QObject::connect(but,SIGNAL(clicked()),this,SLOT(setText()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setMatrix()
{
    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    // Левая часть с QGridLayout
    QGridLayout *gridLayout = new QGridLayout();
    int k = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            button[i][j] = new QPushButton();
            button[i][j]->setStyleSheet(styleheader::button(arr[k].r,arr[k].g,arr[k].b));
            gridLayout->addWidget(button[i][j], i, j);
            button[i][j]->setFixedSize(100, 100);
            k++;
        }
    }
    lineEdit = new QLineEdit();
    QLabel *label = new QLabel("Label");
    but = new QPushButton("Enter");
    but->setStyleSheet("background-color: gray");
    gridLayout->addWidget(label, 7, 0);
    gridLayout->addWidget(lineEdit, 7, 1, 1, 5);
    gridLayout->addWidget(but,7,1, 10, 5);


    // Правая часть с такой же матрицей
    QGridLayout *rightGridLayout = new QGridLayout();
    int l = 0;
    for(int m = 0; m < 6; m++){
        for(int n = 0; n < 6; n++){
            button1[m][n] = new QPushButton();
            button1[m][n]->setStyleSheet(styleheader::button(arr[l].r,arr[l].g,arr[l].b));
            rightGridLayout->addWidget(button1[m][n], m, n);
            button1[m][n]->setFixedSize(100, 100);
            l++;
        }
    }

    // Добавляем оба макета в главный макет
    mainLayout->addLayout(gridLayout);
    mainLayout->addLayout(rightGridLayout);

    setLayout(mainLayout);


}

void Widget::setStyle()
{
    arr[0] = rgb_color(209,205,228);
    arr[1] = rgb_color(211, 208, 225);
    arr[2] = rgb_color(210, 206, 220);
    arr[3] = rgb_color(212, 209, 216);
    arr[4] = rgb_color(228, 226, 227);
    arr[5] = rgb_color(248, 247, 245);

    arr[6] = rgb_color(208, 204, 227);
    arr[7] = rgb_color(210, 207, 224);
    arr[8] = rgb_color(206, 202, 216);
    arr[9] = rgb_color(206, 203, 210);
    arr[10] = rgb_color(224, 222, 225);
    arr[11] = rgb_color(246, 244, 245);

    arr[12] = rgb_color(206, 202, 225);
    arr[13] = rgb_color(206, 203, 220);
    arr[14] = rgb_color(202, 199, 210);
    arr[15] = rgb_color(204, 201, 208);
    arr[16] = rgb_color(224, 222, 225);
    arr[17] = rgb_color(247, 245, 246);

    arr[18] = rgb_color(203, 200, 221);
    arr[19] = rgb_color(200, 197, 214);
    arr[20] = rgb_color(197, 194, 205);
    arr[21] = rgb_color(203, 200, 207);
    arr[22] = rgb_color(226, 224, 229);
    arr[23] = rgb_color(250, 248, 251);

    arr[24] = rgb_color(200, 197, 216);
    arr[25] = rgb_color(196, 194, 208);
    arr[26] = rgb_color(194, 191, 202);
    arr[27] = rgb_color(204, 201, 208);
    arr[28] = rgb_color(229, 227, 232);
    arr[29] = rgb_color(253, 251, 254);

    arr[30] = rgb_color(190, 187, 204);
    arr[31] = rgb_color(192, 190, 203);
    arr[32] = rgb_color(190, 187, 196);
    arr[33] = rgb_color(209, 206, 213);
    arr[34] = rgb_color(248, 246, 251);
    arr[35] = rgb_color(253, 251, 254);

}

void Widget::setEncryption()
{
    button1[1][1]->setStyleSheet(styleheader::button(arr[7].r,arr[7].g,0.15*(0.2989*arr[7].r+0.58662*arr[7].g+0.11448*arr[7].b)));
    button1[1][3]->setStyleSheet(styleheader::button(206, 203, 240));
    button1[2][2]->setStyleSheet(styleheader::button(202, 199, 240));
    button1[2][4]->setStyleSheet(styleheader::button(224, 222, 191));
    button1[3][1]->setStyleSheet(styleheader::button(200, 197, 244));
    button1[3][3]->setStyleSheet(styleheader::button(203, 200, 176));
    button1[4][2]->setStyleSheet(styleheader::button(194, 191, 173));
    button1[4][4]->setStyleSheet(styleheader::button(229, 227, 2));

}

void Widget::setText()
{
    QString textBuffer;
    textBuffer = lineEdit->text();
    textLineEdit = textBuffer[0].toLatin1();
    //qDebug() << textLineEdit;
}



