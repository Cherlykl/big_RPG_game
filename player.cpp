#include "player.h"

//const string Player::propertyfile = "C:\\Qt\\program\\game_code\\properties.txt";

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
