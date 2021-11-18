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
void f2(vector<field>& labyrinths)
{
    labyrinths.push_back(field(20,20));
    int p = labyrinths.size()-1;
    victory * v = new victory(&labyrinths[p]);
    vector <int> line0 = {2,4,8,9,10,11,12,13};
    for(int i(0);i < line0.size();i++)
    {
        labyrinths[p].set_cell(0,line0[i], new wall(NULL));

    }
    vector <int> line1 = {4,5,6,9,11,15,18,19,20};
    for(int i(0);i < line1.size();i++)
    {
        labyrinths[p].set_cell(1,line1[i], new wall(NULL));

    }
    vector <int> line2 = {2,4,7,8,9,10,13,14,20};
    for(int i(0);i< line2.size();i++)
    {
        labyrinths[p].set_cell(2,line2[i], new wall(NULL));

    }
    vector <int> line3 = {2,4,6,9,13,16,17,18};
    for(int i(0);i< line3.size();i++)
    {
        labyrinths[p].set_cell(3,line3[i], new wall(NULL));

    }
    vector <int> line4 = {4,7,9,14,15,16,17,19};
    for(int i(0);i< line4.size();i++)
    {
        labyrinths[p].set_cell(4,line4[i], new wall(NULL));

    }
    vector <int> line5 = {2,3,6,8,11,12,15,18};
    for(int i(0);i< line5.size();i++)
    {
        labyrinths[p].set_cell(5,line5[i], new wall(NULL));

    }
    vector <int> line6 = {1,2,4,5,7,9,11,12,14,15,18,19};
    for(int i(0);i< line6.size();i++)
    {
        labyrinths[p].set_cell(6,line6[i], new wall(NULL));

    }
    vector <int> line7 = {6,10,13,15,17,18};
    for(int i(0);i< line7.size();i++)
    {
        labyrinths[p].set_cell(7,line7[i], new wall(NULL));

    }
    vector <int> line8 = {1,4,5,6,8,9,11,13,14,15,16,18};
    for(int i(0);i< line8.size();i++)
    {
        labyrinths[p].set_cell(8,line8[i], new wall(NULL));

    }
    vector <int> line9 = {1,3,4,5,6,8,12,14,18};
    for(int i(0);i< line9.size();i++)
    {
        labyrinths[p].set_cell(9,line9[i], new wall(NULL));

    }
    vector <int> line10 = {4,5,9,14,15,18,19};
    for(int i(0);i< line10.size();i++)
    {
        labyrinths[p].set_cell(10,line10[i], new wall(NULL));

    }
    vector <int> line11 = {3,6,9,12,13,17,18,20};
    for(int i(0);i< line11.size();i++)
    {
        labyrinths[p].set_cell(11,line11[i], new wall(NULL));

    }
    vector <int> line12 = {3,4,7,15,20};
    for(int i(0);i< line12.size();i++)
    {
        labyrinths[p].set_cell(12,line12[i], new wall(NULL));

    }
    vector <int> line13 = {4,9,10,12,13};
    for(int i(0);i< line13.size();i++)
    {
        labyrinths[p].set_cell(13,line13[i], new wall(NULL));

    }
    vector <int> line14 = {3,7,15,16,18,19,20};
    for(int i(0);i< line14.size();i++)
    {
        labyrinths[p].set_cell(14,line14[i], new wall(NULL));

    }
    vector <int> line15 = {1,4,7,8,12,13,14,20};
    for(int i(0);i< line15.size();i++)
    {
        labyrinths[p].set_cell(15,line15[i], new wall(NULL));

    }
    vector <int> line16 = {3,10,12,16,17,18,20};
    for(int i(0);i< line16.size();i++)
    {
        labyrinths[p].set_cell(16,line16[i], new wall(NULL));

    }
    vector <int> line17 = {2,6,7,8,10,11,12,15,16,18,20};
    for(int i(0);i< line17.size();i++)
    {
        labyrinths[p].set_cell(17,line17[i], new wall(NULL));

    }
    vector <int> line18 = {4,9,10,16,20};
    for(int i(0);i< line18.size();i++)
    {
        labyrinths[p].set_cell(18,line18[i], new wall(NULL));

    }
    vector <int> line19 = {2,3,9,10,11,15,20};
    for(int i(0);i< line19.size();i++)
    {
        labyrinths[p].set_cell(19,line19[i], new wall(NULL));

    }


    labyrinths[p].set_cell(19,19, v);
    labyrinths[p].set_start_row(2);
    labyrinths[p].set_start_col(2);
}

void fill_labyrinths(vector<field>& labyrinths)
{
    f0(labyrinths);
    f1(labyrinths);
    f2(labyrinths);

}

