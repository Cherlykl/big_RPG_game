#ifndef FINAL_PLAYER_H
#define FINAL_PLAYER_H
#include "male_player.h"
#include "female_player.h"

class Final_player:public Male_player,public Female_player
{
public:
    Final_player(){}
    void show(QPainter * painter,int i);
};

#endif // FINAL_PLAYER_H
