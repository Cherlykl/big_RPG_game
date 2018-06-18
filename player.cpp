#include "player.h"

void Player::move(int direction, int steps){
    switch (direction){
        case 1:
            if(_pos_y>=0)
                this->_pos_y -= steps*Speed;
            break;
        case 2:
            if(_pos_y<900)
                this->_pos_y += steps*Speed;
            break;
        case 3:
            if(_pos_x>=0)
                this->_pos_x -= steps*Speed;
            break;
        case 4:
            if(_pos_x<1800)
                this->_pos_x += steps*Speed;
            break;
    }
}

//change by wang
int Player::setp_flag(int t_x, int t_y)
{
    int i=0;
    if ((fabs(this->_pos_x+64-t_x)<=30)&&(fabs(this->_pos_y+64-t_y)<=30))
        i = 1;
     return i;
}
