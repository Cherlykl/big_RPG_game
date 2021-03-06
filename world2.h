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
#include "property.h"
#include "npc.h"
#include"male_npc.h"
#include"female_npc.h"
#include"chest.h"
class World2 : public World1
{
public:
    World2(){}
    ~World2(){}
    void initWorld(string mapFile, int tag);
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

    void change_blood();                                      //change by wang

    Monster& getBoss(){ return this->boss; }
    Final_player& getPlayer(){return this->myplayer; }
    Fairy& getFairy1(){return this->enemy_fairy[1];}
    Fairy& getFairy2(){return this->enemy_fairy[4];}
    Fairy& getFairy3(){return this->enemy_fairy[7];}

    int getHP(){return myplayer.getHP();}
    void setHP(int hp){myplayer.setHP(hp);}
    int getMoney(){return myplayer.getMoney();}
    void setMoney(int money){myplayer.setMoney(money);}
    friend bool Middle(int a,int b,int c);

private:
    vector<RPGObj> _objs;
    Final_player myplayer;
    Fairy enemy_fairy[9];
    Monster boss;
    Male_npc male_npc;
    Female_npc female_npc;
    Chest chest[3];
};

#endif // WORLD2_H
