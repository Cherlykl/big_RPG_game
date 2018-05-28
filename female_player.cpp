#include "female_player.h"

void Female_player::show(QPainter * painter)
{
    painter->drawPixmap(this->_pos_x,this->_pos_y,6*this->SIZE,6*this->SIZE, QPixmap("://images/female_player.png"));

    //700,250,600,600
}
