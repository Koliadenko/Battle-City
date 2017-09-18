#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(int);
    void fire();
public slots:
    void move();
    void shout();
private:
    int direction, newDir;              // UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3
    void changeDir();
};


#endif // ENEMY_H
