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
    char* name;
    int damage;
    char* type;
};
struct blocks
{
    int coor_x;
    int coor_y;
    char* name;
    char* blocks_view;
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
