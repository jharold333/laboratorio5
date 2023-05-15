#include "personaje.h"

Personaje::Personaje(QObject *parent) : QObject(parent)
{

}

QRectF Personaje::boundingRect() const
{
    return QRectF(Posx,Posy,40,40);
}

void Personaje::advance(int phase)
{
    setPos(Posx,Posy);
}

Personaje::Personaje(QString name, int w , int h)
{
    setPixmap(QPixmap(name).scaled(w,h));
}

Personaje::Personaje(float _px, float _py)
{
    Posx = _px;
    Posy = _py;
}

int Personaje::getPosY() const
{
    return Posy;
}

void Personaje::setPosY(int value)
{
    Posy = value;
}

int Personaje::getPosx() const
{
    return Posx;
}

void Personaje::setPosx(int value)
{
    Posx = value;

}

/*
int Personaje::getVelocidad() const
{
    return velocidad;
}


void Personaje::setVelocidad(int newVelocidad)
{
    velocidad = newVelocidad;
}





void Personaje::arriba()
{
    Posy-=velocidad;
    setPos(Posx, Posy);
}

void Personaje::abajo()
{
    Posy+=velocidad;
    setPos(Posx, Posy);
}

void Personaje::izquierda()
{
    Posx-=velocidad;
    setPos(Posx, Posy);
}

void Personaje::derecha()
{
    Posx+=velocidad;
    setPos(Posx, Posy);
}


*/
