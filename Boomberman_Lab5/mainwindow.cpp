#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    escena = new QGraphicsScene(this);
//    escena->setSceneRect(0,0,0,0);
//    ui->graphicsView->setScene(escena);

    tiempo = new QTimer();

    set_window();
    CrearMapa(5);
    Posx=40, Posy=40;
    creacionPersonaje();
    //colisiones();

    connect(tiempo, &QTimer::timeout, this, &MainWindow::onUpdate);


}

void MainWindow::CrearMapa(int nivel)
{

    int Tablero[13][31] = {
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
        {2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2},
        {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
        {2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2},
        {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
        {2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2},
        {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
        {2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2},
        {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
        {2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2},
        {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}

    };

    int muritos = 0;
    for (int i=0; i<13; i++) {
        muritos = 0;
        for (int j=0; j<31; j++) {
            if(i<5 && j<5){ // para que al principio no se pueda poner elementos
                continue;
            }
            if(Tablero[i][j]==0){
                Tablero[i][j]=rand()%2; //generar aleatoriamente cuantos cuadritos salen
                muritos++;
            }

            if (muritos > nivel*3){ //cuantos cuadritos maximo salen por fila
                break;
            }
        }
    }

    int x, y;
    for (int i=0; i<13; i++) {
         y = 38*i;
        for (int j=0; j<31; j++) {
            x = 38*j;
            if(Tablero[i][j] != 0){
                Muros.push_back(new Obstaculo(x,y,Tablero[i][j])); //muros estan guardando
                Muros2.push_back(new Obstaculo(x,y,Tablero[i][j]));
                escena->addItem(Muros.last());
            }
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
    delete escena;
    delete principal;
}

void MainWindow::keyPressEvent(QKeyEvent *i)
{
    if ( i->key() == Qt::Key_D ){
        Posx+=5;
        principal->setPos(Posx,Posy);

        qDebug() <<"Derecha"<<endl;
    }
    if ( i->key() == Qt::Key_A ){
        Posx-=5;
        principal->setPos(Posx,Posy);

        qDebug() <<"Izquierda"<<endl;
    }
    if ( i->key() == Qt::Key_S ){
        Posy+=5;
        principal->setPos(Posx,Posy);

        qDebug() <<"Abajo"<<endl;
    }
    if ( i->key() == Qt::Key_W ){
        Posy-=5;
        principal->setPos(Posx,Posy);
        qDebug() <<"Arriba"<<endl;
    }

}

void MainWindow::creacionPersonaje()
{

    principal = new Personaje(":/new/images/Imagenes/Personaje.png",30,30);
    principal->setPos(Posx,Posy);
    escena->addItem(principal);
}

void MainWindow::set_window()
{
    escena = new QGraphicsScene;
    ui->graphicsView->setGeometry(0,0,tam*col+2,tam*(fil+2)+2);
    escena->setSceneRect(0,-70,tam*col,tam*(fil+2));
    ui->graphicsView->setScene(escena);
    setFixedSize(tam*col+2,tam*(fil+2)+2);
    setWindowTitle("Bomberman");
}

//bool MainWindow::colisiones()
//{
//    bool bandera=false;
//    QList<QGraphicsItem *> colision = escena->collidingItems(principal);
//    if(principal->getPosY()==Muros){
//        bandera=true;
//    }
//    return bandera;
//}

void MainWindow::onUpdate()
{
    escena->advance();
    QList<QGraphicsItem *> colisiones = escena->collidingItems(principal);
    if(!colisiones.isEmpty()){
        Personaje *item = dynamic_cast<Personaje *>(colisiones[0]);
        if(item)
            escena->removeItem(item);

        Obstaculo *muros = dynamic_cast<Obstaculo *>(colisiones[0]);
        if(muros){
            escena->removeItem(muros);
            //personaje->setVx(0);
           //personaje->setVy(0);
        }
    }
}


/*
bool MainWindow::colisiones(){
    bool colision=true;
   QVector<Obstaculo *>::Iterator it;
    for(it=Muros.begin();it!=Muros.end();it++){
        if(principal->getPosx()==Muros){
            colision=false;
        }
    }

    return colision;
}*/


































