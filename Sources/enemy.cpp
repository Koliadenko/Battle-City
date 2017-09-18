#include "Enemy.h"
#include <QTimer>
#include <QKeyEvent>
#include "Bullet.h"
#include <stdlib.h>
#include <QGraphicsScene>
#include "Game.h"
#include "Wall.h"
#include "Field.h"
#include <QDebug>

extern Game * game;


Enemy::Enemy(int pos){
    direction = 0;
    setPixmap(QPixmap(":/images/Enemy.png"));
    setTransformOriginPoint(25,25);
    if (pos == 0){
        setPos(50,25);
    }
    else if (pos == 1){
        setPos(350,25);
    }
    else if (pos == 2){
        setPos(650,25);
    }
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer -> start(120);
    QTimer * timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(shout()));
    timer1 -> start(1000);
}

/*void Enemy::move(){
    direction = rand()%4;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move1()));
    timer -> start(70);


}*/

void Enemy::move(){


    if ((game -> field -> isPossibleToMove(direction,pos().x(),pos().y()))){
        if (direction==0){
            setRotation(0);
            setPos(x(),y()-10);
        }
        else if (direction==1){
            setRotation(90);
            setPos(x()+10,y());
        }
        else if (direction==2){
            setRotation(180);
            setPos(x(),y()+10);
        }
        else if (direction==3){
            setRotation(-90);
            setPos(x()-10,y());
        }
        QList <QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0; i < colliding_items.size(); i++){
            if (typeid(*colliding_items[i]) == typeid(Enemy) || typeid(*colliding_items[i]) == typeid(Player) || typeid(*colliding_items[i]) == typeid(Great_Symbol_Of_Independence)){
                if (direction==0){
                       setPos(x(),y()+10);
                }
                else if (direction==1){
                        setPos(x()-10,y());
                }
                else if (direction==2){
                        setPos(x(),y()-10);
                }
                else if (direction==3){
                        setPos(x()+10,y());
                }
                changeDir();
            }


        }
    }
    else
        changeDir();





    /*
    if (direction==0){
        if (pos().y()>25)
                setPos(x(),y()-1);
    }
    else if (direction==1){
        if (pos().x()+rect().width()<850-150)
                setPos(x()+1,y());
    }
    else if (direction==2){
        if (pos().y()+rect().height()<700-25)
                setPos(x(),y()+1);
    }
    else if (direction==3){
        if (pos().x()>50)
                setPos(x()-1,y());
    }
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); i++){
        if (typeid(*colliding_items[i]) == typeid(Enemy) || typeid(*colliding_items[i]) == typeid(Player)){
            if (direction==0){
                   setPos(x(),y()+1);
            }
            else if (direction==1){
                    setPos(x()-1,y());
            }
            else if (direction==2){
                    setPos(x(),y()-1);
            }
            else if (direction==3){
                    setPos(x()+1,y());
            }
        }


    }
    */
}

void Enemy::shout(){
    int dx,dy;
    if (direction==0){
        dx = 20;
        dy = -10;
    }
    else if (direction==1){
        dx = 50;
        dy = 20;
    }
    else if (direction==2){
        dx = 20;
        dy = 50;
    }
    else if (direction==3){
        dx = -10;
        dy = 20;
    }
    Bullet * bullet = new Bullet(direction,1);
    bullet -> setPos(x()+dx,y()+dy);
    scene() -> addItem(bullet);
}

void Enemy::changeDir(){
    int newDir = direction;
    while (newDir == direction)
        newDir = rand()%4;

    if (newDir%2 == 1 && direction%2 == 0){
        int dy = y();
        dy = (dy+12)/25*25;
        setPos(x(),dy);
    }
    else if (newDir%2 == 0 && direction%2 == 1){
        int dx = x();
        dx = (dx+12)/25*25;
        setPos(dx,y());
    }
    direction = newDir;
}

