#ifndef WORLD3_H
#define WORLD3_H
#include <QPainter>
#include "world1.h"

class World3:public World1
{
public:
    World3();
    ~World3(){}
    void show(QPainter * painter);
    Property& getProperty(int i=0){return this->property[i];}
private:
    Property property[8];
};

#endif // WORLD3_H
