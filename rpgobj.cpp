#include "rpgobj.h"
#include <iostream>

void RPGObj::initObj(string type)
{
    //TODO 所支持的对象类型应定义为枚举
    if (type.compare("player")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("stone")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("fruit")==0){
        this->_coverable = false;
        this->_eatable = true;
    }/*
    else if (type.compare("monster")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("mud1")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("mud2")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("light")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("house")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("tree")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("garden")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("grass")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("clothes")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("vegetables")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("well")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("flower")==0){
        this->_coverable = false;
        this->_eatable = false;
    }*/
    else{
        //TODO 应由专门的错误日志文件记录
        cout<<"invalid ICON type."<<endl;
        return;
    }
    this->_icon = ICON::findICON(type);
    QImage all;
    all.load("C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\images\\TileB.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE, _icon.getSrcY()*ICON::GRID_SIZE, _icon.getWidth()*ICON::GRID_SIZE, _icon.getHeight()*ICON::GRID_SIZE));
}

void RPGObj::show(QPainter * pa){
    int gSize = ICON::GRID_SIZE;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}
