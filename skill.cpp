#include "skill.h"

void Skill::show(QPainter *painter, int tag)
{
    if((fabs(_pos_x-start_x)<500)&&(fabs(_pos_y-start_y)<500))
    {
        switch (tag){
            case 1:
                painter->drawPixmap(this->_pos_x,this->_pos_y, this->length ,this->width, QPixmap("://images/skill1.png"));
                break;
            case 2:
                painter->drawPixmap(this->_pos_x,this->_pos_y, this->length ,this->width, QPixmap("://images/skill2.png"));
                break;
            case 3:
                painter->drawPixmap(this->_pos_x,this->_pos_y, this->length ,this->width, QPixmap("://images/skill3.png"));
                break;
            case 4:
                painter->drawPixmap(this->_pos_x,this->_pos_y, this->length ,this->width, QPixmap("://images/skill4.png"));
                break;
            case 5:
                painter->drawPixmap(this->_pos_x,this->_pos_y, this->length ,this->width, QPixmap("://images/skill5.png"));
                break;
            case 6:
                painter->drawPixmap(this->_pos_x,this->_pos_y, this->length ,this->width, QPixmap("://images/skill6.png"));
                break;
            case 7:
                painter->drawPixmap(this->_pos_x,this->_pos_y, this->length ,this->width, QPixmap("://images/skill7.png"));
                break;
            case 8:
                painter->drawPixmap(this->_pos_x,this->_pos_y, this->length ,this->width, QPixmap("://images/skill8.png"));
                break;
            case 9:
                painter->drawPixmap(this->_pos_x,this->_pos_y, this->length ,this->width, QPixmap("://images/skill9.png"));
                break;
            case 10:
                painter->drawPixmap(this->_pos_x,this->_pos_y, this->length ,this->width, QPixmap("://images/skill10.png"));
                break;
        }
    }
}

void Skill::setFlag()
{
    if((fabs(_pos_x-end_x)<3)&&(fabs(_pos_y-end_y)<3))
        this->flag=1;
    else
        this->flag=0;
}

void Skill::move()
{
   if(this->flag==0)
   {
       this->_pos_x += steps_x;
       this->_pos_y += steps_y;
   }
}

void Skill::setSteps()
{
    this->steps_x = (end_x-start_x)/5;
    this->steps_y = (end_y-start_y)/5;
}
