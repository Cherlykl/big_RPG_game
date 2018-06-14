#ifndef PLAYER_H
#define PLAYER_H
#include <QImage>
#include <QPainter>
#include "property.h"
using namespace std;

class Player
{
public:
    Player(int s=32,int b=100,int c=0):Speed(s),Blood(b),Tag(c){}
    virtual ~Player(){}

    void move(int direction, int steps=1);

    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}
    void setSIZE(int size) {this->SIZE=size;}
    void setTurn(int turn) {this->Turn=turn;}
    void setSpeed(int speed) {this->Speed=speed;}
    void sethaveproperty(string property) {this->haveproperty = property;}
    void setTag(int i=0) {this->Tag = i;}

    void addblood(int num) {this->Blood += num; }
    //void subblood(int num) {this->Blood -= num; }

    int getPosX() const{return this->_pos_x;}
    int getPosY() const{return this->_pos_y;}
    int getSIZE() const{return this->SIZE;}
    int getTurn() const{return this->Turn;}
    int getBlood() const{return this->Blood;}
    int getAttackvalue() const{return this->Attack_value;}
    //string getpropertyfile() const{return this->propertyfile;}
    int getSpeed() const {return this->Speed;}
    int getTag(){return this->Tag;}

    int getHP(){return this->HP;}
    void setHP(int hp){HP=hp;}
    int getMoney(){return Money;}
    void setMoney(int money){Money=money;}

    Property& getprop(int i)  {return this->prop[i];}

protected:
    int _pos_x, _pos_y;
    int SIZE;
    int Turn;
    string haveproperty;
    int Speed;
    int Blood ;
    int Attack_value;
    //static const string propertyfile;
    int HP;
    int Money;
    int Tag;
    Property prop[4];
};

#endif // PLAYER_H
