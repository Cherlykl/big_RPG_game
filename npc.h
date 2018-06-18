#ifndef NPC_H
#define NPC_H
#include<QPainter>

class Npc
{
public:
    Npc();
    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}
    void setSIZE(int size) {this->SIZE=size;}
    int getPosX() const{return this->_pos_x;}
    int getPosY() const{return this->_pos_y;}
    int getSIZE() const{return this->SIZE;}
    ~Npc(){}
protected:
    int _pos_x, _pos_y;
    int SIZE;
};

#endif // NPC_H
