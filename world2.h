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
#include "fairy.h"
#include "skill.h"
#include "monster.h"

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
    void showcruise(QPainter * painter, int i);
    void showbattle(QPainter * painter, int i);
    void handlePlayerMove(int direction, int steps);
    void handleFairyMove(int direction);
    void handleMonsterMove(int direction);
    void rebuildWorld();

    void setPlayerX(int x) {this->myplayer.setPosX(x);}
    void setPlayerY(int y) {this->myplayer.setPosY(y);}
    int getPlayerX(){return myplayer.getPosX();}
    int getPlayerY(){return myplayer.getPosY();}

    Monster& getBoss(){ return this->boss; }
    Final_player& getPlayer(){return this->myplayer; }
    Fairy& getFairy1(){return this->enemy_fairy[1];}
    Fairy& getFairy2(){return this->enemy_fairy[4];}
    Fairy& getFairy3(){return this->enemy_fairy[7];}
private:
    vector<RPGObj> _objs;
    Final_player myplayer;
    Fairy enemy_fairy[9];
    Monster boss;

};

#endif // WORLD2_H
