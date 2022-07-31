#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

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

struct character our_character;

void *input_thread(void *vargp)
{
    char button = getch();
    our_character.coor_y_recovery = our_character.coor_y;
    while (true){
        //clear();
        if (button == 'a')
        {
            our_character.coor_x = our_character.coor_x - 1;
        } else if (button == 'd')
        {
            our_character.coor_x = our_character.coor_x + 1;
        } else if (button == ' ')
        {
			int add_y =  our_character.coor_y - 4;
			while (our_character.coor_y != add_y)
			{
				our_character.coor_y = our_character.coor_y - 1;
			}
			while (our_character.coor_y != our_character.coor_y_recovery)
			{
				our_character.coor_y = our_character.coor_y + 1;
			}

    	} else if (button == 's')
    	{
            our_character.coor_y = our_character.coor_y + 1;
        } else if (button == 'q')
        {	
            endwin();
        	exit(0);
        }
        
	button = getch();
    }
}

void character(int x, int y)
{
    our_character.gg_view[0] = (char*)"#%#\n";
    our_character.gg_view[1] = (char*)"$#$\n";
    our_character.gg_view[2] = (char*)"# #\n";
    our_character.coor_y_recovery = our_character.coor_y;
    pthread_t input_thread_id;
    pthread_create(&input_thread_id, NULL, input_thread, NULL);
    while (true)
    {
        clear();
        for (int i = 0; i < 3; i++)
        {
 	        mvprintw(our_character.coor_y, our_character.coor_x, our_character.gg_view[0]);
        	mvprintw(our_character.coor_y+1, our_character.coor_x, our_character.gg_view[1]);
            mvprintw(our_character.coor_y+2, our_character.coor_x, our_character.gg_view[2]);
        };
        refresh();
        sleep(1/2);
    };
};
/*static void npc(int x, int y)
{
    struct npc guide;
    guide.name = (char*) "Mark";
    guide.bubble = (char*) "Hello, i have heard what you need help in this place. I will guide you here";
    guide.coor_x = x;
    guide.coor_y = y;
    while (true){
        guide.npc_view[0] = (char*)"@!@\n";
        guide.npc_view[1] = (char*)"&!&\n";
        guide.npc_view[2] = (char*)"! !\n";
        for (int i = 0; i < 3; i++){
            mvprintw(guide.coor_y, guide.coor_x, guide.npc_view[0]);
            mvprintw(guide.coor_y+1, guide.coor_x, guide.npc_view[1]);
            mvprintw(guide.coor_y+2, guide.coor_x, guide.npc_view[2]);
        }
} 
}*/


