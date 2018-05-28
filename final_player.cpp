#include "final_player.h"
#include "mainwindow.h"

void Final_player::show(QPainter * painter)
{
    if((MainWindow::getMi1())%2==0)
        Male_player::show(painter);
    else
        Female_player::show(painter);
}
