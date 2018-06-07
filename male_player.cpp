#include "male_player.h"

void Male_player::show(QPainter * painter, int i)
{
   /*QRect target(10.0, 20.0, 80.0, 60.0); //建立目标矩形，该区域是显示图像的目的地
    QRect source(0.0, 0.0, 70.0, 40.0); //建立源矩形，用来划定来自外部的源图像文件中需要显示的区域
    QImage image(":/images/myImage.png"); //建立QImage类对象*/

    //painter->drawPixmap(this->_pos_x,this->_pos_y,6*this->SIZE,6*this->SIZE, QPixmap("://images/male_player.png"));
                       //横坐标，纵坐标，宽，高

    switch (i) {
            case 0:
                if (this->getTurn() == 1)
                    painter->drawPixmap(this->_pos_x,this->_pos_y,4*this->SIZE,6*this->SIZE, QPixmap("://images/pw_stand.png"));
                else if (this->getTurn() == 2)
                    painter->drawPixmap(this->_pos_x,this->_pos_y,4*this->SIZE,6*this->SIZE, QPixmap("://images/ps_stand.png"));
                else if (this->getTurn() == 3)
                    painter->drawPixmap(this->_pos_x,this->_pos_y,4*this->SIZE,6*this->SIZE, QPixmap("://images/pa_stand.png"));
                else
                    painter->drawPixmap(this->_pos_x,this->_pos_y,4*this->SIZE,6*this->SIZE, QPixmap("://images/pd_stand.png"));
                break;
            case 1:
                if (this->getTurn() == 1)
                    painter->drawPixmap(this->_pos_x,this->_pos_y,4*this->SIZE,6*this->SIZE, QPixmap("://images/pw_run1.png"));
                else if (this->getTurn() == 2)
                    painter->drawPixmap(this->_pos_x,this->_pos_y,4*this->SIZE,6*this->SIZE, QPixmap("://images/ps_run1.png"));
                else if (this->getTurn() == 3)
                    painter->drawPixmap(this->_pos_x,this->_pos_y,4*this->SIZE,6*this->SIZE, QPixmap("://images/pa_run1.png"));
                else
                    painter->drawPixmap(this->_pos_x,this->_pos_y,4*this->SIZE,6*this->SIZE, QPixmap("://images/pd_run1.png"));
            case 2:
                if (this->getTurn() == 1)
                    painter->drawPixmap(this->_pos_x,this->_pos_y,4*this->SIZE,6*this->SIZE, QPixmap("://images/pw_run2.png"));
                else if (this->getTurn() == 2)
                    painter->drawPixmap(this->_pos_x,this->_pos_y,4*this->SIZE,6*this->SIZE, QPixmap("://images/ps_run2.png"));
                else if (this->getTurn() == 3)
                    painter->drawPixmap(this->_pos_x,this->_pos_y,4*this->SIZE,6*this->SIZE, QPixmap("://images/pa_run2.png"));
                else
                    painter->drawPixmap(this->_pos_x,this->_pos_y,4*this->SIZE,6*this->SIZE, QPixmap("://images/pd_run2.png"));
            default:
                break;
            }
}
