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
void labTruefunoff(vector<field>& labyrinths){
    int p = labyrinths.size();
    labyrinths.push_back(field(20, 20));
    victory * v = new victory(&labyrinths[p]);
    labyrinths[p].set_cell(0,0, new wall(NULL));
    labyrinths[p].set_cell(0,1, new wall(NULL));
    labyrinths[p].set_cell(0,2, new wall(NULL));
    labyrinths[p].set_start_row(0);
    labyrinths[p].set_start_col(4);
    labyrinths[p].set_cell(0,5, new wall(NULL));
    labyrinths[p].set_cell(0,8, new wall(NULL));
    labyrinths[p].set_cell(0,9, new wall(NULL));
    labyrinths[p].set_cell(0,10, new wall(NULL));
    labyrinths[p].set_cell(0,11, new wall(NULL));
    labyrinths[p].set_cell(0,12, new wall(NULL));
    labyrinths[p].set_cell(0,13, new wall(NULL));
    labyrinths[p].set_cell(0,15, new wall(NULL));
    labyrinths[p].set_cell(0,16, new wall(NULL));
    labyrinths[p].set_cell(0,19, new wall(NULL));
    labyrinths[p].set_cell(1,1, new wall(NULL));
    labyrinths[p].set_cell(1,16, new wall(NULL));
    labyrinths[p].set_cell(1,19, new wall(NULL));
    labyrinths[p].set_cell(2,0, new wall(NULL));
    labyrinths[p].set_cell(2,1, new wall(NULL));
    labyrinths[p].set_cell(2,7, new wall(NULL));
    labyrinths[p].set_cell(2,8, new wall(NULL));
    labyrinths[p].set_cell(2,10, new wall(NULL));
    labyrinths[p].set_cell(2,12, new wall(NULL));
    labyrinths[p].set_cell(2,13, new wall(NULL));
    labyrinths[p].set_cell(2,15, new wall(NULL));
    labyrinths[p].set_cell(2,16, new wall(NULL));
    labyrinths[p].set_cell(2,17, new wall(NULL));
    labyrinths[p].set_cell(2,18, new wall(NULL));
    labyrinths[p].set_cell(2,19, new wall(NULL));
    labyrinths[p].set_cell(3,7, new wall(NULL));
    labyrinths[p].set_cell(3,8, new wall(NULL));
    labyrinths[p].set_cell(3,13, new wall(NULL));
    labyrinths[p].set_cell(3,14, new wall(NULL));
    labyrinths[p].set_cell(3,16, new wall(NULL));
    labyrinths[p].set_cell(3,17, new wall(NULL));
    labyrinths[p].set_cell(3,18, new wall(NULL));
    labyrinths[p].set_cell(3,19, new wall(NULL));
    labyrinths[p].set_cell(4,7, new wall(NULL));
    labyrinths[p].set_cell(4,9, new wall(NULL));
    labyrinths[p].set_cell(4,10, new wall(NULL));
    labyrinths[p].set_cell(4,12, new wall(NULL));
    labyrinths[p].set_cell(4,13, new wall(NULL));
    labyrinths[p].set_cell(4,14, new wall(NULL));
    labyrinths[p].set_cell(4,15, new wall(NULL));
    labyrinths[p].set_cell(4,16, new wall(NULL));
    labyrinths[p].set_cell(5,1, new wall(NULL));
    labyrinths[p].set_cell(5,2, new wall(NULL));
    labyrinths[p].set_cell(5,5, new wall(NULL));
    labyrinths[p].set_cell(5,6, new wall(NULL));
    labyrinths[p].set_cell(5,7, new wall(NULL));
    labyrinths[p].set_cell(5,11, new wall(NULL));
    labyrinths[p].set_cell(5,12, new wall(NULL));
    labyrinths[p].set_cell(5,13, new wall(NULL));
    labyrinths[p].set_cell(5,15, new wall(NULL));
    labyrinths[p].set_cell(5,16, new wall(NULL));
    labyrinths[p].set_cell(5,19, new wall(NULL));
    labyrinths[p].set_cell(6,0, new wall(NULL));
    labyrinths[p].set_cell(6,3, new wall(NULL));
    labyrinths[p].set_cell(6,9, new wall(NULL));
    labyrinths[p].set_cell(6,10, new wall(NULL));
    labyrinths[p].set_cell(6,12, new wall(NULL));
    labyrinths[p].set_cell(6,13, new wall(NULL));
    labyrinths[p].set_cell(6,15, new wall(NULL));
    labyrinths[p].set_cell(7,2, new wall(NULL));
    labyrinths[p].set_cell(7,3, new wall(NULL));
    labyrinths[p].set_cell(7,4, new wall(NULL));
    labyrinths[p].set_cell(7,5, new wall(NULL));
    labyrinths[p].set_cell(7,6, new wall(NULL));
    labyrinths[p].set_cell(7,12, new wall(NULL));
    labyrinths[p].set_cell(7,13, new wall(NULL));
    labyrinths[p].set_cell(7,14, new wall(NULL));
    labyrinths[p].set_cell(7,15, new wall(NULL));
    labyrinths[p].set_cell(8,0, new wall(NULL));
    labyrinths[p].set_cell(8,1, new wall(NULL));
    labyrinths[p].set_cell(8,6, new wall(NULL));
    labyrinths[p].set_cell(8,7, new wall(NULL));
    labyrinths[p].set_cell(8,8, new wall(NULL));
    labyrinths[p].set_cell(8,13, new wall(NULL));
    labyrinths[p].set_cell(8,14, new wall(NULL));
    labyrinths[p].set_cell(8,15, new wall(NULL));
    labyrinths[p].set_cell(8,16, new wall(NULL));
    labyrinths[p].set_cell(8,17, new wall(NULL));
    labyrinths[p].set_cell(8,18, new wall(NULL));
    labyrinths[p].set_cell(9,0, new wall(NULL));
    labyrinths[p].set_cell(9,1, new wall(NULL));
    labyrinths[p].set_cell(9,2, new wall(NULL));
    labyrinths[p].set_cell(9,8, new wall(NULL));
    labyrinths[p].set_cell(9,9, new wall(NULL));
    labyrinths[p].set_cell(9,11, new wall(NULL));
    labyrinths[p].set_cell(9,12, new wall(NULL));
    labyrinths[p].set_cell(9,14, new wall(NULL));
    labyrinths[p].set_cell(9,15, new wall(NULL));
    labyrinths[p].set_cell(9,19, new wall(NULL));
    labyrinths[p].set_cell(10,2, new wall(NULL));
    labyrinths[p].set_cell(10,3, new wall(NULL));
    labyrinths[p].set_cell(10,5, new wall(NULL));
    labyrinths[p].set_cell(10,6, new wall(NULL));
    labyrinths[p].set_cell(10,12, new wall(NULL));
    labyrinths[p].set_cell(10,14, new wall(NULL));
    labyrinths[p].set_cell(10,17, new wall(NULL));
    labyrinths[p].set_cell(10,18, new wall(NULL));
    labyrinths[p].set_cell(10,19, new wall(NULL));
    labyrinths[p].set_cell(11,2, new wall(NULL));
    labyrinths[p].set_cell(11,6, new wall(NULL));
    labyrinths[p].set_cell(11,9, new wall(NULL));
    labyrinths[p].set_cell(11,12, new wall(NULL));
    labyrinths[p].set_cell(11,15, new wall(NULL));
    labyrinths[p].set_cell(11,16, new wall(NULL));
    labyrinths[p].set_cell(11,17, new wall(NULL));
    labyrinths[p].set_cell(11,19, new wall(NULL));
    labyrinths[p].set_cell(12,0, new wall(NULL));
    labyrinths[p].set_cell(12,3, new wall(NULL));
    labyrinths[p].set_cell(12,4, new wall(NULL));
    labyrinths[p].set_cell(12,5, new wall(NULL));
    labyrinths[p].set_cell(12,6, new wall(NULL));
    labyrinths[p].set_cell(12,7, new wall(NULL));
    labyrinths[p].set_cell(12,9, new wall(NULL));
    labyrinths[p].set_cell(12,11, new wall(NULL));
    labyrinths[p].set_cell(12,14, new wall(NULL));
    labyrinths[p].set_cell(12,15, new wall(NULL));
    labyrinths[p].set_cell(12,16, new wall(NULL));
    labyrinths[p].set_cell(13,1, new wall(NULL));
    labyrinths[p].set_cell(13,4, new wall(NULL));
    labyrinths[p].set_cell(13,5, new wall(NULL));
    labyrinths[p].set_cell(13,6, new wall(NULL));
    labyrinths[p].set_cell(13,7, new wall(NULL));
    labyrinths[p].set_cell(13,9, new wall(NULL));
    labyrinths[p].set_cell(13,10, new wall(NULL));
    labyrinths[p].set_cell(13,12, new wall(NULL));
    labyrinths[p].set_cell(14,0, new wall(NULL));
    labyrinths[p].set_cell(14,2, new wall(NULL));
    labyrinths[p].set_cell(14,4, new wall(NULL));
    labyrinths[p].set_cell(14,10, new wall(NULL));
    labyrinths[p].set_cell(14,13, new wall(NULL));
    labyrinths[p].set_cell(14,14, new wall(NULL));
    labyrinths[p].set_cell(14,16, new wall(NULL));
    labyrinths[p].set_cell(14,18, new wall(NULL));
    labyrinths[p].set_cell(14,19, v);
    labyrinths[p].set_cell(15,0, new wall(NULL));
    labyrinths[p].set_cell(15,2, new wall(NULL));
    labyrinths[p].set_cell(15,5, new wall(NULL));
    labyrinths[p].set_cell(15,7, new wall(NULL));
    labyrinths[p].set_cell(15,9, new wall(NULL));
    labyrinths[p].set_cell(15,11, new wall(NULL));
    labyrinths[p].set_cell(15,13, new wall(NULL));
    labyrinths[p].set_cell(15,14, new wall(NULL));
    labyrinths[p].set_cell(15,17, new wall(NULL));
    labyrinths[p].set_cell(15,18, new wall(NULL));
    labyrinths[p].set_cell(15,19, new wall(NULL));
    labyrinths[p].set_cell(16,0, new wall(NULL));
    labyrinths[p].set_cell(16,1, new wall(NULL));
    labyrinths[p].set_cell(16,2, new wall(NULL));
    labyrinths[p].set_cell(16,4, new wall(NULL));
    labyrinths[p].set_cell(16,6, new wall(NULL));
    labyrinths[p].set_cell(16,7, new wall(NULL));
    labyrinths[p].set_cell(16,8, new wall(NULL));
    labyrinths[p].set_cell(16,10, new wall(NULL));
    labyrinths[p].set_cell(16,11, new wall(NULL));
    labyrinths[p].set_cell(16,12, new wall(NULL));
    labyrinths[p].set_cell(16,13, new wall(NULL));
    labyrinths[p].set_cell(16,14, new wall(NULL));
    labyrinths[p].set_cell(16,16, new wall(NULL));
    labyrinths[p].set_cell(16,17, new wall(NULL));
    labyrinths[p].set_cell(16,19, new wall(NULL));
    labyrinths[p].set_cell(17,1, new wall(NULL));
    labyrinths[p].set_cell(17,2, new wall(NULL));
    labyrinths[p].set_cell(17,7, new wall(NULL));
    labyrinths[p].set_cell(17,11, new wall(NULL));
    labyrinths[p].set_cell(17,14, new wall(NULL));
    labyrinths[p].set_cell(17,15, new wall(NULL));
    labyrinths[p].set_cell(17,16, new wall(NULL));
    labyrinths[p].set_cell(17,19, new wall(NULL));
    labyrinths[p].set_cell(18,1, new wall(NULL));
    labyrinths[p].set_cell(18,2, new wall(NULL));
    labyrinths[p].set_cell(18,6, new wall(NULL));
    labyrinths[p].set_cell(18,10, new wall(NULL));
    labyrinths[p].set_cell(18,12, new wall(NULL));
    labyrinths[p].set_cell(18,14, new wall(NULL));
    labyrinths[p].set_cell(18,15, new wall(NULL));
    labyrinths[p].set_cell(18,17, new wall(NULL));
    labyrinths[p].set_cell(18,19, new wall(NULL));
    labyrinths[p].set_cell(19,0, new wall(NULL));
    labyrinths[p].set_cell(19,5, new wall(NULL));
    labyrinths[p].set_cell(19,6, new wall(NULL));
    labyrinths[p].set_cell(19,8, new wall(NULL));
    labyrinths[p].set_cell(19,9, new wall(NULL));
    labyrinths[p].set_cell(19,10, new wall(NULL));
    labyrinths[p].set_cell(19,11, new wall(NULL));
    labyrinths[p].set_cell(19,14, new wall(NULL));
    labyrinths[p].set_cell(19,15, new wall(NULL));
    labyrinths[p].set_cell(19,18, new wall(NULL));
    labyrinths[p].set_cell(19,19, new wall(NULL));
    /*
    Add victory position and player position
    */
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
    labyrinths[p].set_cell(17,19, v);
    labyrinths[p].set_start_row(1);
    labyrinths[p].set_start_col(1);

}


void ushenin_lab_1(vector<field>& labyrinths){
    int p = labyrinths.size();
    labyrinths.push_back(field(30, 30));
    victory * v = new victory(&labyrinths[p]);
    labyrinths[p].set_cell(0,2, new wall(NULL));
    labyrinths[p].set_cell(0,6, new wall(NULL));
    labyrinths[p].set_cell(0,13, new wall(NULL));
    labyrinths[p].set_cell(0,14, new wall(NULL));
    labyrinths[p].set_cell(0,15, new wall(NULL));
    labyrinths[p].set_cell(0,19, new wall(NULL));
    labyrinths[p].set_cell(0,20, new wall(NULL));
    labyrinths[p].set_cell(0,23, new wall(NULL));
    labyrinths[p].set_cell(0,26, new wall(NULL));
    labyrinths[p].set_cell(0,28, new wall(NULL));
    labyrinths[p].set_cell(1,1, new wall(NULL));
    labyrinths[p].set_cell(1,2, new wall(NULL));
    labyrinths[p].set_cell(1,6, new wall(NULL));
    labyrinths[p].set_cell(1,9, new wall(NULL));
    labyrinths[p].set_cell(1,10, new wall(NULL));
    labyrinths[p].set_cell(1,12, new wall(NULL));
    labyrinths[p].set_cell(1,16, new wall(NULL));
    labyrinths[p].set_cell(1,21, new wall(NULL));
    labyrinths[p].set_cell(1,24, new wall(NULL));
    labyrinths[p].set_cell(1,27, new wall(NULL));
    labyrinths[p].set_cell(2,0, new wall(NULL));
    labyrinths[p].set_start_row(2);
    labyrinths[p].set_start_col(1);
    labyrinths[p].set_cell(2,3, new wall(NULL));
    labyrinths[p].set_cell(2,8, new wall(NULL));
    labyrinths[p].set_cell(2,13, new wall(NULL));
    labyrinths[p].set_cell(2,17, new wall(NULL));
    labyrinths[p].set_cell(2,22, new wall(NULL));
    labyrinths[p].set_cell(2,24, new wall(NULL));
    labyrinths[p].set_cell(3,2, new wall(NULL));
    labyrinths[p].set_cell(3,5, new wall(NULL));
    labyrinths[p].set_cell(3,6, new wall(NULL));
    labyrinths[p].set_cell(3,10, new wall(NULL));
    labyrinths[p].set_cell(3,12, new wall(NULL));
    labyrinths[p].set_cell(3,18, new wall(NULL));
    labyrinths[p].set_cell(3,20, new wall(NULL));
    labyrinths[p].set_cell(3,21, new wall(NULL));
    labyrinths[p].set_cell(3,24, new wall(NULL));
    labyrinths[p].set_cell(3,25, new wall(NULL));
    labyrinths[p].set_cell(4,2, new wall(NULL));
    labyrinths[p].set_cell(4,8, new wall(NULL));
    labyrinths[p].set_cell(4,9, new wall(NULL));
    labyrinths[p].set_cell(4,18, new wall(NULL));
    labyrinths[p].set_cell(4,20, new wall(NULL));
    labyrinths[p].set_cell(4,21, new wall(NULL));
    labyrinths[p].set_cell(4,24, new wall(NULL));
    labyrinths[p].set_cell(4,28, new wall(NULL));
    labyrinths[p].set_cell(5,1, new wall(NULL));
    labyrinths[p].set_cell(5,4, new wall(NULL));
    labyrinths[p].set_cell(5,6, new wall(NULL));
    labyrinths[p].set_cell(5,19, new wall(NULL));
    labyrinths[p].set_cell(5,21, new wall(NULL));
    labyrinths[p].set_cell(5,24, new wall(NULL));
    labyrinths[p].set_cell(5,26, new wall(NULL));
    labyrinths[p].set_cell(5,27, new wall(NULL));
    labyrinths[p].set_cell(6,1, new wall(NULL));
    labyrinths[p].set_cell(6,4, new wall(NULL));
    labyrinths[p].set_cell(6,6, new wall(NULL));
    labyrinths[p].set_cell(6,16, new wall(NULL));
    labyrinths[p].set_cell(6,17, new wall(NULL));
    labyrinths[p].set_cell(6,18, new wall(NULL));
    labyrinths[p].set_cell(6,21, new wall(NULL));
    labyrinths[p].set_cell(6,23, new wall(NULL));
    labyrinths[p].set_cell(6,26, new wall(NULL));
    labyrinths[p].set_cell(7,6, new wall(NULL));
    labyrinths[p].set_cell(7,15, new wall(NULL));
    labyrinths[p].set_cell(7,16, new wall(NULL));
    labyrinths[p].set_cell(7,18, new wall(NULL));
    labyrinths[p].set_cell(7,20, new wall(NULL));
    labyrinths[p].set_cell(7,22, new wall(NULL));
    labyrinths[p].set_cell(7,25, new wall(NULL));
    labyrinths[p].set_cell(8,4, new wall(NULL));
    labyrinths[p].set_cell(8,5, new wall(NULL));
    labyrinths[p].set_cell(8,13, new wall(NULL));
    labyrinths[p].set_cell(8,14, new wall(NULL));
    labyrinths[p].set_cell(8,16, new wall(NULL));
    labyrinths[p].set_cell(8,19, new wall(NULL));
    labyrinths[p].set_cell(8,23, new wall(NULL));
    labyrinths[p].set_cell(8,28, new wall(NULL));
    labyrinths[p].set_cell(9,7, new wall(NULL));
    labyrinths[p].set_cell(9,8, new wall(NULL));
    labyrinths[p].set_cell(9,10, new wall(NULL));
    labyrinths[p].set_cell(9,14, new wall(NULL));
    labyrinths[p].set_cell(9,15, new wall(NULL));
    labyrinths[p].set_cell(9,18, new wall(NULL));
    labyrinths[p].set_cell(9,22, new wall(NULL));
    labyrinths[p].set_cell(9,25, new wall(NULL));
    labyrinths[p].set_cell(9,26, new wall(NULL));
    labyrinths[p].set_cell(9,28, new wall(NULL));
    labyrinths[p].set_cell(10,4, new wall(NULL));
    labyrinths[p].set_cell(10,8, new wall(NULL));
    labyrinths[p].set_cell(10,9, new wall(NULL));
    labyrinths[p].set_cell(10,13, new wall(NULL));
    labyrinths[p].set_cell(10,14, new wall(NULL));
    labyrinths[p].set_cell(10,15, new wall(NULL));
    labyrinths[p].set_cell(10,18, new wall(NULL));
    labyrinths[p].set_cell(10,23, new wall(NULL));
    labyrinths[p].set_cell(10,28, new wall(NULL));
    labyrinths[p].set_cell(11,0, new wall(NULL));
    labyrinths[p].set_cell(11,2, new wall(NULL));
    labyrinths[p].set_cell(11,9, new wall(NULL));
    labyrinths[p].set_cell(11,12, new wall(NULL));
    labyrinths[p].set_cell(11,15, new wall(NULL));
    labyrinths[p].set_cell(11,19, new wall(NULL));
    labyrinths[p].set_cell(11,20, new wall(NULL));
    labyrinths[p].set_cell(11,21, new wall(NULL));
    labyrinths[p].set_cell(11,22, new wall(NULL));
    labyrinths[p].set_cell(12,0, new wall(NULL));
    labyrinths[p].set_cell(12,6, new wall(NULL));
    labyrinths[p].set_cell(12,11, new wall(NULL));
    labyrinths[p].set_cell(12,14, new wall(NULL));
    labyrinths[p].set_cell(12,22, new wall(NULL));
    labyrinths[p].set_cell(12,23, new wall(NULL));
    labyrinths[p].set_cell(12,26, new wall(NULL));
    labyrinths[p].set_cell(12,29, new wall(NULL));
    labyrinths[p].set_cell(13,3, new wall(NULL));
    labyrinths[p].set_cell(13,6, new wall(NULL));
    labyrinths[p].set_cell(13,8, new wall(NULL));
    labyrinths[p].set_cell(13,9, new wall(NULL));
    labyrinths[p].set_cell(13,13, new wall(NULL));
    labyrinths[p].set_cell(13,15, new wall(NULL));
    labyrinths[p].set_cell(13,16, new wall(NULL));
    labyrinths[p].set_cell(13,19, new wall(NULL));
    labyrinths[p].set_cell(13,20, new wall(NULL));
    labyrinths[p].set_cell(13,28, new wall(NULL));
    labyrinths[p].set_cell(13,29, new wall(NULL));
    labyrinths[p].set_cell(14,3, new wall(NULL));
    labyrinths[p].set_cell(14,4, new wall(NULL));
    labyrinths[p].set_cell(14,6, new wall(NULL));
    labyrinths[p].set_cell(14,17, new wall(NULL));
    labyrinths[p].set_cell(14,21, new wall(NULL));
    labyrinths[p].set_cell(14,22, new wall(NULL));
    labyrinths[p].set_cell(15,1, new wall(NULL));
    labyrinths[p].set_cell(15,8, new wall(NULL));
    labyrinths[p].set_cell(15,12, new wall(NULL));
    labyrinths[p].set_cell(15,15, new wall(NULL));
    labyrinths[p].set_cell(15,24, new wall(NULL));
    labyrinths[p].set_cell(15,29, new wall(NULL));
    labyrinths[p].set_cell(16,6, new wall(NULL));
    labyrinths[p].set_cell(16,8, new wall(NULL));
    labyrinths[p].set_cell(16,14, new wall(NULL));
    labyrinths[p].set_cell(16,17, new wall(NULL));
    labyrinths[p].set_cell(16,21, new wall(NULL));
    labyrinths[p].set_cell(16,24, new wall(NULL));
    labyrinths[p].set_cell(17,0, new wall(NULL));
    labyrinths[p].set_cell(17,11, new wall(NULL));
    labyrinths[p].set_cell(17,15, new wall(NULL));
    labyrinths[p].set_cell(17,16, new wall(NULL));
    labyrinths[p].set_cell(17,19, new wall(NULL));
    labyrinths[p].set_cell(18,1, new wall(NULL));
    labyrinths[p].set_cell(18,4, new wall(NULL));
    labyrinths[p].set_cell(18,5, new wall(NULL));
    labyrinths[p].set_cell(18,6, new wall(NULL));
    labyrinths[p].set_cell(18,13, new wall(NULL));
    labyrinths[p].set_cell(18,15, new wall(NULL));
    labyrinths[p].set_cell(18,16, new wall(NULL));
    labyrinths[p].set_cell(18,19, new wall(NULL));
    labyrinths[p].set_cell(18,22, new wall(NULL));
    labyrinths[p].set_cell(18,27, new wall(NULL));
    labyrinths[p].set_cell(19,4, new wall(NULL));
    labyrinths[p].set_cell(19,5, new wall(NULL));
    labyrinths[p].set_cell(19,15, new wall(NULL));
    labyrinths[p].set_cell(19,16, new wall(NULL));
    labyrinths[p].set_cell(19,20, new wall(NULL));
    labyrinths[p].set_cell(19,22, new wall(NULL));
    labyrinths[p].set_cell(19,23, new wall(NULL));
    labyrinths[p].set_cell(19,24, new wall(NULL));
    labyrinths[p].set_cell(19,25, new wall(NULL));
    labyrinths[p].set_cell(19,26, new wall(NULL));
    labyrinths[p].set_cell(19,27, new wall(NULL));
    labyrinths[p].set_cell(20,1, new wall(NULL));
    labyrinths[p].set_cell(20,5, new wall(NULL));
    labyrinths[p].set_cell(20,7, new wall(NULL));
    labyrinths[p].set_cell(20,10, new wall(NULL));
    labyrinths[p].set_cell(20,22, new wall(NULL));
    labyrinths[p].set_cell(20,23, new wall(NULL));
    labyrinths[p].set_cell(20,28, new wall(NULL));
    labyrinths[p].set_cell(21,2, new wall(NULL));
    labyrinths[p].set_cell(21,4, new wall(NULL));
    labyrinths[p].set_cell(21,5, new wall(NULL));
    labyrinths[p].set_cell(21,9, new wall(NULL));
    labyrinths[p].set_cell(21,15, new wall(NULL));
    labyrinths[p].set_cell(21,16, new wall(NULL));
    labyrinths[p].set_cell(21,19, new wall(NULL));
    labyrinths[p].set_cell(21,27, new wall(NULL));
    labyrinths[p].set_cell(21,28, new wall(NULL));
    labyrinths[p].set_cell(22,0, new wall(NULL));
    labyrinths[p].set_cell(22,5, new wall(NULL));
    labyrinths[p].set_cell(22,7, new wall(NULL));
    labyrinths[p].set_cell(22,9, new wall(NULL));
    labyrinths[p].set_cell(22,13, new wall(NULL));
    labyrinths[p].set_cell(22,14, new wall(NULL));
    labyrinths[p].set_cell(22,20, new wall(NULL));
    labyrinths[p].set_cell(22,27, new wall(NULL));
    labyrinths[p].set_cell(23,2, new wall(NULL));
    labyrinths[p].set_cell(23,5, new wall(NULL));
    labyrinths[p].set_cell(23,6, new wall(NULL));
    labyrinths[p].set_cell(23,11, new wall(NULL));
    labyrinths[p].set_cell(23,14, new wall(NULL));
    labyrinths[p].set_cell(23,18, new wall(NULL));
    labyrinths[p].set_cell(23,27, new wall(NULL));
    labyrinths[p].set_cell(23,28, new wall(NULL));
    labyrinths[p].set_cell(24,5, new wall(NULL));
    labyrinths[p].set_cell(24,9, new wall(NULL));
    labyrinths[p].set_cell(24,11, new wall(NULL));
    labyrinths[p].set_cell(24,12, new wall(NULL));
    labyrinths[p].set_cell(24,13, new wall(NULL));
    labyrinths[p].set_cell(24,16, new wall(NULL));
    labyrinths[p].set_cell(24,19, new wall(NULL));
    labyrinths[p].set_cell(24,23, new wall(NULL));
    labyrinths[p].set_cell(25,21, new wall(NULL));
    labyrinths[p].set_cell(25,24, new wall(NULL));
    labyrinths[p].set_cell(25,29, new wall(NULL));
    labyrinths[p].set_cell(26,4, new wall(NULL));
    labyrinths[p].set_cell(26,5, new wall(NULL));
    labyrinths[p].set_cell(26,11, new wall(NULL));
    labyrinths[p].set_cell(26,14, new wall(NULL));
    labyrinths[p].set_cell(26,17, new wall(NULL));
    labyrinths[p].set_cell(26,18, new wall(NULL));
    labyrinths[p].set_cell(26,24, new wall(NULL));
    labyrinths[p].set_cell(27,2, new wall(NULL));
    labyrinths[p].set_cell(27,4, new wall(NULL));
    labyrinths[p].set_cell(27,8, new wall(NULL));
    labyrinths[p].set_cell(27,10, new wall(NULL));
    labyrinths[p].set_cell(27,20, new wall(NULL));
    labyrinths[p].set_cell(27,28, new wall(NULL));
    labyrinths[p].set_cell(27,29, new wall(NULL));
    labyrinths[p].set_cell(28,7, new wall(NULL));
    labyrinths[p].set_cell(28,8, new wall(NULL));
    labyrinths[p].set_cell(28,10, new wall(NULL));
    labyrinths[p].set_cell(28,12, new wall(NULL));
    labyrinths[p].set_cell(28,16, new wall(NULL));
    labyrinths[p].set_cell(28,20, new wall(NULL));
    labyrinths[p].set_cell(28,24, new wall(NULL));
    labyrinths[p].set_cell(28,26, new wall(NULL));
    labyrinths[p].set_cell(28,28, new wall(NULL));
    labyrinths[p].set_cell(28,29, new wall(NULL));
    labyrinths[p].set_cell(29,1, new wall(NULL));
    labyrinths[p].set_cell(29,6, new wall(NULL));
    labyrinths[p].set_cell(29,7, new wall(NULL));
    labyrinths[p].set_cell(29,8, new wall(NULL));
    labyrinths[p].set_cell(29,9, new wall(NULL));
    labyrinths[p].set_cell(29,11, new wall(NULL));
    labyrinths[p].set_cell(29,13, new wall(NULL));
    labyrinths[p].set_cell(29,15, new wall(NULL));
    labyrinths[p].set_cell(29,16, new wall(NULL));
    labyrinths[p].set_cell(29,19, new wall(NULL));
    labyrinths[p].set_cell(29,26, new wall(NULL));
    labyrinths[p].set_cell(29,29, v);
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


void f_Art(vector<field>& labyrinths)
{
    labyrinths.push_back(field(21,24));
    int p = labyrinths.size()-1;
    victory * v = new victory(&labyrinths[p]);
    for(int i(4);i<16;i++)
    {
    labyrinths[p].set_cell(i,1, new wall(NULL));
    }
    for(int i(8);i<16;i++)
    {
    labyrinths[p].set_cell(0,i, new wall(NULL));
    }
    for(int i(17);i<21;i++)
    {
    labyrinths[p].set_cell(1,i, new wall(NULL));
    }for(int i(0);i<3;i++)
    {
    labyrinths[p].set_cell(2,i, new wall(NULL));
    }
    for(int i(7);i<16;i++)
    {
    labyrinths[p].set_cell(2,i, new wall(NULL));
    }
    for(int i(3);i<7;i++)
    {
    labyrinths[p].set_cell(4,i, new wall(NULL));
    }
    for(int i(10);i<12;i++)
    {
    labyrinths[p].set_cell(4,i, new wall(NULL));
    }
    for(int i(11);i<14;i++)
    {
    labyrinths[p].set_cell(5,i, new wall(NULL));
    }
    for(int i(17);i<20;i++)
    {
    labyrinths[p].set_cell(5,i, new wall(NULL));
    }
    for(int i(8);i<11;i++)
    {
    labyrinths[p].set_cell(8,i, new wall(NULL));
    }
    for(int i(6);i<10;i++)
    {
    labyrinths[p].set_cell(11,i, new wall(NULL));
    }
    for(int i(20);i<23;i++)
    {
    labyrinths[p].set_cell(12,i, new wall(NULL));
    }
    for(int i(8);i<12;i++)
    {
    labyrinths[p].set_cell(13,i, new wall(NULL));
    }
    for(int i(16);i<19;i++)
    {
    labyrinths[p].set_cell(14,i, new wall(NULL));
    }
    for(int i(3);i<6;i++)
    {
    labyrinths[p].set_cell(15,i, new wall(NULL));
    }
    for(int i(9);i<14;i++)
    {
    labyrinths[p].set_cell(15,i, new wall(NULL));
    }
    for(int i(20);i<24;i++)
    {
    labyrinths[p].set_cell(16,i, new wall(NULL));
    }
    for(int i(2);i<5;i++)
    {
    labyrinths[p].set_cell(17,i, new wall(NULL));
    }
    for(int i(10);i<13;i++)
    {
    labyrinths[p].set_cell(17,i, new wall(NULL));
    }
    for(int i(16);i<21;i++)
    {
    labyrinths[p].set_cell(17,i, new wall(NULL));
    }
    for(int i(1);i<4;i++)
    {
    labyrinths[p].set_cell(19,i, new wall(NULL));
    }
    for(int i(13);i<16;i++)
    {
    labyrinths[p].set_cell(19,i, new wall(NULL));
    }
    for(int i(17);i<23;i++)
    {
    labyrinths[p].set_cell(19,i, new wall(NULL));
    }
    for(int i(4);i<7;i++)
    {
    labyrinths[p].set_cell(20,i, new wall(NULL));
    }
    for(int i(10);i<12;i++)
    {
    labyrinths[p].set_cell(20,i, new wall(NULL));
    }


    labyrinths[p].set_cell(0,23, new wall(NULL));		///1 �� �

    labyrinths[p].set_cell(1,4, new wall(NULL));		///2 �� �
    labyrinths[p].set_cell(1,6, new wall(NULL));
    labyrinths[p].set_cell(1,23, new wall(NULL));

    labyrinths[p].set_cell(2,4, new wall(NULL));		///3 �� �
    labyrinths[p].set_cell(2,5, new wall(NULL));
    labyrinths[p].set_cell(2,17, new wall(NULL));
    labyrinths[p].set_cell(2,22, new wall(NULL));

    labyrinths[p].set_cell(3,5, new wall(NULL));		///4 �� �
    labyrinths[p].set_cell(3,7, new wall(NULL));
    labyrinths[p].set_cell(3,12, new wall(NULL));
    labyrinths[p].set_cell(3,14, new wall(NULL));
    labyrinths[p].set_cell(3,17, new wall(NULL));
    labyrinths[p].set_cell(3,19, new wall(NULL));
    labyrinths[p].set_cell(3,20, new wall(NULL));
    labyrinths[p].set_cell(3,22, new wall(NULL));

    labyrinths[p].set_cell(4,14, new wall(NULL));		///5 �� �
    labyrinths[p].set_cell(4,16, new wall(NULL));
    labyrinths[p].set_cell(4,18, new wall(NULL));
    labyrinths[p].set_cell(4,20, new wall(NULL));
    labyrinths[p].set_cell(4,22, new wall(NULL));

    labyrinths[p].set_cell(5,7, new wall(NULL));		///6 �� �
    labyrinths[p].set_cell(5,9, new wall(NULL));
    labyrinths[p].set_cell(5,15, new wall(NULL));
    labyrinths[p].set_cell(5,21, new wall(NULL));
	labyrinths[p].set_cell(5,22, new wall(NULL));

    labyrinths[p].set_cell(6,2, new wall(NULL));		///7 �� �
    labyrinths[p].set_cell(6,4, new wall(NULL));
    labyrinths[p].set_cell(6,5, new wall(NULL));
    labyrinths[p].set_cell(6,7, new wall(NULL));
    labyrinths[p].set_cell(6,9, new wall(NULL));
    labyrinths[p].set_cell(6,11, new wall(NULL));
    labyrinths[p].set_cell(6,12, new wall(NULL));
    labyrinths[p].set_cell(6,15, new wall(NULL));
    labyrinths[p].set_cell(6,17, new wall(NULL));
    labyrinths[p].set_cell(6,19, new wall(NULL));
    labyrinths[p].set_cell(6,22, new wall(NULL));

    labyrinths[p].set_cell(7,4, new wall(NULL));		///8 �� �
    labyrinths[p].set_cell(7,6, new wall(NULL));
    labyrinths[p].set_cell(7,9, new wall(NULL));
    labyrinths[p].set_cell(7,11, new wall(NULL));
    labyrinths[p].set_cell(7,16, new wall(NULL));
    labyrinths[p].set_cell(7,18, new wall(NULL));
    labyrinths[p].set_cell(7,20, new wall(NULL));
    labyrinths[p].set_cell(7,21, new wall(NULL));

    labyrinths[p].set_cell(8,3, new wall(NULL));		///9 �� �
    labyrinths[p].set_cell(8,6, new wall(NULL));
    labyrinths[p].set_cell(8,12, new wall(NULL));
    labyrinths[p].set_cell(8,14, new wall(NULL));
    labyrinths[p].set_cell(8,15, new wall(NULL));
    labyrinths[p].set_cell(8,17, new wall(NULL));
    labyrinths[p].set_cell(8,21, new wall(NULL));
	labyrinths[p].set_cell(8,23, new wall(NULL));

    labyrinths[p].set_cell(9,3, new wall(NULL));		///10 �� �
    labyrinths[p].set_cell(9,5, new wall(NULL));
    labyrinths[p].set_cell(9,7, new wall(NULL));
    labyrinths[p].set_cell(9,10, new wall(NULL));
    labyrinths[p].set_cell(9,15, new wall(NULL));
    labyrinths[p].set_cell(9,17, new wall(NULL));
    labyrinths[p].set_cell(9,19, new wall(NULL));
    labyrinths[p].set_cell(9,21, new wall(NULL));

    labyrinths[p].set_cell(10,3, new wall(NULL));		///11 �� �
    labyrinths[p].set_cell(10,5, new wall(NULL));
    labyrinths[p].set_cell(10,7, new wall(NULL));
    labyrinths[p].set_cell(10,9, new wall(NULL));
    labyrinths[p].set_cell(10,11, new wall(NULL));
    labyrinths[p].set_cell(10,13, new wall(NULL));
    labyrinths[p].set_cell(10,14, new wall(NULL));
    labyrinths[p].set_cell(10,16, new wall(NULL));
    labyrinths[p].set_cell(10,20, new wall(NULL));
    labyrinths[p].set_cell(10,22, new wall(NULL));

    labyrinths[p].set_cell(11,3, new wall(NULL));		///12 �� �
    labyrinths[p].set_cell(11,4, new wall(NULL));
    labyrinths[p].set_cell(11,11, new wall(NULL));
    labyrinths[p].set_cell(11,13, new wall(NULL));
    labyrinths[p].set_cell(11,14, new wall(NULL));
    labyrinths[p].set_cell(11,18, new wall(NULL));
    labyrinths[p].set_cell(11,20, new wall(NULL));
	labyrinths[p].set_cell(11,22, new wall(NULL));

    labyrinths[p].set_cell(12,5, new wall(NULL));		///13 �� �
    labyrinths[p].set_cell(12,11, new wall(NULL));
    labyrinths[p].set_cell(12,13, new wall(NULL));
    labyrinths[p].set_cell(12,14, new wall(NULL));
    labyrinths[p].set_cell(12,16, new wall(NULL));
    labyrinths[p].set_cell(12,18, new wall(NULL));

    labyrinths[p].set_cell(13,3, new wall(NULL));		///14 �� �
    labyrinths[p].set_cell(13,5, new wall(NULL));
    labyrinths[p].set_cell(13,13, new wall(NULL));
    labyrinths[p].set_cell(13,6, new wall(NULL));
    labyrinths[p].set_cell(13,15, new wall(NULL));
    labyrinths[p].set_cell(13,18, new wall(NULL));
    labyrinths[p].set_cell(13,21, new wall(NULL));

    labyrinths[p].set_cell(14,3, new wall(NULL));		///15 �� �
    labyrinths[p].set_cell(14,4, new wall(NULL));
    labyrinths[p].set_cell(14,7, new wall(NULL));
    labyrinths[p].set_cell(14,19, new wall(NULL));
    labyrinths[p].set_cell(14,21, new wall(NULL));
    labyrinths[p].set_cell(14,22, new wall(NULL));

    labyrinths[p].set_cell(15,7, new wall(NULL));		///16 �� �
    labyrinths[p].set_cell(15,14, new wall(NULL));
    labyrinths[p].set_cell(15,15, new wall(NULL));
    labyrinths[p].set_cell(15,16, new wall(NULL));
    labyrinths[p].set_cell(15,19, new wall(NULL));

    labyrinths[p].set_cell(16,0, new wall(NULL));		///17 �� �
    labyrinths[p].set_cell(16,2, new wall(NULL));
    labyrinths[p].set_cell(16,6, new wall(NULL));
    labyrinths[p].set_cell(16,9, new wall(NULL));
    labyrinths[p].set_cell(16,14, new wall(NULL));

    labyrinths[p].set_cell(17,0, new wall(NULL));		///18 �� �
    labyrinths[p].set_cell(17,6, new wall(NULL));
    labyrinths[p].set_cell(17,8, new wall(NULL));
    labyrinths[p].set_cell(17,14, new wall(NULL));
	labyrinths[p].set_cell(17,23, new wall(NULL));

    labyrinths[p].set_cell(18,0, new wall(NULL));		///19 �� �
    labyrinths[p].set_cell(18,5, new wall(NULL));
    labyrinths[p].set_cell(18,7, new wall(NULL));
    labyrinths[p].set_cell(18,8, new wall(NULL));
    labyrinths[p].set_cell(18,10, new wall(NULL));
    labyrinths[p].set_cell(18,13, new wall(NULL));
    labyrinths[p].set_cell(18,21, new wall(NULL));

    labyrinths[p].set_cell(19,5, new wall(NULL));		///20 �� �
    labyrinths[p].set_cell(19,7, new wall(NULL));
    labyrinths[p].set_cell(19,8, new wall(NULL));
    labyrinths[p].set_cell(19,11, new wall(NULL));

    labyrinths[p].set_cell(20,20, new wall(NULL));		///21 �� �

    labyrinths[p].set_cell(20,21, v);
    labyrinths[p].set_start_row(0);
    labyrinths[p].set_start_col(0);
}

void fill_labyrinths(vector<field>& labyrinths)
{

    f_Art(labyrinths);
    ushenin_lab_1(labyrinths);
    labTruefunoff(labyrinths);
    lab_uspenskaya(labyrinths);
    tokarenko_lab_1(labyrinths);
}

