#include "world3.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void World3::show(QPainter * painter)
{
     painter->drawPixmap(150,100,200,180, QPixmap("://images/property1.png"));
     painter->drawPixmap(80,350,62,64, QPixmap("://images/property7.png"));
     painter->drawPixmap(600,100,180,180, QPixmap("://images/property5.png"));
     painter->drawPixmap(530,350,62,64, QPixmap("://images/property7.png"));
     painter->drawPixmap(1050,100,200,180, QPixmap("://images/property4.png"));
     painter->drawPixmap(980,350,62,64, QPixmap("://images/property7.png"));
     painter->drawPixmap(1500,100,200,180, QPixmap("://images/property6.png"));
     painter->drawPixmap(1430,350,62,64, QPixmap("://images/property7.png"));

     painter->drawPixmap(150,600,200,180, QPixmap("://images/property3.png"));
     painter->drawPixmap(80,850,62,64, QPixmap("://images/property7.png"));
     painter->drawPixmap(600,600,180,180, QPixmap("://images/property8.png"));
     painter->drawPixmap(530,850,62,64, QPixmap("://images/property7.png"));
     painter->drawPixmap(1050,600,200,180, QPixmap("://images/property9.png"));
     painter->drawPixmap(980,850,62,64, QPixmap("://images/property7.png"));
     painter->drawPixmap(1500,600,180,180, QPixmap("://images/property12.png"));
     painter->drawPixmap(1430,850,62,64, QPixmap("://images/property7.png"));

}
