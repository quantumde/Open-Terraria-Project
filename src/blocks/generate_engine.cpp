#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
//#include "../structures/Structures.cpp"

static void world_gen(int x, int y)
{
    blocks ground;
    ground.name = "Dirt Block";
    ground.coor_y = y;
    ground.coor_x = x;
    ground.blocks_view = "#";
    for (int i = 0; i < x & i < y; i++)
    {
        for (int j = 0; j < y; j++)
        {
            clear();
            printw(ground.blocks_view);
            sleep(10);
        }
    }
}
