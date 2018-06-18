#ifndef PROPERTY_H
#define PROPERTY_H
#include <QPainter>
#include "skill.h"
using namespace std;


class Property
{
public:
    Property() {}
    void show_pic1(QPainter *painter, int pi);
    void show_pic2(QPainter *painter, int pi);
    void show(QPainter *painter);

    void setname(string n) {this->name = n;}
    void setAttackvalue();
    void setpos(int x, int y) {this->_px = x; this->_py = y; }
    void setSIZE(int s) {this->SIZE = s;}
    void setValue(int v){this->value=v;}

    string getname() const {return this->name;}
    int getAttackvalue() const {return this->Attack_value; }
    int getpx() const {return this->_px; }
    int getpy() const {return this->_py; }
    int getSIZE() const {return this->SIZE;}
    Skill& getSkill() {return this->property_skill;}
    int getValue()const{return this->value;}

    static void addproperty(string newp);
    static string getproperty(int i);
    static string tot_name[8] ;

private:
    string name;
    int Attack_value;
    Skill property_skill;
    int value;
    int _px;
    int _py;
    int SIZE;
    static int props_num;
    static string property_File;
};

#endif // PROPERTY_H
