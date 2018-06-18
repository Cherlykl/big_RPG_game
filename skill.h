#ifndef SKILL_H
#define SKILL_H
#include <string>
#include <QImage>
#include <QPainter>
using namespace std;

class Skill
{
public:
    //change by wang
    Skill(int f=0, int a=0 , int fb = 0,int x = 12345678,int y = 12345678) {this->flag = f; this->attack_value = a; this->flag_blood = fb;this->_pos_x = x;this->_pos_y = y;}         //change by wang
    ~Skill(){}

    void show(QPainter * painter, int range, int tag);
    void move();

    void setPosX(){this->_pos_x = start_x;}
    void setPosY(){this->_pos_y = start_y;}
    void setStartX(double x) {this->start_x = x;}
    void setStartY(double y) {this->start_y = y;}
    void setEndX(double x) {this->end_x = x;}
    void setEndY(double y) {this->end_y = y;}
    void setSize(int i);
    void setTarget(double x,double y){this->target_x = x;this->target_y = y;}
    void setFlag(int i, int range);
    void setSteps();
    void setAttackValue(int i);

    double getPosX() const{return this->_pos_x;}
    double getPosY() const{return this->_pos_y;}
    int getFlagBlood() {return this->flag_blood;}            //change by wang
    int getFlag() {return this->flag;}
    double getStartX() {return this->start_x;}
    double getStartY() {return this->start_y;}
    int getAttackValue() {return this->attack_value;}

private:
    double _pos_x,_pos_y;
    int length,width;
    double start_x,start_y;
    double end_x,end_y;
    double target_x,target_y;
    double steps_x,steps_y;

    int flag;
    int attack_value;

     //change by wang
    int flag_blood;
    int Area;
};

#endif // SKILL_H
