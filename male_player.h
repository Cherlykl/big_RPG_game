#ifndef MALE_PLAYER_H
#define MALE_PLAYER_H
#include <QImage>
#include <QPainter>
#include "player.h"
#include "skill.h"
using namespace std;

class Male_player:virtual public Player
{
public:
    Male_player();
    ~Male_player(){}
    void show(QPainter * painter, int i);
    void show_handskill(QPainter * painter, int i);
    //void propertyskill();
    void show_propertyskill(QPainter * painter,int i);


private:
    Skill punch;

};

#endif // MALE_PLAYER_H
