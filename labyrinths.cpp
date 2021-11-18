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

void lab_uspenskaya(vector<field>& labyrinths)
   {
    labyrinths.push_back(field(20, 20));
    int p = labyrinths.size()-1;
    victory * v = new victory(&labyrinths[p]);

    labyrinths[p].set_cell(0,4, new wall(NULL));
    labyrinths[p].set_cell(0,5, new wall(NULL));
    labyrinths[p].set_cell(0,8, new wall(NULL));
    labyrinths[p].set_cell(0,10, new wall(NULL));
    labyrinths[p].set_cell(0,14, new wall(NULL));
    labyrinths[p].set_cell(0,19, new wall(NULL));
    labyrinths[p].set_cell(1,4, new wall(NULL));
    labyrinths[p].set_cell(1,8, new wall(NULL));
    labyrinths[p].set_cell(1,10, new wall(NULL));
    labyrinths[p].set_cell(1,12, new wall(NULL));
    labyrinths[p].set_cell(1,13, new wall(NULL));
    labyrinths[p].set_cell(1,14, new wall(NULL));
    labyrinths[p].set_cell(1,15, new wall(NULL));
    labyrinths[p].set_cell(2,3, new wall(NULL));
    labyrinths[p].set_cell(2,6, new wall(NULL));
    labyrinths[p].set_cell(2,7, new wall(NULL));
    labyrinths[p].set_cell(2,10, new wall(NULL));
    labyrinths[p].set_cell(2,12, new wall(NULL));
    labyrinths[p].set_cell(2,13, new wall(NULL));
    labyrinths[p].set_cell(2,16, new wall(NULL));
    labyrinths[p].set_cell(2,17, new wall(NULL));
    labyrinths[p].set_cell(2,18, new wall(NULL));
    labyrinths[p].set_cell(2,19, new wall(NULL));
    labyrinths[p].set_cell(3,3, new wall(NULL));
    labyrinths[p].set_cell(3,6, new wall(NULL));
    labyrinths[p].set_cell(3,17, new wall(NULL));
    labyrinths[p].set_cell(3,18, new wall(NULL));
    labyrinths[p].set_cell(3,19, new wall(NULL));
    labyrinths[p].set_cell(4,9, new wall(NULL));
    labyrinths[p].set_cell(4,10, new wall(NULL));
    labyrinths[p].set_cell(4,15, new wall(NULL));
    labyrinths[p].set_cell(5,0, new wall(NULL));
    labyrinths[p].set_cell(5,3, new wall(NULL));
    labyrinths[p].set_cell(5,4, new wall(NULL));
    labyrinths[p].set_cell(5,5, new wall(NULL));
    labyrinths[p].set_cell(5,6, new wall(NULL));
    labyrinths[p].set_cell(5,8, new wall(NULL));
    labyrinths[p].set_cell(5,9, new wall(NULL));
    labyrinths[p].set_cell(5,11, new wall(NULL));
    labyrinths[p].set_cell(5,12, new wall(NULL));
    labyrinths[p].set_cell(5,14, new wall(NULL));
    labyrinths[p].set_cell(5,18, new wall(NULL));
    labyrinths[p].set_cell(5,19, new wall(NULL));
    labyrinths[p].set_cell(6,1, new wall(NULL));
    labyrinths[p].set_cell(6,9, new wall(NULL));
    labyrinths[p].set_cell(6,11, new wall(NULL));
    labyrinths[p].set_cell(6,13, new wall(NULL));
    labyrinths[p].set_cell(6,16, new wall(NULL));
    labyrinths[p].set_cell(6,17, new wall(NULL));
    labyrinths[p].set_cell(6,18, new wall(NULL));
    labyrinths[p].set_cell(6,19, new wall(NULL));
    labyrinths[p].set_cell(7,5, new wall(NULL));
    labyrinths[p].set_cell(7,6, new wall(NULL));
    labyrinths[p].set_cell(7,8, new wall(NULL));
    labyrinths[p].set_cell(7,9, new wall(NULL));
    labyrinths[p].set_cell(7,13, new wall(NULL));
    labyrinths[p].set_cell(7,14, new wall(NULL));
    labyrinths[p].set_cell(8,1, new wall(NULL));
    labyrinths[p].set_cell(8,3, new wall(NULL));
    labyrinths[p].set_cell(8,5, new wall(NULL));
    labyrinths[p].set_cell(8,6, new wall(NULL));
    labyrinths[p].set_cell(8,9, new wall(NULL));
    labyrinths[p].set_cell(8,11, new wall(NULL));
    labyrinths[p].set_cell(8,13, new wall(NULL));
    labyrinths[p].set_cell(8,16, new wall(NULL));
    labyrinths[p].set_cell(9,7, new wall(NULL));
    labyrinths[p].set_cell(9,11, new wall(NULL));
    labyrinths[p].set_cell(9,14, new wall(NULL));
    labyrinths[p].set_cell(9,16, new wall(NULL));
    labyrinths[p].set_cell(9,19, new wall(NULL));
    labyrinths[p].set_cell(10,1, new wall(NULL));
    labyrinths[p].set_cell(10,6, new wall(NULL));
    labyrinths[p].set_cell(10,17, new wall(NULL));
    labyrinths[p].set_cell(11,2, new wall(NULL));
    labyrinths[p].set_cell(11,4, new wall(NULL));
    labyrinths[p].set_cell(11,5, new wall(NULL));
    labyrinths[p].set_cell(11,10, new wall(NULL));
    labyrinths[p].set_cell(11,17, new wall(NULL));
    labyrinths[p].set_cell(11,19, new wall(NULL));
    labyrinths[p].set_cell(12,4, new wall(NULL));
    labyrinths[p].set_cell(12,7, new wall(NULL));
    labyrinths[p].set_cell(12,9, new wall(NULL));
    labyrinths[p].set_cell(12,11, new wall(NULL));
    labyrinths[p].set_cell(12,16, new wall(NULL));
    labyrinths[p].set_cell(13,1, new wall(NULL));
    labyrinths[p].set_cell(13,2, new wall(NULL));
    labyrinths[p].set_cell(13,5, new wall(NULL));
    labyrinths[p].set_cell(13,9, new wall(NULL));
    labyrinths[p].set_cell(13,13, new wall(NULL));
    labyrinths[p].set_cell(13,19, new wall(NULL));
    labyrinths[p].set_cell(14,3, new wall(NULL));
    labyrinths[p].set_cell(14,13, new wall(NULL));
    labyrinths[p].set_cell(14,15, new wall(NULL));
    labyrinths[p].set_cell(14,16, new wall(NULL));
    labyrinths[p].set_cell(14,19, new wall(NULL));
    labyrinths[p].set_cell(15,0, new wall(NULL));
    labyrinths[p].set_cell(15,1, new wall(NULL));
    labyrinths[p].set_cell(15,6, new wall(NULL));
    labyrinths[p].set_cell(15,7, new wall(NULL));
    labyrinths[p].set_cell(15,9, new wall(NULL));
    labyrinths[p].set_cell(15,12, new wall(NULL));
    labyrinths[p].set_cell(15,17, new wall(NULL));
    labyrinths[p].set_cell(15,18, new wall(NULL));
    labyrinths[p].set_cell(16,8, new wall(NULL));
    labyrinths[p].set_cell(16,9, new wall(NULL));
    labyrinths[p].set_cell(16,13, new wall(NULL));
    labyrinths[p].set_cell(16,14, new wall(NULL));
    labyrinths[p].set_cell(16,15, new wall(NULL));
    labyrinths[p].set_cell(17,0, new wall(NULL));
    labyrinths[p].set_cell(17,1, new wall(NULL));
    labyrinths[p].set_cell(17,3, new wall(NULL));
    labyrinths[p].set_cell(17,5, new wall(NULL));
    labyrinths[p].set_cell(17,6, new wall(NULL));
    labyrinths[p].set_cell(17,9, new wall(NULL));
    labyrinths[p].set_cell(17,11, new wall(NULL));
    labyrinths[p].set_cell(18,2, new wall(NULL));
    labyrinths[p].set_cell(18,3, new wall(NULL));
    labyrinths[p].set_cell(18,8, new wall(NULL));
    labyrinths[p].set_cell(18,13, new wall(NULL));
    labyrinths[p].set_cell(18,17, new wall(NULL));
    labyrinths[p].set_cell(18,18, new wall(NULL));
    labyrinths[p].set_cell(18,19, new wall(NULL));
    labyrinths[p].set_cell(19,0, new wall(NULL));
    labyrinths[p].set_cell(19,2, new wall(NULL));
    labyrinths[p].set_cell(19,3, new wall(NULL));
    labyrinths[p].set_cell(19,4, new wall(NULL));
    labyrinths[p].set_cell(19,8, new wall(NULL));
    labyrinths[p].set_cell(19,11, new wall(NULL));
    labyrinths[p].set_cell(19,15, new wall(NULL));
    labyrinths[p].set_cell(19,17, new wall(NULL));
    labyrinths[p].set_cell(19,18, new wall(NULL));

    labyrinths[p].set_start_row(1);
    labyrinths[p].set_start_col(1);

}

void fill_labyrinths(vector<field>& labyrinths)
{
    f0(labyrinths);
    f1(labyrinths);
    lab_uspenskaya(labyrinths);
}

