#include "chest.h"
#include<iostream>
Chest::Chest()
{

}

void Chest::initObj(int xx,int yy)
{
    this->_pic.load("://images/chest.png");
    this->setPosX(xx);
    this->setPosY(yy);
    this->_coverable=true;
    this->_eatable=true;
    this->record=0;
}

void Chest::show(QPainter *painter)
{
    int gSize=32;
    QPixmap pix=QPixmap::fromImage(_pic);
    painter->drawPixmap(this->_pos_x*gSize,this->_pos_y*gSize,2*gSize,2*gSize,pix);
}
