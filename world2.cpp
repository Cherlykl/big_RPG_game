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


void World2::show(QPainter * painter, int i){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    myplayer.setSIZE(20);
    myplayer.show(painter,i);

    int j=0;
    for(j=0;j<5;j=j+1)
    {
        //enemy_fairy[j].setPosX(x1);
        //enemy_fairy[j].setPosY(y1);
        enemy_fairy[j].show(painter);
    }
    for(j=5;j<10;j=j+1)
    {
        //enemy_fairy[j].setPosX(x2);
        //enemy_fairy[j].setPosY(y2);
        enemy_fairy[j].show(painter);
    }
    for(j=10;j<15;j=j+1)
    {
        //enemy_fairy[j].setPosX(x3);
        //enemy_fairy[j].setPosY(y3);
        enemy_fairy[j].show(painter);
    }

}

void World2::handlePlayerMove(int direction, int steps){

    //int flag = 0;
    vector<RPGObj>::iterator it;

    int newX = myplayer.getPosX();
    int newY = myplayer.getPosY();
    switch (direction){
        case 1:
            if(newY>=0)
                newY -= steps*50;
            break;
        case 2:
            if(newY<900)
                newY += steps*50;
            break;
        case 3:
            if(newX>=0)
                newX -= steps*50;
            break;
        case 4:
            if(newX<1800)
                newX += steps*50;
            break;
    }
    for(it=this->_objs.begin();it!=this->_objs.end();it++)
    {
        if( newX ==(*it).getPosX()&& newY==(*it).getPosY())
        {
            //flag =1;

            if((*it).canEat())
            {
                 _objs.erase(it);
                this->myplayer.move(direction, steps);
            }

            else if((*it).canCover())
                this->myplayer.move(direction, steps);
            else
                return;
        }
    }

    //if(flag == 0 )
            this->myplayer.move(direction, steps);
}
