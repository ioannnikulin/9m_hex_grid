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


    labyrinths[p].set_cell(0,23, new wall(NULL));		///1 по у

    labyrinths[p].set_cell(1,4, new wall(NULL));		///2 по у
    labyrinths[p].set_cell(1,6, new wall(NULL));
    labyrinths[p].set_cell(1,23, new wall(NULL));

    labyrinths[p].set_cell(2,4, new wall(NULL));		///3 по у
    labyrinths[p].set_cell(2,5, new wall(NULL));
    labyrinths[p].set_cell(2,17, new wall(NULL));
    labyrinths[p].set_cell(2,22, new wall(NULL));

    labyrinths[p].set_cell(3,5, new wall(NULL));		///4 по у
    labyrinths[p].set_cell(3,7, new wall(NULL));
    labyrinths[p].set_cell(3,12, new wall(NULL));
    labyrinths[p].set_cell(3,14, new wall(NULL));
    labyrinths[p].set_cell(3,17, new wall(NULL));
    labyrinths[p].set_cell(3,19, new wall(NULL));
    labyrinths[p].set_cell(3,20, new wall(NULL));
    labyrinths[p].set_cell(3,22, new wall(NULL));

    labyrinths[p].set_cell(4,14, new wall(NULL));		///5 по у
    labyrinths[p].set_cell(4,16, new wall(NULL));
    labyrinths[p].set_cell(4,18, new wall(NULL));
    labyrinths[p].set_cell(4,20, new wall(NULL));
    labyrinths[p].set_cell(4,22, new wall(NULL));

    labyrinths[p].set_cell(5,7, new wall(NULL));		///6 по у
    labyrinths[p].set_cell(5,9, new wall(NULL));
    labyrinths[p].set_cell(5,15, new wall(NULL));
    labyrinths[p].set_cell(5,21, new wall(NULL));
	labyrinths[p].set_cell(5,22, new wall(NULL));

    labyrinths[p].set_cell(6,2, new wall(NULL));		///7 по у
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

    labyrinths[p].set_cell(7,4, new wall(NULL));		///8 по у
    labyrinths[p].set_cell(7,6, new wall(NULL));
    labyrinths[p].set_cell(7,9, new wall(NULL));
    labyrinths[p].set_cell(7,11, new wall(NULL));
    labyrinths[p].set_cell(7,16, new wall(NULL));
    labyrinths[p].set_cell(7,18, new wall(NULL));
    labyrinths[p].set_cell(7,20, new wall(NULL));
    labyrinths[p].set_cell(7,21, new wall(NULL));

    labyrinths[p].set_cell(8,3, new wall(NULL));		///9 по у
    labyrinths[p].set_cell(8,6, new wall(NULL));
    labyrinths[p].set_cell(8,12, new wall(NULL));
    labyrinths[p].set_cell(8,14, new wall(NULL));
    labyrinths[p].set_cell(8,15, new wall(NULL));
    labyrinths[p].set_cell(8,17, new wall(NULL));
    labyrinths[p].set_cell(8,21, new wall(NULL));
	labyrinths[p].set_cell(8,23, new wall(NULL));

    labyrinths[p].set_cell(9,3, new wall(NULL));		///10 по у
    labyrinths[p].set_cell(9,5, new wall(NULL));
    labyrinths[p].set_cell(9,7, new wall(NULL));
    labyrinths[p].set_cell(9,10, new wall(NULL));
    labyrinths[p].set_cell(9,15, new wall(NULL));
    labyrinths[p].set_cell(9,17, new wall(NULL));
    labyrinths[p].set_cell(9,19, new wall(NULL));
    labyrinths[p].set_cell(9,21, new wall(NULL));

    labyrinths[p].set_cell(10,3, new wall(NULL));		///11 по у
    labyrinths[p].set_cell(10,5, new wall(NULL));
    labyrinths[p].set_cell(10,7, new wall(NULL));
    labyrinths[p].set_cell(10,9, new wall(NULL));
    labyrinths[p].set_cell(10,11, new wall(NULL));
    labyrinths[p].set_cell(10,13, new wall(NULL));
    labyrinths[p].set_cell(10,14, new wall(NULL));
    labyrinths[p].set_cell(10,16, new wall(NULL));
    labyrinths[p].set_cell(10,20, new wall(NULL));
    labyrinths[p].set_cell(10,22, new wall(NULL));

    labyrinths[p].set_cell(11,3, new wall(NULL));		///12 по у
    labyrinths[p].set_cell(11,4, new wall(NULL));
    labyrinths[p].set_cell(11,11, new wall(NULL));
    labyrinths[p].set_cell(11,13, new wall(NULL));
    labyrinths[p].set_cell(11,14, new wall(NULL));
    labyrinths[p].set_cell(11,18, new wall(NULL));
    labyrinths[p].set_cell(11,20, new wall(NULL));
	labyrinths[p].set_cell(11,22, new wall(NULL));

    labyrinths[p].set_cell(12,5, new wall(NULL));		///13 по у
    labyrinths[p].set_cell(12,11, new wall(NULL));
    labyrinths[p].set_cell(12,13, new wall(NULL));
    labyrinths[p].set_cell(12,14, new wall(NULL));
    labyrinths[p].set_cell(12,16, new wall(NULL));
    labyrinths[p].set_cell(12,18, new wall(NULL));

    labyrinths[p].set_cell(13,3, new wall(NULL));		///14 по у
    labyrinths[p].set_cell(13,5, new wall(NULL));
    labyrinths[p].set_cell(13,13, new wall(NULL));
    labyrinths[p].set_cell(13,6, new wall(NULL));
    labyrinths[p].set_cell(13,15, new wall(NULL));
    labyrinths[p].set_cell(13,18, new wall(NULL));
    labyrinths[p].set_cell(13,21, new wall(NULL));

    labyrinths[p].set_cell(14,3, new wall(NULL));		///15 по у
    labyrinths[p].set_cell(14,4, new wall(NULL));
    labyrinths[p].set_cell(14,7, new wall(NULL));
    labyrinths[p].set_cell(14,19, new wall(NULL));
    labyrinths[p].set_cell(14,21, new wall(NULL));
    labyrinths[p].set_cell(14,22, new wall(NULL));

    labyrinths[p].set_cell(15,7, new wall(NULL));		///16 по у
    labyrinths[p].set_cell(15,14, new wall(NULL));
    labyrinths[p].set_cell(15,15, new wall(NULL));
    labyrinths[p].set_cell(15,16, new wall(NULL));
    labyrinths[p].set_cell(15,19, new wall(NULL));

    labyrinths[p].set_cell(16,0, new wall(NULL));		///17 по у
    labyrinths[p].set_cell(16,2, new wall(NULL));
    labyrinths[p].set_cell(16,6, new wall(NULL));
    labyrinths[p].set_cell(16,9, new wall(NULL));
    labyrinths[p].set_cell(16,14, new wall(NULL));

    labyrinths[p].set_cell(17,0, new wall(NULL));		///18 по у
    labyrinths[p].set_cell(17,6, new wall(NULL));
    labyrinths[p].set_cell(17,8, new wall(NULL));
    labyrinths[p].set_cell(17,14, new wall(NULL));
	labyrinths[p].set_cell(17,23, new wall(NULL));

    labyrinths[p].set_cell(18,0, new wall(NULL));		///19 по у
    labyrinths[p].set_cell(18,5, new wall(NULL));
    labyrinths[p].set_cell(18,7, new wall(NULL));
    labyrinths[p].set_cell(18,8, new wall(NULL));
    labyrinths[p].set_cell(18,10, new wall(NULL));
    labyrinths[p].set_cell(18,13, new wall(NULL));
    labyrinths[p].set_cell(18,21, new wall(NULL));

    labyrinths[p].set_cell(19,5, new wall(NULL));		///20 по у
    labyrinths[p].set_cell(19,7, new wall(NULL));
    labyrinths[p].set_cell(19,8, new wall(NULL));
    labyrinths[p].set_cell(19,11, new wall(NULL));

    labyrinths[p].set_cell(20,20, new wall(NULL));		///21 по у

    labyrinths[p].set_cell(20,21, v);
    labyrinths[p].set_start_row(0);
    labyrinths[p].set_start_col(0);
}

void fill_labyrinths(vector<field>& labyrinths)
{
    f_Art(labyrinths);
}

