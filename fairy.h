#ifndef FAIRY_H
#define FAIRY_H
#include <QImage>
#include <QPainter>
using namespace std;

class Fairy
{
public:
    Fairy(int _b_v=100){ blood_volume = _b_v; }
    virtual ~Fairy(){}

    void show(QPainter * painter);
    void move(int direction, int steps=1);

    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}
    int getPosX() const{return this->_pos_x;}
    int getPosY() const{return this->_pos_y;}
    int getblood_volume() const { return this->blood_volume; }
    void setblood_volume(int _blood_volume){ blood_volume = _blood_volume; }

private:
    int _pos_x, _pos_y;
    int blood_volume;
};

#endif // FAIRY_H
