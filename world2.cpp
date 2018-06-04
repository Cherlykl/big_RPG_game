#include "world2.h"
#include "icon.h"
#include <iostream>
#include <QMessageBox>
#include <cstring>
#include <stdio.h>
#include <fstream>


void World2::initWorld(string mapFile)
{
   // myplayer.setPosX(1);
    //myplayer.setPosY(1);

    string match_name;
    int posx,posy;
    RPGObj  obj;
    ifstream infile(mapFile);
    if(!infile.is_open())
        cout<<"fail to open the file"<<endl;
    while(!infile.eof())
    {
       infile>>match_name>>posx>>posy;
       if(match_name=="finalplayer")
       {
           myplayer.setPosX(posx);
           myplayer.setPosY(posy);
       }
       obj.initObj(match_name);
       obj.setPosX(posx);
       obj.setPosY(posy);
       this->_objs.push_back(obj);
       infile.get();
       if(infile.peek()=='\n') break;
    }
    infile.close();
}

void World2::rebuildWorld()
{
    ofstream rebuildfile("C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\rebuilt_map.txt");
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        rebuildfile<<(*it).getObjType()<<" "<<(*it).getPosX()<<" "<<(*it).getPosY()<<endl;
    }
    rebuildfile<<"finalplayer"<<" "<<myplayer.getPosX()<<" "<<myplayer.getPosY()<<endl;
    rebuildfile.close();

    ofstream determinefile("C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\determine.txt");
    int flag=1;
    determinefile<<flag<<endl;
    determinefile.close();
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
