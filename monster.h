#ifndef MONSTER_H
#define MONSTER_H
#include "fairy.h"
#include "skill.h"
#include <QImage>
#include <QPainter>
using namespace std;

class Monster:public Fairy
{
public:
    Monster(int _b_v=100){blood_volume = _b_v;}
    ~Monster(){}
    void show(QPainter * painter);
    void setblood_volume(){ blood_volume = blood_volume-10; }
    void recoverblood_volume(){ blood_volume = blood_volume+2; }
    void move(int direction, int steps=25);

    Skill& getVersion1() { return this->version1;}
    Skill& getVersion2() { return this->version2;}
    Skill& getVersion3() { return this->version3;}
    Skill& getVersion4() { return this->version4;}

private:
    Skill version1;
    Skill version2;
    Skill version3;
    Skill version4;
};

#endif // MONSTER_H
