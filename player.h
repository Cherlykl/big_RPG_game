#ifndef PLAYER_H
#define PLAYER_H
#include <QImage>
#include <QPainter>
#include "property.h"
using namespace std;

class Player
{
public:

    //change by wang
    Player(int s=32,int b=100,int a=20, int hp=200, int m=0, int c=0): Speed(s), Blood(b),  Attack_value(a), HP(hp), Money(m),Tag(c){}
    virtual ~Player(){}

    void move(int direction, int steps=1);

    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}
    void setSIZE(int size) {this->SIZE=size;}
    void setTurn(int turn) {this->Turn=turn;}
    void setSpeed(int speed) {this->Speed=speed;}
    void setTag(int i=0) {this->Tag = i;}
    void setProperty_num(int a){this->property_num=a;}
    void setBlood(int b_value) {this->Blood = b_value; }    //change_byke
    void setAttackValue(int a_v) {this->Attack_value = a_v; }

    void addblood(int num) {this->Blood += num; }

    int getPosX() const{return this->_pos_x;}
    int getPosY() const{return this->_pos_y;}
    int getSIZE() const{return this->SIZE;}
    int getTurn() const{return this->Turn;}
    int getBlood() const{return this->Blood;}
    int getAttackvalue() const{return this->Attack_value;}
    int getSpeed() const {return this->Speed;}
    int getTag(){return this->Tag;}
    int getProperty_num(){return property_num;}
    int getHP(){return this->HP;}
    void setHP(int hp){HP=hp;}
    int getMoney(){return Money;}
    void setMoney(int money){Money=money;}

    int setp_flag(int t_x, int t_y);                   //change by wang

    Property& getprop(int i)  {return this->prop[i];}

protected:
    int _pos_x, _pos_y;
    int SIZE;
    int Turn;
    int Speed;
    int Blood;
    int Attack_value;
    int HP;
    int Money;
    int Tag;
    int property_num;
    Property prop[4];
};

#endif // PLAYER_H
