#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#elif defined(__linux__)
#include <sys/ioctl.h>
#endif 

#include "Structures.cpp"


void get_terminal_size(int& width, int& height) {
#if defined(_WIN32)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = (int)(csbi.srWindow.Right-csbi.srWindow.Left+1);
    height = (int)(csbi.srWindow.Bottom-csbi.srWindow.Top+1);
#elif defined(__linux__)
    struct winsize w;
    ioctl(fileno(stdout), TIOCGWINSZ, &w);
    width = (int)(w.ws_col);
    height = (int)(w.ws_row);
#endif
}
int width=0, height=0;


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
    hardstone.coor_x = x % rand();
    hardstone.coor_y = y % rand();
    hardstone.name = (char*)"Hardstone Block";
    //wood.coor_x = rand() % 500;
    //wood.name = (char*)"Standart Wood";
    /* view of blocks */
    /* ground.blocks_view[0] = (char*)"@@";
    stone.blocks_view[0] = (char*)"$$";
    hardstone.blocks_view[0] = (char*)"&&";
    mvprintw(ground.coor_y, ground.coor_x, ground.blocks_view[0]);
    printw("\n");
    mvprintw(ground.coor_y, ground.coor_x, stone.blocks_view[0]);
    printw("\n");
    mvprintw(ground.coor_y, ground.coor_x, hardstone.blocks_view[0]);
    printw("\n"); */
};
static void character(int x, int y)
{
    get_terminal_size(width, height);
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
    our_character.coor_y_recovery = our_character.coor_y;
    char button = getch();
    while (true)
    {
        clear();
        if (our_character.coor_y < our_character.coor_y_recovery && our_character.jumping){
		our_character.coor_y = our_character.coor_y + 1;
        } else 
        	our_character.jumping=false;
        if (button == 'a')
        {
            our_character.coor_x = our_character.coor_x - 1;
        } else if (button == 'd')
        {
            our_character.coor_x = our_character.coor_x + 1;
        } else if (button == ' ' && !our_character.jumping )
	{
	    our_character.jumping=true;
	    our_character.coor_y_recovery = our_character.coor_y;
	    our_character.coor_y-=4;
    	} else if (button == 's')
    	{
        	our_character.coor_y = our_character.coor_y + 1;
        } else if (button == 'q')
        	break;
        
	
        for (int i = 0; i < 3; i++)
        {
            mvprintw(our_character.coor_y, our_character.coor_x, our_character.gg_view[0]);
            mvprintw(our_character.coor_y+1, our_character.coor_x, our_character.gg_view[1]);
            mvprintw(our_character.coor_y+2, our_character.coor_x, our_character.gg_view[2]);
        };
	button = getch();
    };
};
static void npc(int x, int y)
{
    struct npc guide;
    guide.name = (char*) "Mark";
    guide.bubble = (char*) "Hello, i have heard what you need help in this place. I will guide you here";
    guide.coor_x = x;
    guide.coor_y = y;
/*    guide.npc_view[0] = (char)"@!@\n";
    guide.npc_view[1] = (char)"&!&\n";
    guide.npc_view[2] = (char)"! !\n";
    for (int i = 0; i < 3; i++){
        mvprintw(guide.coor_y, guide.coor_x, guide.npc_view[0]);
        mvprintw(guide.coor_y+1, guide.coor_x, guide.npc_view[1]);
        mvprintw(guide.coor_y+2, guide.coor_x, guide.npc_view[2]);
    }*/
} 
