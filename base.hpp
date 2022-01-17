#ifndef BASE_HPP_INCLUDED
#define BASE_HPP_INCLUDED
#include <iostream>
#include <vector>
#include <cmath>


#define SHOW 1
#define BENCHMARK 2
#define MODE BENCHMARK


using std::string;
using std::cout;
using std::clog;
using std::vector;
using std::endl;
using std::pair;
class field;

class cell
{
    friend class field;
    friend class pc;//for row, col
public:
    cell(field * p):col(-1),row(-1),parent(p) {}
    virtual string str() const = 0;
    virtual bool is_walkable() const {return false;}
    virtual bool is_victory() const =0;
    virtual bool is_player() const =0;
    int get_col() const {return col;}
    int get_row() const {return row;}
    virtual ~cell() {}
protected:
    int col;
    int row;
    field * parent;
private:
    cell(const cell&):col(-1),row(-1),parent(NULL){}
    cell& operator=(const cell&){return *this;}
};

enum direction
{
    w, e, d, x, z, a
};

class space: public cell
{
public:
    space(field * p):cell(p) {}
    virtual bool is_walkable() const {return true;}
    virtual bool is_victory() const {return false;}
    virtual string str() const {return ".";}
    virtual bool is_player() const {return false;}
};

class wall: public cell
{
public:
    wall(field * p):cell(p) {}
    virtual bool is_walkable() const {return false;}
    virtual bool is_victory() const {return false;}
    virtual bool is_player() const {return false;}
    virtual string str() const {return "#";}
};

class victory: public cell
{
public:
    victory(field * p):cell(p) {}
    virtual bool is_walkable() const {return false;}
    virtual bool is_victory() const {return true;}
    virtual bool is_player() const {return false;}
    virtual string str() const {return "*";}
};

class character: public cell
{
public:
    virtual string str() const {return name;}
    character(field * p, string n):cell(p), name(n) {}
    virtual bool is_walkable() const {return false;}
    virtual bool is_victory() const {return false;}
    virtual bool is_player() const {return false;}

protected:
    string name;
};

class pc: public character
{
public:
    pc(field * p, string n):character(p, n) {}
    void go(direction dir);
    bool can_go(direction dir) const;
    bool won() const;
    float dist_to_exit() const;
    virtual bool is_player() const {return true;}
    virtual void ai() = 0;
};

class field
{
public:
    field(int rows, int cols);
    void swap(cell * f, cell * t);
    void go(pc * f, direction d);
    bool can_go(const pc * f, direction d) const;
    void swap(int frow, int fcol, int trow, int tcol);
    void show() const;
    void set_cell(int r, int c, cell * nc);
    int width() const;
    int height() const;
    float dist_to_exit(const pc * p) const;
    void set_start_row(int r) {start_row = r;}
    void set_start_col(int c) {start_col = c;}
    void place_player(pc * bot);
    int get_steps() const {return steps;}
    void remove_bots();
private:
    vector<vector<cell*>> cells;
    cell * look(const cell * p, direction dir) const;
    int start_row, start_col;
    int steps;
    int ttl;

    template <class T1, class T2>
    int interact(T1 * src, T2 * tgt);
    vector<cell*> m_exits;
};



void fill_labyrinths(vector<field> & labyrinths);
void fill_bots(vector<pc*> & bots);

#endif // BASE_HPP_INCLUDED
