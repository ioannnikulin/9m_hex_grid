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
void f_ermolaeva(vector<field>& labyrinths)
{
labyrinths.push_back(field(24, 24));
int p = labyrinths.size() - 1;
victory* v = new victory(&labyrinths[p]);
vector<int> fil0 = { 2,4,10,11,13,16,17,18,21,22 };
for (int i(0); i < fil0.size(); i++)
{
labyrinths[p].set_cell(0, fil0[i], new wall(NULL));
}
vector<int> fil1 = { 1,7,9,10,15,18,22,23 };
for (int i(0); i < fil1.size(); i++)
{
labyrinths[p].set_cell(1, fil1[i], new wall(NULL));
}
vector<int> fil2 = { 3,4,5,6,7,8,14,16,18,19,20,22 };
for (int i(0); i < fil2.size(); i++)
{
labyrinths[p].set_cell(2, fil2[i], new wall(NULL));
}
vector<int> fil3 = { 0,2,8,10,11,12,16,17,19,21,22 };
for (int i(0); i < fil3.size(); i++)
{
labyrinths[p].set_cell(3, fil3[i], new wall(NULL));
}
vector<int> fil4 = { 1,2,4,6,9,10,15,18,19,22 };
for (int i(0); i < fil4.size(); i++)
{
labyrinths[p].set_cell(4, fil4[i], new wall(NULL));
}
vector<int> fil5 = { 2,4,6,7,8,10,11,14,16,22 };
for (int i(0); i < fil5.size(); i++)
{
labyrinths[p].set_cell(5, fil5[i], new wall(NULL));
}
vector<int> fil6 = { 0,2,3,4,9,10,12,16,18,22,23 };
for (int i(0); i < fil6.size(); i++)
{
labyrinths[p].set_cell(6, fil6[i], new wall(NULL));
}
vector<int> fil7 = { 2,3,4,7,9,12,14,15,17,18,19,22 };
for (int i(0); i < fil7.size(); i++)
{
labyrinths[p].set_cell(7, fil7[i], new wall(NULL));
}
vector<int> fil8 = { 1,3,6,7,10,12,15,17,21,22,23 };
for (int i(0); i < fil8.size(); i++)
{
labyrinths[p].set_cell(8, fil8[i], new wall(NULL));
}
vector<int> fil9 = { 2,3,4,8,9,12,14,16,17,20,23 };
for (int i(0); i < fil9.size(); i++)
{
labyrinths[p].set_cell(9, fil9[i], new wall(NULL));
}
vector<int> fil10 = { 2,3,4,6,7,16,17,19,20,22,23 };
for (int i(0); i < fil10.size(); i++)
{
labyrinths[p].set_cell(10, fil10[i], new wall(NULL));
}
vector<int> fil11 = { 1,2,4,8,13,14,16,19,21,22 };
for (int i(0); i < fil11.size(); i++)
{
labyrinths[p].set_cell(11, fil11[i], new wall(NULL));
}
vector<int> fil12 = { 1,3,4,6,8,9,11,12,13,14,16,19,21,22 };
for (int i(0); i < fil12.size(); i++)
{
labyrinths[p].set_cell(12, fil12[i], new wall(NULL));
}
vector<int> fil13 = { 4,11,17,19,20,22 };
for (int i(0); i < fil13.size(); i++)
{
labyrinths[p].set_cell(13, fil13[i], new wall(NULL));
}
vector<int> fil14 = { 0,5,7,10,11,13,16,17,20 };
for (int i(0); i < fil14.size(); i++)
{
labyrinths[p].set_cell(14, fil14[i], new wall(NULL));
}
vector<int> fil15 = { 0,1,3,4,6,9,12,13,14,17,18,19,20,21 };
for (int i(0); i < fil15.size(); i++)
{
labyrinths[p].set_cell(15, fil15[i], new wall(NULL));
}
vector<int> fil16 = { 4,5,6,8,9,11,12,14,15,17,18,19,21,22,23 };
for (int i(0); i < fil16.size(); i++)
{
labyrinths[p].set_cell(16, fil16[i], new wall(NULL));
}
vector<int> fil17 = { 0,1,3,5,6,8,13,16,17,18,19,22,23 };
for (int i(0); i < fil17.size(); i++)
{
labyrinths[p].set_cell(17, fil17[i], new wall(NULL));
}
vector<int> fil18 = { 4,5,6,9,11,13,14,17,19,23 };
for (int i(0); i < fil18.size(); i++)
{
labyrinths[p].set_cell(18, fil18[i], new wall(NULL));
}
vector<int> fil19 = { 2,4,5,7,8,9,11,12,15,16,19,21,22 };
for (int i(0); i < fil19.size(); i++)
{
labyrinths[p].set_cell(19, fil19[i], new wall(NULL));
}
vector<int> fil20 = { 1,2,4,11,13,15,20,21 };
for (int i(0); i < fil20.size(); i++)
{
labyrinths[p].set_cell(20, fil20[i], new wall(NULL));
}
vector<int> fil21 = { 0,1,3,5,7,10,13,19,21,22,23 };
for (int i(0); i < fil21.size(); i++)
{
labyrinths[p].set_cell(21, fil21[i], new wall(NULL));
}
vector<int> fil22 = { 6,9,11,12,13,15,17,19 };
for (int i(0); i < fil22.size(); i++)
{
labyrinths[p].set_cell(22, fil22[i], new wall(NULL));
}
vector<int> fil23 = { 2,4,5,9,12,13,21,22 };
for (int i(0); i < fil23.size(); i++)
{
labyrinths[p].set_cell(23, fil23[i], new wall(NULL));
}
labyrinths[p].set_cell(23, 23, v);
labyrinths[p].set_start_row(0);
labyrinths[p].set_start_col(0);
}
void fill_labyrinths(vector<field>& labyrinths)
{
    f0(labyrinths);
    f1(labyrinths);
    f_ermolaeva(labyrinths);
}

