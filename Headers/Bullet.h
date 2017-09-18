#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(int, int);
public slots:
    void move();
private:
    int direction;
    int side; // 0 - player's, 1 - enemy's
};


#endif // BULLET_H
