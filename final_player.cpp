#include "final_player.h"
#include "mainwindow.h"

void Final_player::show(QPainter * painter, int i)
{
    if((MainWindow::getMi1())%2==0)
        Male_player::show(painter,i);
    else
        Female_player::show(painter);
}
