struct character
{
    int gender  ;
    char* name  ;
    int coor_x  ;
    int coor_y  ;
    int coor_y_recovery;
    char* gg_view[3];
    bool jumping = false;
};
struct weapon
{
    char name[15];
    int damage;
    char type[10];
};
struct blocks
{
    int coor_x;
    int coor_y;
    char* name;
    char* blocks_view[1];
};
struct npc
{
    int coor_x;
    int coor_y;
    char* name;
    char* bubble;
    char sales[30];
    char* npc_view;
};
