#include "world2.h"
#include "icon.h"
#include <iostream>
#include <QMessageBox>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <QDialog>

void World2::initWorld(string mapFile)
{ 
    boss.setPosX(1500);
    boss.setPosY(600);

    enemy_fairy[1].getSkill().setSize(1);
    enemy_fairy[4].getSkill().setSize(1);
    enemy_fairy[7].getSkill().setSize(1);

    boss.getVersion1().setSize(10);
    boss.getVersion2().setSize(8);
    boss.getVersion3().setSize(3);
    boss.getVersion4().setSize(7);

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

bool Middle(int a, int b, int c)
{
    if((a<=c&&c<=b)||(b<=c&&c<=a))
        return true;
    else
        return false;
}

void World2::showcruise(QPainter * painter, int i){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    myplayer.setSIZE(30);
    if (myplayer.getTurn()!=5)
       myplayer.show(painter, i);
    else
       this->myplayer.show_handskill(painter,i);

    for(int j=0;j<9;j=j+1)
    {
        if(enemy_fairy[j].getblood_volume()>0)
            enemy_fairy[j].show(painter);
    }

    //if((abs(myplayer.getPosX()-enemy_fairy[1].getPosX())<300)&&(abs(myplayer.getPosY()-enemy_fairy[1].getPosY())<300))
        if(enemy_fairy[1].getblood_volume()>0)
            if(enemy_fairy[1].getSkill().getFlag()==0)
                enemy_fairy[1].getSkill().show(painter,300,1);
    //if((abs(myplayer.getPosX()-enemy_fairy[4].getPosX())<300)&&(abs(myplayer.getPosY()-enemy_fairy[1].getPosY())<300))
        if(enemy_fairy[4].getblood_volume()>0)
            if(enemy_fairy[4].getSkill().getFlag()==0)
                enemy_fairy[4].getSkill().show(painter,300,1);
    //if((abs(myplayer.getPosX()-enemy_fairy[7].getPosX())<300)&&(abs(myplayer.getPosY()-enemy_fairy[1].getPosY())<300))
        if(enemy_fairy[7].getblood_volume()>0)
            if(enemy_fairy[7].getSkill().getFlag()==0)
                enemy_fairy[7].getSkill().show(painter,300,1);

    int pi=0;
    while ((Property::getproperty(pi)!="\0")&&(pi<4))
    {
        this->getPlayer().getprop(pi).setname(Property::getproperty(pi));
        this->getPlayer().getprop(pi).show_pic1(painter, pi);
        pi++;
    }


}

void World2::showbattle(QPainter *painter, int i)
{
    this->myplayer.setSIZE(60);
    if (myplayer.getTurn()!=5)
    {
        myplayer.show(painter, i);
        if (myplayer.getTurn()>5)
        {
            int flag=0;
            for(int k=0;k<8;k=k+1)
            {
                if(this->myplayer.getprop(myplayer.getTurn()-6).getname() == this->myplayer.getprop(myplayer.getTurn()-6).tot_name[k])
                {
                    switch (k){
                        case 0:
                            flag = 6;
                            break;
                        case 1:
                            flag = 11;
                            break;
                        case 2:
                            flag = 4;
                            break;
                        case 3:
                            flag = 5;
                            break;
                        case 4:
                            flag = 9;
                            break;
                        case 5:
                            flag = 5;
                            break;
                    }
                }

            }

            if(this->myplayer.getprop(myplayer.getTurn()-6).getSkill().getFlag()==0)
                this->myplayer.getprop(myplayer.getTurn()-6).getSkill().show(painter,1800,flag);
            this->getPlayer().show_propertyskill(painter, myplayer.getTurn()-6);
            //this->myplayer.getprop(myplayer.getTurn()-6).getSkill().setStartX(this->myplayer.getprop(myplayer.getTurn()-6).getpx()+210);
            //this->myplayer.getprop(myplayer.getTurn()-6).getSkill().setPosX();
            //this->myplayer.getprop(myplayer.getTurn()-6).getSkill().setStartY(this->myplayer.getprop(myplayer.getTurn()-6).getpy()+100);
            //this->myplayer.getprop(myplayer.getTurn()-6).getSkill().setPosY();
            //cout<<this->myplayer.getprop(0).getSkill().getPosX()<<" "<<this->myplayer.getprop(0).getSkill().getPosY()<<endl;

        }

    }
    else
        this->myplayer.show_handskill(painter,i);
    boss.show(painter);

    if(boss.getblood_volume()>=90)
        if(boss.getVersion1().getFlag()==0)
            boss.getVersion1().show(painter,800,10);

    if((boss.getblood_volume()<90)&&(boss.getblood_volume()>=75))
        if(boss.getVersion1().getFlag()==0)
            boss.getVersion1().show(painter,800,8);

    if((boss.getblood_volume()<75)&&(boss.getblood_volume()>=50))
        if(boss.getVersion3().getFlag()==0)
            boss.getVersion3().show(painter,800,3);

    if(boss.getblood_volume()<50)
        if(boss.getVersion4().getFlag()==0)
            boss.getVersion4().show(painter,800,7);

    int pi=0;
    while((Property::getproperty(pi)!="\0")&&(pi<4))
    {
        this->getPlayer().getprop(pi).show_pic2(painter, pi);
        pi++;
     }

}

void World2::handlePlayerMove(int direction, int steps){
    this->myplayer.setTurn(direction);
    if(direction<=4)
    {
        vector<RPGObj>::iterator it;
        int xx=myplayer.getPosX();
        int yy=myplayer.getPosY();
        int newX = myplayer.getPosX();
        int newY = myplayer.getPosY();
        bool willCover=false;
        switch (direction){
            case 1:
                if(newY>=0)
                    newY -= steps*32;
                break;
            case 2:
                if(newY<900)
                    newY += steps*32;
                break;
            case 3:
                if(newX>=0)
                    newX -= steps*32;
                break;
            case 4:
                if(newX<1800)
                    newX += steps*32;
                break;
        }
        if(myplayer.getTag()==0)
        {
            for(it=this->_objs.begin();it!=this->_objs.end();it++)
            {
                if(myplayer.getHP()==0){
                    QDialog*dialog=new QDialog;
                    QMessageBox::information(dialog,"提示","您的HP值已耗完，请原地等待，恢复体力",QMessageBox::Ok);
                    this->myplayer.move(direction,0);
                    return;
                }
                if(direction==1&&Middle(xx+22,newX+44,32*(*it).getPosX())&&Middle(yy+96,newY+100,32*((*it).getPosY()+(*it).getHeight())))willCover=true;
                if(direction==2&&Middle(xx+22,newX+44,32*(*it).getPosX())&&Middle(yy+96,newY+100,32*(*it).getPosY()))willCover=true;
                if(direction==3&&Middle(xx+32,newX+22,32*((*it).getPosX()+(*it).getWidth()))&&Middle(yy+64,newY+96,32*(*it).getPosY()))willCover=true;
                if(direction==4&&Middle(xx+32,newX+42,32*(*it).getPosX())&&Middle(yy+64,newY+96,32*(*it).getPosY()))willCover=true;

                if(willCover)
                {
                    //cout<<"yes"<<endl;
                    if((*it).canEat()||(*it).canCover()){
                        //  cout<<"canerase"<<(*it).getPosX()<<""<<(*it).getPosY()<<endl;
                        _objs.erase(it);
                        myplayer.setHP(myplayer.getHP()-1);
                        myplayer.setMoney(myplayer.getMoney()+2);
                        this->myplayer.move(direction,steps);
                        return;
                    }
                    else{
                        //  cout<<"cannot move"<<(*it).getPosX()<<""<<(*it).getPosY()<<endl;
                        this->myplayer.move(direction,0);
                        return;
                    }
                }
            }
           myplayer.setHP((myplayer.getHP()-1));
        }

        myplayer.move(direction,steps);
       // cout<<myplayer.getPosX()<<" "<<myplayer.getPosY()<<endl;
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
