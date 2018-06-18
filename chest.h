#ifndef CHEST_H
#define CHEST_H
#include"rpgobj.h"
#include<QPainter>
class Chest:public RPGObj
{
public:
    Chest();
    void initObj(int xx,int yy);
    void show(QPainter *painter);
    void setValue(int v){value=v;}
    int getValue(){return value;}
    int getRecord(){return record;}
    void setRecord(int xx){record=xx;}
private:
    int value;
    int record;
};

#endif // CHEST_H
