#ifndef MONSTER_H
#define MONSTER_H
#include "fairy.h"
#include <QImage>
#include <QPainter>
using namespace std;

class Monster:public Fairy
{
public:
    Monster(int _b_v=90){blood_volume = _b_v;}
    ~Monster(){}
    void show(QPainter * painter);
    void setblood_volume(){ blood_volume = blood_volume-10; }
    void recoverblood_volume(){ blood_volume = blood_volume+1; }
    void move(int direction, int steps=25);

};

#endif // MONSTER_H
