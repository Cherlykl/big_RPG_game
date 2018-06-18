#include "male_player.h"
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

Male_player::Male_player()
{
    punch.setSize(2);
}

 //change by wang
void Male_player::show(QPainter * painter, int i)
{
    int t = this->getTurn();
    if ((t>5)&&(t<10)) t=6;
    switch (t) {
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
    case 6:
        painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pd_stand.png"));
        break;
    case 10:
        switch (i) {
        case 0:
            painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pd_stand.png"));
            break;
        case 1:
            painter->drawPixmap(this->_pos_x,this->_pos_y+80,5*this->SIZE,3*this->SIZE, QPixmap("://images/pdied.png"));
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
    punch.setStartX(this->_pos_x-30);
    punch.setEndX(this->_pos_x-30);
    punch.setPosX();
    punch.setStartY(this->_pos_y+70);
    punch.setEndY(this->_pos_y+70);
    punch.setPosY();

    switch (i) {
    case 0:
        painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pd_stand.png"));
        break;
    case 1:
        punch.show(painter,100,2);
        painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pl_fight.png"));
        break;
    case 2:
        punch.show(painter,100,2);
        painter->drawPixmap(this->_pos_x,this->_pos_y,3*this->SIZE,4*this->SIZE, QPixmap("://images/pr_fight.png"));
        break;
    default:
        break;
    }
}

 //change by wang
void Male_player::show_propertyskill(QPainter * painter,int i)
{
    this->prop[i].setpos(this->_pos_x+160,this->_pos_y+100);
    this->prop[i].setSIZE(10);

    if (this->prop[i].getname() == Property::tot_name[0])
    {
        this->prop[i].getSkill().setSize(6);
    }
    else if (this->prop[i].getname() == Property::tot_name[1])
    {
        this->prop[i].getSkill().setSize(11);
    }
    else if (this->prop[i].getname() == Property::tot_name[2])
    {
        this->prop[i].getSkill().setSize(4);
    }
    else if (this->prop[i].getname() == Property::tot_name[3])
    {
        this->prop[i].getSkill().setSize(5);
    }
    else if (this->prop[i].getname() == Property::tot_name[4])
    {
        this->prop[i].getSkill().setSize(9);
    }
    else if (this->prop[i].getname() == Property::tot_name[5])
    {
        this->prop[i].getSkill().setSize(5);
    }
    else if (this->prop[i].getname() == Property::tot_name[6])
    {
        this->setSpeed(150);
    }
    this->prop[i].show(painter);
}


