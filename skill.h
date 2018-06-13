#ifndef SKILL_H
#define SKILL_H
#include <string>
#include <QImage>
#include <QPainter>
using namespace std;

class Skill
{
public:
    Skill(){}
    ~Skill(){}

    void show(QPainter * painter,int tag);
    void move();

    void setPosX(){this->_pos_x = start_x;}
    void setPosY(){this->_pos_y = start_y;}
    void setStartX(double x) {this->start_x = x;}
    void setStartY(double y) {this->start_y = y;}
    void setEndX(double x) {this->end_x = x;}
    void setEndY(double y) {this->end_y = y;}
    void setWidth(int size_x){this->length = size_x;}
    void setLength(int size_y){this->width = size_y;}
    void setFlag();
    void setSteps();

    double getPosX() const{return this->_pos_x;}
    double getPosY() const{return this->_pos_y;}
    int getFlag() {return this->flag;}
    double getStartX() {return this->start_x;}
    double getStartY() {return this->start_y;}

private:
    double _pos_x,_pos_y;
    int length,width;
    double start_x,start_y;
    double end_x,end_y;
    int flag;
    double steps_x,steps_y;
};

#endif // SKILL_H
