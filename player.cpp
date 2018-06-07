#include "player.h"

void Player::move(int direction, int steps){
    this->Turn = direction;
    switch (direction){
        case 1:
            if(_pos_y>=0)
                this->_pos_y -= steps*50;
            break;
        case 2:
            if(_pos_y<900)
                this->_pos_y += steps*50;
            break;
        case 3:
            if(_pos_x>=0)
                this->_pos_x -= steps*50;
            break;
        case 4:
            if(_pos_x<1800)
                this->_pos_x += steps*50;
            break;
    }
}
