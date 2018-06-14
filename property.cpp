#include "property.h"
#include <iostream>
#include <fstream>
using namespace std;


int Property::props_num = 0;
string Property::property_File = "C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\properties.txt";
string Property::tot_name[8] = {"斩灵刀", "轮回镖", "虎魄杖", "竹音箫", "花鸾扇", "伏羲琴", "神行靴", "血灵丹"};

void Property::show_pic1(QPainter *painter, int pi)
{
    int xx = 1500+100*pi;
    int yy = 950;
    int ss = 10;
    if (this->name==tot_name[0])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property1.png"));
    else if (this->name==tot_name[1])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property5.png"));
    else if (this->name==tot_name[2])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property4.png"));
    else if (this->name==tot_name[3])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property6.png"));
    else if (this->name==tot_name[4])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property3.png"));
    else if (this->name==tot_name[5])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property8.png"));
    else if (this->name==tot_name[6])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property9.png"));
    else if (this->name==tot_name[7])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property12.png"));
}

void Property::show_pic2(QPainter *painter, int pi)
{
    int xx = 10;
    int yy = 200+200*pi;
    int ss = 15;
    if (this->name==tot_name[0])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property1.png"));
    else if (this->name==tot_name[1])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property5.png"));
    else if (this->name==tot_name[2])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property4.png"));
    else if (this->name==tot_name[3])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property6.png"));
    else if (this->name==tot_name[4])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property3.png"));
    else if (this->name==tot_name[5])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property8.png"));
    else if (this->name==tot_name[6])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property9.png"));
    else if (this->name==tot_name[7])
        painter->drawPixmap(xx,yy,6*ss,6*ss, QPixmap("://images/property12.png"));
}

void Property::show(QPainter *painter)
{
    //this->property_skill.setStartX(this->_px+60);
    //this->property_skill.setPosX();
    //this->property_skill.setStartY(this->_py+10);
    //this->property_skill.setPosY();

    if (this->name==tot_name[0])
    {
        painter->drawPixmap(this->_px,this->_py,6*this->SIZE,6*this->SIZE, QPixmap("://images/property1.png"));
        /*if(this->property_skill.getFlag()==0)
        {
            //cout<<"test"<<endl;
            this->property_skill.show(painter,1800,6);
        }*/

    }
    else if (this->name==tot_name[1])
    {
        painter->drawPixmap(this->_px,this->_py,6*this->SIZE,6*this->SIZE, QPixmap("://images/property5.png"));
        /*if(this->property_skill.getFlag()==0)
            this->property_skill.show(painter,1800,11);*/
    }
    else if (this->name==tot_name[2])
    {
        painter->drawPixmap(this->_px,this->_py,6*this->SIZE,6*this->SIZE, QPixmap("://images/property4.png"));
        /*if(this->property_skill.getFlag()==0)
            this->property_skill.show(painter,1800,4);*/
    }
    else if (this->name==tot_name[3])
    {
        painter->drawPixmap(this->_px,this->_py,6*this->SIZE,6*this->SIZE, QPixmap("://images/property6.png"));
        /*if(this->property_skill.getFlag()==0)
            this->property_skill.show(painter,1800,5);*/
    }
    else if (this->name==tot_name[4])
    {
        painter->drawPixmap(this->_px,this->_py,6*this->SIZE,6*this->SIZE, QPixmap("://images/property3.png"));
        /*if(this->property_skill.getFlag()==0)
            this->property_skill.show(painter,1800,9);*/
    }
    else if (this->name==tot_name[5])
    {
        painter->drawPixmap(this->_px,this->_py,6*this->SIZE,6*this->SIZE, QPixmap("://images/property8.png"));
        /*if(this->property_skill.getFlag()==0)
            this->property_skill.show(painter,1800,5);*/
    }
    /*else if (this->name==tot_name[6])
        painter->drawPixmap(this->_px,this->_py,6*this->SIZE,6*this->SIZE, QPixmap("://images/property9.png"));
    else if (this->name==tot_name[7])
        painter->drawPixmap(this->_px,this->_py,6*this->SIZE,6*this->SIZE, QPixmap("://images/property12.png"));*/
}

void Property::addproperty(string newp)
{
    ofstream proper;
    proper.open(property_File, ios::app);
    if (!proper.is_open())
        cout<<"fail to open the file"<<endl;
    else if (props_num<4)
    {
        if(props_num == 0)
            proper<<"\n";
        props_num++;
        proper<<newp<<"\n";
    }
    else
        cout<<"The backpack is full."<<endl;
    proper.close();
}

string Property::getproperty(int i)
{
    ifstream ifs;
    ifs.open(property_File, ios::in);
    string prop;
    int j=0;
    if (!ifs.is_open())
        cout<<"fail to open the file"<<endl;
    //ifs>>prop;
    while((!ifs.eof())&&(j<=i))
    {
        ifs>>prop;

        j++;
        ifs.get();
        if(ifs.peek()==EOF) break;


    }
    if (j!=i+1)
        prop = "\0";

    ifs.close();
    return prop;
}

void Property::setAttackvalue()
{
     if (this->name==tot_name[0])
     {
         property_skill.setAttackValue(6);
         this->Attack_value = property_skill.getAttackValue();
     }
     else if (this->name==tot_name[1])
     {
         property_skill.setAttackValue(11);
         this->Attack_value = property_skill.getAttackValue();
     }
     else if (this->name==tot_name[2])
     {
         property_skill.setAttackValue(4);
         this->Attack_value = property_skill.getAttackValue();
     }
     else if (this->name==tot_name[3])
     {
         property_skill.setAttackValue(5);
         this->Attack_value = property_skill.getAttackValue();
     }
     else if (this->name==tot_name[4])
     {
         property_skill.setAttackValue(9);
         this->Attack_value = property_skill.getAttackValue();
     }
     else if (this->name==tot_name[5])
     {
         property_skill.setAttackValue(5);
         this->Attack_value = property_skill.getAttackValue();
     }
     else if (this->name==tot_name[6])
     {
         this->Attack_value = 0;
     }
     else if (this->name==tot_name[7])
     {
         this->Attack_value = 0;
     }
}
