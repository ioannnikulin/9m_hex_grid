#include <iostream>
#include <vector>

using namespace std;

class field;

class cell
{
    friend class field;
    friend class pc;//for row, col
public:
    cell(field * p):parent(p) {}
    virtual void interact(cell * src) = 0;
    virtual string str() {return ".";}
protected:
    int col;
    int row;
    field * parent;
};

enum direction
{
    w, e, d, x, z, a
};

class space: public cell
{
public:
    space(field * p):cell(p) {}
    virtual void interact(cell * src);
};

class wall: public cell
{
public:
    virtual void interact(cell * src){}
};

class character: public cell
{
public:
    virtual void interact(cell * src)
    {
    }
    virtual string str() {return name;}
    character(field * p, string n):cell(p), name(n) {}
protected:
    string name;
};

class pc: public character
{
public:
    pc(field * p, string n):character(p, n) {}
    void go(direction dir);
    virtual void interact(cell * src)
    {
        cout << "we'll fight" << endl;
    }
    virtual string str() {return "P";}
};

class field
{
public:
    field(int rows, int cols)
    {
        cells = vector<vector<cell*>>(rows);
        for (size_t r(0); r<cells.size(); r++)
            cells[r] = vector<cell*>(cols, NULL);
        for (size_t r(0); r<cells.size(); r++)
        for (size_t c(0); c<cells[0].size(); c++)
        {
            cells[r][c] = new space(this);
            cells[r][c]->col = c;
            cells[r][c]->row = r;
        }
    }
    void go(int frow, int fcol, int trow, int tcol)
    {
        swap(cells[frow][fcol], cells[trow][tcol]);
        swap(cells[frow][fcol]->col, cells[trow][tcol]->col);
        swap(cells[frow][fcol]->row, cells[trow][tcol]->row);
    }
    void show()
    {
        for (size_t i(0); i<cells.size(); i++)
        {
            if (i%2 == 0) cout << " ";
            for (auto j: cells[i])
                cout << j->str() << " ";
            cout << endl;
        }
        cout << endl;
    }
    void set_cell(int r, int c, cell * nc)
    {
        cells[r][c] = nc;
        nc->row = r;
        nc->col = c;
    }
    int width()
    {
        return cells[0].size();
    }
    int height()
    {
        return cells.size();
    }
    cell * get(int r, int c) {return cells[r][c];}
private:
    vector<vector<cell*>> cells;
};

void space::interact(cell * src)
{
    //parent->go(src->x, src->y);//TODO
}

void pc::go(direction dir)
{
    cell * tgt(NULL);
    switch (dir)
    {
    case direction::d:
        if (col<parent->width()-1)
            tgt = parent->get(row, col+1);
        break;
    case direction::a:
        if (col > 0)
            tgt = parent->get(row, col-1);
        break;
    case direction::w:
        if (row > 0)
            if (row%2 == 0)
                tgt = parent->get(row-1, col);
            else if (col > 0)
                tgt = parent->get(row-1, col-1);
        break;
    case direction::e:
        if (row > 0)
            if (row%2 > 0)
                tgt = parent->get(row-1, col);
            else if (col < parent->width()-1)
                tgt = parent->get(row-1, col+1);
        break;
    case direction::z:
        if (row < parent->height()-1)
            if (row%2 == 0)
                tgt = parent->get(row+1, col);
            else if (col > 0)
                tgt = parent->get(row+1, col-1);
        break;
    case direction::x:
        if (row < parent->height()-1)
            if (row%2 > 0)
                tgt = parent->get(row+1, col);
            else if (col < parent->width()-1)
                tgt = parent->get(row+1, col+1);
        break;
    }
    if (tgt!=NULL)
    {
        clog << "go to " << tgt->row << ":" << tgt->col << endl;
        parent->go(row, col, tgt->row, tgt->col);
    }
}

vector<field> labyrinths;

int main()
{
    labyrinths.push_back(field(5,6));
    pc * player = new pc(&labyrinths[0], "Q");
    labyrinths[0].set_cell(2,3, player);
    labyrinths[0].show();
    for (auto i: {direction::w, direction::e, direction::d, direction::x, direction::z, direction::a})
    {
        //for (int j(0); j<5; j++)
        {
            player->go(i);
            labyrinths[0].show();
        }
    }
    return 0;
}
