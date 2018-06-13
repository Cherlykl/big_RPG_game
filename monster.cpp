#include "monster.h"

void Monster::show(QPainter *painter)
{
    painter->drawPixmap(this->_pos_x,this->_pos_y,500,300, QPixmap("://images/monster.gif"));
}

void Monster::move(int direction, int steps)
{
    switch (direction){
        case 1:
            if(_pos_y>=100)
                this->_pos_y -= steps;
            break;
        case 2:
            if(_pos_y<800)
                this->_pos_y += steps;
            break;
        case 3:
            if(_pos_x<800)
                this->_pos_y += steps;
            break;
        case 4:
            if(_pos_x>=100)
                this->_pos_y -= steps;
            break;
    }
}
