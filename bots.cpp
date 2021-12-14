#include "base.hpp"
#include "jenya705.hpp"

class right_bot:public pc
{
public:
    right_bot(field * p, string n):pc(p, n) {}
    virtual void ai()
    {
        while (can_go(d)){
            go(d);
        }
    }
};

class panic_bot:public pc
{
public:
    panic_bot(field * p, string n):pc(p, n) {}
    virtual void ai()
    {
        while (!won())
        for (auto i: {direction::w, direction::e, direction::d, direction::x, direction::z, direction::a})
        {
            go(i);
        }
    }
};

class a_star_sidorova: public pc
{
public:
   a_star_sidorova(field * p, string n):pc(p, n) {}
    virtual void ai()
    {   int wall (999);
        int fog (9999);
        vector<vector<float>> field_model(50, vector<float> (50, fog));
        float cur_dist = dist_to_exit();
        field_model[row][col] = cur_dist;
        direction choice = w;
        pair<int,int> choice_coord ({-1,-1});
        choice_coord.first = row + delta(w).first;
        choice_coord.second = col + delta(w).second;
        for (auto i: {direction::w, direction::e, direction::d, direction::x, direction::z, direction::a})
        {
            pair<int,int> deltas = delta(i);
            if (!can_go(i)) field_model[row + deltas.first][col + deltas.second] = wall;
            else
            {
                go (i);
                field_model[row + deltas.first][col + deltas.second] = dist_to_exit();
                if (field_model[row + deltas.first][col + deltas.second] < field_model[choice_coord.first][choice_coord.second])
            {
                    choice = i;
                    choice_coord.first = row + deltas(i).first;
                    choice_coord.second = col + deltas(i).second;
            }
        }
        go(choice);

    }
private:
    int row=25;
    int col=25;
    pair <int, int> delta(direction dir)
    {
        if (dir == w ) return (-1, -row%2);
        if (dir == e ) return (-1, +row%2);
        if (dir == d ) return (+1, 0);
        if (dir == x ) return (+1, +row%2);
        if (dir == z ) return (-1, -row%2);
        if (dir == a ) return (-1, 0);

    }
};


void fill_bots(vector<pc*> & bots)
{
    bots.a_star_sidorova(new panic_bot(NULL, "0"));
};
