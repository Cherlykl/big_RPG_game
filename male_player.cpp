#include "male_player.h"
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

void Male_player::show(QPainter * painter, int i)
{
    switch (this->getTurn()) {
    case 1:
        switch (i) {
        case 0:
            painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pw_stand.png"));
            break;
        case 1:
            painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pw_run1.png"));
            break;
        case 2:
            painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pw_run2.png"));
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (i) {
        case 0:
            painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/ps_stand.png"));
            break;
        case 1:
            painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/ps_run1.png"));
            break;
        case 2:
            painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/ps_run2.png"));
            break;
        default:
            break;
        }
        break;
    case 3:
        switch (i) {
        case 0:
            painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pa_stand.png"));
            break;
        case 1:
            painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pa_run1.png"));
            break;
        case 2:
            painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pa_run2.png"));
            break;
        default:
            break;
        }
        break;
    case 4:
        switch (i) {
        case 0:
            painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pd_stand.png"));
            break;
        case 1:
            painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pd_run1.png"));
            break;
        case 2:
            painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pd_run2.png"));
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void Male_player::show_handskill(QPainter *painter, int i)
{
    switch (i) {
    case 0:
        painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pd_stand.png"));
        break;
    case 1:
        painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pl_fight.png"));
        break;
    case 2:
        painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pr_fight.png"));
        break;
    default:
        break;
    }
}
/*
void Male_player::propertyskill()
{
    if (this->haveproperty.compare("神行靴")==0)
    {
        this->setSpeed(200);
    }
    else if (this->haveproperty.compare("血灵丹")==0)
    {
        this->addblood(10);
    }
}
*/
