#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QWidget>
#include <QLabel>
#include <QImage>
#include<QMouseEvent>

class graphic : public QLabel
{
public:
    graphic(QWidget *parent);
    QRgb renk;
    QPoint ilkNokta,sonNokta;
    QImage res;
    void mousePressEvent(QMouseEvent*);
    int counter = 0;

    //algorithms
    void cidDDA();
    void bresenhams_algoritm();
};

#endif // GRAPHIC_H
