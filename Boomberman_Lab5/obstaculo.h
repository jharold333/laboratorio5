#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QVector>
#include <QPixmap>

class Obstaculo : public QGraphicsPixmapItem, public QPixmap
{
public:
    Obstaculo();
    Obstaculo(float _px, float _py, int _tipo);


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);

    //void Obstaculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    float getPx() const;
    void setPx(float value);

    float getPy() const;
    void setPy(float value);

private:
    float px, py;
    int tipo;
    Obstaculo *figurita;
    QPixmap pxmap;
};

#endif // OBSTACULO_H
