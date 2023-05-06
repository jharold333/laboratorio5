#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsPixmapItem>

class Personaje : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Personaje(QObject *parent = nullptr);

    QRectF boundingRect() const;
    void advance(int phase);


    Personaje(QString name, int w, int h);
    Personaje(float , float);




    int getPosx() const;
    void setPosx(int value);

    int getPosY() const;
    void setPosY(int value);

signals:

private:

        float Posx,Posy;

};

#endif // PERSONAJE_H
