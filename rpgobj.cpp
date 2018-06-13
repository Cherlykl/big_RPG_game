#include "rpgobj.h"
#include <iostream>

void RPGObj::initObj(string type)
{

      string obj[]={"ice1","ice2","stone1","stone2","npc1","npc2","npc3","npc4","tomb","gem1","gem2"};
       for(int i=0;i<9;i++)
          if(type.compare(obj[i])==0){
              this->_coverable=false;
              this->_eatable=false;
          }
       if(type.compare(obj[9])==0||type.compare(obj[10])==0){
           this->_coverable=false;
           this->_eatable=true;
       }

    //TODO 所支持的对象类型应定义为枚举
   if (type.compare("white_leaf")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("green_leaf")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("yellow_leaf")==0){this->_coverable = false;this->_eatable = false;}

        else if (type.compare("s_golden_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("m_golden_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("l_golden_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("s_silver_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("m_silver_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("l_silver_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("s_red_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("m_red_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("l_red_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("s_white_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("m_white_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("l_white_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("s_green_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("m_green_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("l_green_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("s_blue_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("m_blue_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("l_blue_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("s_orange_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("m_orange_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("l_orange_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("s_purple_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("m_purple_mineral")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("l_purple_mineral")==0){this->_coverable = false;this->_eatable = false;}

        else if (type.compare("rect_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("semirect_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("cir_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("semicir_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("gray_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("semigray_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("green_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("semigreen_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("white_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("semiwhite_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("wooden_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("semiwooden_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("brown_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("semibrown_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("pearl_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("semipearl_column")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("gray_stone")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("white_stone")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("green_stone")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("wood")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("brown_stone")==0){this->_coverable = false;this->_eatable = false;}

        else if (type.compare("spider_web")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("tomb_stone")==0){this->_coverable = false;this->_eatable = false;}

        else if (type.compare("lush_rattan")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("dry_rattan")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("grass_rattan")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("grass1")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("grass1")==0){this->_coverable = false;this->_eatable = false;}

        else if (type.compare("s_crack")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("m_crack")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("l_crack")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("w_crack")==0){this->_coverable = false;this->_eatable = false;}

        else if (type.compare("tip_column1")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("tip_column2")==0){this->_coverable = false;this->_eatable = false;}

        else if (type.compare("dark_door")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("bright_door")==0){this->_coverable = false;this->_eatable = false;}

        else if (type.compare("man_statue")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("l_woman_statue")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("r_woman_statue")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("mirror_statue")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("broke_statue")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("golden_statue")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("s_dragon_statue")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("l_dragon_statue")==0){this->_coverable = false;this->_eatable = false;}

        else if (type.compare("l_coppor_heap")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("l_aluminum_heap")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("l_golden_heap")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("l_silver_heap")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("s_coppor_heap")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("s_aluminum_heap")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("s_golden_heap")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("s_silver_heap")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("coppor_lump")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("aluminum_lump")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("golden_lump")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("silver_lump")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("coppor_case")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("aluminum_case")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("golden_case")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("silver_case")==0){this->_coverable = false;this->_eatable = false;}

        else if (type.compare("rope")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("golden_silk")==0){this->_coverable = false;this->_eatable = false;}

        else if (type.compare("beast_bone")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("animal_bone")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("human_bone")==0){this->_coverable = false;this->_eatable = false;}

        else if (type.compare("metal_fence_door")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("metal_fence")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("wooden_fence_door")==0){this->_coverable = false;this->_eatable = false;}
        else if (type.compare("wooden_fence")==0){this->_coverable = false;this->_eatable = false;}
       /*else{
        //TODO 应由专门的错误日志文件记录
        cout<<"invalid ICON type."<<endl;
        return;
    }*/
    this->_icon = ICON::findICON(type);
    QImage all;
    all.load("C:\\Users\\lenovo\\Desktop\\coding_homework\\big_RPG_game\\game_code\\images\\TileB.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE, _icon.getSrcY()*ICON::GRID_SIZE, _icon.getWidth()*ICON::GRID_SIZE, _icon.getHeight()*ICON::GRID_SIZE));
}

void RPGObj::show(QPainter * pa){
    int gSize = ICON::GRID_SIZE;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}
