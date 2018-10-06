#include "graphic.h"
#include <math.h>
#include<QApplication>
graphic::graphic(QWidget *parent) : QLabel(parent)
{
    renk = qRgb(255,0,0);
    QImage ortam(600,600,QImage::Format_RGB32);
    setPixmap(QPixmap::fromImage(ortam));
    res = ortam;
}

void graphic::mousePressEvent(QMouseEvent *e)
{
    if (counter == 0 ) {
        ilkNokta = e->pos();
        counter ++;
    }else{
        sonNokta = e->pos();
        counter = 0;
        //cidDDA();
        bresenhams_algoritm();
    }
}

void graphic::cidDDA()
{
    double dx = sonNokta.x() - ilkNokta.x();
    double dy = sonNokta.y() - ilkNokta.y();
    double x_artim, y_artim;
    double adim; // dongu sayisi, formuldeki toplam Pixel sayisi anlamina geliyor
    double x, y;

    if (fabs(dx) > fabs(dy)) {
        adim = fabs(dx);
    } else {
        adim = fabs(dy);
    }

    x_artim = dx / adim;
    y_artim = dy / adim;

    x = ilkNokta.x();
    y = ilkNokta.y();

    for (int i = 0; i < adim; ++i) {
        x += x_artim; //Xn+1 = Xn + Xfark;
        y += y_artim;


        res.setPixel(round(x),round(y),qRgb(255,0,0));
        setPixmap(QPixmap::fromImage(res));
        QApplication::processEvents();

    }
}

void graphic::bresenhams_algoritm()
{

    float x1 = ilkNokta.x();
    float x2 = sonNokta.x();
    float y1 = ilkNokta.y();
    float y2 = sonNokta.y();

    const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
    if(steep)
    {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }

    if(x1 > x2)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    const float dx = x2 - x1;
    const float dy = fabs(y2 - y1);

    float error = dx / 2.0f;
    const int ystep = (y1 < y2) ? 1 : -1;
    int y = (int)y1;

    const int maxX = (int)x2;

    for(int x=(int)x1; x<maxX; x++)
    {
        if(steep)
        {
            res.setPixel(x,y,qRgb(255,0,0));
            setPixmap(QPixmap::fromImage(res));
        }else {
            res.setPixel(x,y,qRgb(255,0,0));
            setPixmap(QPixmap::fromImage(res));
        }

        error -= dy;
        if(error < 0)
        {
            y += ystep;
            error += dx;
        }
    }
}



