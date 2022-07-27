struct character
{
    int gender;
    char* name;
    int coor_x;
    int coor_y;
    char* gg_view[3];
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
};
struct npc
{
    int coor_x;
    int coor_y;
    char* name;
    char* bubble;
    char sales[30];
};