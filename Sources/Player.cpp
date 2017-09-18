#include "Player.h"
#include <QKeyEvent>
#include "Bullet.h"
#include <Enemy.h>
#include <QGraphicsScene>
#include "Field.h"
#include "Game.h"

#include <QDebug>

extern Game * game;

Player::Player(){
    direction = 0;      // UP ^
    spawned = 0;

    setPixmap(QPixmap(":/images/Player.png"));
    setTransformOriginPoint(25,25);
    setPos(250,625);
}


 void Player::keyPressEvent(QKeyEvent * event){
     if (event -> key() == Qt::Key_Up){
         setRotation(0);
         if (direction%2==1){
             int dx = x();
             dx = (dx+12)/25*25;
             setPos(dx,y());
             direction = 0;
         }
         else if (direction == 2)
            direction = 0;
         else if (game -> field -> isPossibleToMove(direction,game->player->x(),game->player->y()))
            setPos(x(),y()-10);
     }
     else if (event -> key() == Qt::Key_Down){
         setRotation(180);
         if (direction%2==1){
             int dx = x();
             dx = (dx+12)/25*25;
             setPos(dx,y());
             direction = 2;
         }
         else if (direction == 0)
            direction = 2;
         else if (game -> field -> isPossibleToMove(direction,game->player->x(),game->player->y()))
            setPos(x(),y()+10);
     }
     else if (event -> key() == Qt::Key_Left){
         setRotation(-90);
         if (direction%2==0){
             int dy = y();
             dy = (dy+12)/25*25;
             setPos(x(),dy);
             direction = 3;
         }
         else if (direction == 1)
             direction = 3;
         else if (game -> field -> isPossibleToMove(direction,game->player->x(),game->player->y()))
            setPos(x()-10,y());
     }
     else if (event -> key() == Qt::Key_Right){
         setRotation(90);
         if (direction%2==0){
             int dy = y();
             dy = (dy+12)/25*25;
             setPos(x(),dy);
             direction = 1;
         }
         else if (direction == 3)
             direction = 1;
         else if (game -> field -> isPossibleToMove(direction,game->player->x(),game->player->y()))
            setPos(x()+10,y());
     }
    /*if (event -> key() == Qt::Key_Left || event -> key() == Qt::Key_Right){
        if (direction%2 == 0){                                               //change dir
            setPos(x(),(y()+12)/25*25);
            if (event -> key() == Qt::Key_Left)
                direction = 3;
            else direction = 1;
        }
        else if (game -> field -> isPossibleToMove(direction,x(),y())){     //move
                 int dx = (2-direction)*10;
                 setPos(x()+dx,y());
        }
    }
    else if (event -> key() == Qt::Key_Up || event -> key() == Qt::Key_Down){
        if (direction%2 == 1){                                               //change dir
            setPos((x()+12)/25*25,y());
            if (event -> key() == Qt::Key_Up)
                direction = 0;
            else direction = 2;
        }
        else if (game -> field -> isPossibleToMove(direction,x(),y())){     //move
                 int dy = (direction-1)*10;
                 setPos(x(),y()+dy);
        }

    }*/

    else if (event -> key() == Qt::Key_Space){
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
         Bullet * bullet = new Bullet(direction,0);
         bullet -> setPos(x()+dx,y()+dy);
         scene() -> addItem(bullet);
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
         }


     }

 }

 void Player::spawn(){
    int pos = spawned%3;         //0 = LEFT, 1 = MIDDLE, 2 = RIGHT
    if (spawned < 25){
            spawned++;
        Enemy * enemy = new Enemy(pos);
        scene() -> addItem(enemy);
    }
}


