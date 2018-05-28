#include "world1.h"

void World1::show(QPainter * painter,int flag){
    if(flag==0)
    {
        this->m_player.setPosX(700);
        this->m_player.setPosY(250);
        this->m_player.setSIZE(100);
        this->m_player.show(painter);
    }

    else
    {
        this->f_player.setPosX(700);
        this->f_player.setPosY(250);
        this->f_player.setSIZE(100);
        this->f_player.show(painter);
    }
}

