struct Character
{
    int gender  ;
    char* name  ;
    int coor_x  ;
    int coor_y  ;
    int coor_y_recovery;
    char* gg_view[3];
    bool jumping = false;
};
struct Weapon
{
    char name[15];
    int damage;
    char type[10];
};
struct Blocks
{
    int coor_x;
    int coor_y;
    char* name;
    char* blocks_view[1];
    Blocks(int x, int y, char* n, char* view)
    {
        x = coor_x;
        y = coor_y;
        n = name;
        view = blocks_view[1];

    }
};
struct Npc
{
    int coor_x;
    int coor_y;
    char* name;
    char* bubble;
    char sales[30];
    char* npc_view;
};
