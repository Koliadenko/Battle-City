#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include "Wall.h"

#include <QDebug>

extern Game * game;

Bullet::Bullet(int dir, int sid){
    side = sid;
    direction = dir;
    setPixmap(QPixmap(":/images/Bullet.png"));
    setTransformOriginPoint(5,5);
    if (direction==1){
        setRotation(90);
    }
    else if (direction==2){
        setRotation(180);
    }
    else if (direction==3){
        setRotation(-90);
    }

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer -> start(10);
}

void Bullet::move(){
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); i++){
        if (typeid(*colliding_items[i]) == typeid(Enemy) && this->side == 0){
            game -> score -> decrease();
            scene() -> removeItem(colliding_items[i]);
            scene() -> removeItem(this);
            delete (colliding_items[i]);
            delete(this);
            return;
        }
        else if (typeid(*colliding_items[i]) == typeid(Player) && this->side == 1){
            game -> health -> decrease();
            //scene() -> removeItem(colliding_items[i]);
            scene() -> removeItem(this);
            //delete (colliding_items[i]);
            delete(this);
            return;
        }
        else if (typeid(*colliding_items[i]) == typeid(Bullet) ){
            game -> health -> decrease();
            scene() -> removeItem(colliding_items[i]);
            scene() -> removeItem(this);
            delete (colliding_items[i]);
            delete(this);
            return;
        }
        else if (typeid(*colliding_items[i]) == typeid(Wall) ){
            scene() -> removeItem(this);
            delete(this);
            return;
        }
        else if (typeid(*colliding_items[i]) == typeid(Great_Symbol_Of_Independence) ){
            game -> health -> decrease();
            scene() -> removeItem(this);
            delete(this);
            return;
        }
    }

    if (direction==0){
        setPos(x(),y()-10);
    }
    else if (direction==1){
        setPos(x()+10,y());
    }
    else if (direction==2){
        setPos(x(),y()+10);
    }
    else if (direction==3){
        setPos(x()-10,y());
    }

    if (pos().y()+pixmap().height()<25 || pos().y()>675 || pos().x()+pixmap().width()<50 || pos().x()>700){
        scene() -> removeItem(this);
        delete(this);
    }
}
