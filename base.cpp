#include "base.hpp"
#include <chrono>
#include <thread>

field::field(int rows, int cols):cells(vector<vector<cell*>>(rows)),start_row(-1),start_col(-1),steps(0),ttl(0)
{
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
void field::swap(cell * f, cell * t)
{
    swap(f->row, f->col, t->row, t->col);
}
void field::swap(int frow, int fcol, int trow, int tcol)
{
    std::swap(cells[frow][fcol], cells[trow][tcol]);
    std::swap(cells[frow][fcol]->col, cells[trow][tcol]->col);
    std::swap(cells[frow][fcol]->row, cells[trow][tcol]->row);
}
void field::show()
{
    for (size_t i(0); i<cells.size(); i++)
    {
        if (i%2 == 0) cout << " ";
        for (auto j: cells[i])
            cout << j->str() << " ";
        cout << endl;
    }
    cout << endl << std::flush;
}
void field::set_cell(int r, int c, cell * nc)
{
    cells[r][c] = nc;
    nc->row = r;
    nc->col = c;
    nc->parent = this;
}
int field::width()
{
    return cells[0].size();
}
int field::height()
{
    return cells.size();
}

float field::dist_to_exit(pc * p)
{
    if (passed) return 0;
    float res(width() + height());
    for (auto i: cells)
        for (auto j: i)
            if (j->is_victory())
            {
                float dist = sqrt(pow(j->row - p->row, 2) + pow(j->col - p->col, 2));
                res = std::min(dist, res);
            }
    return res;
}

float pc::dist_to_exit()
{
    return parent->dist_to_exit(this);
}

bool pc::won()
{
    return (dist_to_exit() < 2);
}


int interact(pc * src, cell * tgt, field * f)
{
    if (tgt->is_walkable())
    {
        f->swap(src, tgt);
        return 0;
    }
    return -1;
}


cell * field::look(cell * p, direction dir)
{
    int row = p->row;
    int col = p->col;
    cell * tgt(NULL);
    switch (dir)
    {
    case direction::d:
        if (col<width()-1)
            tgt = cells[row][col+1];
        break;
    case direction::a:
        if (col > 0)
            tgt = cells[row][col-1];
        break;
    case direction::w:
        if (row > 0)
        {
            if (row%2 == 0)
                tgt = cells[row-1][col];
            else if (col > 0)
                tgt = cells[row-1][col-1];
        }
        break;
    case direction::e:
        if (row > 0)
        {
            if (row%2 > 0)
                tgt = cells[row-1][col];
            else if (col < width()-1)
                tgt = cells[row-1][col+1];
        }
        break;
    case direction::z:
        if (row < height()-1)
        {
            if (row%2 == 0)
                tgt = cells[row+1][col];
            else if (col > 0)
                tgt = cells[row+1][col-1];
        }
        break;
    case direction::x:
        if (row < height()-1)
        {
            if (row%2 > 0)
                tgt = cells[row+1][col];
            else if (col < width()-1)
                tgt = cells[row+1][col+1];
        }
        break;
    }
    return tgt;
}

void pc::go(direction dir) {parent->go(this, dir);}
bool pc::can_go(direction dir) {return parent->can_go(this, dir);}

bool field::can_go(pc * p, direction dir)
{
    cell * tgt = look(p, dir);
    if (tgt!=NULL) return tgt->is_walkable();
    return false;
}

void field::go(pc * p, direction dir)
{
    steps++;
    cell * tgt = look(p, dir);
    if (tgt!=NULL)
    {
        //clog << "go to " << tgt->row << ":" << tgt->col << endl;
        if (interact(p, tgt, this) == 0)
        #if MODE == SHOW
        {
            system("cls");
            show();//if interact successful, smth changed
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        #else
            ;
        #endif
    }
    if (steps >= ttl)
    {
        throw std::runtime_error("bot out of gas");
    }
}

void field::place_player(pc * bot)
{
    set_cell(start_row, start_col, bot);
    ttl = (width()*height())*25;//TODO
    steps = 0;
    passed = false;
}
