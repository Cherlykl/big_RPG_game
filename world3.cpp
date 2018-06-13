#include "world3.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int World3::props_num = 0;

void World3::show(QPainter * painter)
{
     painter->drawPixmap(150,100,200,180, QPixmap("://images/property1.png"));
     painter->drawPixmap(80,350,62,64, QPixmap("://images/property7.png"));
     painter->drawPixmap(600,100,180,180, QPixmap("://images/property5.png"));
     painter->drawPixmap(530,350,62,64, QPixmap("://images/property7.png"));
     painter->drawPixmap(1050,100,200,180, QPixmap("://images/property4.png"));
     painter->drawPixmap(980,350,62,64, QPixmap("://images/property7.png"));
     painter->drawPixmap(1500,100,200,180, QPixmap("://images/property6.png"));
     painter->drawPixmap(1430,350,62,64, QPixmap("://images/property7.png"));

     painter->drawPixmap(150,600,200,180, QPixmap("://images/property3.png"));
     painter->drawPixmap(80,850,62,64, QPixmap("://images/property7.png"));
     painter->drawPixmap(600,600,180,180, QPixmap("://images/property8.png"));
     painter->drawPixmap(530,850,62,64, QPixmap("://images/property7.png"));
     painter->drawPixmap(1050,600,200,180, QPixmap("://images/property9.png"));
     painter->drawPixmap(980,850,62,64, QPixmap("://images/property7.png"));
     painter->drawPixmap(1500,600,180,180, QPixmap("://images/property12.png"));
     painter->drawPixmap(1430,850,62,64, QPixmap("://images/property7.png"));

}

void World3::addproperty(string newp, string file)
{
    if (this->props_num<=4)
    {
        ofstream property;
        property.open(file, ios::app);
        if (!property.is_open())
            cout<<"fail to open the file"<<endl;
        else
            property<<newp<<"\n";
        property.close();
        this->props_num++;
    }
    else
        cout<<"The backpack is full."<<endl;

}
/*
void World3::getproperty(string file)
{
    ifstream ifs;
    //ifs.imbue(locale("chs"));
    ifs.open((file), ios::in | ios::binary);
    string prop;
    //int j=0;
    if (!ifs.is_open())
        cout<<"fail to open the file"<<endl;
    while((!ifs.eof()))
    {
        ifs>>prop;
        //cout<<prop<<endl;
    }
    ifs.close();
   // return prop;
}*/
