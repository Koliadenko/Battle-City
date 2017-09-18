#include "Score.h"
#include <QFont>
#include "Game.h  "

extern Game * game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 25;

    // draw the text
    setPlainText(QString("  Enemies left:  ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::decrease(){
    score--;
    if (score == 0)
        delete(game);
    setPlainText(QString("  Enemies left:  ") + QString::number(score)); // Score: 1
}

int Score::getScore(){
    return score;
}
