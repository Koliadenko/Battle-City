#include "Health.h"
#include <QFont>
#include "Game.h"

extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 5;

    // draw the text
    setPlainText(QString("     Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    if (health == 0)
        delete(game);
    setPlainText(QString("     Health: ") + QString::number(health)); // Health: 2
}

int Health::getHealth(){
    return health;
}
