#include "base.hpp"

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
class truefunoff_right_hand_bot:public pc
{
 public:
    truefunoff_right_hand_bot(field * p, string n):pc(p, n) {}
    direction last_d=direction::d;
    direction saw_d=next_d(last_d);
    direction next_d(direction l_d)
    {
        if (l_d==direction::d)
        {
            return direction::x;
        }
        if (l_d==direction::x)
        {
            return direction::z;
        }
        if (l_d==direction::z)
        {
            return direction::a;
        }
        if (l_d==direction::a)
        {
            return direction::w;
        }
        if (l_d==direction::w)
        {
            return direction::e;
        }
        if (l_d==direction::e)
        {
            return direction::d;
        }
    }
    direction try_d(direction l_d)
    {
        if (l_d==direction::d)
        {
            return direction::e;
        }
        if (l_d==direction::x)
        {
            return direction::d;
        }
        if (l_d==direction::z)
        {
            return direction::x;
        }
        if (l_d==direction::a)
        {
            return direction::z;
        }
        if (l_d==direction::w)
        {
            return direction::a;
        }
        if (l_d==direction::e)
        {
            return direction::w;
        }
    }
    direction going()
    {
       if (can_go(saw_d))
            {
                return saw_d;
            }
            else
            {
                saw_d=try_d(saw_d);
                going();
            }
    }
    virtual void ai()
    {
        while (!won())
        {
            last_d=going();
            go(last_d);
            saw_d=next_d(last_d);
        }
    }
};

void fill_bots(vector<pc*> & bots)
{
    bots.push_back(new truefunoff_right_hand_bot(NULL, "%"));
    bots.push_back(new right_bot(NULL, ">"));
    bots.push_back(new panic_bot(NULL, "?"));
}
