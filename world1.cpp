#include "world1.h"
#include <ctime>

void World1::show(QPainter * painter, int sex, int i){
        this->m_player.setPosX(700);
        this->m_player.setPosY(250);
        this->m_player.setSIZE(100);
        if (sex==0){
            if (i<25)
                painter->drawPixmap(this->m_player.getPosX(), this->m_player.getPosY(),
                      4*this->m_player.getSIZE(),4*this->m_player.getSIZE(), QPixmap("://images/ps_stand.png"));
            else if (i<50)
                painter->drawPixmap(this->m_player.getPosX(), this->m_player.getPosY(),
                      4*this->m_player.getSIZE(),4*this->m_player.getSIZE(), QPixmap("://images/pd_stand.png"));
            else if (i<75)
                painter->drawPixmap(this->m_player.getPosX(), this->m_player.getPosY(),
                      4*this->m_player.getSIZE(),4*this->m_player.getSIZE(), QPixmap("://images/pw_stand.png"));
            else
                painter->drawPixmap(this->m_player.getPosX(), this->m_player.getPosY(),
                      4*this->m_player.getSIZE(),4*this->m_player.getSIZE(), QPixmap("://images/pa_stand.png"));
        }
        else
            painter->drawPixmap(this->m_player.getPosX(), this->m_player.getPosY(),
              4*this->m_player.getSIZE(),4*this->m_player.getSIZE(), QPixmap("://images/female_player"));
}
