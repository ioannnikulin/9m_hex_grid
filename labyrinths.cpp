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

void tokarenko_lab_1(vector<field>& labyrinths)
{
labyrinths.push_back(field(20,20));
int p = labyrinths.size()-1;
victory * v = new victory(&labyrinths[p]);
for (int i(0); i<20; i++)
{
labyrinths[p].set_cell(i,0, new wall(NULL));
labyrinths[p].set_cell(0,i, new wall(NULL));
labyrinths[p].set_cell(19,i, new wall(NULL));
labyrinths[p].set_cell(i,19, new wall(NULL));
}
for (int i(2); i<11; i++)
{
labyrinths[p].set_cell(6,i, new wall(NULL));
labyrinths[p].set_cell(13,i, new wall(NULL));
}
for (int i(8); i<13; i++)
{
labyrinths[p].set_cell(i,2, new wall(NULL));
labyrinths[p].set_cell(i,5, new wall(NULL));
labyrinths[p].set_cell(i,8, new wall(NULL));
}
for (int i(6); i<13; i++)
{
labyrinths[p].set_cell(i,10, new wall(NULL));
}
for (int i(2); i<12; i++)
{
labyrinths[p].set_cell(15,i, new wall(NULL));
}
for (int i(2); i<11; i++)
{
labyrinths[p].set_cell(17,i, new wall(NULL));
}
for (int i(15); i<18; i++)
{
labyrinths[p].set_cell(i,2, new wall(NULL));
}
for (int i(12); i<19; i++)
{
labyrinths[p].set_cell(17,i, new wall(NULL));
}
for (int i(12); i<19; i++)
{
labyrinths[p].set_cell(12,i, new wall(NULL));
}
for (int i(12); i<16; i++)
{
labyrinths[p].set_cell(i,12, new wall(NULL));
}
for (int i(14); i<17; i++)
{
labyrinths[p].set_cell(i,14, new wall(NULL));
}
for (int i(16); i<19; i++)
{
labyrinths[p].set_cell(14,i, new wall(NULL));
}
for (int i(1); i<6; i++)
{
labyrinths[p].set_cell(i,2, new wall(NULL));
}
for (int i(3); i<8; i++)
{
labyrinths[p].set_cell(i,4, new wall(NULL));
}
for (int i(6); i<12; i++)
{
labyrinths[p].set_cell(4,i, new wall(NULL));
}
for (int i(5); i<14; i++)
{
labyrinths[p].set_cell(2,i, new wall(NULL));
}

labyrinths[p].set_cell(5,12, new wall(NULL));

for (int i(13); i<17; i++)
{
labyrinths[p].set_cell(6,i, new wall(NULL));
}
for (int i(6); i<12; i++)
{
labyrinths[p].set_cell(i,14, new wall(NULL));
}
for (int i(3); i<10; i++)
{
labyrinths[p].set_cell(i,17, new wall(NULL));
}
for (int i(2); i<5; i++)
{
labyrinths[p].set_cell(i,13, new wall(NULL));
}
labyrinths[p].set_cell(7,15, v);
labyrinths[p].set_start_col(1);
labyrinths[p].set_start_row(1);
}

void fill_labyrinths(vector<field>& labyrinths)
{
    f0(labyrinths);
    f1(labyrinths);
}

