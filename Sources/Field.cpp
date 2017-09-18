#include "Field.h"
#include "Wall.h"
#include <QGraphicsScene>
#include "Game.h"
#include <stdlib.h>
#include <QDebug>



extern Game * game;

Field::Field()
{
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            wallMatrix[i][j] = 1;

}

bool Field::isPossibleToMove(int direction, int x1, int y1){
    int x = (x1-50)/25;
    int y = (y1-25)/25;
    int x2 = x*25+50;
    int y2 = y*25+25;

    if (x == 24 && direction == 1) return false;
    if (x == 0 && x1-50<10 && direction == 3) return false;
    if (y == 0 && y1-25<10 && direction == 0) return false;
    if (y == 24 && direction == 2) return false;
    if (direction%2 == 0){
        int dy;
        if (direction == 0) dy = -1;
        else dy = 2;
        if (wallMatrix[x][y+dy] && wallMatrix[x+1][y+dy]) return true;
        else if (direction == 0 && y1-y2 >= 10) return true;
        else return false;
}
    else{
        int dx;
        if (direction == 1) dx = 2;
        else dx = -1;
        if (wallMatrix[x+dx][y] && wallMatrix[x+dx][y+1]) return true;
        else if (direction == 3 && x1-x2 >= 10) return true;
        else return false;

    }
    //return true;
}

void Field::showField()
{
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            if (!wallMatrix[i][j])
                cetRect(50+i*25,25+j*25);


}

void Field::cetRect(int x, int y){          //to make them all local
    Wall * wall = new Wall();
    wall->setPos(x,y);
    scene() -> addItem(wall);
}

void Field::setField()
{
    for (int i = 2; i < 11; i++){       //upper
        wallMatrix[2][i] = 0;
        wallMatrix[3][i] = 0;
        wallMatrix[6][i] = 0;
        wallMatrix[7][i] = 0;
        wallMatrix[18][i] = 0;
        wallMatrix[19][i] = 0;
        wallMatrix[22][i] = 0;
        wallMatrix[23][i] = 0;
    }
    for (int i = 17; i < 24; i++){      //lower
        wallMatrix[2][i] = 0;
        wallMatrix[3][i] = 0;
        wallMatrix[6][i] = 0;
        wallMatrix[7][i] = 0;
        wallMatrix[18][i] = 0;
        wallMatrix[19][i] = 0;
        wallMatrix[22][i] = 0;
        wallMatrix[23][i] = 0;
    }
    for (int i = 2; i < 9; i++){        //upper mid
        wallMatrix[10][i] = 0;
        wallMatrix[11][i] = 0;
        wallMatrix[14][i] = 0;
        wallMatrix[15][i] = 0;
    }
    for (int i = 11; i < 13; i++){      //middle
        wallMatrix[10][i] = 0;
        wallMatrix[11][i] = 0;
        wallMatrix[14][i] = 0;
        wallMatrix[15][i] = 0;
    }
    for (int i = 15; i < 21; i++){      //lower mid
        wallMatrix[10][i] = 0;
        wallMatrix[11][i] = 0;
        wallMatrix[14][i] = 0;
        wallMatrix[15][i] = 0;
    }
//  small walls
    for(int i = 12; i < 14; i++)
        for(int j = 6; j < 8; j++)
            wallMatrix[i][j] = 0;

    for(int i = 12; i < 14; i++)
        for(int j = 16; j < 18; j++)
            wallMatrix[i][j] = 0;

    for(int i = 0; i < 2; i++)
        for(int j = 13; j < 15; j++)
            wallMatrix[i][j] = 0;

    for(int i = 24; i < 26; i++)
        for(int j = 13; j < 15; j++)
            wallMatrix[i][j] = 0;

    for(int i = 4; i < 8; i++)
        for(int j = 13; j < 15; j++)
            wallMatrix[i][j] = 0;
    for(int i = 18; i < 22; i++)
        for(int j = 13; j < 15; j++)
            wallMatrix[i][j] = 0;
    for(int i = 10; i < 12; i++)
        for(int j = 11; j < 13; j++)
            wallMatrix[i][j] = 0;
    for(int i = 14; i < 16; i++)
        for(int j = 11; j < 13; j++)
            wallMatrix[i][j] = 0;

}
