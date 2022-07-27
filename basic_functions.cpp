#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include "Structures.cpp"

static void generate(int x, int y)
{
    struct blocks ground;
    struct blocks stone;
    struct blocks hardstone;
    //struct blocks wood;
    
    ground.coor_x = x % rand() % 100;
    ground.coor_y = y % rand() % 20;
    ground.name = (char*)"Dirt Block";
    stone.coor_x = x % rand() % 100;
    stone.coor_y = y % rand() % 20;
    stone.name = (char*)"Stone Block";
    hardstone.coor_x = x % rand() % 100;
    hardstone.coor_y = y % rand() % 20;
    hardstone.name = (char*)"Hardstone Block";
    //wood.coor_x = rand() % 500;
    //wood.name = (char*)"Standart Wood";
};
static void character(int x, int y)
{
    //char character_name[30];
    //int character_gender;
    //scanf("%c", character_name);
    //scanf("%d", &character_gender);
    struct character our_character;
    //our_character.name = character_name;
    //our_character.gender = character_gender;
    our_character.coor_x = x;
    our_character.coor_y = y;
    our_character.gg_view[0] = (char*)"#%#\n";
    our_character.gg_view[1] = (char*)"$#$\n";
    our_character.gg_view[2] = (char*)"# #\n";
    char button = getch();
    while (button != 'q')
    {
        if (button == 'a')
        {
            our_character.coor_x = our_character.coor_x - 1;
            for (int i = 0; i < 3; i++)
            {
                mvprintw(our_character.coor_y, our_character.coor_x, our_character.gg_view[0]);
                mvprintw(our_character.coor_y+1, our_character.coor_x, our_character.gg_view[1]);
                mvprintw(our_character.coor_y+2, our_character.coor_x, our_character.gg_view[2]);
            };
        } elif (button == 'd')
        {
            our_character.coor_x = our_character.coor_x + 1;
            for (int i = 0; i < 3; i++)
            {
                mvprintw(our_character.coor_y, our_character.coor_x, our_character.gg_view[0]);
                mvprintw(our_character.coor_y+1, our_character.coor_x, our_character.gg_view[1]);
                mvprintw(our_character.coor_y+2, our_character.coor_x, our_character.gg_view[2]);
            }
        }
        char button = getch();
    }
};
static void npc(int x, int y)
{
    struct npc guide;
    guide.name = (char*) "Mark";
    guide.bubble = (char*) "Hello, i have heard what you need help in this place. I will guide you here";
    guide.coor_x = x;
    guide.coor_y = y;
} 
