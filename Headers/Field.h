#ifndef FIELD_H
#define FIELD_H

#include <QGraphicsRectItem>

class Field: public QGraphicsRectItem{
public:
    Field();
    bool isPossibleToMove(int,int,int);
    void setField();
    void showField();
private:
    void cetRect(int,int); //sets 25x25 rect in given pos
    bool wallMatrix[26][26];
};

#endif // FIELD_H
