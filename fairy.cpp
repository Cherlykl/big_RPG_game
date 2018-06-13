#include "fairy.h"

void Fairy::show(QPainter *painter)
{
     painter->drawPixmap(this->_pos_x,this->_pos_y,30,40, QPixmap("://images/fairy.png"));
}

void Fairy::move1(int direction, int steps)
{
    switch (direction){
        case 1:
            if((_pos_x<450)&&(_pos_y<400))
            {
                this->_pos_x += steps;
                this->_pos_y += steps;
            }
            break;
        case 2:
            if((_pos_x>=200)&&(_pos_y<400))
            {
                 this->_pos_x -= steps;
                 this->_pos_y += steps;
            }
            break;
        case 3:
            if((_pos_x<450)&&(_pos_y>=200))
            {
                this->_pos_x += steps;
                this->_pos_y -= steps;
            }
            break;
        case 4:
            if((_pos_x>=200)&&(_pos_y>=200))
            {
                this->_pos_x -= steps;
                this->_pos_y -= steps;
            }
            break;
    }
}

void Fairy::move2(int direction, int steps)
{
    switch (direction){
        case 1:
            if((_pos_x<1400)&&(_pos_y>=600))
            {
                this->_pos_x += steps;
                this->_pos_y -= steps;
            }
            break;
        case 2:
            if((_pos_x>=500)&&(_pos_y<770))
            {
                 this->_pos_x -= steps;
                 this->_pos_y += steps;
            }
            break;
        case 3:
            if((_pos_x>=500)&&(_pos_y>=600))
            {
                this->_pos_x -= steps;
                this->_pos_y -= steps;
            }
            break;
        case 4:
            if((_pos_x<1400)&&(_pos_y<770))
            {
                this->_pos_x += steps;
                this->_pos_y += steps;
            }
            break;
    }
}

void Fairy::move3(int direction, int steps)
{
    switch (direction){
        case 1:
            if((_pos_x<1550)&&(_pos_y<500))
            {
                this->_pos_x += steps;
                this->_pos_y += steps;
            }
            break;
        case 2:
            if((_pos_x>=1450)&&(_pos_y<500))
            {
                 this->_pos_x -= steps;
                 this->_pos_y += steps;
            }
            break;
        case 3:
            if((_pos_x<1550)&&(_pos_y>=400))
            {
                this->_pos_x += steps;
                this->_pos_y -= steps;
            }
            break;
        case 4:
            if((_pos_x>=1450)&&(_pos_y>=400))
            {
                this->_pos_x -= steps;
                this->_pos_y -= steps;
            }
            break;
    }
}
