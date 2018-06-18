#include "female_npc.h"

Female_npc::Female_npc()
{

}
void Female_npc::show(QPainter *painter){
    painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE,QPixmap("://images/npc1.png"));
}
