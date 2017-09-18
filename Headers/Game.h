
#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <Player.h>
#include "Score.h"
#include "Health.h"
#include "Field.h"
#include "Great_Symbol_Of_Independence.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    Field * field;
    Great_Symbol_Of_Independence * great_symbol_of_independence;

};
#endif // GAME_H
