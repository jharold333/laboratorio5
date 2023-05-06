#include "obstaculo.h"

Obstaculo::Obstaculo()
{

}


Obstaculo::Obstaculo(float x, float y, int _tipo)
{
    px=x;
    py=y;
    tipo=_tipo;
    setPos(px,py);
}


QRectF Obstaculo::boundingRect() const
{
    return QRectF(0,0,38,38);
}

void Obstaculo::advance(int phase)
{
    setPos(px,py);
}

float Obstaculo::getPx() const
{
    return px;
}

void Obstaculo::setPx(float value)
{
    px = value;
}

float Obstaculo::getPy() const
{
    return py;
}

void Obstaculo::setPy(float value)
{
    py = value;
}

void Obstaculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (tipo == 1){
        //painter->setBrush(Qt::yellow);

        QPixmap pixmap(":/new/images/Imagenes/Muro romplible.png");
        painter->drawPixmap(0,0,38,38,pixmap);
        //setScale(2);
    }else if(tipo == 2){
        QPixmap pixmap(":/new/images/Imagenes/Muro irrompible.png");
        painter->drawPixmap(0,0,38,38,pixmap);
    }
    painter->drawRect(boundingRect());
}



















