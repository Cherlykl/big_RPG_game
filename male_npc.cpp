#include "male_npc.h"

Male_npc::Male_npc()
{

}
void Male_npc::show(QPainter *painter){
    painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE,QPixmap("://images/npc0.png"));
}
