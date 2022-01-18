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
void karpov_lab_1(vector<field>& labyrinths)
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
    labyrinths[p].set_start_row(8);
    labyrinths[p].set_start_col(10);
}
void daryina_lab_1(vector<field>& labyrinths)
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
void lab_dubovenko(vector<field>& labyrinths)
   {
    labyrinths.push_back(field(20, 20));
    int p = labyrinths.size()-1;
    victory * v = new victory(&labyrinths[p]);
    labyrinths[p].set_start_row(0);
    labyrinths[p].set_start_col(0);
    labyrinths[p].set_cell(1,0, new wall(NULL));
    labyrinths[p].set_cell(2,0, new wall(NULL));
    labyrinths[p].set_cell(3,0, new wall(NULL));
    labyrinths[p].set_cell(4,0, new wall(NULL));
    labyrinths[p].set_cell(5,0, new wall(NULL));
    labyrinths[p].set_cell(6,0, new wall(NULL));
    labyrinths[p].set_cell(7,0, new wall(NULL));
    labyrinths[p].set_cell(8,0, new wall(NULL));
    labyrinths[p].set_cell(9,0, new wall(NULL));
    labyrinths[p].set_cell(10,0, new wall(NULL));
    labyrinths[p].set_cell(11,0, new wall(NULL));
    labyrinths[p].set_cell(12,0, new wall(NULL));
    labyrinths[p].set_cell(13,0, new wall(NULL));
    labyrinths[p].set_cell(14,0, new wall(NULL));
    labyrinths[p].set_cell(15,0, new wall(NULL));
    labyrinths[p].set_cell(16,0, new wall(NULL));
    labyrinths[p].set_cell(17,0, new wall(NULL));
    labyrinths[p].set_cell(18,0, new wall(NULL));
    labyrinths[p].set_cell(19,0, new wall(NULL));
    labyrinths[p].set_cell(19,1, new wall(NULL));

    labyrinths[p].set_cell(19,4, new wall(NULL));
    labyrinths[p].set_cell(19,5, new wall(NULL));
    labyrinths[p].set_cell(19,6, new wall(NULL));
    labyrinths[p].set_cell(19,7, new wall(NULL));
    labyrinths[p].set_cell(19,8, new wall(NULL));
    labyrinths[p].set_cell(19,9, new wall(NULL));
    labyrinths[p].set_cell(19,10, new wall(NULL));
    labyrinths[p].set_cell(19,11, new wall(NULL));
    labyrinths[p].set_cell(19,12, new wall(NULL));
    labyrinths[p].set_cell(19,13, new wall(NULL));
    labyrinths[p].set_cell(19,14, new wall(NULL));
    labyrinths[p].set_cell(19,15, new wall(NULL));
    labyrinths[p].set_cell(19,16, new wall(NULL));
    labyrinths[p].set_cell(19,17, new wall(NULL));
    labyrinths[p].set_cell(19,18, new wall(NULL));
    labyrinths[p].set_cell(0,1, new wall(NULL));
    labyrinths[p].set_cell(0,2, new wall(NULL));
    labyrinths[p].set_cell(0,3, new wall(NULL));
    labyrinths[p].set_cell(0,4, new wall(NULL));
    labyrinths[p].set_cell(0,5, new wall(NULL));
    labyrinths[p].set_cell(0,6, new wall(NULL));
    labyrinths[p].set_cell(0,7, new wall(NULL));
    labyrinths[p].set_cell(0,8, new wall(NULL));
    labyrinths[p].set_cell(0,9, new wall(NULL));
    labyrinths[p].set_cell(0,10, new wall(NULL));
    labyrinths[p].set_cell(0,11, new wall(NULL));
    labyrinths[p].set_cell(0,12, new wall(NULL));

    labyrinths[p].set_cell(0,15, new wall(NULL));
    labyrinths[p].set_cell(0,16, new wall(NULL));
    labyrinths[p].set_cell(0,17, new wall(NULL));
    labyrinths[p].set_cell(0,18, new wall(NULL));
    labyrinths[p].set_cell(1,18, new wall(NULL));
    labyrinths[p].set_cell(2,18, new wall(NULL));
    labyrinths[p].set_cell(3,18, new wall(NULL));

    labyrinths[p].set_cell(5,18, new wall(NULL));
    labyrinths[p].set_cell(6,18, new wall(NULL));
    labyrinths[p].set_cell(7,18, new wall(NULL));
    labyrinths[p].set_cell(8,18, new wall(NULL));
    labyrinths[p].set_cell(9,18, new wall(NULL));
    labyrinths[p].set_cell(10,18, new wall(NULL));
    labyrinths[p].set_cell(11,18, new wall(NULL));

    labyrinths[p].set_cell(13,18, new wall(NULL));
    labyrinths[p].set_cell(14,18, new wall(NULL));
    labyrinths[p].set_cell(15,18, new wall(NULL));
    labyrinths[p].set_cell(16,18, new wall(NULL));
    labyrinths[p].set_cell(17,18, new wall(NULL));
    labyrinths[p].set_cell(18,18, new wall(NULL));
    labyrinths[p].set_cell(19,18, new wall(NULL));
    labyrinths[p].set_cell(1,2, new wall(NULL));
    labyrinths[p].set_cell(2,2, new wall(NULL));

    labyrinths[p].set_cell(4,2, new wall(NULL));
    labyrinths[p].set_cell(5,2, new wall(NULL));
    labyrinths[p].set_cell(6,2, new wall(NULL));
    labyrinths[p].set_cell(7,2, new wall(NULL));

    labyrinths[p].set_cell(9,2, new wall(NULL));
    labyrinths[p].set_cell(10,2, new wall(NULL));
    labyrinths[p].set_cell(11,2, new wall(NULL));
    labyrinths[p].set_cell(12,2, new wall(NULL));
    labyrinths[p].set_cell(13,2, new wall(NULL));
    labyrinths[p].set_cell(14,2, new wall(NULL));
    labyrinths[p].set_cell(15,2, new wall(NULL));
    labyrinths[p].set_cell(16,2, new wall(NULL));
    labyrinths[p].set_cell(17,2, new wall(NULL));
    labyrinths[p].set_cell(18,2, new wall(NULL));

    labyrinths[p].set_cell(1,4, new wall(NULL));
    labyrinths[p].set_cell(2,4, new wall(NULL));
    labyrinths[p].set_cell(3,4, new wall(NULL));
    labyrinths[p].set_cell(4,4, new wall(NULL));
    labyrinths[p].set_cell(5,4, new wall(NULL));

    labyrinths[p].set_cell(7,4, new wall(NULL));
    labyrinths[p].set_cell(8,4, new wall(NULL));
    labyrinths[p].set_cell(9,4, new wall(NULL));
    labyrinths[p].set_cell(10,4, new wall(NULL));
    labyrinths[p].set_cell(11,4, new wall(NULL));
    labyrinths[p].set_cell(12,4, new wall(NULL));
    labyrinths[p].set_cell(13,4, new wall(NULL));
    labyrinths[p].set_cell(14,4, new wall(NULL));
    labyrinths[p].set_cell(15,4, new wall(NULL));
    labyrinths[p].set_cell(16,4, new wall(NULL));
    labyrinths[p].set_cell(17,4, new wall(NULL));
    labyrinths[p].set_cell(18,4, new wall(NULL));
    labyrinths[p].set_cell(19,4, new wall(NULL));
    labyrinths[p].set_cell(1,6, new wall(NULL));
    labyrinths[p].set_cell(2,6, new wall(NULL));
    labyrinths[p].set_cell(3,6, new wall(NULL));
    labyrinths[p].set_cell(4,6, new wall(NULL));
    labyrinths[p].set_cell(5,6, new wall(NULL));
    labyrinths[p].set_cell(6,6, new wall(NULL));
    labyrinths[p].set_cell(7,6, new wall(NULL));
    labyrinths[p].set_cell(8,6, new wall(NULL));
    labyrinths[p].set_cell(9,6, new wall(NULL));
    labyrinths[p].set_cell(10,6, new wall(NULL));
    labyrinths[p].set_cell(11,6, new wall(NULL));
    labyrinths[p].set_cell(12,6, new wall(NULL));
    labyrinths[p].set_cell(13,6, new wall(NULL));

    labyrinths[p].set_cell(15,6, new wall(NULL));
    labyrinths[p].set_cell(16,6, new wall(NULL));
    labyrinths[p].set_cell(17,6, new wall(NULL));
    labyrinths[p].set_cell(18,6, new wall(NULL));
    labyrinths[p].set_cell(19,6, new wall(NULL));
    labyrinths[p].set_cell(1,8, new wall(NULL));

    labyrinths[p].set_cell(3,8, new wall(NULL));
    labyrinths[p].set_cell(4,8, new wall(NULL));
    labyrinths[p].set_cell(5,8, new wall(NULL));
    labyrinths[p].set_cell(6,8, new wall(NULL));
    labyrinths[p].set_cell(7,8, new wall(NULL));
    labyrinths[p].set_cell(8,8, new wall(NULL));
    labyrinths[p].set_cell(8,9, new wall(NULL));
    labyrinths[p].set_cell(10,8, new wall(NULL));
    labyrinths[p].set_cell(11,8, new wall(NULL));
    labyrinths[p].set_cell(12,8, new wall(NULL));
    labyrinths[p].set_cell(13,8, new wall(NULL));
    labyrinths[p].set_cell(14,8, new wall(NULL));
    labyrinths[p].set_cell(15,8, new wall(NULL));
    labyrinths[p].set_cell(16,8, new wall(NULL));
    labyrinths[p].set_cell(17,8, new wall(NULL));
    labyrinths[p].set_cell(18,8, new wall(NULL));
    labyrinths[p].set_cell(19,8, new wall(NULL));
    labyrinths[p].set_cell(1,10, new wall(NULL));
    labyrinths[p].set_cell(2,10, new wall(NULL));
    labyrinths[p].set_cell(3,10, new wall(NULL));
    labyrinths[p].set_cell(4,10, new wall(NULL));
    labyrinths[p].set_cell(5,10, new wall(NULL));
    labyrinths[p].set_cell(6,10, new wall(NULL));
    labyrinths[p].set_cell(7,10, new wall(NULL));
    labyrinths[p].set_cell(8,10, new wall(NULL));

    labyrinths[p].set_cell(10,10, new wall(NULL));
    labyrinths[p].set_cell(11,10, new wall(NULL));

    labyrinths[p].set_cell(13,10, new wall(NULL));
    labyrinths[p].set_cell(14,10, new wall(NULL));
    labyrinths[p].set_cell(15,10, new wall(NULL));
    labyrinths[p].set_cell(16,10, new wall(NULL));
    labyrinths[p].set_cell(17,10, new wall(NULL));
    labyrinths[p].set_cell(18,10, new wall(NULL));
    labyrinths[p].set_cell(19,10, new wall(NULL));
    labyrinths[p].set_cell(1,12, new wall(NULL));
    labyrinths[p].set_cell(2,12, new wall(NULL));
    labyrinths[p].set_cell(3,12, new wall(NULL));
    labyrinths[p].set_cell(4,12, new wall(NULL));
    labyrinths[p].set_cell(5,12, new wall(NULL));

    labyrinths[p].set_cell(7,12, new wall(NULL));
    labyrinths[p].set_cell(8,12, new wall(NULL));
    labyrinths[p].set_cell(9,12, new wall(NULL));
    labyrinths[p].set_cell(10,12, new wall(NULL));
    labyrinths[p].set_cell(11,12, new wall(NULL));
    labyrinths[p].set_cell(12,12, new wall(NULL));
    labyrinths[p].set_cell(13,12, new wall(NULL));
    labyrinths[p].set_cell(14,12, new wall(NULL));
    labyrinths[p].set_cell(15,12, new wall(NULL));

    labyrinths[p].set_cell(17,12, new wall(NULL));
    labyrinths[p].set_cell(18,12, new wall(NULL));
    labyrinths[p].set_cell(19,12, new wall(NULL));
    labyrinths[p].set_cell(1,14, new wall(NULL));

    labyrinths[p].set_cell(3,14, new wall(NULL));
    labyrinths[p].set_cell(4,14, new wall(NULL));
    labyrinths[p].set_cell(5,14, new wall(NULL));
    labyrinths[p].set_cell(6,14, new wall(NULL));
    labyrinths[p].set_cell(7,14, new wall(NULL));
    labyrinths[p].set_cell(8,14, new wall(NULL));
    labyrinths[p].set_cell(9,14, new wall(NULL));

    labyrinths[p].set_cell(11,14, new wall(NULL));
    labyrinths[p].set_cell(12,14, new wall(NULL));
    labyrinths[p].set_cell(13,14, new wall(NULL));
    labyrinths[p].set_cell(14,14, new wall(NULL));
    labyrinths[p].set_cell(15,14, new wall(NULL));
    labyrinths[p].set_cell(16,14, new wall(NULL));
    labyrinths[p].set_cell(17,14, new wall(NULL));
    labyrinths[p].set_cell(18,14, new wall(NULL));
    labyrinths[p].set_cell(19,14, new wall(NULL));
    labyrinths[p].set_cell(1,16, new wall(NULL));
    labyrinths[p].set_cell(2,16, new wall(NULL));

    labyrinths[p].set_cell(4,16, new wall(NULL));
    labyrinths[p].set_cell(5,16, new wall(NULL));
    labyrinths[p].set_cell(6,16, new wall(NULL));
    labyrinths[p].set_cell(7,16, new wall(NULL));
    labyrinths[p].set_cell(8,16, new wall(NULL));
    labyrinths[p].set_cell(9,16, new wall(NULL));
    labyrinths[p].set_cell(10,16, new wall(NULL));
    labyrinths[p].set_cell(11,16, new wall(NULL));
    labyrinths[p].set_cell(12,16, new wall(NULL));
    labyrinths[p].set_cell(13,16, new wall(NULL));

    labyrinths[p].set_cell(15,16, new wall(NULL));
    labyrinths[p].set_cell(16,16, new wall(NULL));
    labyrinths[p].set_cell(17,16, new wall(NULL));
    labyrinths[p].set_cell(18,16, new wall(NULL));
    labyrinths[p].set_cell(19,16, new wall(NULL));
    labyrinths[p].set_cell(13,19, new wall(NULL));
    labyrinths[p].set_cell(12,17, new wall(NULL));
    labyrinths[p].set_cell(12,18, new wall(NULL));
    labyrinths[p].set_cell(10,13, new wall(NULL));
    labyrinths[p].set_cell(10,15, new wall(NULL));
    labyrinths[p].set_cell(11,15, new wall(NULL));
    labyrinths[p].set_cell(12,19, v);
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


void sidorova_lab_1(vector<field>& labyrinths)
{
labyrinths.push_back(field(20,20));
int p = labyrinths.size()-1;
victory * v = new victory(&labyrinths[p]);
labyrinths[p].set_cell(3, 18, v);
for (int i(0); i<10; i++)
{
labyrinths[p].set_cell(i, 10, new wall(NULL));
}
for (int i(6); i<18; i++)
{
labyrinths[p].set_cell(i, 7, new wall(NULL));
}
for (int i(0); i<4; i++)
{
labyrinths[p].set_cell(i, 6, new wall(NULL));
}
for (int i(0); i<9; i++)
{
labyrinths[p].set_cell(i, 16, new wall(NULL));
}
for (int i(10); i<20; i++)
{
labyrinths[p].set_cell(i, 16, new wall(NULL));
}
for (int i(10); i<17; i++)
{
labyrinths[p].set_cell(6, i, new wall(NULL));
}
for (int i(18); i<20; i++)
{
labyrinths[p].set_cell(6, i, new wall(NULL));
}
for (int i(0); i<3; i++)
{
labyrinths[p].set_cell(6, i, new wall(NULL));
}
for (int i(5); i<8; i++)
{
labyrinths[p].set_cell(6, i, new wall(NULL));
}
for (int i(0); i<10; i++)
{
labyrinths[p].set_cell(19, i, new wall(NULL));
}
for (int i(11); i<16; i++)
{
labyrinths[p].set_cell(12, i, new wall(NULL));
}
for (int i(5); i<9; i++)
{
labyrinths[p].set_cell(12, i, new wall(NULL));
}
labyrinths[p].set_cell(14, 17, new wall(NULL));
labyrinths[p].set_cell(16, 7, new wall(NULL));
labyrinths[p].set_cell(2, 13, new wall(NULL));
labyrinths[p].set_cell(12, 13, new wall(NULL));
labyrinths[p].set_cell(10, 10, new wall(NULL));
labyrinths[p].set_cell(8, 18, new wall(NULL));
labyrinths[p].set_cell(15, 4, new wall(NULL));
labyrinths[p].set_cell(17, 3, new wall(NULL));
labyrinths[p].set_cell(3, 12, new wall(NULL));
labyrinths[p].set_cell(5, 11, new wall(NULL));
labyrinths[p].set_cell(16, 10, new wall(NULL));
labyrinths[p].set_cell(15, 9, new wall(NULL));
labyrinths[p].set_cell(3, 13, new wall(NULL));
labyrinths[p].set_cell(17, 4, new wall(NULL));
labyrinths[p].set_cell(17, 18, new wall(NULL));
labyrinths[p].set_cell(17, 2, new wall(NULL));
labyrinths[p].set_cell(3, 16, new wall(NULL));
labyrinths[p].set_cell(5, 18, new wall(NULL));
labyrinths[p].set_cell(3, 13, new wall(NULL));
labyrinths[p].set_start_row(3);
labyrinths[p].set_start_col(3);
}

void evtukhov_lab(vector<field>& labyrinths){
    int p = labyrinths.size();
    labyrinths.push_back(field(20, 20));
    victory * v = new victory(&labyrinths[p]);
    labyrinths[p].set_cell(0,0, new wall(NULL));
    labyrinths[p].set_start_row(1);
    labyrinths[p].set_start_col(2);
    labyrinths[p].set_cell(1,6, new wall(NULL));
    labyrinths[p].set_cell(3,6, new wall(NULL));
    labyrinths[p].set_cell(3,15, new wall(NULL));
    labyrinths[p].set_cell(4,4, new wall(NULL));
    labyrinths[p].set_cell(4,6, new wall(NULL));
    labyrinths[p].set_cell(4,16, new wall(NULL));
    labyrinths[p].set_cell(4,19, new wall(NULL));
    labyrinths[p].set_cell(5,2, new wall(NULL));
    labyrinths[p].set_cell(5,8, new wall(NULL));
    labyrinths[p].set_cell(5,19, new wall(NULL));
    labyrinths[p].set_cell(6,11, new wall(NULL));
    labyrinths[p].set_cell(6,13, new wall(NULL));
    labyrinths[p].set_cell(6,14, new wall(NULL));
    labyrinths[p].set_cell(6,18, new wall(NULL));
    labyrinths[p].set_cell(7,17, new wall(NULL));
    labyrinths[p].set_cell(8,0, new wall(NULL));
    labyrinths[p].set_cell(8,7, new wall(NULL));
    labyrinths[p].set_cell(8,13, new wall(NULL));
    labyrinths[p].set_cell(9,13, new wall(NULL));
    labyrinths[p].set_cell(9,15, new wall(NULL));
    labyrinths[p].set_cell(9,17, new wall(NULL));
    labyrinths[p].set_cell(11,3, new wall(NULL));
    labyrinths[p].set_cell(11,4, new wall(NULL));
    labyrinths[p].set_cell(11,13, new wall(NULL));
    labyrinths[p].set_cell(13,1, new wall(NULL));
    labyrinths[p].set_cell(13,3, new wall(NULL));
    labyrinths[p].set_cell(13,5, new wall(NULL));
    labyrinths[p].set_cell(13,10, new wall(NULL));
    labyrinths[p].set_cell(14,6, new wall(NULL));
    labyrinths[p].set_cell(14,7, new wall(NULL));
    labyrinths[p].set_cell(14,8, new wall(NULL));
    labyrinths[p].set_cell(14,19, new wall(NULL));
    labyrinths[p].set_cell(16,5, new wall(NULL));
    labyrinths[p].set_cell(16,17, new wall(NULL));
    labyrinths[p].set_cell(16,19, new wall(NULL));
    labyrinths[p].set_cell(17,8, new wall(NULL));
    labyrinths[p].set_cell(18,0, new wall(NULL));
    labyrinths[p].set_cell(18,15, new wall(NULL));
    labyrinths[p].set_cell(18,17, new wall(NULL));
    labyrinths[p].set_cell(19,6, new wall(NULL));
    labyrinths[p].set_cell(19,19, v);
}




void skorodumov_lab_1 (vector<field>& labyrinths)
{
labyrinths.push_back(field(20,20));
int p = labyrinths.size()-1;
victory * v = new victory(&labyrinths[p]);
labyrinths[p].set_cell(15,19, v);
labyrinths[p].set_cell(3,4,new wall(NULL));
labyrinths[p].set_cell(3,5,new wall(NULL));
labyrinths[p].set_cell(3,6,new wall(NULL));
labyrinths[p].set_cell(3,8,new wall(NULL));
labyrinths[p].set_cell(3,12,new wall(NULL));
labyrinths[p].set_cell(3,18,new wall(NULL));
labyrinths[p].set_cell(3,19,new wall(NULL));
labyrinths[p].set_cell(4,2,new wall(NULL));
labyrinths[p].set_cell(4,3,new wall(NULL));
labyrinths[p].set_cell(4,9,new wall(NULL));
labyrinths[p].set_cell(4,14,new wall(NULL));
labyrinths[p].set_cell(5,0,new wall(NULL));
labyrinths[p].set_cell(5,1,new wall(NULL));
labyrinths[p].set_cell(5,8,new wall(NULL));
labyrinths[p].set_cell(5,14,new wall(NULL));
labyrinths[p].set_cell(6,8,new wall(NULL));
labyrinths[p].set_cell(6,15,new wall(NULL));
labyrinths[p].set_cell(7,3,new wall(NULL));
labyrinths[p].set_cell(7,15,new wall(NULL));
labyrinths[p].set_cell(8,3,new wall(NULL));
labyrinths[p].set_cell(8,6,new wall(NULL));
labyrinths[p].set_cell(8,7,new wall(NULL));
labyrinths[p].set_cell(8,16,new wall(NULL));
labyrinths[p].set_cell(9,3,new wall(NULL));
labyrinths[p].set_cell(9,7,new wall(NULL));
labyrinths[p].set_cell(9,8,new wall(NULL));
labyrinths[p].set_cell(9,16,new wall(NULL));
labyrinths[p].set_cell(10,3,new wall(NULL));
labyrinths[p].set_cell(10,4,new wall(NULL));
labyrinths[p].set_cell(10,9,new wall(NULL));
labyrinths[p].set_cell(10,10,new wall(NULL));
labyrinths[p].set_cell(10,11,new wall(NULL));
labyrinths[p].set_cell(10,12,new wall(NULL));
labyrinths[p].set_cell(10,14,new wall(NULL));
labyrinths[p].set_cell(10,15,new wall(NULL));
labyrinths[p].set_cell(10,16,new wall(NULL));
labyrinths[p].set_cell(10,17,new wall(NULL));
labyrinths[p].set_cell(11,3,new wall(NULL));
labyrinths[p].set_cell(11,6,new wall(NULL));
labyrinths[p].set_cell(11,7,new wall(NULL));
labyrinths[p].set_cell(11,8,new wall(NULL));
labyrinths[p].set_cell(11,17,new wall(NULL));
labyrinths[p].set_cell(12,10,new wall(NULL));
labyrinths[p].set_cell(12,11,new wall(NULL));
labyrinths[p].set_cell(12,18,new wall(NULL));
labyrinths[p].set_cell(13,0,new wall(NULL));
labyrinths[p].set_cell(13,3,new wall(NULL));
labyrinths[p].set_cell(13,12,new wall(NULL));
labyrinths[p].set_cell(13,15,new wall(NULL));
labyrinths[p].set_cell(13,18,new wall(NULL));
labyrinths[p].set_cell(14,4,new wall(NULL));
labyrinths[p].set_cell(14,0,new wall(NULL));
labyrinths[p].set_cell(14,3,new wall(NULL));
labyrinths[p].set_cell(14,4,new wall(NULL));
labyrinths[p].set_cell(14,5,new wall(NULL));
labyrinths[p].set_cell(14,11,new wall(NULL));
labyrinths[p].set_cell(14,12,new wall(NULL));
labyrinths[p].set_cell(15,5,new wall(NULL));
labyrinths[p].set_cell(15,6,new wall(NULL));
labyrinths[p].set_cell(15,7,new wall(NULL));
labyrinths[p].set_cell(15,8,new wall(NULL));
labyrinths[p].set_cell(15,9,new wall(NULL));
labyrinths[p].set_cell(15,10,new wall(NULL));
labyrinths[p].set_cell(15,11,new wall(NULL));
labyrinths[p].set_cell(15,12,new wall(NULL));
labyrinths[p].set_cell(16,13,new wall(NULL));
labyrinths[p].set_cell(16,15,new wall(NULL));
labyrinths[p].set_cell(16,18,new wall(NULL));
labyrinths[p].set_cell(17,5,new wall(NULL));
labyrinths[p].set_cell(17,13,new wall(NULL));
labyrinths[p].set_cell(17,14,new wall(NULL));
labyrinths[p].set_cell(17,15,new wall(NULL));
labyrinths[p].set_cell(17,17,new wall(NULL));
labyrinths[p].set_cell(18,4,new wall(NULL));
labyrinths[p].set_cell(18,15,new wall(NULL));
labyrinths[p].set_cell(19,4,new wall(NULL));
labyrinths[p].set_cell(19,15,new wall(NULL));
labyrinths[p].set_start_row(19);
labyrinths[p].set_start_col(0);
}
void lab_s (vector<field>& labyrinths)
{
labyrinths.push_back(field(5,5));
int p = labyrinths.size()-1;
victory * v = new victory(&labyrinths[p]);
labyrinths[p].set_cell(2,3, v);
labyrinths[p].set_cell(1,2,new wall(NULL));
labyrinths[p].set_cell(2,2,new wall(NULL));
labyrinths[p].set_cell(3,2,new wall(NULL));
labyrinths[p].set_start_row(2);
labyrinths[p].set_start_col(1);
}
void fill_labyrinths(vector<field>& labyrinths)
{


    //f_Art(labyrinths);
    //ushenin_lab_1(labyrinths);
    //labTruefunoff(labyrinths);
    //lab_uspenskaya(labyrinths);
    //tokarenko_lab_1(labyrinths);
    //lab_dubovenko(labyrinths);
    //f_ermolaeva(labyrinths);
    //daryina_lab_1(labyrinths);
	//sidorova_lab_1(labyrinths);
    //karpov_lab_1(labyrinths);
    //skorodumov_lab_1(labyrinths);
    //evtukhov_lab(labyrinths);
    lab_s(labyrinths);
}

