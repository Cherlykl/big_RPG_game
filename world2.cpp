#include "world2.h"
#include "icon.h"
#include <iostream>
#include <QMessageBox>


void World2::initWorld(string mapFile)
{
    myplayer.setPosX(1);
    myplayer.setPosY(1);

    RPGObj  obj2, obj3;

    obj2.initObj("stone");
    obj2.setPosX(15);
    obj2.setPosY(17);

    obj3.initObj("fruit");
    obj3.setPosX(23);
    obj3.setPosY(4);

    //this->_objs.push_back(obj1);
    this->_objs.push_back(obj2);
    this->_objs.push_back(obj3);

}

void World2::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }

    myplayer.setSIZE(20);
    myplayer.show(painter);
}

void World2::handlePlayerMove(int direction, int steps){

    int flag1=0,flag2=0,flag3=0,flag4=0;
    vector<RPGObj>::iterator it;


    if(direction==1)
    {
        for(it=this->_objs.begin();it!=this->_objs.end();it++)
        {
            if( myplayer.getPosX()==(*it).getPosX()&& myplayer.getPosY()+1-steps==(*it).getPosY())
            {
                flag1=1;
                if((*it).canCover())
                        this->myplayer.move(direction, steps);

                if((*it).canEat())
                {
                   _objs.erase(it);
                   this->myplayer.move(direction, steps);
                }
            }
        }
        if(flag1==0)
                this->myplayer.move(direction, steps);
    }
    if(direction==2)
    {
        for(it=this->_objs.begin();it!=this->_objs.end();it++)
        {
            if( myplayer.getPosX()==(*it).getPosX()&& myplayer.getPosY()+1+steps==(*it).getPosY())
            {
                flag2=1;
                if((*it).canCover())
                        this->myplayer.move(direction, steps);
                if((*it).canEat())
                {
                   _objs.erase(it);
                       this->myplayer.move(direction, steps);
                }
            }
        }
        if(flag2==0)
                this->myplayer.move(direction, steps);
    }
    if(direction==3)
    {
        for(it=this->_objs.begin();it!=this->_objs.end();it++)
        {
            if( myplayer.getPosX()-steps==(*it).getPosX()&& myplayer.getPosY()+1==(*it).getPosY())
            {
                flag3=1;
                if((*it).canCover())
                        this->myplayer.move(direction, steps);
                if((*it).canEat())
                {
                   _objs.erase(it);
                   this->myplayer.move(direction, steps);
                }
            }
        }
        if(flag3==0)
                this->myplayer.move(direction, steps);
    }
    if(direction==4)
    {
        for(it=this->_objs.begin();it!=this->_objs.end();it++)
        {
            if( myplayer.getPosX()+steps==(*it).getPosX()&& myplayer.getPosY()+1==(*it).getPosY())
            {
                flag4=1;
                if((*it).canCover())
                        this->myplayer.move(direction, steps);
                if((*it).canEat())
                {
                   _objs.erase(it);
                       this->myplayer.move(direction, steps);
                }
            }
        }
        if(flag4==0)
                this->myplayer.move(direction, steps);
    }
}
