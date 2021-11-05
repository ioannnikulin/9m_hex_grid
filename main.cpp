#include <iostream>
#include <vector>

using namespace std;

class field;

class cell
{
    friend class field;
public:
    cell(field * p):parent(p) {}
    virtual void interact(cell * src) = 0;
    virtual string str() {return ".";}
protected:
    int x;
    int y;
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
    void go(direction d);
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
        space * ddummy = new space(this);
        auto dummy = vector<cell*>(cols, ddummy);
        cells = vector<vector<cell*>>(rows, dummy);
        for (size_t r(0); r<cells.size(); r++)
        for (size_t c(0); c<cells[0].size(); c++)
        {
            cells[r][c]->x = c;
            cells[r][c]->y = r;
        }
    }
    void go(int fx, int fy, int tx, int ty)
    {
        swap(cells[fx][fy], cells[tx][ty]);
        swap(cells[fx][fy]->x, cells[tx][ty]->x);
        swap(cells[fx][fy]->y, cells[tx][ty]->y);
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
    }
    void set_cell(int r, int c, cell * nc)
    {
        cells[r][c] = nc;
    }
private:
    vector<vector<cell*>> cells;
};

void space::interact(cell * src)
{
    //parent->go(src->x, src->y);//TODO
}

vector<field> labyrinths;

int main()
{
    labyrinths.push_back(field(5,6));
    pc * player = new pc(&labyrinths[0], "Q");
    labyrinths[0].set_cell(2,3, player);
    labyrinths[0].show();
    return 0;
}
