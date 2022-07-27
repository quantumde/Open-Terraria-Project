#include "basic_functions.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main()
{
    initscr();
    int x = 1;
    int y = 1;
    character(x, y);
    refresh();
    getch();
    endwin();
    return 0;
}