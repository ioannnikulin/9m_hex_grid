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




void f3(vector<field>& labyrinths)
{
labyrinths.push_back(field(21,21));
int p = labyrinths.size()-1;
victory * v = new victory(&labyrinths[p]);
///1
vector<int> r1 = {3,5,10,13,15,17, 20};
for(int i=0; i<r1.size(); i++) {labyrinths[p].set_cell(2,r1[i], new wall(NULL));}
///2
vector<int> r2 = {1,3,6,7,5,9,10,12,14,17,19,20};
for(int i=0; i<r2.size(); i++) {labyrinths[p].set_cell(2,r2[i], new wall(NULL));}
///3
vector<int> r3 = {2,3,6,10,11,14,13,20};
for(int i=0; i<r3.size(); i++) {labyrinths[p].set_cell(3,r3[i], new wall(NULL));}
///4
vector<int> r4 = {1,5,6,9,10,12,14,18,19};
for(int i=0; i<r4.size(); i++) {labyrinths[p].set_cell(4,r4[i], new wall(NULL));}
///5
vector<int> r5 = {1,3,7,8,16,19};
for(int i=0; i<r5.size(); i++) {labyrinths[p].set_cell(5,r5[i], new wall(NULL));}
///6
vector<int> r6 = {2,3,4,6,10,11,12,13,14,15,17,19};
for(int i=0; i<r6.size(); i++) {labyrinths[p].set_cell(6,r6[i], new wall(NULL));}
///7
vector<int> r7 = {7,8,9,15,18,19};
for(int i=0; i<r7.size(); i++) {labyrinths[p].set_cell(7,r7[i], new wall(NULL));}
///8
vector<int> r8 = {1,3,5,6,10,11,15};
for(int i=0; i<r8.size(); i++) {labyrinths[p].set_cell(8,r8[i], new wall(NULL));}
///9
vector<int> r9 = {2,4,7,9,11,13,19,20};
for(int i=0; i<r9.size(); i++) {labyrinths[p].set_cell(9,r9[i], new wall(NULL));}
///10
vector<int> r10 = {1,3,5,6,8,16,17,18};
for(int i=0; i<r10.size(); i++) {labyrinths[p].set_cell(10,r10[i], new wall(NULL));}
///11
vector<int> r11 = {2,4,6,7,9,10,12,14,18,19,20};
for(int i=0; i<r11.size(); i++) {labyrinths[p].set_cell(11,r11[i], new wall(NULL));}
///12
vector<int> r12 = {2,4,9,12,14,16,18,20};
for(int i=0; i<r12.size(); i++) {labyrinths[p].set_cell(12,r12[i], new wall(NULL));}
///13
vector<int> r13 = {1,5,7,9,10,12,13,14,15,18};
for(int i=0; i<r13.size(); i++) {labyrinths[p].set_cell(13,r13[i], new wall(NULL));}
///14
vector<int> r14 = {3,4,6,10,15,17,19};
for(int i=0; i<r14.size(); i++) {labyrinths[p].set_cell(14,r14[i], new wall(NULL));}
///15
vector<int> r15 = {1,2,5,6,7,8,11,12,13,15,17,18,20};
for(int i=0; i<r15.size(); i++) {labyrinths[p].set_cell(15,r15[i], new wall(NULL));}
///16
vector<int> r16 = {1,4,5,10,15};
for(int i=0; i<r16.size(); i++) {labyrinths[p].set_cell(16,r16[i], new wall(NULL));}
///17
vector<int> r17 = {1,2,6,7,9,10,12,16,18,20};
for(int i=0; i<r17.size(); i++) {labyrinths[p].set_cell(17,r17[i], new wall(NULL));}
///18
vector<int> r18 = {1,3,5,9,14,16,17,19};
for(int i=0; i<r18.size(); i++) {labyrinths[p].set_cell(18,r18[i], new wall(NULL));}
///19
vector<int> r19 = {1,2,3,6,7,8,10,13,14,15,16,17,18,19};
for(int i=0; i<r19.size(); i++) {labyrinths[p].set_cell(19,r19[i], new wall(NULL));}
///20
vector<int> r20 = {2,5,9,10,19,20};
for(int i=0; i<r20.size(); i++) {labyrinths[p].set_cell(20,r20[i], new wall(NULL));}



labyrinths[p].set_cell(5,5, new wall(NULL));
labyrinths[p].set_cell(17,7, v);
labyrinths[p].set_start_row(1);
labyrinths[p].set_start_col(1);
}



void fill_labyrinths(vector<field>& labyrinths)
{
f0(labyrinths);
f1(labyrinths);
f3(labyrinths);
}
