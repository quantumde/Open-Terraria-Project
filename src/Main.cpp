#include "./character/character_engine.cpp"
#include "./blocks/generate_engine.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main()
{
    initscr();
    int x = 0;
    int y = 0;
    noecho();
    character(x, y);
    world_gen(x, y);
    refresh();
    endwin();
    return 0;
}
