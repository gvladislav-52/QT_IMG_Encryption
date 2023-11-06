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
    for(int i = 0; i < binary.size(); i++)
    {
        switch(i)
        {
        case 0:
            if(binary.at(i) == 0)
                button1[1][1]->setStyleSheet(styleheader::NewButtonStyle(arr[7].r,arr[7].g,arr[7].b-plus(arr[7])));
            else
                button1[1][1]->setStyleSheet(styleheader::NewButtonStyle(arr[7].r,arr[7].g,arr[7].b+plus(arr[7])));
            break;
        case 1:
            if(binary.at(i) == 0)
                button1[1][3]->setStyleSheet(styleheader::NewButtonStyle(arr[9].r,arr[9].g,arr[9].b-plus(arr[9])));
            else
                button1[1][3]->setStyleSheet(styleheader::NewButtonStyle(arr[9].r,arr[9].g,arr[9].b+plus(arr[9])));
            break;
        case 2:
            if(binary.at(i) == 0)
                button1[2][2]->setStyleSheet(styleheader::NewButtonStyle(arr[14].r,arr[14].g,arr[14].b-plus(arr[14])));
            else
                button1[2][2]->setStyleSheet(styleheader::NewButtonStyle(arr[14].r,arr[14].g,arr[14].b+plus(arr[14])));
            break;
        case 3:
            if(binary.at(i) == 0)
                button1[2][4]->setStyleSheet(styleheader::NewButtonStyle(arr[16].r,arr[16].g,arr[16].b-plus(arr[16])));
            else
                button1[2][4]->setStyleSheet(styleheader::NewButtonStyle(arr[16].r,arr[16].g,arr[16].b+plus(arr[16])));
            break;
        case 4:
            if(binary.at(i) == 0)
                button1[3][1]->setStyleSheet(styleheader::NewButtonStyle(arr[19].r,arr[19].g,arr[19].b-plus(arr[19])));
            else
                button1[3][1]->setStyleSheet(styleheader::NewButtonStyle(arr[19].r,arr[19].g,arr[19].b+plus(arr[19])));
            break;
        case 5:
            if(binary.at(i) == 0)
                button1[3][3]->setStyleSheet(styleheader::NewButtonStyle(arr[21].r,arr[21].g,arr[21].b-plus(arr[21])));
            else
                button1[3][3]->setStyleSheet(styleheader::NewButtonStyle(arr[21].r,arr[21].g,arr[21].b+plus(arr[21])));
            break;
        case 6:
            if(binary.at(i) == 0)
                button1[4][2]->setStyleSheet(styleheader::NewButtonStyle(arr[26].r,arr[26].g,arr[26].b-plus(arr[26])));
            else
                button1[4][2]->setStyleSheet(styleheader::NewButtonStyle(arr[26].r,arr[26].g,arr[26].b+plus(arr[26])));
            break;
        case 7:
            if(binary.at(i) == 0)
                button1[4][4]->setStyleSheet(styleheader::NewButtonStyle(arr[28].r,arr[28].g,arr[28].b-plus(arr[28])));
            else
                button1[4][4]->setStyleSheet(styleheader::NewButtonStyle(arr[28].r,arr[28].g,arr[28].b+plus(arr[28])));
            break;
        }

    }

}

void Widget::setText()
{
    QString textBuffer;
    textBuffer = lineEdit->text();
    textLineEdit = textBuffer[0].toLatin1();
    qDebug() << textLineEdit;
    charToBinary(textLineEdit);
}

void Widget::charToBinary(char c) {
    while (c > 0) {
        binary.push_front(c % 2); // добавляем бит в начало вектора
        c /= 2;
    }
    while (binary.size() < 8) {
        binary.push_front(0); // дополняем вектор нулями до 8 бит
    }
        setEncryption();
    //for(auto c: binary)
    //    qDebug() << c << " ";
}

int Widget::plus(rgb_color arr)
{
        int k = 0.15*(0.2989*arr.r+0.58662*arr.g+0.11448*arr.b);
        k = k%255;
        return k;
}




