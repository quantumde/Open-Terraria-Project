#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

static void world_gen(int x, int y)
{
    blocks ground = blocks(x, y, "Ground", '%');
    /*Blocks stone = Blocks(x, y, "Stone", '$');
    Blocks hardstone = Blocks(x, y, "HardStone", '#');*/
    for (int i = 0; i < x & i < y; i++)
    {
        for (int j = 0; j < y; j++)
        {
            clear();
            mvprintw(y, x, ground.name);
            sleep(10);
        }
    }
}