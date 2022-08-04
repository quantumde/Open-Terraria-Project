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

/*
    Соблюдай принципы ООП когда пишешь код!
    Абстракция — отделение концепции от ее экземпляра;
    Полиморфизм — реализация задач одной и той же идеи разными способами;
    Наследование — способность объекта или класса базироваться на другом объекте или классе. Это главный механизм для повторного использования кода. Наследственное отношение классов четко определяет их иерархию;
    Инкапсуляция — размещение одного объекта или класса внутри другого для разграничения доступа к ним.
*/

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

struct Character our_Character;

void *input_thread(void *vargp)
{
    char button = getch();
    our_Character.coor_y_recovery = our_Character.coor_y;
    while (true){
        //clear();
        if (button == 'a')
        {
            our_Character.coor_x = our_Character.coor_x - 1;
        } else if (button == 'd')
        {
            our_Character.coor_x = our_Character.coor_x + 1;
        } else if (button == ' ')
        {
			int add_y =  our_Character.coor_y - 4;
			our_Character.coor_y_recovery=our_Character.coor_y;
			while (our_Character.coor_y > add_y)
			{
				our_Character.coor_y = our_Character.coor_y - 1;
                                sleep(1/(our_Character.coor_y-add_y+1));
			}
			while (our_Character.coor_y < our_Character.coor_y_recovery)
			{
				our_Character.coor_y = our_Character.coor_y + 1;
                                sleep(1/(our_Character.coor_y_recovery-our_Character.coor_y+1));
			}

    	} else if (button == 's')
    	{
            our_Character.coor_y = our_Character.coor_y + 1;
        } else if (button == 'q')
        {	
            endwin();
        	exit(0);
        }
        
	button = getch();
    }
}

void Character(int x, int y)
{
    our_Character.gg_view[0] = (char*)"#%#\n";
    our_Character.gg_view[1] = (char*)"$#$\n";
    our_Character.gg_view[2] = (char*)"# #\n";
    our_Character.coor_y_recovery = our_Character.coor_y;
    pthread_t input_thread_id;
    pthread_create(&input_thread_id, NULL, input_thread, NULL);
    while (true)
    {
        clear();
        for (int i = 0; i < 3; i++)
        {
 	        mvprintw(our_Character.coor_y, our_Character.coor_x, our_Character.gg_view[0]);
        	mvprintw(our_Character.coor_y+1, our_Character.coor_x, our_Character.gg_view[1]);
            mvprintw(our_Character.coor_y+2, our_Character.coor_x, our_Character.gg_view[2]);
        };
        //refresh();
        sleep(1/2);
    };
};


