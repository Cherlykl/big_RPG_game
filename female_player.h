#ifndef FEMALE_PLAYER_H
#define FEMALE_PLAYER_H
#include <QImage>
#include <QPainter>
#include "player.h"
using namespace std;

class Female_player:virtual public Player
{
public:
    Female_player(){}
    ~Female_player(){}
    void show(QPainter * painter);

};

#endif // FEMALE_PLAYER_H
