#ifndef WORLD1_H
#define WORLD1_H
#include <QPainter>
#include "male_player.h"
#include "female_player.h"
class World1
{
public:
    World1(){}
    virtual ~World1(){}
    void show(QPainter * painter,int sex,int i);
private:
     Male_player m_player;
     Female_player f_player;
};

#endif // WORLD1_H
