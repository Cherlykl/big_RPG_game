#ifndef FEMALE_NPC_H
#define FEMALE_NPC_H
#include"npc.h"
#include <QPainter>
class Female_npc:public Npc
{
public:
    Female_npc();
    void show(QPainter*painter);
};

#endif // FEMALE_NPC_H
