  #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QVector>
#include <QList>
#include <QPainter>
#include <QFile>


#include <obstaculo.h>
#include <personaje.h>


#define fil 12.6
#define col 29.4
#define tam 40


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void CrearMapa(int);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *i);
    void creacionPersonaje();
    //int tablero[13][31]={0};

    void set_window();





    bool Colisiones();
    void onUpdate();
    bool EvaluarColision();
    bool EvaluarColision2();

    QVector<Obstaculo *> Muros;
    QList<Obstaculo *> Muros2;

public slots:





private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QString h;

    float Posx,Posy;




    Personaje *principal;

    QTimer *tiempo;








};
#endif // MAINWINDOW_H





