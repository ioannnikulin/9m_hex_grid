#include "base.hpp"
void f0(vector<field>& labyrinths)
{
    labyrinths.push_back(field(5,6));
    int p = labyrinths.size()-1;
    victory * v = new victory(&labyrinths[p]);
    labyrinths[p].set_cell(1,3, new wall(NULL));
    labyrinths[p].set_cell(2,3, new wall(NULL));
    labyrinths[p].set_cell(3,3, new wall(NULL));
    labyrinths[p].set_cell(4,5, v);
    labyrinths[p].set_start_row(2);
    labyrinths[p].set_start_col(2);
}

void f1(vector<field>& labyrinths)
{
    labyrinths.push_back(field(1,10));
    int p = labyrinths.size()-1;
    victory * v = new victory(&labyrinths[p]);
    labyrinths[p].set_cell(0,9, v);
    labyrinths[p].set_start_row(0);
    labyrinths[p].set_start_col(0);
}
void karpov_lab1(vector<field>& labyrinths)
{
    labyrinths.push_back(field(22,22));
    int p = labyrinths.size()-1;
    victory * v = new victory(&labyrinths[p]);
    for(int i=0;i<=21;i++){
    labyrinths[p].set_cell(0,i, new wall(NULL));
    labyrinths[p].set_cell(21,i, new wall(NULL));
    labyrinths[p].set_cell(i,0, new wall(NULL));
    labyrinths[p].set_cell(i,21, new wall(NULL));
    if(i<=6 or i>=9 and i<=18){labyrinths[p].set_cell(3,i, new wall(NULL));}
    if(i>=3 and i<=9){labyrinths[p].set_cell(i,18, new wall(NULL));}
    if(i>=3 and i<=15){labyrinths[p].set_cell(6,i, new wall(NULL));}
    if(i>=6 and i<=17){labyrinths[p].set_cell(9,i, new wall(NULL));}
    if(i>=6 and i<=9){labyrinths[p].set_cell(i,15, new wall(NULL));}
    if(i>=3 and i<=20){labyrinths[p].set_cell(12,i, new wall(NULL));}
    if(i>=6 and i<=12 or i>=15 and i<=18){labyrinths[p].set_cell(i,3, new wall(NULL));}
    if(i>=3 and i<=6 or i>=15 and i<=20){labyrinths[p].set_cell(18,i, new wall(NULL));}
    if(i>=13 and i<=18){labyrinths[p].set_cell(i,6, new wall(NULL));}
    if(i>=15 and i<=18){labyrinths[p].set_cell(i,9, new wall(NULL));}
    if(i>=15 and i<=20){labyrinths[p].set_cell(i,12, new wall(NULL));}
    if(i>=12 and i<=18){labyrinths[p].set_cell(15,i, new wall(NULL));}
    }
    labyrinths[p].set_cell(19,2, new wall(NULL));
    labyrinths[p].set_cell(20,20, v);
    labyrinths[p].set_start_row(1);
    labyrinths[p].set_start_col(1);
}
void fill_labyrinths(vector<field>& labyrinths)
{
    f0(labyrinths);
    f1(labyrinths);
    karpov_lab1(labyrinths);
}

