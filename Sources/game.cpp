
#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include "Wall.h"
#include "Field.h"
#include <QBrush>
#include "Great_Symbol_Of_Independence.h"

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,850,700); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/bg")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(850,700);

    QGraphicsRectItem *walls = new QGraphicsRectItem[4];
    //border walls
    walls[0].setRect(0,0,50,700);
    walls[1].setRect(50,675,650,25);
    walls[2].setRect(700,0,150,700);
    walls[3].setRect(50,0,650,25);

    for(int i = 0; i <= 3; i++){
        scene->addItem(&walls[i]);
    }

    field = new Field();
    field->setRect(0,0,5,5); // change the rect from 0x0 (default) to 50x50 pixels
    scene->addItem(field);
    field->setField();
    field->showField();

    great_symbol_of_independence = new Great_Symbol_Of_Independence();
    great_symbol_of_independence->setPos(325,600);
    scene->addItem(great_symbol_of_independence);

    // create the player
    player = new Player();
    //player->setRect(0,0,50,50); // change the rect from 0x0 (default) to 50x50 pixels
    //player->setPos(250,625); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    health = new Health();
    score->setPos(score->x()+700,score->y()+100);
    health->setPos(health->x()+700,health->y()+200);
    scene->addItem(score);
    scene->addItem(health);

    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(7000);
    show();
}
