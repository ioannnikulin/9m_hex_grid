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

class dubovenko_astar_bot:public pc
{
public:
    dubovenko_astar_bot(field * p, string n):pc(p, n) {}
    virtual void ai()
    {
        while(!won())
        {int wall(999);
        int fog(9999);
        vector<vector<float>> field_model(50, vector<float> (50, fog));
        int row(25), col(25);
        float cur_dist=dist_to_exit();
        field_model[row][col]=cur_dist;
        direction choice=w;
        pair<int, int> choice_coord({-1, -1});
        choice_coord.first=row+delta(w).first;
        choice_coord.second=col+delta(w).second;
        for(auto i: {direction::w, direction::e, direction::d, direction::x, direction::z, direction::a})
        {
            pair<int, int> deltas=delta(i);
            if(!can_go(i)) field_model[row+deltas.first][col+deltas.second]=wall;
            else
            {
                go(i);
                field_model[row+deltas.first][col+deltas.second]=dist_to_exit();
                if(field_model[row+deltas.first][col+deltas.second]<field_model[choice_coord.first][choice_coord.second])
                {
                    choice=i;
                    choice_coord.first=row+delta(i).first;
                    choice_coord.second=col+delta(i).second;
                }
                go(opposite(i));
            }
        }
        go(choice);
    }}
private:
    int row=25;
    int col=25;
    pair<int, int> delta(direction dir)
    {
        if(dir==w) return{-1, -row%2};
        if(dir==e) return{-1, (row+1)%2};
        if(dir==d) return{0, 1};
        if(dir==x) return{1, (row+1)%2};
        if(dir==z) return{1, -row%2};
        if(dir==a) return{0, -1};
    }
    direction opposite (direction dir)
    {
        if(dir==w) return x;
        if(dir==e) return z;
        if(dir==d) return a;
        if(dir==x) return w;
        if(dir==z) return e;
        if(dir==a) return d;
    }
};
void fill_bots(vector<pc*> & bots)
{
    //bots.push_back(new jenya705::jenya705_bot_starter(NULL));
    //bots.push_back(new right_bot(NULL, ">"));
    //bots.push_back(new panic_bot(NULL, "?"));
    bots.push_back(new dubovenko_astar_bot(NULL, ">"));
}
