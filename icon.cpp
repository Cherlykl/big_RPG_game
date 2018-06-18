#include "icon.h"
#include<iostream>
int ICON::GRID_SIZE = 32;

pair<string,ICON> pairArray[] =
{

        make_pair("ice1",ICON("ice1",5,7,1,1)),
        make_pair("ice2",ICON("ice2",5,8, 1, 2)),
        make_pair("stone1",ICON("stone1",4,12,1,1)),
        make_pair("stone2",ICON("stone2",4,10,1,2)),
        make_pair("gem1",ICON("gem1",7,7,1,1)),
        make_pair("gem2",ICON("gem2",7,8,1,2)),
        make_pair("npc1",ICON("npc1",8,7,1,2)),
        make_pair("npc2",ICON("npc2",9,7,1,2)),
        make_pair("npc3",ICON("npc3",10,7,1,2)),
        make_pair("npc4",ICON("npc4",13,7,1,2)),
        make_pair("tomb",ICON("tomb",13,5,3,2)),

        make_pair("white_leaf",ICON("white_leaf", 0, 1, 1, 1)),
        make_pair("green_leaf",ICON("green_leaf", 1, 0, 1, 1)),
        make_pair("yellow_leaf",ICON("yellow_leaf", 1, 0, 1, 1)),

        make_pair("s_golden_mineral",ICON("s_golden_mineral", 0, 6, 1, 1)),
        make_pair("m_golden_mineral",ICON("m_golden_mineral", 0, 7, 1, 1)),
        make_pair("l_golden_mineral",ICON("l_golden_mineral", 0, 8, 1, 2)),
        make_pair("s_silver_mineral",ICON("s_silver_mineral", 1, 6, 1, 1)),
        make_pair("m_silver_mineral",ICON("m_silver_mineral", 1, 7, 1, 1)),
        make_pair("l_silver_mineral",ICON("l_silver_mineral", 1, 8, 1, 2)),
        make_pair("s_red_mineral",ICON("s_red_mineral", 2, 6, 1, 1)),
        make_pair("m_red_mineral",ICON("m_red_mineral", 2, 7, 1, 1)),
        make_pair("l_red_mineral",ICON("l_red_mineral", 2, 8, 1, 2)),
        make_pair("s_white_mineral",ICON("s_white_mineral", 3, 6, 1, 1)),
        make_pair("m_white_mineral",ICON("m_white_mineral", 3, 7, 1, 1)),
        make_pair("l_white_mineral",ICON("l_white_mineral", 3, 8, 1, 2)),
        make_pair("s_green_mineral",ICON("s_green_mineral", 4, 6, 1, 1)),
        make_pair("m_green_mineral",ICON("m_green_mineral", 4, 7, 1, 1)),
        make_pair("l_green_mineral",ICON("l_green_mineral", 4, 8, 1, 2)),
        make_pair("s_blue_mineral",ICON("s_blue_mineral", 5, 6, 1, 1)),
        make_pair("m_blue_mineral",ICON("m_blue_mineral", 5, 7, 1, 1)),
        make_pair("l_blue_mineral",ICON("l_blue_mineral", 5, 8, 1, 2)),
        make_pair("s_orange_mineral",ICON("s_orange_mineral", 6, 6, 1, 1)),
        make_pair("m_orange_mineral",ICON("m_orange_mineral", 6, 7, 1, 1)),
        make_pair("l_orange_mineral",ICON("l_orange_mineral", 6, 8, 1, 2)),
        make_pair("s_purple_mineral",ICON("s_purple_mineral", 7, 6, 1, 1)),
        make_pair("m_purple_mineral",ICON("m_purple_mineral", 7, 7, 1, 1)),
        make_pair("l_purple_mineral",ICON("l_purple_mineral", 7, 8, 1, 2)),

        make_pair("rect_column",ICON("rect_column", 0, 10, 1, 2)),
        make_pair("semirect_column",ICON("semirect_column", 0, 12, 1, 1)),
        make_pair("cir_column",ICON("cir_column", 1, 10, 1, 2)),
        make_pair("semicir_column",ICON("semicir_column", 1, 12, 1, 1)),
        make_pair("gray_column",ICON("gray_column", 2, 10, 1, 2)),
        make_pair("semigray_column",ICON("semigray_column", 2, 12, 1, 1)),
        make_pair("green_column",ICON("green_column", 3, 10, 1, 2)),
        make_pair("semigreen_column",ICON("semigreen_column", 3, 12, 1, 1)),
        make_pair("white_column",ICON("white_column", 4, 10, 1, 2)),
        make_pair("semiwhite_column",ICON("semiwhite_column", 4, 12, 1, 1)),
        make_pair("wooden_column",ICON("wooden_column", 5, 10, 1, 2)),
        make_pair("semiwooden_column",ICON("semiwooden_column", 5, 12, 1, 1)),
        make_pair("brown_column",ICON("brown_column", 6, 10, 1, 2)),
        make_pair("semibrown_column",ICON("semibrown_column", 6, 12, 1, 1)),
        make_pair("pearl_column",ICON("pearl_column", 7, 10, 1, 2)),
        make_pair("semipearl_column",ICON("semipearl_column", 7, 12, 1, 1)),
        make_pair("gray_stone",ICON("gray_stone", 0, 13, 1, 1)),
        make_pair("green_stone",ICON("green_stone", 1, 13, 1, 1)),
        make_pair("white_stone",ICON("white_stone", 2, 13, 1, 1)),
        make_pair("wood",ICON("wood", 3, 13, 1, 1)),
        make_pair("brown_stone",ICON("brown_stone", 4, 13, 1, 1)),

        make_pair("spider_web",ICON("spider_web", 8, 2, 1, 1)),
        make_pair("tomb_stone",ICON("tomb_stone", 9, 2, 1, 1)),

        make_pair("lush_rattan",ICON("lush_rattan", 8, 3, 1, 2)),
        make_pair("dry_rattan",ICON("dry_rattan", 9, 3, 1, 2)),
        make_pair("grass_rattan",ICON("grass_rattan", 10, 3, 1, 2)),
        make_pair("grass1",ICON("grass1", 11, 3, 1, 1)),
        make_pair("grass2",ICON("grass2", 11, 4, 1, 1)),

        make_pair("s_crack",ICON("s_crack", 12, 3, 1, 2)),
        make_pair("m_crack",ICON("m_crack", 13, 3, 1, 2)),
        make_pair("l_crack",ICON("l_crack", 14, 3, 1, 2)),
        make_pair("w_crack",ICON("w_crack", 15, 3, 1, 2)),

        make_pair("tip_column1",ICON("tip_column1", 8, 5, 1, 2)),
        make_pair("tip_column2",ICON("tip_column2", 9, 5, 1, 2)),

        make_pair("dark_door",ICON("dark_door", 10, 5, 3, 2)),
        make_pair("bright_door",ICON("bright_door", 13, 5, 3, 2)),

        make_pair("man_statue",ICON("man_statue", 8, 7, 1, 2)),
        make_pair("l_woman_statue",ICON("l_woman_statue", 9, 7, 1, 2)),
        make_pair("r_woman_statue",ICON("r_woman_statue", 10, 7, 1, 2)),
        make_pair("mirror_statue",ICON("mirror_statue", 11, 7, 1, 2)),
        make_pair("broke_statue",ICON("broke_statue", 12, 7, 1, 2)),
        make_pair("golden_statue",ICON("golden_statue", 13, 7, 1, 2)),
        make_pair("s_dragon_statue",ICON("s_dragon_statue", 14, 7, 1, 2)),
        make_pair("l_dragon_statue",ICON("l_dragon_statue", 15, 7, 1, 2)),

        make_pair("l_coppor_heap",ICON("l_coppor_heap", 8, 9, 2, 2)),
        make_pair("l_aluminum_heap",ICON("l_aluminum_heap", 10, 9, 2, 2)),
        make_pair("l_golden_heap",ICON("l_golden_heap", 12, 9, 2, 2)),
        make_pair("l_silver_heap",ICON("l_silver_heap", 14, 9, 2, 2)),
        make_pair("s_coppor_heap",ICON("s_coppor_heap", 8, 11, 1, 1)),
        make_pair("s_aluminum_heap",ICON("s_aluminum_heap", 9, 11, 1, 1)),
        make_pair("s_golden_heap",ICON("s_golden_heap", 8, 12, 1, 1)),
        make_pair("s_silve_heap",ICON("s_silve_heap", 9, 12, 1, 1)),
        make_pair("coppor_lump",ICON("coppor_lump", 10, 11, 1, 1)),
        make_pair("aluminum_lump",ICON("aluminum_lump", 10, 12, 1, 1)),
        make_pair("golden_lump",ICON("golden_lump", 11, 11, 1, 1)),
        make_pair("silve_lump",ICON("silve_lump", 11, 12, 1, 1)),
        make_pair("coppor_case",ICON("coppor_case", 12, 11, 1, 1)),
        make_pair("aluminum_case",ICON("aluminum_case", 13, 11, 1, 1)),
        make_pair("golden_case",ICON("golden_case", 12, 12, 1, 1)),
        make_pair("silve_case",ICON("silve_case", 13, 12, 1, 1)),

        make_pair("rope",ICON("rope", 10, 13, 1, 1)),
        make_pair("golden_silk",ICON("golden_silk", 11, 13, 1, 1)),

        make_pair("beast_bone",ICON("beast_bone", 8, 14, 2, 2)),
        make_pair("animal_bone",ICON("animal_bone", 10, 14, 1, 1)),
        make_pair("human_bone",ICON("human_bone", 10, 15, 1, 1)),

        make_pair("metal_fence_door",ICON("metal_fence_door", 12, 14, 1, 2)),
        make_pair("metal_fence",ICON("metal_fence", 13, 14, 3, 2)),
        make_pair("wooden_fence_door",ICON("wooden_fence_door", 3, 14, 2, 2)),
        make_pair("wooden_fence",ICON("wooden_fence", 0, 14, 3, 2))

};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));


ICON::ICON(string name, int x, int y, int w, int h){
    this->typeName = name;
    this->srcX = x;
    this->srcY = y;
    this->width = w;
    this->height = h;
}

ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;
    kv = ICON::GAME_ICON_SET.find(type);
    if (kv==ICON::GAME_ICON_SET.end()){

       cout<<"Error: cannot find ICON"<<endl;
       return ICON();
    }
    else{
        return kv->second;
    }
}
