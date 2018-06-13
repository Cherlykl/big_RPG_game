#include "world2.h"
#include "icon.h"
#include <iostream>
#include <QMessageBox>
#include <cstring>
#include <stdio.h>
#include <fstream>

void World2::initWorld(string mapFile)
{ 
    boss.setPosX(1500);
    boss.setPosY(600);

    enemy_fairy[1].getSkill().setLength(50);
    enemy_fairy[1].getSkill().setWidth(50);
    enemy_fairy[4].getSkill().setLength(50);
    enemy_fairy[4].getSkill().setWidth(50);
    enemy_fairy[7].getSkill().setLength(50);
    enemy_fairy[7].getSkill().setWidth(50);

    string match_name;
    int posx,posy;
    int i=0;
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
       if(match_name=="fairy")
       {
           enemy_fairy[i].setPosX(posx);
           enemy_fairy[i].setPosY(posy);
           i=i+1;
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
    for(int i=0;i<15;i=i+1)
        rebuildfile<<"fairy"<<" "<<enemy_fairy[i].getPosX()<<" "<<enemy_fairy[i].getPosY()<<endl;

    rebuildfile.close();

    ofstream determinefile("C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\determine.txt");
    int flag=1;
    determinefile<<flag<<endl;
    determinefile.close();
}


void World2::showcruise(QPainter * painter, int i){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    myplayer.setSIZE(20);
    if (myplayer.getTurn()<=4)
            myplayer.show(painter, i);
    else
    {
        switch (myplayer.getTurn()) {
            case 5:
                this->myplayer.show_handskill(painter,i);
                break;
            default:
                break;
        }
    }

    for(int j=0;j<9;j=j+1)
    {
        if(enemy_fairy[j].getblood_volume()>0)
            enemy_fairy[j].show(painter);
    }

    if((abs(myplayer.getPosX()-enemy_fairy[1].getPosX())<500)&&(abs(myplayer.getPosY()-enemy_fairy[1].getPosY())<500))
        if(enemy_fairy[1].getblood_volume()>0)
            if(enemy_fairy[1].getSkill().getFlag()==0)
                enemy_fairy[1].getSkill().show(painter,8);
    if((abs(myplayer.getPosX()-enemy_fairy[4].getPosX())<500)&&(abs(myplayer.getPosY()-enemy_fairy[1].getPosY())<500))
        if(enemy_fairy[4].getblood_volume()>0)
            if(enemy_fairy[4].getSkill().getFlag()==0)
                enemy_fairy[4].getSkill().show(painter,8);
    if((abs(myplayer.getPosX()-enemy_fairy[7].getPosX())<500)&&(abs(myplayer.getPosY()-enemy_fairy[1].getPosY())<500))
        if(enemy_fairy[7].getblood_volume()>0)
            if(enemy_fairy[7].getSkill().getFlag()==0)
                enemy_fairy[7].getSkill().show(painter,8);


}

void World2::showbattle(QPainter *painter, int i)
{
    this->myplayer.setSIZE(60);
    if (myplayer.getTurn()<=4)
        myplayer.show(painter, i);
    else
    {
        switch (myplayer.getTurn()) {
        case 5:
            this->myplayer.show_handskill(painter,i);
            break;
        default:
            break;
        }
    }
    boss.show(painter);
}

void World2::handlePlayerMove(int direction, int steps){

    this->myplayer.setTurn(direction);
    if(direction<=4)
    {
        vector<RPGObj>::iterator it;

        int newX = myplayer.getPosX();
        int newY = myplayer.getPosY();
        int s = myplayer.getSpeed();
        switch (direction){
            case 1:
                if(newY>=0)
                    newY -= steps*s;
                break;
            case 2:
                if(newY<900)
                    newY += steps*s;
                break;
            case 3:
                if(newX>=0)
                    newX -= steps*s;
                break;
            case 4:
                if(newX<1800)
                    newX += steps*s;
                break;
        }
        for(it=this->_objs.begin();it!=this->_objs.end();it++)
        {
            if( newX ==(*it).getPosX()&& newY==(*it).getPosY())
            {
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
        this->myplayer.move(direction, steps);
    }

}

void World2::handleFairyMove(int direction)
{
    int i=0;
    for(i=0;i<3;i=i+1)
        enemy_fairy[i].move1( direction);
    for(i=3;i<6;i=i+1)
        enemy_fairy[i].move2( direction);
    for(i=6;i<9;i=i+1)
        enemy_fairy[i].move3( direction);
}
void World2::handleMonsterMove(int direction)
{
    boss.move(direction);
}
