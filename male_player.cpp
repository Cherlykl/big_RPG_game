#include "male_player.h"

void Male_player::show(QPainter * painter)
{
   /*QRect target(10.0, 20.0, 80.0, 60.0); //建立目标矩形，该区域是显示图像的目的地
    QRect source(0.0, 0.0, 70.0, 40.0); //建立源矩形，用来划定来自外部的源图像文件中需要显示的区域
    QImage image(":/images/myImage.png"); //建立QImage类对象*/

    painter->drawPixmap(this->_pos_x,this->_pos_y,6*this->SIZE,6*this->SIZE, QPixmap("://images/male_player.png"));
                       //横坐标，纵坐标，宽，高
}
