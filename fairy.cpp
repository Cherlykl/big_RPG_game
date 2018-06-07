#include "fairy.h"

void Fairy::show(QPainter *painter)
{
     painter->drawPixmap(this->_pos_x,this->_pos_y,54,80, QPixmap("://images/fairy.png"));
}
