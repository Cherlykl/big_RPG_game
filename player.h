#ifndef PLAYER_H
#define PLAYER_H
#include <QImage>
#include <QPainter>
using namespace std;

class Player
{
public:
    Player(){}
    virtual ~Player(){}

    //void show(QPainter * painter);
    void move(int direction, int steps=1);

    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}
    void setSIZE(int size) {this->SIZE=size;}
    int getPosX() const{return this->_pos_x;}
    int getPosY() const{return this->_pos_y;}
    int getSIZE() const{return this->SIZE;}


protected:
    int _pos_x, _pos_y;
    int SIZE;
};

#endif // PLAYER_H
