#include "world2.h"
#include "icon.h"
#include <iostream>
#include <QMessageBox>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <QDialog>
#include "mainwindow.h"

void World2::initWorld(string mapFile, int tag)
{ 
    enemy_fairy[1].getSkill().setSize(1);
    enemy_fairy[4].getSkill().setSize(1);
    enemy_fairy[7].getSkill().setSize(1);

    boss.getVersion1().setSize(10);
    boss.getVersion2().setSize(8);
    boss.getVersion3().setSize(3);
    boss.getVersion4().setSize(7);


    chest[0].setValue(-2);
    chest[1].setValue(3);
    chest[2].setValue(4);

    string match_name;
    int posx,posy;
    int value;
    int i=0,j=0,k=0;
    RPGObj  obj;
    ifstream infile(mapFile);
    if(!infile.is_open())
        cout<<"fail to open the file"<<endl;

    if(tag==0)
    {
        while(!infile.eof())
        {
           infile>>match_name>>posx>>posy;
           if(match_name=="finalplayer")
           {
               myplayer.setPosX(posx);
               myplayer.setPosY(posy);
           }
           else if(match_name=="fairy")
           {
               enemy_fairy[i].setPosX(posx);
               enemy_fairy[i].setPosY(posy);
               i=i+1;
           }
           else if(match_name=="boss")
           {
               boss.setPosX(posx);
               boss.setPosY(posy);
           }
           else if(match_name=="male_npc")
           {
               male_npc.setPosX(posx);
               male_npc.setPosY(posy);
           }
           else if(match_name=="female_npc")
           {
               female_npc.setPosX(posx);
               female_npc.setPosY(posy);
           }
           else if(match_name=="chest")
           {
               chest[k].initObj(posx,posy);
               k++;
           }
           else
           {
               obj.initObj(match_name);
               obj.setPosX(posx);
               obj.setPosY(posy);
               this->_objs.push_back(obj);
           }
           infile.get();
           if(infile.peek()=='\n') break;
        }
    }
    else
    {
        while(!infile.eof())
        {
            infile>>match_name>>value;
            if(match_name=="player_blood")//pk 右下角
                myplayer.setBlood(value);
            if(match_name=="player_HP")
                myplayer.setHP(value);
            if(match_name=="player_money")
                myplayer.setMoney(value);
            if(match_name=="player_attackvalue")//pk
                myplayer.setAttackValue(value);
            if(match_name=="fairy_blood")
            {
                enemy_fairy[j].setBlood(value);
                j=j+1;
            }
            if(match_name=="boss_blood")//血量条
                boss.setBlood(value);
            infile.get();
            if(infile.peek()=='\n') break;
        }
    }
    infile.close();
}

void World2::rebuildWorld()
{
    vector<RPGObj>::iterator it;
    ofstream rebuildfile1("C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\rebuilt_map1.txt");
    for(it=this->_objs.begin();it<this->_objs.begin()+200;it++){
            rebuildfile1<<(*it).getObjType()<<" "<<(*it).getPosX()<<" "<<(*it).getPosY()<<endl;
    }
    rebuildfile1.close();

    ofstream rebuildfile2("C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\rebuilt_map2.txt");
    for(it=this->_objs.begin()+200;it!=this->_objs.end();it++){
            rebuildfile2<<(*it).getObjType()<<" "<<(*it).getPosX()<<" "<<(*it).getPosY()<<endl;
    }
    rebuildfile2<<"finalplayer"<<" "<<myplayer.getPosX()<<" "<<myplayer.getPosY()<<endl;

    for(int i=0;i<9;i=i+1)
        rebuildfile2<<"fairy"<<" "<<enemy_fairy[i].getPosX()<<" "<<enemy_fairy[i].getPosY()<<endl;

    rebuildfile2<<"boss"<<" "<<boss.getPosX()<<" "<<boss.getPosY()<<endl;

    for(int i=0;i<3;i=i+1)
        rebuildfile2<<"chest"<<" "<<chest[i].getPosX()<<" "<<chest[i].getPosY()<<endl;

    rebuildfile2<<"male_npc "<<male_npc.getPosX()<<" "<<male_npc.getPosY()<<endl;
    rebuildfile2<<"female_npc "<<female_npc.getPosX()<<" "<<female_npc.getPosY()<<endl;

    rebuildfile2.close();

    ofstream determinefile("C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\determine.txt");
    determinefile<<1<<endl;
    determinefile<<MainWindow::getMi6()<<endl;
    determinefile<<MainWindow::getMi7()<<endl;
    determinefile.close();

    ofstream varietyfile("C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\player_fairy_monster.txt");

    varietyfile<<"player_blood"<<" "<<this->myplayer.getBlood()<<endl;
    varietyfile<<"player_HP"<<" "<<this->myplayer.getHP()<<endl;
    varietyfile<<"player_money"<<" "<<this->myplayer.getMoney()<<endl;
    varietyfile<<"player_attackvalue"<<" "<<this->myplayer.getAttackvalue()<<endl;

    for(int i=0;i<9;i=i+1)
        varietyfile<<"fairy_blood"<<" "<<enemy_fairy[i].getblood_volume()<<endl;

    varietyfile<<"boss_blood"<<" "<<boss.getblood_volume()<<endl;

    varietyfile.close();
}

//change by wang
void World2::change_blood()
{
    //player->fairy,boss--hand
    if (myplayer.setp_flag(enemy_fairy[1].getPosX(), enemy_fairy[1].getPosY()))
    {
        enemy_fairy[1].setblood_volume();
        enemy_fairy[2].setblood_volume();
        enemy_fairy[0].setblood_volume();
        if(enemy_fairy[1].getblood_volume()==0){
            myplayer.setMoney(myplayer.getMoney()+5);
            QDialog*dia=new QDialog;
            dia->resize(1000,1000);
            QMessageBox::information(dia,"提示","恭喜获得金币*5",QMessageBox::Ok);
            delete dia;
        }
    }

    if (myplayer.setp_flag(enemy_fairy[4].getPosX(), enemy_fairy[4].getPosY()))
    {
        enemy_fairy[4].setblood_volume();
        enemy_fairy[5].setblood_volume();
        enemy_fairy[3].setblood_volume();
        if(enemy_fairy[3].getblood_volume()==0)
        {
            myplayer.setMoney(myplayer.getMoney()+5);
            QDialog*dia=new QDialog;
            dia->resize(1000,1000);
            QMessageBox::information(dia,"提示","恭喜获得金币*5",QMessageBox::Ok);
            delete dia;
        }
    }
    if (myplayer.setp_flag(enemy_fairy[7].getPosX(), enemy_fairy[7].getPosY()))
    {
        enemy_fairy[7].setblood_volume();
        enemy_fairy[8].setblood_volume();
        enemy_fairy[6].setblood_volume();
        if(enemy_fairy[7].getblood_volume()==0)
        {
            myplayer.setMoney(myplayer.getMoney()+5);
            QDialog*dia=new QDialog;
            dia->resize(1000,1000);
            QMessageBox::information(dia,"提示","恭喜获得金币*5",QMessageBox::Ok);
            delete dia;
        }
    }
    if (myplayer.setp_flag(boss.getPosX(), boss.getPosY()))
        boss.setblood_volume(myplayer.getAttackvalue());

    //player->boss--skill
    if (myplayer.getprop(0).getSkill().getFlagBlood())
    {
        myplayer.getprop(0).setAttackvalue();
        boss.setblood_volume(myplayer.getprop(0).getSkill().getAttackValue());
    }
    if (myplayer.getprop(1).getSkill().getFlagBlood())
    {
        myplayer.getprop(1).setAttackvalue();
        boss.setblood_volume(myplayer.getprop(1).getSkill().getAttackValue());
    }
    if (myplayer.getprop(2).getSkill().getFlagBlood())
    {
        myplayer.getprop(2).setAttackvalue();
        boss.setblood_volume(myplayer.getprop(2).getSkill().getAttackValue());
    }
    if (myplayer.getprop(3).getSkill().getFlagBlood())
    {
        myplayer.getprop(3).setAttackvalue();
        boss.setblood_volume(myplayer.getprop(3).getSkill().getAttackValue());
    }

    //fairy,boss->player--skill
    if(enemy_fairy[1].getSkill().getFlagBlood())
    {
        enemy_fairy[1].getSkill().setAttackValue(1);
        myplayer.addblood(-enemy_fairy[1].getSkill().getAttackValue());
    }
    if(enemy_fairy[4].getSkill().getFlagBlood())
    {
        enemy_fairy[4].getSkill().setAttackValue(1);
        myplayer.addblood(-enemy_fairy[4].getSkill().getAttackValue());
    }
    if(enemy_fairy[7].getSkill().getFlagBlood())
    {
        enemy_fairy[7].getSkill().setAttackValue(1);
        myplayer.addblood(-enemy_fairy[7].getSkill().getAttackValue());
    }


    if(boss.getVersion1().getFlagBlood())
    {
        boss.getVersion1().setAttackValue(10);
        myplayer.addblood(-boss.getVersion1().getAttackValue());
        myplayer.setTurn(10);
    }
    if(boss.getVersion2().getFlagBlood())
    {
        boss.getVersion2().setAttackValue(8);
        myplayer.addblood(-boss.getVersion2().getAttackValue());
        myplayer.setTurn(10);
    }
    if(boss.getVersion3().getFlagBlood())
    {
        boss.getVersion3().setAttackValue(3);
        myplayer.addblood(-boss.getVersion3().getAttackValue());
        myplayer.setTurn(10);
    }
    if(boss.getVersion4().getFlagBlood())
    {
        boss.getVersion4().setAttackValue(7);
        myplayer.addblood(-boss.getVersion4().getAttackValue());
        myplayer.setTurn(10);
    }
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
    for(int j=0;j<3;j++)
        chest[j].show(painter);
    male_npc.show(painter);
    female_npc.show(painter);
    myplayer.setSIZE(30);
    if (myplayer.getTurn()!=5)
       myplayer.show(painter, i);
    else
       this->myplayer.show_handskill(painter,i);

    for(int j=0;j<9;j=j+1)
    {
        if(enemy_fairy[j].getblood_volume()>0)
            enemy_fairy[j].show(painter);
     //   else if(enemy_fairy[j].getblood_volume()<=0){

     //   }
    }

    //if((abs(myplayer.getPosX()-enemy_fairy[1].getPosX())<300)&&(abs(myplayer.getPosY()-enemy_fairy[1].getPosY())<300))
        if(enemy_fairy[1].getblood_volume()>0)
        {
            if(enemy_fairy[1].getSkill().getFlag()==0)
                enemy_fairy[1].getSkill().show(painter,300,1);
        }
    //if((abs(myplayer.getPosX()-enemy_fairy[4].getPosX())<300)&&(abs(myplayer.getPosY()-enemy_fairy[1].getPosY())<300))
        if(enemy_fairy[4].getblood_volume()>0)
        {
            if(enemy_fairy[4].getSkill().getFlag()==0)
                enemy_fairy[4].getSkill().show(painter,300,1);
        }
    //if((abs(myplayer.getPosX()-enemy_fairy[7].getPosX())<300)&&(abs(myplayer.getPosY()-enemy_fairy[1].getPosY())<300))
        if(enemy_fairy[7].getblood_volume()>0)
        {
            if(enemy_fairy[7].getSkill().getFlag()==0)
                enemy_fairy[7].getSkill().show(painter,300,1);
        }

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
        if ((myplayer.getTurn()>5)&&(myplayer.getTurn()<10))
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
                this->myplayer.getprop(myplayer.getTurn()-6).getSkill().show(painter,1800,flag);  //end
            this->getPlayer().show_propertyskill(painter, myplayer.getTurn()-6);
        }
    }
    else
        this->myplayer.show_handskill(painter,i);
    if(boss.getblood_volume()>0)
        boss.show(painter);

    if(boss.getblood_volume()>=90)
    {
        if(boss.getVersion1().getFlag()==0)
            boss.getVersion1().show(painter,800,10);
    }

    if((boss.getblood_volume()<90)&&(boss.getblood_volume()>=75))
    {
        if(boss.getVersion2().getFlag()==0)
            boss.getVersion2().show(painter,800,8);
    }

    if((boss.getblood_volume()<75)&&(boss.getblood_volume()>=50))
    {
        if(boss.getVersion3().getFlag()==0)
            boss.getVersion3().show(painter,800,3);
    }

    if(boss.getblood_volume()<50)
    {
        if(boss.getVersion4().getFlag()==0)
            boss.getVersion4().show(painter,800,7);
    }

    int pi=0;
    while((Property::getproperty(pi)!="\0")&&(pi<4))
    {
        myplayer.getprop(pi).show_pic2(painter, pi);
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
                    if((*it).canEat()||(*it).canCover()){
                        _objs.erase(it);
                        myplayer.setHP(myplayer.getHP()-1);
                        myplayer.setMoney(myplayer.getMoney()+2);
                        this->myplayer.move(direction,steps);
                        return;
                    }
                    else{
                        this->myplayer.move(direction,0);
                        return;
                    }
                }
            }
           myplayer.setHP((myplayer.getHP()-1));
           for(int i=0;i<3;i++){
               if(Middle(32*chest[i].getPosX(),32*chest[i].getPosX()+32,myplayer.getPosX())&&myplayer.getPosY()+96==32*chest[i].getPosY()&&chest[i].getRecord()==0){
                       chest[i].setRecord(1);
                       QDialog*dialog=new QDialog;
                       QString t1="恭喜您获得金币+";
                       QString t2="很遗憾您金币-";
                       QString s=QString::number(chest[i].getValue(),10);
                       if(chest[i].getValue()<0)
                           s=t2+s;
                       else
                           s=t1+s;
                       myplayer.setMoney(myplayer.getMoney()+chest[i].getValue());
                       dialog->setStyleSheet("border-image:url(://images/property7.png);");
                       dialog->resize(1000,1000);
                       QMessageBox::information(dialog,"宝箱",s,QMessageBox::Ok);
               }
           }
        }

        myplayer.move(direction,steps);
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
