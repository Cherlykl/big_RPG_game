#ifndef PLAYER_H
#define PLAYER_H
#include <QImage>
#include <QPainter>
using namespace std;

class Player
{
public:
    Player(int s=50,int b=100):Speed(s),Blood(b){}
    virtual ~Player(){}

    void move(int direction, int steps=1);

    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}
    void setSIZE(int size) {this->SIZE=size;}
    void setTurn(int turn) {this->Turn=turn;}
    void setSpeed(int speed) {this->Speed=speed;}
    void sethaveproperty(string property) {this->haveproperty = property;}

    void addblood(int num) {this->Blood += num; }
    void subblood(int num) {this->Blood -= num; }

    int getPosX() const{return this->_pos_x;}
    int getPosY() const{return this->_pos_y;}
    int getSIZE() const{return this->SIZE;}
    int getTurn() const{return this->Turn;}
    int getBlood() const{return this->Blood;}
    int getAttackvalue() const{return this->Attack_value;}
    //string getpropertyfile() const{return this->propertyfile;}
    int getSpeed() const {return this->Speed;}

protected:
    int _pos_x, _pos_y;
    int SIZE;
    int Turn;
    string haveproperty;
    int Speed;
    int Blood ;
    int Attack_value;
    //static const string propertyfile;
};

#endif // PLAYER_H
