#ifndef WORLD3_H
#define WORLD3_H
#include <QPainter>
#include "world1.h"

class World3:public World1
{
public:
    World3(){}
    ~World3(){}
    void show(QPainter * painter);
};

#endif // WORLD3_H
