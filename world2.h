#ifndef WORLD2_H
#define WORLD2_H
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
#include "male_player.h"
#include "female_player.h"
#include "final_player.h"
#include "world1.h"

class World2 : public World1
{
public:
    World2(){}
    ~World2(){}
    void initWorld(string mapFile);
        //输入的文件中定义了初始状态下游戏世界有哪些对象，出生点在哪
        /*e.g.
           player 5 5
           stone 3 3
           fruit 7 8
         */
    void show(QPainter * painter);
    void handlePlayerMove(int direction, int steps);
private:
    vector<RPGObj> _objs;
    Final_player myplayer;
};

#endif // WORLD2_H
