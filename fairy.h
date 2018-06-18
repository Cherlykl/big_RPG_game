#ifndef FAIRY_H
#define FAIRY_H
#include <QImage>
#include <QPainter>
#include "skill.h"
using namespace std;

class Fairy
{
public:
    Fairy(int _b_v=100){ blood_volume = _b_v; }
    virtual ~Fairy(){}

    void show(QPainter * painter);

    void move1(int direction, int steps=25);
    void move2(int direction, int steps=25);
    void move3(int direction, int steps=25);

    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}
    int getPosX() const{return this->_pos_x;}
    int getPosY() const{return this->_pos_y;}
    int getblood_volume() const { return this->blood_volume; }
    Skill& getSkill() { return this->fairy_skill;}
    void setblood_volume(){ blood_volume = blood_volume-20; }
    void setBlood(int b){this->blood_volume = b;}

protected:
    int _pos_x, _pos_y;
    int blood_volume;
    Skill fairy_skill;
};

#endif // FAIRY_H
