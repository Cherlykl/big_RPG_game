#include "skill.h"

void Skill::show(QPainter *painter,int range, int tag)
{
    if((fabs(end_x-start_x)<range)&&(fabs(end_y-start_y)<range))
    {
        if((fabs(_pos_x-start_x)<range)&&(fabs(_pos_y-start_y)<range))
        {
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
                    case 11:
                        painter->drawPixmap(this->_pos_x,this->_pos_y, this->length ,this->width, QPixmap("://images/property5.png"));
                        break;
                }
            }
        }
    }
}

void Skill::setFlag(int i)
{
    if(i==0)
    {
        this->flag = 0;
    }
    else
    {
        if((fabs(_pos_x-target_x)<3)&&(fabs(_pos_y-target_y)<3))
            this->flag=1;
    }

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

void Skill::setAttackValue(int i)
{
    switch(i){
        case 1:
            this->attack_value = 5;
            break;
        case 2:
            this->attack_value = 0;
            break;
        case 3:
            this->attack_value = 20;
            break;
        case 4:
            this->attack_value = 10;
            break;
        case 5:
            this->attack_value = 15;
            break;
        case 6:
            this->attack_value = 20;
            break;
        case 7:
            this->attack_value = 30;
            break;
        case 8:
            this->attack_value = 15;
            break;
        case 9:
            this->attack_value = 10;
            break;
        case 10:
            this->attack_value = 10;
            break;
        case 11:
            this->attack_value = 10;
            break;
    }
}

void Skill::setSize(int i)
{
    switch(i){
        case 1:
            this->length = 50;
            this->width = 50;
            break;
        case 2:
            this->length = 185;
            this->width = 201;
            break;
        case 3:
            this->length = 244;
            this->width = 122;
            break;
        case 4:
            this->length = 127;
            this->width = 127;
            break;
        case 5:
            this->length = 150;
            this->width = 150;
            break;
        case 6:
            this->length = 244;
            this->width = 122;
            break;
        case 7:
            this->length = 244;
            this->width = 244;
            break;
        case 8:
            this->length = 244;
            this->width = 244;
            break;
        case 9:
            this->length = 164;
            this->width = 164;
            break;
        case 10:
            this->length = 181;
            this->width = 154;
            break;
        case 11:
            this->length = 119;
            this->width = 119;
            break;
    }
}
