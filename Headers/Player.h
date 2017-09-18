#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
private:
    int direction;              // UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3
    int spawned;
};



#endif // PLAYER_H
