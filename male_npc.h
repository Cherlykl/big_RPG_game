#ifndef MALE_NPC_H
#define MALE_NPC_H
#include<QPainter>
#include<npc.h>
class Male_npc:public Npc
{
public:
    Male_npc();
    void show(QPainter*painter);
};

#endif // MALE_NPC_H
