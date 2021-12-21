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
        while (!won())
        {
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
            }
        go(choice);
        while (field_model[row + deltas.first][col + deltas.second] < field_model[choice_coord.first][choice_coord.second])
            {
                    choice = i;
                    choice_coord.first = row + delta(i).first;
                    choice_coord.second = col + delta(i).second;
            }
        }
    }
    }
private:
    int row=25;
    int col=25;
    pair <int, int> delta(direction dir)
    {
        if (dir == w ) return {-1, -row%2};
        if (dir == e ) return {-1, 1-row%2};
        if (dir == d ) return {0, +1};
        if (dir == x ) return {+1, row%2};
        if (dir == z ) return {+1, row%2+1};
        if (dir == a ) return {0, -1};

    }
    direction backwards(direction dir)
    {
        if (dir == w) return x;
        if (dir == e) return z;
        if (dir == d) return a;
        if (dir == x) return w;
        if (dir == a) return d;
        if (dir == z) return e;


    }
};


void fill_bots(vector<pc*> & bots)
{
    bots.push_back(new a_star_sidorova(NULL, "<"));
}
